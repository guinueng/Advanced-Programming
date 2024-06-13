#ifndef FILE_H
#define FILE_H

#include <cstddef>
#include <vector>

class file{
    public:
    virtual size_t blocks_required() const = 0;
    virtual file* copy() const = 0;
    virtual ~file() {}
};

class regular_file : public file{
    protected:
    size_t bytes;
    public:
    regular_file(size_t bytes) : bytes(bytes) {}
    virtual size_t num_bytes() const { return this -> bytes; }
    size_t blocks_required() const override { return (this -> num_bytes() + 4095) / 4096; }
    file* copy() const override { return new regular_file(this -> bytes); }
};

class text_file : public regular_file{
    public:
    text_file(size_t bytes) : regular_file(bytes) {}
    virtual size_t num_bytes() const { return (size_t)(this -> bytes / 3.5 + 1); }
    file* copy() const override { return new text_file(this -> bytes); }
};

class video_stream : public regular_file{
    double duration, byterate;
    public:
    video_stream(double duration, double byterate = 800000) : regular_file((size_t)(duration * byterate)), duration(duration), byterate(byterate) {}
    file* copy() const override { return new video_stream(this -> duration, this -> byterate); }
};

class directory : public file{
    std::vector<file *> files;
    public:
    directory(std::vector<file *> fs) : files(fs) {}
    ~directory();
    directory(directory const&);
    directory& operator=(directory const&);
    size_t blocks_required() const override;
    file* copy() const override;
};

#endif