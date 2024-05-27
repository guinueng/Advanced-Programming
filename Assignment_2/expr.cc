#include "expr.h"

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
        out << "1 / " << "x" << this -> exp;
    }
    return out;
}

ostream& addition::print(ostream& out) const{
    out << "(";
    this -> first -> print(out);
    out << " + ";
    this -> second -> print(out);
    out << ")";
    return out;
}

ostream& multiplication::print(ostream& out) const{
    this -> first -> print(out);
    out << " * ";
    this -> second -> print(out);
    return out;
}

ostream& division::print(ostream& out) const{
    this -> first -> print(out);
    out << " / ";
    this -> second -> print(out);
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
    return new addition(this -> first, this -> second);
}

expr* multiplication::copy() const{
    return new multiplication(this -> first, this -> second);
}

expr* division::copy() const{
    return new division(this -> first, this -> second);
}

expr* monomial::derivative() const{
    return new multiplication(new int_literal(this -> exp), new monomial(this -> exp - 1));
    
    if(this -> exp > 0)
        return new multiplication(new int_literal(this -> exp), new monomial(this -> exp - 1));
    else
        return new division(new int_literal(-1 * this -> exp), new monomial(-1 * (this -> exp - 1)));
}

expr* addition::derivative() const{
    return new addition(this -> first -> derivative(), this -> second -> derivative());
}

expr* multiplication::derivative() const{
    return new addition(new multiplication(this -> first -> derivative(), this -> second -> copy()), new multiplication(this -> first -> copy(), this -> second -> derivative()));
}

expr* division::derivative() const{
    return new division(new addition(new multiplication(this -> first -> derivative(), this -> second -> copy()), new multiplication(new int_literal(-1), new multiplication(this -> first -> copy(), this -> second -> derivative()))), new multiplication(this -> second -> copy(), this -> second -> copy()));
}