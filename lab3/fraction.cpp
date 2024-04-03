#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric>   // std::gcd

#include "fraction.h"



Fraction::Fraction( int numerator, int denominator):
        numerator_(numerator),denominator_(denominator){
    if(denominator==0){
        throw std::invalid_argument("Denominator must not be 0.");
    }

}

void Fraction::setNumerator(int numerator) {
    this->numerator_=numerator;
}
void Fraction::setDenominator(int denominator){
    if(denominator==0){
        throw std::invalid_argument("Denominator must not be 0.");
    }
    this->denominator_=denominator;
}
int Fraction::numerator()const{
    return this->numerator_;
}
int Fraction:: denominator()const{
    return this->denominator_;
}
Fraction Fraction::operator+(const Fraction &other_fraction) const{
    Fraction ans;
    ans.numerator_=(numerator()*other_fraction.denominator())+(other_fraction.numerator()*denominator());
    ans.denominator_=denominator()*other_fraction.denominator();
    if(ans.denominator()==0){
        throw std::invalid_argument("Denominator must not be 0.");
    }
    return reduce_fraction(ans);


}
Fraction Fraction::operator*(const Fraction &other_fraction) const{
    Fraction ans;
    ans.numerator_=numerator()*other_fraction.numerator();
    ans.denominator_=denominator()*other_fraction.denominator();
    if(ans.denominator()==0){
        throw std::invalid_argument("Denominator must not be 0.");
    }
    return reduce_fraction(ans);

}
Fraction Fraction::reduce_fraction( Fraction fraction) {
    int divider = std::gcd(fraction.numerator(),fraction.denominator());
    if(fraction.denominator()==0){
        throw std::invalid_argument("Denominator must not be 0.");
    }
    return Fraction(fraction.numerator()/divider,fraction.denominator()/divider);
}