/*Program: using int*, char [].
filename:case6.cpp
date:10-04-2020
Author:L. keerthi
*/

#include<iostream>
using namespace std ;

class base
{
	// private members
	int iNo ;
	int *iPtr;
	int iOpp ;
	char cStr[20] ;
	
	public:
		// public members
		// default constructor
		base()
		{			
			cout<<"enter integer for overloading :"<< endl ;
			cin >> iOpp ;
			
		}
		// destructor
		~base()
		{
			cout<<"Destructor called" << endl ;
		}
		// operator overloading
		
		 void operator ++(int)
		{	
			iOpp++;
		}
		// read function to read inputs
		int read ()
		{
			iPtr= &iNo ;
			cout<< "enter integer " << endl  ; 
			cin >> iNo ;
			
			cout<<"enter char:"<< endl ;
			cin >> cStr ;
		}
		// display function to display outputs
		
		int display()
		{
			cout<< "character:" << cStr <<endl ;
			cout<< "Adress of iNo:"<< iPtr << endl ;
			cout<< "Data at *iPtr:"<< *iPtr << endl ;
			cout<< "Data at iNo:"<< iNo << endl ;
			cout<< "After increment:"<< iOpp << endl ; 
		}
		
} ;

int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if (argc == 2)
    {
        cout << "\\usage of the program:\\" << endl ; 
		cout << "using int* , char[] as private member variables " << endl ;
		
    
    }
    
    else
    {
    // object creation	
	base obj ;	
	// object for opperator overloading
	obj++ ;
	//functions calling
	obj.read() ;
	obj.display() ;
	}
}
