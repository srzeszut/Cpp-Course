#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

#ifdef UNIMPLEMENTED_classFraction
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // UNIMPLEMENTED_classFraction

int Fraction::removedFractions_=0;

Fraction::Fraction( int numerator, int denominator, std::string fractionName):
        numerator_(numerator),denominator_(denominator),fractionName_(fractionName){
}

void Fraction::setNumerator(int numerator) {
    this->numerator_=numerator;
}
void Fraction::setDenominator(int denominator){
    this->denominator_=denominator;
}
int Fraction::getNumerator()const{
    return this->numerator_;
}
int Fraction:: getDenominator()const{
    return this->denominator_;
}
std::string Fraction::getFractionName()const {
    return fractionName_;
}
 int Fraction:: removedFractions() {
    return removedFractions_;
}

void Fraction::print() const{
    cout<<this->numerator_<<'/'<<this->denominator_<<'\n';

}
void Fraction::load(std::istream &is) {
    string input;
    getline(is, input);
    int delimiter =input.find("/");
    numerator_= std::stoi(input.substr(0,delimiter));
    cout<<numerator_<<'\n';
    denominator_= std::stoi(input.substr(delimiter+1,input.size()-1));
    cout<<denominator_<<'\n';
}
void Fraction::save(std::ostream &os) const{
    os<<this->numerator_<<'/'<<this->denominator_;

}

int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}

Fraction::~Fraction() {
    removedFractions_++;
}

