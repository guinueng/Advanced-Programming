#ifndef EXPR_H
#define EXPR_H

#include <iostream>
#include <math.h>

/*class expr{
    protected:
    enum class func_type { integer, expression } type;
    union{
        long int_val;
        struct{
            expr* first;
            expr* second;
        } mem_add;
    };
    expr(long input_val) : int_val(input_val), type(func_type::integer) {}
    expr(expr* f_input, expr* s_input) : mem_add{ .first = f_input, .second = s_input }, type(func_type::expression) {}
    public:
    //virtual expr* optimize() = 0;
    friend std::ostream& operator<<(std::ostream&, expr*);
    virtual std::ostream& print(std::ostream&) const = 0;
    //virtual void operator<< () const = 0;
    //virtual expr* eval_at() = 0;
    //virtual expr* derivative() = 0;
    virtual ~expr() {}
};*/

class expr{
    public:
    friend std::ostream& operator<<(std::ostream&, expr*);
    virtual std::ostream& print(std::ostream&) const = 0;
    virtual double eval_at(long) const = 0;
    //virtual long derivative(long) const = 0;
    virtual ~expr() {}
};

std::ostream& operator<<(std::ostream&, expr*); // 출력 함수 여기서 쓰기

/*class int_var : public expr{
    long int_val;
    public:
    int_var(long val) : int_val(val) {}
    
};*/

class int_literal : public expr {
    long int_val;
    public: // 내부 출력 함수 만들기
    int_literal(long e): int_val(e) {}
    double eval_at(long x) const override { return this -> int_val; };
    //long derivative(long x) const override { return 0; }
    std::ostream& print(std::ostream& out) const { out << this -> int_val; return out; };
};

class monomial : public expr{
    long exp;
    public:
    monomial(long e) : exp(e) {}
    double eval_at(long x) const override { return pow(x, this -> exp); };
    std::ostream& print(std::ostream& out) const;
};

class exp_var : public expr{
    protected:
    expr* first;
    expr* second;
    public:
    exp_var(expr* first, expr* second) : first(first), second(second) {}
    ~exp_var() { delete first; delete second; }
    virtual std::ostream& print(std::ostream&) const = 0;
};

class addition : public exp_var{
    public:
    addition(expr* const f_input, expr* const s_input) : exp_var(f_input, s_input) {}
    double eval_at(long) const override;
    std::ostream& print(std::ostream&) const override;
};

class multiplication : public exp_var{
    public:
    multiplication(expr* const f_input, expr* const s_input) : exp_var(f_input, s_input) {}
    double eval_at(long) const override;
    std::ostream& print(std::ostream&) const override;
};

class division : public exp_var{
    public:
    division(expr* const f_input, expr* const s_input) : exp_var(f_input, s_input) {}
    double eval_at(long) const override;
    std::ostream& print(std::ostream&) const override;
};

#endif