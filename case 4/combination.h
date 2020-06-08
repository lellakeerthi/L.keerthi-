#ifndef COMBINATION_H
#define COMBINATION_H
#include <vector>

using namespace std ;
class combination
{
	int num ;
	int Length ;
	vector<string>result ;
// public members
public:
	combination(); 
	~combination();
	vector<string> mapping(string digits);
};

#endif 
