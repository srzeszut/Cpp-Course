#include "circle.h"


Shapes::Circle::Circle(int xCenter, int yCenter, int radius):
        xCenter_(xCenter),yCenter_(yCenter){
    if(radius<0){
        throw std::invalid_argument("Radius cannot be negative.");
    }
    radius_=radius;
}

bool Shapes::Circle::isIn(int x, int y) const {
    double distance=std::pow(x - xCenter_, 2) + std::pow(y - yCenter_, 2);
    return distance<=std::pow(getRadius(),2);
}
int Shapes::Circle::x() const {
    return xCenter_;
}

int Shapes::Circle::y() const {
    return yCenter_;
}

int Shapes::Circle::getRadius() const {
    return radius_;
}