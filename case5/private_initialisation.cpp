#include<iostream>
#include<string.h>
using namespace std;
class Rectangle
{
	//Private member variables
	int ilength,ibreadth,ilen,ibre;
	public:
		Rectangle()
		{
		ilen = 20 ;
		ibre = 10 ;
		}
		
		Rectangle(int il, int ib)
		{
			ilength=il ;
			ibreadth=ib ;
			cout<<"ilength: "<<ilength<<endl;
			cout<<"ibreadth:"<<ibreadth<<endl;
			cout<<"Area of rectangle :"<<il*ib<<endl;
		}
	int Var()
	{
		cout << "length:" << ilen << endl ;
		cout << "breadth:" << ibre << endl ;
	}		
};

int main(int argc,char * argv[])
{
	
	if((argc==2) && (strcmp(argv[1],"-h")==0))	 				
	{
    	cout<<" usage of"<< argv[0] << endl;
        cout<< " initilization of private variables" << endl ;
	}
    
    else
    {
    	//Creating object to class A
    	Rectangle ob;
    	ob.Var() ;
	Rectangle ob1(4, 5);
		
	}
}

