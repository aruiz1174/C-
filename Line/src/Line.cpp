//============================================================================
// Name        : Line.cpp
// Author      : Anibal Ruiz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Line.h"
#include "Point.h"
using namespace std;

/**
 *One value constructor that takes care of the case when no points are passed in
 */
Line::Line()
{
	first = Point(0,0);
	second = Point(1,0);
}

/**
 * constructor when only one point is passed, theother is set to (0,0)
 */
Line::Line(Point p2PassedIn)
{
	first = Point(0,0);
	second = p2PassedIn;

}

/**
 * Constructor when both points are passed.
 * if they are equal, set one of them to (0,0)
 */
Line::Line(Point p1, Point p2)
{
	if(p1 == p2)
	{
		first = Point(0,0);
		second = p2;
		//cout << "EQUAL"<< endl;
	}
	else
	{
		//cout << "ERROR"<< endl;
		first = p1;
		second = p2;
		//cout << first << " " << second << endl;
	}
}

/**
 * Copy Constructor
 */
Line::Line(const Line& myLine)
{
	first = myLine.get_first();
	second = myLine.get_second();
}

/**
 * returns the slope of the line as a double. Remember,
 * slope is rise over run, or change in y between the two
 * points over the change in x between the two points.
 */
double Line::slope() const
{
	//cout << first.get_x() << " " << second.get_x() << endl;
	if(second.get_x() == first.get_x())
	{
		//cout << "HEY I AM IN" << endl;
		return INT_MAX;
	}
	return (second.get_y() - first.get_y()) / (second.get_x() - first.get_x());
	//return slope;
}

/**
 * add a fixed pair of numbers (x,y) to the points of a given line.
 */
void Line::translate(double x, double y)
{
	first.translate(x, y);
	second.translate(x, y);
}

/**
 * reflect x over the x axis
 */
void Line::reflect_x()
{
	first.reflect_x();
	second.reflect_x();
}

/**
 * reflect y over the y axis
 */
void Line::reflect_y()
{
	first.reflect_y();
	second.reflect_y();
}

/**
 * You can rotate a line, about the origin counter clockwise,
 *  by rotating both of it’s points a given amount in radians r.
 */
void Line::rotate(double number)
{
	first.rotate(number);
	second.rotate(number);
}

/**
 * Assignment operator— Allows you to set two Lines equal to each other.
 */
void Line::operator =(const Line& passedIn)
{
	first = passedIn.get_first();
	second = passedIn.get_second();
}

/**
 * returns the y-intercept of the Line. This can be calculated
 * by using the formula. All you need to  calculate the y-intercept
 * is the y-value when x is 0.
 */
double Line::y_intercept() const
{
	//find slope
	double m = slope();

	//get x1 and y1
	double x = first.get_x();
	double y = first.get_y();

	//find the b for y = mx + b
	double b = y - m * x;

	//y_intercept is when x = 0, use y=mx + b
	x = 0.0;
	y = m * x + b;


	return y;
}

/**
 * Checks if two lines are equal. Two lines are equal if their Slope and Y Intercept
 *  are equal (i.e. the points of the two lines may not be equal but as long as the
 *   slope and y-intercept are equal, the lines are equal.
 */
bool operator ==(const Line& first, const Line& second)
{
	return ( (first.slope() == second.slope()) && (first.y_intercept() == second.y_intercept()));
}

/**
 * Friend function to Overload cin— this is the same as cinning two points.
 */
std::istream& operator >>(std::istream& ins, Line& target)
{

	//input first Point
	Point f;
	cin >> f;
	//target.setfirst(f);
	//cout << target.get_first() << endl;

	//input second input
	Point d;
	cin >> d;
	//target.setsecond(d);

	//if both POints are equal, one has to be (0,0)
	if(f == d)
	{
		target.setfirst(Point(0,0));
		target.setsecond(d);
	}
	else
	{
		target.setfirst(f);
		target.setsecond(d);
	}
	//cout << target.get_second() << endl;

	return ins;
}


/**
 * Friend function to Overload cout
 */
std::ostream& operator <<(std::ostream& outs, const Line& source)
{
	//to compare both and see if the slope is infinite
	double x = source.get_first().get_x();
	double y = source.get_first().get_y();

	//slope
	double m = source.slope();

	//b to complete y = mx + b
	double b = y - m * x;

	//normal slope
	if((m != 0) && (source.get_first().get_x() != source.get_second().get_x()))
	{
		outs << "y = " << m <<"x + " << b;
	}

	//infinite slope
	else if(source.get_first().get_x() == source.get_second().get_x())
	{
		outs << "x = " << x;
	}

	//slope = 0
	else if(m == 0)
	{
		outs << "y = " << y;
	}

	return outs;
}


