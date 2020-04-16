
/*Program:program using int*, char [] .
filename:copy.cpp
Date:10-04-2020
Author:.
*/
#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Name
{
//declaration of variables in private
char str[20];
int *ival;
public:
//default constructor
	Name()
	{
	cout<<"IN default constructor"<<endl;
	}
//parametrised constructor
	Name(char *Mystr)
	{
	cout<<"In parametrised constructor"<<endl;
	strcpy(str,Mystr);//coping string
	}
//display function
	/*function name:display
	return type:void
	*/
	void display()
	{
	cout<<"value is "<<*ival<<endl;
	}
//display1 function
	/*function name:display1
	return type:void
	*/
	void display1()
	{
	cout<<"string is:"<<str<<endl;
	}
//overloadding oprator'+'
	Name operator+(Name s)
	{
	Name temp=str;
	strcat(temp.str,s.str);	//adding two strings
	return temp;
	}
//put_value function


	/*function name:put_value
	return type:void
	input parameter:int *
	*/
	void put_value(int *ig)
	{
	ival=ig;
	}
	~Name()
	{
	cout<<"IN destructor"<<endl;
	}
};
int main(int argc,char**argv)
{
	if(argc==2)
	{
	cout<<"programname.exe"<<endl;
	cout<<"meberfunction and operatoe overloading"<<endl;
	}
	else
	{
	int iJ;
	cout<<"enter value:"<<endl;
	cin>>iJ;
	//object declaration for class "Name"
	Name str1("copy");
	Name str2=("constructor");
	Name str3;
	Name s;
	str3=str1+str2;
	s.put_value(&iJ);
	s.display();
	str3.display1();
	}
}
