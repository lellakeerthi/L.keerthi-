#ifndef CODE_H
#define CODE_H

class encode
{
	//private members
	private:
		char alpha ;
		char word ;
		char String[100] ;
		int count ;
		std::string line ;
		std::string Skey, Key ;
	//public members
	public:
		encode() ;	
		~encode() ;
		int encrypt(char* filename, char* key) ;
		int decrypt(char* filename, char* key) ;
		
};
#endif 

