#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Abstract base class Shape
class Shape
{
public:
    virtual double getArea() const = 0;
    virtual bool compareArea(const Shape *other) const = 0;
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return M_PI * radius * radius; }
    bool compareArea(const Shape *other) const override
    {
        const Circle *otherCircle = dynamic_cast<const Circle *>(other);
        if (!otherCircle)
            return false;
        return getArea() < otherCircle->getArea();
    }
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    bool compareArea(const Shape *other) const override
    {
        const Rectangle *otherRect = dynamic_cast<const Rectangle *>(other);
        if (!otherRect)
            return false;
        return getArea() < otherRect->getArea();
    }
};

// Derived class Triangle
class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() const override { return 0.5 * base * height; }
    bool compareArea(const Shape *other) const override
    {
        const Triangle *otherTri = dynamic_cast<const Triangle *>(other);
        if (!otherTri)
            return false;
        return getArea() < otherTri->getArea();
    }
};

// Interface Sortable
class Sortable
{
public:
    virtual bool compare(const Shape *a, const Shape *b) const = 0;
    virtual ~Sortable() {}
};

// Implementation of Sortable for comparing shapes by area
class AreaSortable : public Sortable
{
public:
    bool compare(const Shape *a, const Shape *b) const override
    {
        return a->compareArea(b);
    }
};

int main()
{
    // Create a vector of Shape pointers
    std::vector<Shape *> shapes;

    // Add shapes to the vector
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4));

    // Create a sorting object
    AreaSortable areaSorter;

    // Sort the shapes based on area
    sort(shapes.begin(), shapes.end(), [&areaSorter](const Shape *a, const Shape *b)
              { return areaSorter.compare(a, b); });

    // Display information of all shapes after sorting
    cout << "Shapes after sorting by area:" << endl;
    for (const Shape *shape : shapes)
    {
        cout << "Area: " << shape->getArea() << endl;
    }

    // Free memory allocated to shape objects
    for (Shape *shape : shapes)
    {
        delete shape;
    }

    return 0;
}
