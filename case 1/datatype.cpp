/*Program: checking the command line arguments.
filename:datatype.cpp
date:14-04-2020
Author:L. keerthi
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

/*function name:check_number
return type :bool
input parameter:string
*/

bool check_number(string str)
{
int flag=0;
for(int i=0;i<str.length();i++)
{
//condition for checking real no
if(str[i]=='.')		
{
flag=1;
break;
}
}
//condition wheather the input sring is integer or float
if(flag)
cout<<"float"<< "\t"<<str<<"\t"<<sizeof(str)<<endl;
else
cout<<"int"<< "\t"<<str<<"\t"<<sizeof(str)<<endl;
}
// main function using command line arguments
int main(int argc,char *argv[])  
{
	
int Pos;
int Int;
float Float;

// checking arguments to display -h
if (argc==2)  
	{
		cout << " usage of parse.exe" <<endl;           
		cout << " argv[0] datatype1, datatype2, datatype3....n" << endl ; 

	}
	else if (argc>2)  
	{
	//looping for arguments
	for(Pos=1; Pos<argc; Pos++)  
	{
		// converting ascii to int
		Int = atoi(argv[Pos]); 
		// converting ascii to float
		Float = atof(argv[Pos]); 
		
		if(Int == 0) 
		{
			// comparing string length for char
			if(strlen(argv[Pos])==1) 
			{
				cout<<"Char" << "\t" << argv[Pos] << "\t"<< strlen(argv[Pos]) << endl;
			}
			else
			{
				cout<<"String" << "\t"<< argv[Pos] << "\t"<< sizeof(argv[Pos]) << endl;
			}
		}
		else
		{
			check_number(argv[Pos]);
		}
		
	}
	}
	else 
	{
	cout<<"no arguments are given" << endl << "-h for usage" ;
	}
}

