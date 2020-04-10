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
	int Loop = 0, Sum = 0 ;
	if(No>0) // to check if the number is greater than zero 
    {
		for (Loop = 0; Loop <= No; Loop++) 
        {
            Sum = (Loop * Loop) + Sum; // to square and add the squares

        }
        cout <<"sum :" << Sum ;
	}
}

int main(int argc, char* argv[])
{
    
    if (argc == 2) // checking arguments to display -h 
    {
        cout << " ./ program: sum of squares of 'n' numbers " << endl <<" input: int" ;
    }
    else
	{
        int Num=0 ;
        cout << "enter number:" ;
        cin >> Num;  
        SquareSum(Num) ;
    
	}

}

