#include<iostream> 
using namespace std; 
  
class base 
{ 
public: 
    base()  
    { 
        cout<< "Constructor called" <<endl; 
    	fun() ; 
    } 
  
    ~base() 
    {  
    	cout<< "Base class destructor" <<endl;
    } 
  
    virtual void fun() 
    {  
        cout<< "Virtual function" <<endl;  
    } 
  
    void fun1()  
    {  
        fun();  
    } 
}; 
  
class derived : public base 
{ 
public: 
        derived()  
        { 
            cout<< "Derived class Constructor" <<endl;  
        } 
        void fun()  
        { 
            cout<< "Derived class Virtual function" <<endl;  
        }
		virtual	~derived() 
    	{  
        	cout<< "Derived class destructor" << endl ;
    	}
}; 
  
int main() 
{ 
    derived d; 
    d.fun(); 
} 

