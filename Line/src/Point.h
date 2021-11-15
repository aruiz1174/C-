#ifndef POINT_H_
#define POINT_H_
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    private:
    double x;
    double y;

    public:
    Point() {x = 0.0, y = 0.0;}
    Point(double x) {this->x = x, y = 0.0;}
    Point(double x, double y) {this->x = x, this->y = y;}

    Point(const Point &myPoint); //copy constrcutor
    double get_x() const {return x;}
    double get_y() const {return y;}

    void set_x(double x);
    void set_y(double y);

    void translate(const double x, const double y);
    void scale(const double m);

    void reflect_x();
    void reflect_y();

    void rotate(double number);

    void operator =(const Point& passedIn);

    friend std::istream& operator >>(std::istream& ins, Point& target);
    friend std::ostream& operator <<(std::ostream& outs, const Point& source);

};

bool operator ==(const Point& first, const Point& second);

#endif
