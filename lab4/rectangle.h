#pragma once
#include "shape.h"

namespace Shapes {
    class Rectangle
            : public Shapes::Shape {
    private:
        int xFrom_;
        int xTo_;
        int yFrom_;
        int yTo_;

    public:
        Rectangle(int xFrom, int yFrom, int xTo, int yTo);

        virtual bool isIn(int x, int y) const override;
        int x() const;

        int xTo() const;

        int y() const;

        int yTo() const;
    };
}