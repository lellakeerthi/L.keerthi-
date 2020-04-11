/*Program: checking the command line arguments.
filename:parse.cpp
date:10-04-2020
Author:L. keerthi
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

// main function using command line arguments
int main(int argc,char *argv[])  
{
int Arg;
int Int;
float Float; 

// checking arguments to display -h
if (argc==2)  
	{
		cout << " ./ program: checks for the command line arguments" << endl;           
		cout << " enter arguments in command line" << endl ;
		cout << " inputs: arg1 arg2 arg3 arg4 " << endl ; 
		cout << " filename a.out -h for usage " << endl << " "  

	}
	if (argc>2)  
	{
	//looping for arguments
	for(Arg=1; Arg<argc; Arg++)  
	{
		// converting ascii to int
		Int = atoi(argv[Arg]); 
		// converting ascii to float
		Float = atof(argv[Arg]); 
		
		if(Int == 0) 
		{
			// comparing string length for char
			if(strlen(argv[Arg])==1) 
			{
				cout<<"Char" << "\t" << argv[Arg] << "\t"<< strlen(argv[Arg]) << endl;
			}
			else
			{
				cout<<"String" << "\t"<< argv[Arg] << "\t"<< sizeof(argv[Arg]) << endl;
			}
		}
		else
		{
			if(Int == Float) 
			cout<<"Int"<< "\t" << Int << "\t" << sizeof(Int) << endl;
			
			else
			cout<< "Float" << "\t" << Float << "\t" << sizeof(Float) << endl;
		}
	}
	}
	else 
	{
	cout<<" no arguments are given" ;
	}
}

