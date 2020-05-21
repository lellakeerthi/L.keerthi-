/*Description: To find letter combinations.  
Filename:combination.cpp
Author:l.keerthi
date:09-5-2020
*/	

#include<iostream>
#include<string.h>
#include"combination.h"

using namespace std ;

int main(int argc, char* argv[])
{
	// condition for arguments to dispaly -h file
    if(argc==2)
	{  
		if (strcmp(argv[1],"-h")==0)
	    {
	        cout << "Usage of: "<< argv[0] << endl;
	    }
	    else
	    {
	    	cout<<" use '-h' for usage" ;
		}
	}
    
    else 
    {
    	// object for class combination
		combination obj ;
		string numb ;
		cout<<"enter number between 2-9 :" ;
		cin>> numb ;
		// passing inputs to the vector function mappng.
		obj.mapping(numb) ;
	}
	return 0 ;
}
