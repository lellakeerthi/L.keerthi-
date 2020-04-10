/*Program: checking the command line arguments.
filename:parse.cpp
date:10-04-2020
Author:L. keerthi
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(int argc,char *argv[])  // main function using command line arguments
{
int Arg;
int Int;
float Float; 
if (argc==2) // checking arguments to display -h 
	{
		cout << " ./ program: checks for the command line arguments" << endl;           
		cout << " enter arguments in command line" << endl ;
		cout << " inputs : int "<< endl << " char" << endl << " flaot " << endl << " string" << endl ;  

	}
	if (argc>2)  
	{
	
	for(Arg=1; Arg<argc; Arg++) //looping for arguments 
	{
		Int = atoi(argv[Arg]); // converting ascii to int
		Float = atof(argv[Arg]); // converting ascii to float
		
		if(Int == 0) 
		{
			if(strlen(argv[Arg])==1) // comparing string length for char
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

