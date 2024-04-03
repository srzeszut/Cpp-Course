#include "shapecomposite.h"


Shapes::ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1,std::shared_ptr<Shape> shape2,
                                       Shapes::ShapeOperation operation):
        shape1_(shape1),shape2_(shape2),operation_(operation){}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
    switch (operation_) {
        case ShapeOperation::INTERSECTION:{
            return shape1_->isIn(x,y)&&shape2_->isIn(x,y);
        }
        case ShapeOperation::SUM:{
            return shape1_->isIn(x,y)||shape2_->isIn(x,y);

        }
        case ShapeOperation::DIFFERENCE:{
            return (shape1_->isIn(x,y) && !shape2_->isIn(x,y)) or(!shape1_->isIn(x,y) && shape2_->isIn(x,y));
        }
        default:
            return false;

    }
}