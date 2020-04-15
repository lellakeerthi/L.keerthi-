/*PROGRAM: describes access specifiers
filename:acess_specifiers.cpp
date:14-04-2020
Author:l.keerthi*/

#include<iostream>
#include<string.h>

using namespace std;

class base
{   
	//Private members
	int iPrivate ;
	
	public: 
	//Public members
	int iPublic ;
	
	protected:
	//Protected members
	int iProtected ;
};

// class derived as public
class derive : public base
{
	public:
	void display()
	{
	
		cout<<"public Acess"<<endl;
		
		//Cannot access private members

		iPublic = 20;
		cout <<" public member variable "<< iPublic << endl;
		iProtected = 30;
 		cout <<" protected member variable "<< iProtected << endl;
    }
};

//class derived as protected
class derive2 : protected base
{
	public:
	void display()
	{
		cout << "Protected Access" << endl;
		//Cannot access private members
		
		iPublic = 50;
		cout << "public member variable "<< iPublic << endl;
		iProtected = 60;
 		cout << "protected member variable "<< iProtected << endl;
    }
	
};
class derive3:private base
{
	public:
	void display()
	{
		cout << "Private Access" << endl;
		//Cannot access private member

		iPublic = 80;
		cout << "public member variable "<< iPublic << endl;
		iProtected = 90;
 		cout<< "protected member variable "<< iProtected << endl;
    }
};
int main(int argc,char* argv[])
{   
	 if(argc==2)
    {
    	//condition for comparing the input string with "-h"
	    if(strcmp(argv[1],"-h")==0)	 				
	    {
            cout << "usage of" << argv[0] << endl;
	    }
    }
    else
    {
    	//Creating objects
		derive ob;
		derive2 ob1;
		derive3 ob2;
		
		//Calling display functions  
		ob.display();	
		ob1.display();
		ob2.display();
	}
}


