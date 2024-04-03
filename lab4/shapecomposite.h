#pragma once
#include "shape.h"
#include "memory"



namespace Shapes {

    enum class ShapeOperation{
        INTERSECTION,
        SUM,
        DIFFERENCE
    };
    class ShapeComposite
            : public Shapes::Shape {
    private:
        std::shared_ptr<Shape> shape1_;
        std::shared_ptr<Shape> shape2_;
        ShapeOperation operation_;

    public:
        ShapeComposite(std::shared_ptr<Shape> shape1,std::shared_ptr<Shape> shape2,
                       Shapes::ShapeOperation operation);

        virtual bool isIn(int x, int y) const override;

    };
}