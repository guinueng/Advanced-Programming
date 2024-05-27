#include "expr.h"

using namespace std;

ostream& operator<<(ostream& out, expr* e){
    e -> print(out);
    return out;
}

std::ostream& monomial::print(std::ostream& out) const{
    out << "x";
    if(this -> exp > 1)
        out << this -> exp;
    return out;
}

ostream& addition::print(ostream& out) const{
    this -> first -> print(out);
    out << " + ";
    this -> second -> print(out);
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