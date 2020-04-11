/*About the program: explains the variablescope and modifiers type. 
Author:l. keerthi
filename:scope.cpp
date:10-04-2020
*/

#include <iostream>
using namespace std;
// Global variables
short unsigned int i;
long unsigned int k; 

extern int e=2 ;
/*
function name:storageclass
input parameter:0
return type:void
*/

int storageclass ()
{
	static int s;
	register int r;
	r= e ;
	s= s+r*i ;
	cout<<"storage class:"<< s << endl ;
	
}

/*
function name:fLocal
input parameter:0
return type:void
*/

int fLocal ()
{
	auto int a ;
	cout<< "enter value:" ;
	cin>> a ;
	cout<< "local variable: "<< a << endl ;
}

/*
function name:modifier
input parameter:0
return type:void
*/

int modifier( )
{
	short int j;  
    long int l;
        
	cout<< "enter short int value  : " << endl ;
	cin >> j ;
	cout << "enter long int value : " << endl ;
	cin >> l ;
	
	k = l;
    i = j;
    
	cout << "short unsigned int:" <<i << " " << " short int: " << j << endl;
    cout << "long unsigned int: " << k << " " << "long int:" << l << endl;
    
}


int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if (argc == 2)
    {
        cout << "\\usage of the program:\\" << endl << "variable scope & modifier type " << endl;
        cout << " "<< endl ;
    }
    
    else
    {
    // calling functions 
	modifier() ; 
    fLocal () ;
    storageclass() ;
    storageclass() ;
    cout<< "global variables:" << i << " " << k << " " << " " << e << endl ;
	}
}
