// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include <cstring>

#include "vector.h"




Vector::Vector(std::size_t capacity):
        size_(0),capacity_(capacity),data_(new Fraction[capacity]){

}
Vector::Vector(const Vector &vector) {
    size_=vector.size();
    capacity_=vector.capacity();
    data_= new Fraction[capacity()];
    for(std::size_t i=0;i<vector.size();i++){
        data_[i]=vector.data()[i];
    }
//    std::memcpy(data_,vector.data_,capacity()*sizeof(Fraction));
}
Vector::Vector(Vector &&vector):
        size_(vector.size_),capacity_(vector.capacity_),data_(vector.data_){
    vector.data_ = nullptr;
    vector.size_ = 0;
    vector.capacity_ = 0;
}

size_t Vector::size() const{
    return size_;
}

Fraction *Vector::data() const{
    return data_;
}

size_t Vector::capacity() const{
    return capacity_;
}
//kopiujacy
Vector& Vector::operator=(Vector &vector) {
    if(this!=&vector){
        delete[] data_;
        size_=vector.size();
        capacity_=vector.capacity();
        data_=new Fraction[capacity()];
        for(std::size_t i=0;i<vector.size();i++){
            data_[i]=vector.data()[i];
        }
//        std::memcpy(data_,vector.data_,capacity()*sizeof(Fraction));

    }
    return *this;

    
}
//przenoszacy
Vector& Vector::operator=(Vector &&vector) {
    if(this!=&vector){
        delete[] data_;
        data_=vector.data_;
        size_=vector.size_;
        capacity_=vector.capacity_;
        vector.data_= nullptr;
        vector.size_=0;
        vector.capacity_=0;
    }
    return *this;
}

Fraction Vector::operator[](std::size_t index) {
    if(index>=size()){
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}
const Fraction Vector::operator[](std::size_t index) const{
    if(index>=size()){
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}

void Vector::push_back(const Fraction &fraction) {
    if(size()==capacity()){
        Fraction* new_data= new Fraction[capacity_++];
        for (std::size_t i = 0; i < capacity(); i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_=new_data;

    }
    data_[size()]=fraction;
    size_++;

}
Vector::~Vector() {
    delete[] data_;
    data_= nullptr;
    capacity_=0;
    size_=0;
}