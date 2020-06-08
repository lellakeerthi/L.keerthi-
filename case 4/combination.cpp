#include<iostream>
#include<vector>
#include"combination.h"

using namespace std;

//default constructor
combination::combination()
{
	num = 0;
	Length = 0;
}
/*
 Function name: mapping
 Input parameters: string
 Return type: vector string
*/
vector<string>combination:: mapping(string digits) 
{
    //if input is other than 0/1
	if(digits.length()== 0 )
	{
        return result;
	}
	string letter[] ={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	// to make string as integer
    num = digits[0] -'0';
    
	// loop for length of input digits.
	for(int index =0; index <letter[num].length(); index++)
    {
        string String;
        // take letters of digit and push to vector
        String += letter[num][index];
        result.push_back(String);
    }
    // loop iterarte for size of digit and stores letters in temp vector
    for(int index=1; index<=digits.size(); index++)
    {
    	
        num =digits[index]-'0';
            
        vector<string> temp = result;
            
		Length = result.size();
		//iterate till len. and make letter mapping
        for(int pos =0; pos<letter[num].length()-1; pos++)
        {
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
		for(int map=0, pos=0, size=0; map<result.size(); map++)
        {
            	
        	result[map] += letter[num][pos];
                
			if(result[map].size()==digits.size())
				
			cout<<result[map] <<",";
				
			size++;
                
			if(size==Length)
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

