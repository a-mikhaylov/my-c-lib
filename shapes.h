// C++ Interface Class
//some updates


#if !defined(MY_EXPORT)
#define MY_EXPORT
#endif

typedef struct Shape* ShapeHandle;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {} //55555
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }

    double perimeter() const override {
        return 4 * side;
    }
};

//=======================================================

MY_EXPORT
ShapeHandle Shape_create_circle(double radius);
MY_EXPORT
ShapeHandle Shape_create_square(double side);
MY_EXPORT
double Shape_area(ShapeHandle handle);
MY_EXPORT
double Shape_perimeter(ShapeHandle handle);
MY_EXPORT
void Shape_destroy(ShapeHandle handle);

