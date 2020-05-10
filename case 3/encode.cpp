/*Name of program: to perform list of operations addconfig,delete config,serch config,display string
filename:list.cpp
Author:l.keerthi
date:16-4-2020
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std ; 

class code
{
	public:
/*Function Name :encrypt
  Parameters    :char*, char*
  Return Type   :no return type
  Usage         :to encrypt data of input file in reverse */
	
		void encrypt(char* filename, char* key)	
		{
			char word;
			int count=0;
			char str[100] ;
			string s ;
			
			char alpha ;
			cout<<"enter alpha numeric character" ;
			cin>>alpha ;
			//open a file to perform write operation using file object
			ofstream outfile ;
			outfile.open("encrypt.txt") ;//,ios::out ) ;
			//open a file to perform read operation using file object
			ifstream file;
			file.open(filename);
 			
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
			
 			
			for(int indx=0; key[indx]!= '\0'; indx++)
 			{
 				s += key[indx]+5;
 			}
			cout<<s<< endl ;
			outfile << s <<endl;
		
			// to reverse the content of input file			 
			while(!file.eof())
	 		{
	 			file.get(word);
	 			if(word ==' '|| word =='\n')
	 			{
					str[count]='\0';
					
					strrev(str) ;
					outfile << str ;
					cout << str ;
					
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
		   			str[count++]=word;
	 		} 

			outfile.close() ;
			file.close() ;
		}
/*Function Name :decrypt
  Parameters    :char*
  Return Type   :no return type
  Usage         :to decrypt reverse data of encrypt file */		
		void decrypt(char* filename)
		{
			
			char word;
			int count=0;
			char str[50];
			string line ;
			
			char alpha ;
			cout<<"enter alpha numeric character" ;
			cin>>alpha ;
			//open a file to perform read operation using file object
			ifstream file ;
			file.open(filename) ;
			//open a file to perform write operation using file object
			ofstream outfile ;
			outfile.open("decrypt.txt");
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
			getline(file, line) ;
			// to reverse the content of encrypted file
			while(!file.eof())
	 		{
	 			file.get( word );
	 			if(word == alpha|| word =='\n')
	 			{
					str[count]='\0';
					
					strrev(str) ;
					outfile << str ;
					cout << str ;
					
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
		   			str[count++]=word;
	 		}

    		
			file.close();
    		outfile.close();

		}
/*Function Name :encrypt
  Parameters    :char*, char*
  Return Type   :no return type
  Usage         :to compare the secret key & to display decoded data */
		void Secret_key(char* filename, char* key) 
		{
			string Skey, str ;
         
  			ifstream file ;
  			//open a file to perform read operation using file object
  			file.open("encrypt.txt");
			//checking whether the file is open   
   			if (file.is_open())  
   			{
				getline(file,Skey ) ;
				
				for(int indx=0; key[indx]!= '\0'; indx++)
 				{
 					str += key[indx]+5;
				}
			}
   			if((Skey.compare(str))==0)
   			{
   				decrypt(filename) ;
   			}
   			else
   			{
   				cout<<"key not matched" ;
   			}   
  			
   			file.close(); 
		}
} ;

int main(int argc,char *argv[])  
{
	code obj ;
	// checking arguments to display -h
    if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
		cout << " usage of"<< argv[0] <<endl;           
		cout << "-f filename -e encryption / -d decryption -k key " << endl ; 		
	}
		
	else if(argc>=2)
	{
			if (strcmp(argv[1],"-e")==0)
			{
				if ((strcmp(argv[2],"-f")==0 ) )
					
					obj.encrypt(argv[3], argv[5]) ;
				
				else if((strcmp(argv[2], "-k")==0))
				
					obj.encrypt(argv[5], argv[3]) ;		
			}
					
			else if (strcmp(argv[1],"-d")==0)
			{
				if ((strcmp(argv[2],"-f")==0 ) )
					
					obj.Secret_key(argv[3], argv[5]) ;
				
				else if((strcmp(argv[2], "-k")==0))
				
					obj.Secret_key(argv[5], argv[3]) ;		
			}
	}
	else
	{
		cout<< " use -h for usage" ;
	}
	
}

