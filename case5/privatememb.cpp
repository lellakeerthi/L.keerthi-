#include <iostream>
using namespace std;
// base class
class base
{
	// private members
   	int iA , iB, iC ;
	//friend function declaration 
    friend int mul(base); 
   	// public members
   	public:
   		int display() 
		   	{
		   		// private data member 'iC' accessed in public
		   		iC= 10 ;
		   		cout <<"public:"<< iC ;
 			}	
	 
	
};
//friend function definition to access private data members
int mul(base obj)
{
	cout<<" enter values" ;
	cin>> obj.iA >> obj.iB ;
    cout<<"product = "<<obj.iA * obj.iB << endl ;
}
int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if (argc == 2)
    {
        cout << "\\usage of the program:\\" << endl << " Acessing private data members " << endl;
        cout << " using friend function and public member function"<< endl ;
    }
    
    else
    {
    	
   	base obj ;
    mul(obj);
    obj.display();
	
	}
}
