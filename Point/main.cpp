
#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

const double PI=3.14159265359;
const double TOL=.0000001; //allows us to do a comparison for double value equality
int main() {

	int toTest=0;
	//TEST AS YOU DEVELOP COMMENT OUT EVERYTHING BUT WHAT YOU HAVE IMPLEMENTED
	//AND UNCOMMENT AS YOU CREATE.
	//(you can look below to see what I make this variable to test given things)
	cout<<"MUST IMPLEMENT GETTERS BEFORE TESTING \n";
	cout<<"What would you like to test? \n";
	cout<<"1-value constructor \n";
	cout<<"2-copy constructor \n";
	cout<<"3-setters test \n";
	cout<<"4-translation test \n";
	cout<<"5-scaling test \n";
	cout<<"6-reflect over x-axis test \n";
	cout<<"7-reflect over y-axis test \n";
	cout<<"8-rotation \n";
	cout<<"9-assignment operator \n";
	cout<<"10-operator equals equals \n";
	cout<<"11-cin overload \n";
	cout<<"12-cout overload \n";
	cin>>toTest;

	Point a; // a should be at (0,0)
	Point b(5.0); //b should be at (5.0,0)
	Point c(-15.3, -32.22); //c should be at (-15.3, -32.33)


	if(toTest==1)
	{
		cout<<"**Value Constructor Test: \n";
		if(abs(a.get_x())<TOL && abs(a.get_y())<TOL &&
			abs(b.get_x()-5)<TOL && abs(b.get_y())<TOL &&
			abs(-15.3-c.get_x())<TOL && abs(-32.22-c.get_y())<TOL)
		{
			cout<<" Value Constructor Works\n" <<endl;
		}
		else
		{
			cout<<" Value Constructor Failed\n"<<endl;
		}
	}
	Point d(c);
	if(toTest==2)
	{
		cout<<"\n**Copy Constructor Test: \n";
		if(abs(d.get_x()-c.get_x())<TOL && abs(d.get_y()-c.get_y())<TOL)
		{
			cout<<" Copy Constructor Works\n"<<endl;
		}
		else
		{
			cout<<" Copy Constructor Failed\n"<<endl;
		}
	}

	if(toTest==3)
	{
		cout<<"\n**Setters Test: \n";
		a.set_x(5.3); a.set_y(-3.2);
		if(abs(a.get_x()-5.3)<TOL && abs(a.get_y()+3.2)<TOL)
		{
			cout<<" Setters Work\n"<<endl;
		}
		else
		{
			cout<<" Setters Failed\n"<<endl;
		}
	}

		if(toTest==4)
	{
		cout<<"\n**Translation Test: \n";
		a.translate(5.3,-3.2);
		if(abs(a.get_x()-5.3)<TOL && abs(a.get_y()+3.2)<TOL)
		{
			cout<<" Translate Works\n"<<endl;
		}
		else
		{
			cout<<" Translate Failed\n"<<endl;
		}
	}

	if(toTest==5)
	{
		cout<<"\n**Scale Test: \n";
		c.scale(-3);
		if(abs(c.get_x()-45.9)<TOL && (abs(c.get_y()-96.66)<TOL))
		{
			cout<<" Scale Works\n"<<endl;
		}
		else
		{
			cout<<" Scale Failed\n"<<endl;
		}

	}

	if(toTest==6)
	{
		cout<<"\n**Reflect Over X-Axis Test: ";
		c.reflect_x();
		if(abs(c.get_y()-32.22)<TOL)
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
		c.reflect_y();
		if(abs(c.get_x()-15.3)<TOL)
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
		Point e(-1,0); //e shoule be at (-1, 0)
		cout<<"\n**Rotation of Point Test: ";
		e.rotate(PI/2);
		if(abs(e.get_x())<TOL && abs(e.get_y()+1)<TOL)
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
		d=b;
		if((abs(d.get_x()-b.get_x())<TOL) && (abs(d.get_y()-b.get_y())<TOL))
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
		cout<<"\n**Operator equals equals Test: ";
		Point e(-15.3, -32.22);
		if(e==c)
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
		cout<<"\n**CIN Test: \ncin the values 10 and 20 to test this with (10,20): ";
		cin>>d;
		if(abs(d.get_x()-10)<TOL && abs(d.get_y()-20)<TOL)
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
		cout<<"**COUT Test: coutting Points a,b,c: \n";
		cout<<a;
		cout<<b;
		cout<<c;

	}

}











