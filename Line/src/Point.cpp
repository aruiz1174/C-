/*
 * Point.cpp
 *
 *  Created on: Oct 29, 2021
 *      Author: Anibal Ruiz
 */
#include <string>
#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

/**
 * Copy Constructor:
 * COpy an object inside this object
 */
Point::Point(const Point &myPoint)
{
	this->x = myPoint.get_x();
	this->y = myPoint.get_y();
}

/**
 * setter for x
 * set a new value for x
 */
void Point::set_x(double x)
{
	this->x = x;
}

/**
 * setter for y
 * set a new value for y
 */
void Point::set_y(double y)
{
	this->y = y;
}

/**
 * Translating a point is equivalent to adding a fixed pair of numbers
 * (x,y) to the cartesian coordinates of the point.
 */
void Point::translate(const double x, const double y)
{
	this->x += x;
	this->y += y;
}

/**
 * Scaling a point is equivalent to multiplying both
 * coordinates of a point by some constant.
 */
void Point::scale(const double m)
{
	this->x *= m;
	this->y *= m;
}

/**
 * This reflects the point over the x-axis. If I have
 * pointA at (x,y), after reflecting over the x-axis
 * pointA will now be located at coordinates  (x,-y).
 *
 */
void Point::reflect_x()
{
	this->y *= -1;
}

/**
 * will reflect the point over the y-axis. If I have pointA
 * at (x,y) after reflecting over the y-axis pointA will
 * now be located at coordinates (-x,y)
 *
 */
void Point::reflect_y()
{
	this->x *= -1;
}

/**
 * After rotating pointA at (x,y) counterclockwise around
 * the origin by some angle r radians
 */
void Point::rotate(double number)
{
	int temp = x;
	x = x * cos(number) - y * sin(number);
	y = temp * sin(number) + y * cos(number);
}

/**
 * Overload the assignment operator (=).
 */
void Point::operator =(const Point& passedIn)
{
	this->x = passedIn.get_x();
	this->y = passedIn.get_y();
}


/**
 * Overload the comparison operator (==). This must be
 * overloaded as a NON-MEMBER. Two points are deemed
 * the same if they are at the same coordinates.
 */
bool operator ==(const Point& first, const Point& second)
{
	//return ( abs( (first.get_x() + second.get_x() ) - (first.get_y() + second.get_y()) ) < 0.0000001 );

	return ((first.get_x() == second.get_x()) && (first.get_y() == second.get_y() ));
}


/**
 * Overload cin as a FRIEND function. if I have pointA and say cin>>pointA and
 *  user types in 12.4 and 13.2 either separated by a space or enter, pointA
 *  should now be at the coordinate (12.4,13.2).
 *
 */
std::istream& operator >>(std::istream& ins, Point& target)
{
	int temp;

	cin >> temp;
	target.set_x(temp);

	cin >> temp;
	target.set_y(temp);

	return ins;
}

/**
 * Overload cout as a FRIEND function. if I have pointA at coordinate
 *  (12.4,13.2) and say cout<<pointA the following should be outputted
 *  (and nothing more!— no need for endlines etc.)
 *  (12.4,13.2)
 *
 */
std::ostream& operator <<(std::ostream& outs, const Point& source)
{
	outs << "(" << source.get_x() << "," << source.get_y() << ")";

	return outs;
}




