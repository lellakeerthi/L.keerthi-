/*Description: to encrypt and decrypt the a file
Filename:encode.cpp
Author:l.keerthi
date:09-5-2020
*/	
#include"encode.h"
  
code::code()
{
	cout<<"enter alpha numeric character" ;
	cin>>alpha ;

}
/*Function Name :encrypt
  Parameters    :char*
  Return Type   :no return type
  Usage         :to reverse data of input file */		

void code::encrypt(char* filename, char* key)	
{
	char word;
	int count=0;
	char str[100] ;
	string Key ;
			
	//open a file to perform write operation using file object
	ofstream outfile ;
	outfile.open("encrypt.txt") ;
	//open a file to perform read operation using file object
	ifstream file;
	file.open(filename);
 			
 	//checking whether the file is present
 	if(!file)
	{
		cout<<" file not found"<< endl ;
	}
	if (!outfile)
	{
        cout << "decrypt file not found" << endl;
    }    				
 			
	for(int indx=0; key[indx]!= '\0'; indx++)
 	{
 		Key += key[indx]+5;
 	}
	cout<<Key<< endl ;
	outfile << Key <<endl;
		
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
  Parameters    :char*, char*
  Return Type   :no return type
  Usage         :to check for the key & decrypt reverse data of encrypt file */		
void code::decrypt(char* filename, char* key)
{
			
	char word;
	int count=0;
	char str[50];
	string line ;
	string Skey, Key ;

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
	if (file.is_open())  
   	{
		// getting key from the encrypted file
		getline(file,Skey ) ;
				
		for(int indx=0; key[indx]!= '\0'; indx++)
 		{
 			Key += key[indx]+5;
		}
	// comparing key in encrypted file and given key	
   	if((Skey.compare(Key))==0)
   	{
   	    		
	// to reverse the content of encrypted file if key matches
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
	}
	else
   	{
   		cout<<"key not matched" ;
   	}   
	}
	
    file.close();
    outfile.close();

}

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
return 0 ;	
}
