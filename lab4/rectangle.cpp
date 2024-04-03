#include "rectangle.h"


Shapes::Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo):
        xFrom_(xFrom),xTo_(xTo),yFrom_(yFrom),yTo_(yTo){}

bool Shapes::Rectangle::isIn(int x, int y) const {
    return ((x>=xFrom_&&x<=xTo())&&(y>=yFrom_&&y<=yTo()));

}
int Shapes::Rectangle::x() const {
    return xFrom_;

}
int Shapes::Rectangle::xTo() const {
    return xTo_;
}
int Shapes::Rectangle::y() const {
    return yFrom_;
}
int Shapes::Rectangle::yTo() const {
    return yTo_;
}
