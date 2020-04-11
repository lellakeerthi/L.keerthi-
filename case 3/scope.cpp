/*About the program: explains the variablescope, modifiers type & storage classes. 
Author:l. keerthi
filename:scope.cpp
date:10-04-2020
*/

#include <iostream>
using namespace std;
// Global variables

short int sNo;  
long int lNum;

int iE = 2;
/*
function name:externclass
input parameter:0
return type:void
*/
int externclass()
{
	extern int iE;
	iE= 2 ;
}
/*
function name:storageclass
input parameter:0
return type:void
*/

int storageclass ()
{
	static int iS;
	register int iR;

	iR= iE ;
	iS= iS+iR*sNo ;
	cout<<"storage class:"<< iS << endl ;
	
}

/*
function name:fLocal
input parameter:0
return type:void
*/

int fLocal ()
{
	auto int iA ;
	cout<< "enter value for local variable:" ;
	cin>> iA ;
	cout<< "local variable: "<< iA << endl ;
}

/*
function name:modifier
input parameter:0
return type:void
*/

int modifier( )
{
	short unsigned int suNo;
	long unsigned int luNum ;
        
	cout<< "enter short unsigned int value  : " << endl ;
	cin >>  suNo ;
	cout << "enter long unsigned int value : " << endl ;
	cin >> luNum ;
	
	sNo = suNo;
    lNum = luNum;
    
	cout << "short unsigned int:" <<suNo << " " << " short int: " << sNo << endl;
    cout << "long unsigned int: " << luNum << " " << "long int:" << lNum << endl;
    
}


int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if (argc == 2)
    {
        cout << "\\usage of the program:\\" << endl << "variable scope, modifier type & storage classes" << endl;
        cout << " inputs are given for different modifier types and storage classes "<< endl ;
    }
    
    else
    {
    // calling functions 
	modifier() ; 
    fLocal () ;
    storageclass() ;
    storageclass() ;
    cout<< "global variables:" << lNum << " " << sNo << " " << " " << iE << endl ;
	}
}
