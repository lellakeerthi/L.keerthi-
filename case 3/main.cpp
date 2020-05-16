/*Description: to encrypt and decrypt the a file
Filename:encode.cpp
Author:l.keerthi
date:09-5-2020
*/	
#include <iostream>
#include<string.h>
#include"encode.h"

using namespace std ;

int main(int argc,char *argv[])  
{
	encode obj ;
	//int a = result ;
	// checking arguments to display -h
    if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
		cout << " usage of"<< argv[0] <<endl;           
		cout << "-f filename -e encryption / -d decryption -k key " << endl ; 		
	}
		
	else if(argc>=2)
	{
			// conditions for encryption
			if (strcmp(argv[1],"-e")==0)
			{
				if ((strcmp(argv[2],"-f")==0 ) )
					
					obj.encrypt(argv[3], argv[5]) ;
				
				else if((strcmp(argv[2], "-k")==0))
				
					obj.encrypt(argv[5], argv[3]) ;		
			}
			// conditions for decryption		
			else if (strcmp(argv[1],"-d")==0)
			{
				//if ()
				if ((strcmp(argv[2],"-f")==0 ) )
					
					obj.decrypt(argv[3], argv[5]) ;
				
				else if((strcmp(argv[2], "-k")==0))
				
					obj.decrypt(argv[5], argv[3]) ;		
			}
	}
	else
	{
		cout<< " use -h for usage" ;
	}	
}

