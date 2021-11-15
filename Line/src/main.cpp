/*
 * main.cpp
 *
 *  Created on: Nov 4, 2021
 *      Author: anibalruiz
 */

#include <iostream>
#include <cmath>
#include "Point.h"
#include "Line.h"
using namespace std;
bool doesLineHavePoints(Line lineToCheck, Point pointA, Point pointB);
bool arePointsEqual(Point pointA, Point pointB);

const double PI=3.14159265359;
const double TOL=.0000001; //allows us to do a comparison for double value equality
const double INFI=1/.0000001;

int main()
{
	int toTest=0;
	//TEST AS YOU DEVELOP COMMENT OUT EVERYTHING BUT WHAT YOU HAVE IMPLEMENTED
	//AND UNCOMMENT AS YOU CREATE.
	//(you can look below to see what I make this variable to test given things)
	cout<<"MUST IMPLEMENT POINT CLASS AND LINE GETTERS (4a- get_first() get_second()) BEFORE TESTING \n";
	cout<<"What would you like to test? (no 1 so the numbers line up with writeup) \n";
	cout<<"2-value constructor \n";
	cout<<"3-copy constructor \n";
	cout<<"4-slope \n";
	cout<<"5-translate \n";
	cout<<"6-reflect over x-axis \n";
	cout<<"7-reflect over y-axis \n";
	cout<<"8-rotation (Note: depends on slope)\n";
	cout<<"9-assignment operator \n";
	cout<<"10-Operator == (and y-intercept, this script cannot test y-intercept directly. Why?) \n";
	cout<<"11-cin overload \n";
	cout<<"12-cout overload \n";
	cin>>toTest;

	Point a(0,0);
	Point b(1,0);
	Point c(1,1);
	Point d(-1,-1);
	Point e(3.2,2.3);
	Point f(-9.2, 23);

	Line fL;
	Line sL(e); //Line from (0,0) to (3.2, 2.3)
	Line tL(d,c); //Line from (-1,-1) to (1,1)
	Line l4(f,f); //Line from (0,0) to (-9.2, 23)
	Line l9(e,f); //Line from (3.2,2.3) to (-9.2,23)
	Line lInf(Point(-99,9), Point(-99,100)); //should have an infinite slope



	if(toTest==2)
	{

		cout<<"**Line Value Constructor Test: ";
		if(doesLineHavePoints(fL, Point(0,0), Point(1,0)) &&
				doesLineHavePoints(sL, Point(3.2,2.3), Point(0,0)) &&
				doesLineHavePoints(tL, Point(-1,-1), Point(1,1)) &&
				doesLineHavePoints(l4, Point(0,0), Point(-9.2, 23)))
		{
			cout<<" Line Value Constructor Works\n" <<endl;
		}
		else
		{
			cout<<" Line Value Constructor Failed\n"<<endl;
		}


	}
	if(toTest==3)
	{
		Line l5(l4); //l5 should be a copy of l4
		Line l6= sL; //l6 should be a copy of l5
		cout<<"\n**Line Copy Constructor Test: ";
		if(doesLineHavePoints(l5,l4.get_first(),l4.get_second()) &&
				doesLineHavePoints(l6,sL.get_first(),sL.get_second()))
		{
			cout<<" Copy Constructor Works\n"<<endl;
		}
		else
		{
			cout<<" Copy Constructor Failed\n"<<endl;
		}
	}



	if(toTest==4)
	{
		cout<<"\n**Slope Test: ";
		if(abs(fL.slope())<TOL && abs(sL.slope()-(2.3/3.2))<TOL && abs(tL.slope()-1)<TOL && lInf.slope()>INFI)
		{
			cout<<" Slope Works\n"<<endl;
		}
		else
		{
			cout<<" Slope Failed\n"<<endl;
		}
	}





	if(toTest==5)
	{
		cout<<"\n**Translation Test: ";
		l4.translate(10,20); //l4 should now be at (10,20) (0.8,43)
		sL.translate(-3,-2);//sL should now be at (-3,-2) to (0.2, 0.3)
		if(doesLineHavePoints(l4, Point(10,20), Point(0.8,43)) &&
				doesLineHavePoints(sL, Point(-3,-2), Point(0.2,0.3)))
		{
			cout<<" Translate Works\n"<<endl;
		}
		else
		{
			cout<<" Translate Failed\n"<<endl;
		}
	}

	if(toTest==6)
	{
		cout<<"\n**Reflect Over X-Axis Test: ";
		sL.reflect_x(); //sl is now (0,0) (3.2,-2.3)
		l9.reflect_x(); //l9 is (3.2,-2.3) to (-9.2,-23)
		if(doesLineHavePoints(sL,Point(0,0),Point(3.2,-2.3)) &&
				doesLineHavePoints(l9,Point(3.2,-2.3),Point(-9.2,-23)))
		{
			cout<<" Reflect Over X-axis Works\n"<<endl;
		}
		else
		{
			cout<<" Reflect Over X-Axis Failed\n"<<endl;
		}

	}
	if(toTest==7)
	{
		cout<<"\n**Reflect Over Y-Axis Test: ";
		sL.reflect_y(); //sl is now (0,0) (-3.2,2.3)
		l9.reflect_y(); //l9 is (-3.2,2.3) to (9.2,23)
		if(doesLineHavePoints(sL,Point(0,0),Point(-3.2,2.3)) &&
				doesLineHavePoints(l9,Point(-3.2,2.3),Point(9.2,23)))
		{
			cout<<" Reflect Over Y-Axis Works\n"<<endl;
		}
		else
		{
			cout<<" Reflect Over Y-Axis Failed\n"<<endl;
		}

	}

	if(toTest==8)
	{
		cout<<"\n**Rotation of Line About Origin CCW: (depends on slope)";
		//Line fL; //line on the x-axis
		//Line sL(e); //Line from (0,0) to (3.2, 2.3)
		//Line tL(d,c); //Line from (-1,-1) to (1,1)
		fL.rotate(PI/2); //fl should now be on the y-axis
		sL.rotate(PI); //sl should technically be the same line, now at (0,0) to (-3.2,2.3)
		tL.rotate(PI/4); //tl should now be on the y-axis
		lInf.rotate(PI/2); //lInf should now be on the x-axis
		if(abs(lInf.slope())<TOL && abs(fL.slope())>INFI && abs(tL.slope())>INFI && doesLineHavePoints(sL,Point(0,0),Point(-3.2,-2.3)))
		{
			cout<<" Rotation Of PI/2 (90 deg CCW) Worked\n"<<endl;
		}
		else
		{
			cout<<" Rotation Of PI/2 (90 deg CCW) Failed\n"<<endl;
		}
	}

	if(toTest==9)
	{
		cout<<"\n**Operator equals Test: ";
		fL=l9; //fl should now have points (3.2,2.3) to (-9.2,23)
		if(doesLineHavePoints(fL,Point(3.2,2.3),Point(-9.2,23)))
		{
			cout<<" Operator Equals Test Passed\n"<<endl;
		}
		else
		{
			cout<<" Operator Equals Test Failed\n"<<endl;
		}

	}



	if(toTest==10)
	{
		cout<<"\n**Operator equals equals Test:  ";


		if(Line(Point(0,0), Point(10,10))==Line(Point(1,1),Point(-10,-10)) &&
				Line(Point(-1,0),Point(0,1))==Line(Point(0,1),Point(1,2)) &&
				Line(Point(-.826,0), Point(-1.047,5.081))== Line(Point(-.826,0), Point(-1.047,5.081))&&
				!(fL==sL))
		{
			cout<<" Operator equals equals Test Passed \n"<<endl;
		}
		else
		{
			cout<<" Operator equals equals Test Failed \n"<<endl;
		}
	}

	if(toTest==11)
	{
		cout<<"\n**CIN Test: \ncin the values -10,-20,10,20 to test this with Line: (-10,-20) (10,20): ";
		Line input;
		cin>>input;
		cout<<"\n now cin the values 10,20,10,20 (2 identical points) to make sure it changes it to (0,0)(10,20): ";
		Line input2;
		cin>>input2;
		if(doesLineHavePoints(input,Point(-10,-20),Point(10,20)) &&
				doesLineHavePoints(input2, Point(0,0), Point(10,20)))
		{
			cout<<"CIN Test Passed\n"<<endl;
		}
		else
		{
			cout<<"CIN Test Failed\n"<<endl;
		}
	}


	if(toTest==12)
	{
		Line fL; //line on the x-axis
		Line sL(e); //Line from (0,0) to (3.2, 2.3)
		Line tL(d,c); //Line from (-1,-1) to (1,1)
		Line l4(f,f); //Line from (0,0) to (-9.2, 23)
		Line l9(e,f); //Line from (3.2,2.3) to (-9.2,23)
		Line lInf(Point(-99,9), Point(-99,100)); //should have an infinite slope

		cout<<"fls points: "<<fL.get_first()<<fL.get_second();
		cout<<"\n**COUT Test: "<<endl;
		cout<<"fL line on x-axis: "<<fL<<endl;
		cout<<"horizontal line at 10: "<<Line(Point(2,10), Point(5,10))<<endl;
		cout<<"sL (0.0) to (3.2,2.3): "<<sL<<endl;
		cout<<"tL (-1,-1) to (1,1): "<<tL<<endl;
		cout<<"l4 (0,0) to (-9.2,23): "<<l4<<endl;
		cout<<"l9 (3.2,2.3) to (-9.2,23): "<<l9<<endl;
		cout<<"lInf, vertical line at -99: "<<lInf<<endl;

	}



}

bool doesLineHavePoints(Line lineToCheck, Point pointA, Point pointB)
{
	if(arePointsEqual(lineToCheck.get_first(), pointA) && arePointsEqual(lineToCheck.get_second(),pointB))
	{
		return true;
	}
	if(arePointsEqual(lineToCheck.get_first(), pointB) && arePointsEqual(lineToCheck.get_second(),pointA))
	{
		return true;
	}
	return false;
}



bool arePointsEqual(Point pointA, Point pointB)
{
	if(abs(pointA.get_x()-pointB.get_x())<TOL && abs(pointA.get_y()-pointB.get_y())<TOL)
	{
		return true;
	}
	return false;
}

