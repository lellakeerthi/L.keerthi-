/*File Name     :copy.cpp
  Author Name   :l.keerthi
  Created Date  :22-04-2020 */

#include<iostream>
#include<string.h>

using namespace std;

class test
{
	private:
		int *iNum;
		char str[20];
	public:
    test()
    {
        cout<<"default constructor"<<endl;
        //allocating memory dynamically
        iNum = new int;
        *iNum =0;
        *str ='\0';
    }
    test(int ino,char cstr[20])
    {
        cout<<"Parameterized Constructor "<<endl;
        iNum = new int;
        *iNum = ino;
        strcpy(str ,cstr );
    }
    //copy constructor
    test(const test& ob)
    {
        
        iNum = new int;
        strcpy(str ,ob.str);
        *iNum=*ob.iNum;
    }

/*Function Name :getdata
  Parameters    :int*,char[]
  Return Type   :no return type
 */

    void getdata(int ino,char Str[])
    {
        iNum = new int;
        *this-> iNum=ino;
        strcpy(str ,Str);
    }

/*Function Name :display
  Parameters    :no parameters
  Return Type   :no return type
 */
    void display()
    {
        cout <<*iNum <<" "<<str <<endl;
        cout<<endl;
    }
    
	//void operator=(const test& ob);
	~test()
    {
        cout<<"Deallocating Memory"<<endl;
    }

	void operator=(const test& ob)
	{
    if (&ob != this)
    {
        strcpy(str,ob.str);
        delete iNum;
        iNum = new int;
        iNum = ob.iNum;
    }
	}
};
 
int main(int argc,char* argv[])
{
	if(argc==2)
    {
     	if(strcmp(argv[1],"-h")==0)
    	{
			cout<<"Enter given Inputs"<<endl;
        }
    }
	else
    {
		int ino;
		char cStr[20];
        
		test* ob=new test();
        ob->display();
        
        test* ob1=new test(100 ,"constructor");
        ob1->display();
        
        //copy constructor is invoked
        test *ob2=new test(*ob1);
        cout<<"using copy constructor"<<endl;
        ob2->display();
        
        cout<<"Enter number:";
        cin>>ino;
        cout<<"Enter less than 20 characters:";
        cin>>cStr;
        ob1-> getdata(ino,cStr);
        cout<<" coping, assingning different values"<<endl;
        ob2->display();
        ob1->display();
        
        cout<<"using Assignment Operator"<<endl;
        ob2=ob1;
        ob2->~test();
        ob1->display();
        
       
	}
return 0;
}

