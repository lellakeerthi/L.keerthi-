#include<iostream>
#include<vector>
#include"combination.h"

using namespace std ;

//default constructor
combination::combination()
{
	num = 0;
	len = 0 ;
}
/*
 Function name: mapping
 Input parameters: string
 Return type: vector string
*/
vector<string>combination:: mapping(string digits) 
{
    // if input is 1/0	
	if(digits == "1" ||digits=="0" ||digits=="01" ||digits=="10")
	{
		cout<<"enter digits between 2-9" ;
	}
	//if input is other than 0/1
	else if(digits.length()== 0 )
	{
        return result;
	}
	string letter[] ={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	// to make string as integer
    num = digits[0] -'0';
	// loop for length of input digits.
	for(int index =0; index <letter[num].length(); index++)
    {
        string s;
        // take letters of digit and push to vector
        s += letter[num][index];
        result.push_back(s);
    }
    // loop iterarte for size of digit and stores letters in temp vector
    for(int index=1; index<=digits.size(); index++)
    {
        num =digits[index]-'0';
            
        vector<string> temp = result;
            
		len = result.size();
		//iterate till len. and make letter mapping
        for(int pos =0; pos<letter[num].length()-1; pos++)
        {
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
		for(int map=0, pos=0, size=0; map<result.size(); map++)
        {
            	
        	result[map] += letter[num][pos];
                
			if(result[map].size()==digits.size())
				
			cout<<result[map] <<"," ;
				
			size++;
                
			if(size==len)
            {
                size=0;
                pos++;
            }

        }
    }
    return result;
}

//destructor
combination::~combination()
{
	
}

