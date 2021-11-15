/*
 * Line.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Anibal Ruiz
 */

#ifndef LINE_H_
#define LINE_H_

#include "Point.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Line
{

private:
	Point first;
	Point second;

public:
	Line();

	Line(Point p1PassedIn);

	Line(Point p1, Point p2);

	Line(const Line& myLine);

	Point get_first() const {return first;}
	Point get_second() const {return second;}

	void setfirst(Point p1) {first = p1;}
	void setsecond(Point p2) {second = p2;}

	double slope() const;
	void translate(double x, double y);

	void reflect_x();
	void reflect_y();

	void rotate(double number);

	void operator =(const Line& passedIn);

	double y_intercept() const;

	friend std::istream& operator >>(std::istream& ins, Line& target);
	friend std::ostream& operator <<(std::ostream& outs, const Line& source);

};

bool operator ==(const Line& first, const Line& second);


#endif /* LINE_H_ */

