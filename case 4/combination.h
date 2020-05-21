#ifndef COMBINATION_H
#define COMBINATION_H
#include <vector>
class combination
{
	int num ;
	int len ;
	std::vector<std::string>result ;
// public members
public:
	combination(); 
	~combination() ;
	std::vector<std::string> mapping(std::string digits) ;
} ;

#endif 
