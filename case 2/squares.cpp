/*Program: finding square and adding the squares of 'n' numbers.
filename:squares.cpp
date:10-04-2020
Author:L. keerthi
*/

#include <iostream>
using namespace std;

/*function name:SquareSum
input parameter:int
output parameter:int
*/

int SquareSum(int No) // function for square & sum
{
	int index = 0, Sum = 0 ;
	
	if(No>0 )  
    {
		for ( index = 0; index <= No; index ++) 
        {
        	// to square and add the squares
            Sum = ( index * index ) + Sum; 

        }
        cout <<"sum :" << Sum ;
	}
}

int main(int argc, char* argv[])
{
    // checking arguments to display -h 
    if (argc == 2) 
    {
        cout << "usage of " << argv[0] ;
    }
    else
	{
        int Num=0 ;
        cout << "enter number:" ;
        cin >> Num;  
        SquareSum(Num) ;
    
	}

}

