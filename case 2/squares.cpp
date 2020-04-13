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
	int i= 0, Sum = 0 ;
	
	if(No>0 )  
    {
		for ( i = 0; i <= No; i ++) 
        {
        	// to square and add the squares
            Sum = (i*i) + Sum; 

        }
        cout <<"sum :" << Sum ;
	}
}

int main(int argc, char* argv[])
{
    // checking arguments to display -h 
    if (argc == 2) 
    {
        cout << "usage of square.exe" << endl <<argv[0] << endl << "input: int" ;
    }
    else
	{
        int Num=0 ;
        cout << "enter number:" ;
        cin >> Num;  
        SquareSum(Num) ;
    
	}

}

