/*Program: Acess Specifiers.
filename:Acess Specifiers.cpp
date:10-04-2020
Author:L. keerthi
*/
#include<iostream>
using namespace std ;
// base class
class base
 {
	// Private members
	int iAdd ;
	
	public:
		// Public members
		int  add (int iNo1, int iNo2)
		{
			iAdd= iNo1+ iNo2 ;
			cout<< "Add: " << iAdd <<endl  ;
		}
	protected:
		//Protected members
		int iSub ;
 };
 // derived class
 class derived : private base
 {
 	public:
 		// Public members
 
 		int sub(int iNum1, int iNum2)
		{
 			iSub= iNum1 - iNum2 ;
			cout<< "sub: " << iSub <<endl  ;
		}
 };
 
int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if (argc == 2)
    {
        cout << "\\usage of the program:\\" << endl << " Acess Specifiers " << endl;
    }
    
    else
    {
    // creating object for classes
 	base obj ;
 	derived obj1 ;
	obj.add (3.2, 8.5) ;
 	obj1.sub (15.2, 6.3) ;
 	}
}
