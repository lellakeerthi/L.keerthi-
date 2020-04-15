/*About the program: explains the variablescope, modifiers type & storage classes. 
Author:l. keerthi
filename:scope.cpp
date:15-04-2020
*/

#include <iostream>
#include<string.h>
using namespace std;

// Global variables
short int sNo=1;  
long int lNum=2;

int iE =2;
// class for mutable
class Mute 
{ 
	static int var1;
    static int var2;
	
	public:	
	static void printValues()
	{
      var1++;
      ++var2;
      cout <<"Value of A: " << var1 << endl;
      cout <<"Value of B: " << var2 << endl;
   	}
   	
 
		int x; 
		mutable int y; 
		
		Mute() 
  		{ 
  			x = 4; 
  			y = 10; 
  		}	 
}; 

int Mute :: var1 =10;
int Mute :: var2 =20;


/*
function name:externclass
input parameter:0
return type:int
*/
int externclass()
{
	extern int iE;
	iE= 2 ;
}

/*
function name:modifier
input parameter:0
return type:int
*/

int modifier( )
{
	short signed int sNo = 4 ;
	long signed int lNum = 6 ;
        
	cout << "sNo local :" << sNo << " " << " sNo global:" << ::sNo << endl;
    cout << "lNum local :" << lNum << " " << "lNum global:" << ::lNum << endl ;
    
}

int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
        	cout << " usage of " << argv[0] << endl;           
	}
	
    else
    {
    
	    const Mute ob; 
    	ob.y = 8; 
    	cout << "mutable"<< ob.y << endl << endl ; 
    	
		modifier() ;
		cout << endl ;
		//staticClass() ; 
		Mute::printValues();    
	}
}
