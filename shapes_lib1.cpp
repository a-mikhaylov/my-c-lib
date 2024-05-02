#include "shapes.h"

// C API Wrapper for Shape interface
extern "C" {
    typedef struct Shape* ShapeHandle;

    ShapeHandle Shape_create_circle(double radius) {
        return reinterpret_cast<ShapeHandle>(new Circle(radius));
    }
    ShapeHandle Shape_create_square(double side) {
        return reinterpret_cast<ShapeHandle>(new Square(side));
    }

    double Shape_area(ShapeHandle handle) {
        return reinterpret_cast<Shape*>(handle)->area();
    }

    double Shape_perimeter(ShapeHandle handle) {
        return reinterpret_cast<Shape*>(handle)->perimeter();
    }

    void Shape_destroy(ShapeHandle handle) {
        delete reinterpret_cast<Shape*>(handle);
    }
}
