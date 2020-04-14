/*About the program: explains the variablescope, modifiers type & storage classes. 
Author:l. keerthi
filename:scope.cpp
date:15-04-2020
*/

#include <iostream>
using namespace std;

// Global variables
short int sNo=1;  
long int lNum=2;

int iE =2;
// class for mutable
class Mute 
{ 
	public: 
		int x; 
		mutable int y; 
		
		Mute() 
  		{ 
  			x = 4; 
  			y = 10; 
  		}	 
}; 

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
function name:staticClass
input parameter:0
return type:void
*/

void staticClass() 
{ 
    
    for (int i = 1; i < 5; i++) { 
  
        // Declaring the static variable  
        static int Stat = 5; 
  
        // Declare a non-static variable  
        int Var = 10; 
  		
		Stat++; 
        Var++; 
 
        cout << "static increment:" << Stat << endl ;  
        cout << "non static increment:"<< Var << endl ;
    } 
  
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
    if (argc == 2)
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
		staticClass() ; 
    
	}
}
