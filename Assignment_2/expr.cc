#include "expr.h"
#include <utility>

using namespace std;

ostream& operator<<(ostream& out, expr* e){
    e -> print(out);
    return out;
}

std::ostream& monomial::print(std::ostream& out) const{
    if(this -> exp >= 1){
        out << "x";
        if(this -> exp > 1)
            out << this -> exp;
    }
    else if(this -> exp == 0)
        out << "1";
    else{
        out << "1 / " << "x";
        if(this -> exp != -1)
            out << abs(this -> exp);
    }
    return out;
}

exp_var::exp_var(exp_var const& other) : expr(other.type), first(other.first->copy()), second(other.second->copy()) {}

ostream& addition::print(ostream& out) const{
    // addition* left__add = dynamic_cast<addition*>(this -> left); > compiler checks what object is pointing to.
    if(this -> first -> type_check() == expr::func_type::addition)
        out << "(";
    this -> first -> print(out);
    if(this -> first -> type_check() == expr::func_type::addition)
        out << ")";
    out << " + ";
    if(this -> second -> type_check() == expr::func_type::addition)
        out << "(";
    this -> second -> print(out);
    if(this -> second -> type_check() == expr::func_type::addition)
        out << ")";
    return out;
}

ostream& multiplication::print(ostream& out) const{
    if(this -> first -> type_check() == expr::func_type::addition)
        out << "(";
    this -> first -> print(out);
    if(this -> first -> type_check() == expr::func_type::addition)
        out << ")";
    out << " * ";
    if(this -> second -> type_check() == expr::func_type::addition)
        out << "(";
    this -> second -> print(out);
    if(this -> second -> type_check() == expr::func_type::addition)
        out << ")";
    return out;
}

ostream& division::print(ostream& out) const{
    if(this -> first -> type_check() == expr::func_type::addition)
        out << "(";
    this -> first -> print(out);
    if(this -> first -> type_check() == expr::func_type::addition)
        out << ")";
    out << " / ";
    if(this -> second -> type_check() == expr::func_type::addition)
        out << "(";
    this -> second -> print(out);
    if(this -> second -> type_check() == expr::func_type::addition)
        out << ")";
    return out;
}

double addition::eval_at(long x) const{
    return this -> first -> eval_at(x) + this -> second -> eval_at(x);
}

double multiplication::eval_at(long x) const{
    return this -> first -> eval_at(x) * this -> second -> eval_at(x);
}

double division::eval_at(long x) const{
    return this -> first -> eval_at(x) / this -> second -> eval_at(x);
}

expr* addition::copy() const{
    return new addition(this -> first -> copy(), this -> second -> copy());
}

expr* multiplication::copy() const{
    return new multiplication(this -> first -> copy(), this -> second -> copy());
}

expr* division::copy() const{
    return new division(this -> first -> copy(), this -> second -> copy());
}

expr* monomial::derivative() const{
    if(this -> exp != 1)
        return new multiplication(new int_literal(this -> exp), new monomial(this -> exp - 1));
    else
        return new int_literal(1);
}

expr* addition::derivative() const{
    if(this -> first -> type_check() == expr::func_type::int_literal && this -> first -> value() == 0)
        return this -> second -> derivative();
    if(this -> first -> type_check() == expr::func_type::int_literal && this -> second -> value() == 0)
        return this -> first -> derivative();
    return new addition(this -> first -> derivative(), this -> second -> derivative());
}

expr* multiplication::derivative() const{
    if(this -> first -> type_check() == expr::func_type::int_literal)
        return new multiplication(this -> first -> copy(), this -> second -> derivative());
    if(this -> first -> type_check() == expr::func_type::int_literal)
        return new multiplication(this -> second -> copy(), this -> first -> derivative());
    return new addition(new multiplication(this -> first -> derivative(), this -> second -> copy()), new multiplication(this -> first -> copy(), this -> second-> derivative()));
}

expr* division::derivative() const{
    if(this -> first -> type_check() == expr::func_type::int_literal)
        return new division(new multiplication(new multiplication(new int_literal(-1), this -> first -> copy()), this -> second -> derivative()), new multiplication(this -> second -> copy(), this -> second -> copy()));
    return new division(new addition(new multiplication(this -> first -> derivative(), this -> second -> copy()), new multiplication(new int_literal(-1), new multiplication(this -> first -> copy(), this -> second -> derivative()))), new multiplication(this -> second -> copy(), this -> second -> copy()));
}

expr* addition::optimize(){
    if(this -> first -> type_check() == expr::func_type::int_literal){
        if(this -> second -> type_check() == expr::func_type::int_literal)
            return new int_literal( this -> first -> value() + this -> second -> value() );
        if(this -> first -> value() == 0)
            return this -> second -> copy();
    }
    if(this -> second -> type_check() == expr::func_type::int_literal){
        if(this -> second -> value() == 0)
            return this -> first -> copy();
    }
    if(this -> first -> type_check() == expr::func_type::monomial && this -> second -> type_check() == expr::func_type::monomial){
        if(this -> first -> value() == this -> second -> value())
            return new multiplication( new int_literal(2), this -> first -> copy() );
    }
    return new addition( this -> first -> optimize(), this -> second -> optimize() );
}

expr* multiplication::optimize(){
    if(this -> first -> type_check() == expr::func_type::int_literal){
        if(this -> first -> value() == 0)
            return new int_literal(0);
        if(this -> second -> type_check() == expr::func_type::int_literal){
            cout << "Target" << endl;
            return new int_literal( this -> first -> value() * this -> second -> value() );
        }
        if(this -> first -> value() == 1)
            return this -> second -> copy();
    }
    if(this -> second -> type_check() == expr::func_type::int_literal){
        if(this -> second -> value() == 0)
            return new int_literal(0);
        if(this -> second -> value() == 1)
            return this -> first -> copy();
    }
    if(this -> first -> type_check() == expr::func_type::monomial && this -> second -> type_check() == expr::func_type::monomial){
        return new monomial( this -> first -> value() + this -> second -> value() );
    }

    return new multiplication( this -> first -> optimize(), this -> second -> optimize() );
}

expr* division::optimize(){
    if(this -> first -> type_check() == expr::func_type::int_literal){
        if(this -> first -> value() == 0)
            return new int_literal(0);
        else if(this -> second -> type_check() == expr::func_type::int_literal)
            return new int_literal( this -> first -> value() / this -> second -> value() );
    }
    if(this -> first -> type_check() == expr::func_type::monomial && this -> second -> type_check() == expr::func_type::monomial){
        if(this -> first -> value() > this -> second -> value())
            return new monomial( this -> first -> value() - this -> second -> value() );
        else if(this -> first -> value() < this -> second -> value())
            return new division( new int_literal(1), new monomial( abs(this -> first -> value() - this -> second -> value()) ) );
        else
            return new int_literal(1);
    }

    return new division( this -> first -> optimize(), this -> second -> optimize() );
}