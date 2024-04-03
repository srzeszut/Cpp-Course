#pragma once
#include "shape.h"
#include <cmath>
#include <stdexcept>

namespace Shapes {
    class Circle
            : public Shapes::Shape {
    private:
        int xCenter_;
        int yCenter_;
        int radius_;


    public:
        Circle(int xCenter,int yCenter,int radius);
        virtual bool isIn(int x, int y) const override;
        int x() const;

        int y() const;

        int getRadius() const;
    };
}