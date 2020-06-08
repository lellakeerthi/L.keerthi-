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
		combination combinationobj ;
		string input ;
		cout<<"enter number between 2-9 :" ;
		cin>> input ;
		
        //checking for 0,1 
	    int count=0;
    	for(int i=0;i<input.length();i++)
        {
            
            if ((input[i]>=50 && input[i]<=57))
            {
                continue;
            }
            else
            {
                cout<<"invalid input"<<endl;
                count=1;
                exit(0);
            }
        }
            
        if(count==0)
    	{
         	// passing inputs to the vector function mappng.
			combinationobj.mapping(input);
		 
        }
  
	}
	return 0 ;
}
