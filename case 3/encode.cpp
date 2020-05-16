#include<iostream>
#include <fstream>
#include <string.h>
#include"encode.h"
using namespace std ;

encode::encode()
{
	strcpy(String,"\0") ;
	count=0 ;
}
 encode::~encode()
{

}	
/*Function Name :encrypt
  Parameters    :char*
  Return Type   :no return type
  Usage         :to reverse data of input file */	
int encode::encrypt(char* filename, char* key)	
{

	std::string Key ;
	
	cout<<"enter alpha numeric character" ;
	cin>>alpha ;
			
	//open a file to perform write operation using file object
	ofstream outfile("encrypt.txt", ios::out);
	//open a file to perform read operation using file object
	ifstream file(filename, ios::in);
 			
 	//checking whether the file is present
 	if(!file)
	{
		cout<<" file not found"<< endl ;
	}
	if (!outfile)
	{
        cout << "encrypt file not found" << endl;
    }    				
 			
	for(int indx=0; key[indx]!= '\0'; indx++)
 	{
 		Key += key[indx]+5;
 	}
	outfile << Key <<endl;
		
	// to reverse the content of input file			 
	while(!file.eof())
	{
	 	file.get(word);
	 	if(word ==' '|| word =='\n')
	 	{
			String[count]='\0';		
			strrev(String) ;
			outfile << String ;
			cout << String ;
					
			if(word ==' ')
			{
				cout<<alpha ;
				outfile << alpha ;
			}
			else
			{
				cout<< word ;
				outfile << (word) ;
			}
			count=0;
		}
		
		else
		   	String[count++]=word;
	} 

	outfile.close() ;
	file.close() ;
	return 1 ;
}
/*Function Name :decrypt
  Parameters    :char*
  Return Type   :no return type
  Usage         :to decrypt reverse data of encrypt file */		
void encode::decrypt(char* filename, char* key)
{
			
	string line ;
	string Skey, Key ;
	
	cout<<"enter alpha numeric character" ;
	cin>>alpha ;

	//open a file to perform read operation using file object
	ifstream file(filename, ios::in) ;
	//file.open(filename) ;
	//open a file to perform write operation using file object
	ofstream outfile("decrypt.txt", ios::out) ;
	//outfile.open("decrypt.txt");
    //checking whether the file is present	
	if(!file)
	{
		cout<<" file not found"<< endl ;
	}
	//checking whether the file is present
	if (!outfile)
	{
        cout << "decrypt file not found" << endl;
    }
	if (file.is_open())  
   	{
		getline(file,Skey ) ;
				
		for(int indx=0; key[indx]!= '\0'; indx++)
 		{
 			Key += key[indx]+5;
		}
		
	   	if((Skey.compare(Key))==0)
	   	{
	   	    		
		// to reverse the content of encrypted file
			while(!file.eof())
			{
		 		file.get( word );
		 		if(word == alpha|| word =='\n')
		 		{
					String[count]='\0';
							
					strrev(String) ;
					outfile << String ;
					cout << String ;
							
					if(word==alpha)
					{
						cout<<" " ;
						outfile << " " ;
					}
					else
					{
						cout<<word ;
						outfile << (word) ;
					}
					count=0;
				}
			
				else
			   		String[count++]=word;
			}
		}
		else
   		{
   		cout<<"key not matched" ;
   		}   
	}
	
    file.close();
    outfile.close();

}

