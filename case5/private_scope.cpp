/*PROGRAM:Initialisation of private variable using scope resolution 
filename:private_scope.cpp
date:15-04-2020
Author:l.keerthi
*/
#include<iostream>
#include<string.h>
using namespace std;
class Rectangle
{ 
	int iLength;
	int ibreadth;
	static int iLen;
	static int iBre;
public:
	/*function name:calculatearea
	return type:void
	input parameter:int ,int
	*/
    	void calculatearea( int iLength, int ibreadth )
    	{
                  
    		int Area;
		Area = ( iLength * ibreadth );
        	cout<< "Area of rectangle:" << Area << endl;
    	}
	/*function name:calculateperimeter
	return type:void
	input parameter:int ,int
	*/
	void calculateperimeter()
	{
		int iPeri;
		iPeri = 2*( iLen + iBre );
		cout<< "perimeter of rectangle:" << iPeri << endl;
	}
};
//private data member initialization using scope resolution .
    	int Rectangle::iLen = 90;
     int Rectangle::iBre = 80;
     
int main( int argc, char *argv[] )
{
	
    if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
		cout << " usage of " << argv[0] << endl;
		cout<< " private member initilization using scope resolution" << endl ;
	}
	else
	{
    	Rectangle rect;
		rect.calculatearea(8,9);
		rect.calculateperimeter();
        return 0;
	}
}
