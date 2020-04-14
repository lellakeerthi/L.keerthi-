/*About the program: explains the variablescope, modifiers type & storage classes. 
Author:l. keerthi
filename:scope.cpp
date:15-04-2020
*/

#include <iostream>
using namespace std;

// Global variables
short int sNo;  
long int lNum;

int iE =2;
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
function name:storageclass
input parameter:0
return type:int
*/

int storageclass ()
{
	static int iS;
	register int iR;

	iR= iE ;
	iS= iS+iR*sNo ;
	cout<<"static class:"<< iS << endl ;
	
}

/*
function name:iLocal
input parameter:0
return type:int
*/

int iLocal ()
{
	auto int iA ;
	cout<< "enter value for local variable:" ;
	cin>> iA ;
	cout<< "local variable: "<< iA << endl ;
}

/*
function name:modifier
input parameter:0
return type:int
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
    
	cout << "short unsigned int:" <<suNo << " " << " short int:" << sNo << endl;
    cout << "long unsigned int:" << luNum << " " << "long int:" << lNum << endl;
    
}


int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if (argc == 2)
    {
        cout << " usage of scope.exe" <<endl;           
		cout << argv[0] << endl << "inputs:int" << endl ; 
    }
    
    else
    {
    // calling functions 
	modifier() ; 
    iLocal () ;
    storageclass() ;
    storageclass() ;
    cout<< "global variables:" << lNum << " " << sNo << " " << " " << iE << endl ;
	}
}
