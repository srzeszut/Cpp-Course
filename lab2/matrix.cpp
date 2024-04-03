#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix(){
        for(size_t i=0;i<size();i++){
            for(size_t j=0;j<size();j++){
                this->matrix_[i][j]=0;
            }
        }
    }
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& other_matrix){
    for(size_t i=0;i<size();i++){
        for(size_t j=0;j<size();j++){
            this->matrix_[i][j]=other_matrix.get(i,j);
        }
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix[size_][size_]){
        for(size_t i=0;i<size();i++){
            for(size_t j=0;j<size();j++){
                this->matrix_[i][j]=matrix[i][j];
            }
        }
    }

MatrixElement TwoDimensionMatrix::get(size_t x, size_t y) const {
    return this->matrix_[x][y];
}
TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix& other_matrix){
    for(size_t i=0;i<TwoDimensionMatrix::size();i++){
        for(size_t j=0;j<TwoDimensionMatrix::size();j++){
            matrix_[i][j]=other_matrix.get(i,j);
        }
    }
    return *this;
}
std::ostream& operator <<(std::ostream& os,const TwoDimensionMatrix& matrix){
    os<<"{ "<<matrix.get(0,0)<<", "<<matrix.get(0,1)<<" }\n";
    os<<"{ "<<matrix.get(1,0)<<", "<<matrix.get(1,1)<<" }\n";
    return os;
}
std::istream& operator >>(std::istream& is,TwoDimensionMatrix& matrix){

    is >> matrix.matrix_[0][0] >> matrix.matrix_[0][1];
    is>>matrix.matrix_[1][0] >> matrix.matrix_[1][1];
    return is;
}
TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2){
    TwoDimensionMatrix output;
    for(size_t i=0;i<TwoDimensionMatrix::size();i++){
        for(size_t j=0;j<TwoDimensionMatrix::size();j++){
            output.matrix_[i][j]=matrix1.get(i,j)+matrix2.get(i,j);
        }
    }
    return output;
}
MatrixElement* TwoDimensionMatrix::operator[](size_t i) {
    return matrix_[i];
}
const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
    return matrix_[i];
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &other_matrix) const {
    TwoDimensionMatrix output;
    for(size_t i=0;i<TwoDimensionMatrix::size();i++){
        for(size_t j=0;j<TwoDimensionMatrix::size();j++){
            output.matrix_[i][j]=this->get(i,j) && other_matrix.get(i,j);
        }
    }
    return output;

}
TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(size_t i=0;i<TwoDimensionMatrix::size();i++){
        for(size_t j=0;j<TwoDimensionMatrix::size();j++){
            matrix_[i][j]*=number;
        }
    }
    return *this;
}

