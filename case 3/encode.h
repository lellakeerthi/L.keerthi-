#ifndef CODE_H
#define CODE_H

class code
{
	//private members
	private:
		char alpha ;
		char word ;
		char str[100] ;
		int count ;
		

	//public members
	public:
	
		code() ;	
		void encrypt(char* filename, char* key) ;
		void decrypt(char* filename, char* key) ;
		
};
#endif 
