#ifndef EXPR_H
#define EXPR_H

#include <iostream>
#include <math.h>

class expr{
    protected:
    enum class func_type { int_literal, monomial, addition, multiplication, division } type;
    expr(func_type t) : type(t) {}
    public:
    friend std::ostream& operator<<(std::ostream&, expr*);
    virtual std::ostream& print(std::ostream&) const = 0;
    virtual double eval_at(long) const = 0;
    virtual expr* derivative() const = 0;
    virtual expr* copy() const = 0;
    virtual expr* optimize() = 0;
    virtual long value() const { return 0; };
    func_type type_check() { return type; };
    virtual ~expr() {} // virtual destructor
};

std::ostream& operator<<(std::ostream&, expr*);

class int_literal : public expr {
    long int_val;
    public:
    int_literal(long e): expr(expr::func_type::int_literal), int_val(e) {} // constructor
    double eval_at(long x) const override { return this -> int_val; };
    expr* derivative() const override { return new int_literal(0); };
    expr* copy() const override { return new int_literal(this -> int_val); };
    expr* optimize() override { return this -> copy(); };
    long value() const { return this -> int_val; };
    std::ostream& print(std::ostream& out) const { out << this -> int_val; return out; };
};

class monomial : public expr{
    long exp;
    public:
    monomial(long e) : expr(expr::func_type::monomial), exp(e) {}
    double eval_at(long x) const override { return pow(x, this -> exp); };
    expr* derivative() const override;
    expr* copy() const override { return new monomial(this -> exp); };
    expr* optimize() override { return this -> copy(); };
    long value() const { return this -> exp; };
    std::ostream& print(std::ostream& out) const;
};

class exp_var : public expr{
    protected:
    expr* first;
    expr* second;
    public:
    exp_var(expr* const first, expr* const second, expr::func_type t) : expr(t), first(first), second(second) {} // binary constructor
    exp_var(exp_var const& other); // copy constructor
    virtual std::ostream& print(std::ostream&) const = 0;
    ~exp_var() { delete first; delete second; } // destructor
};

class addition : public exp_var{
    public:
    addition(expr* const f_input, expr* const s_input) : exp_var(f_input, s_input, expr::func_type::addition) {}
    double eval_at(long) const override;
    expr* derivative() const override;
    expr* copy() const override;
    expr* optimize() override;
    std::ostream& print(std::ostream&) const override;
};

class multiplication : public exp_var{
    public:
    multiplication(expr* const f_input, expr* const s_input) : exp_var(f_input, s_input, expr::func_type::multiplication) {}
    double eval_at(long) const override;
    expr* derivative() const override;
    expr* copy() const override;
    expr* optimize() override;
    std::ostream& print(std::ostream&) const override;
};

class division : public exp_var{
    public:
    division(expr* const f_input, expr* const s_input) : exp_var(f_input, s_input, expr::func_type::division) {}
    double eval_at(long) const override;
    expr* derivative() const override;
    expr* copy() const override;
    expr* optimize() override;
    std::ostream& print(std::ostream&) const override;
};

#endif