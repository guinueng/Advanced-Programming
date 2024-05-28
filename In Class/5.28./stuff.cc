#include <vector>
#include <map>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class pointer{ // Unique pointer. Not completed rule of 3. -> Not possible to complete it.
    T* ptr;
    public:
    pointer(T* ptr) : ptr(ptr) {}
    ~pointer() { delete this -> ptr; } // Make destructor to be automatically delete heap memory.
    pointer(pointer<T> const&) = delete;
    pointer& operator= (pointer<T> const&&) = delete;
    T& operator*() const { return *this -> ptr; } // & want to be pointer, but not syntactically ptr.

};

int main(){
    unique_ptr<int> x(new int);
    //pointer<int> x = new int; // Need unary constructor.
    *x = 5;
    cout << *x << endl;
    
    /*
        map<string, int> prices;
        prices["apples"] = 1000;
        prices["oranges"] = 2000;
        for(auto[n, p] : prices) // auto keyword. automatically type define. Not same as python's typing.
            cout << n << " : " << p << "\n";
        auto x = 1;
    
        illegal ->
        auto x = prices["apples"];
        x = 2;
    
        vector<int> a;
        a.push_back(5);
        a.push_back(10);
        a.push_back(-5);

        for(int& x : a) // Call loop(?) -> power to choose type
            x *= 2;

        for(int x : a) // Call loop(?) -> power to choose type
            cout << x << " ";
        cout << endl;
    */

    return 0;
}