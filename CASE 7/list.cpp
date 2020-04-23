/*Name of program: to perform list of operations addconfig,delete config,serch config,display string
filename:list.cpp
Author:l.keerthi
date:16-4-2020
*/
#include<iostream>
#include<list>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class config
{
    char Key[100];
    char Value[100];
public:

/*Function Name :setkey
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of key the private member*/

    void setkey()
    {
        cout<<"Enter key:";
        getchar();
        cin.get(Key,100,'\n');
    }

/*Function Name :setvalue
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of value the private member*/

    void setvalue()
    {
        cout<<"Enter value:";
        getchar();
        cin.get(Value,100,'\n');
    }

/*Function Name :putkey
  Parameters    :no parameter
  Return Type   :char return type
  Usage         :to return the key*/

    char* putkey()
    {
        return Key;
    }

/*Function Name :putvalue
  Parameters    :no parameter
  Return Type   :string return type
  Usage         :to return value*/

    char* putvalue()
    {
        return Value;
    }
    void print()
    {
        cout<<Key<<"\t"<<Value<<endl;
    }
};

/*Function Name :removefile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to remove file if file is empty*/

void removefile()
{
    config c;
    int Count;
    ifstream infile("notes.ini",ios::in);
    while(1)
    {
        //reading the contents in file
        infile.read((char*)&c,sizeof(c));
        Count++;
        //checking for end of file
        if(infile.eof())break;
    }
    if(Count==0)
    {
        cout<<"file is deleted"<<endl;
        //to remove file
        remove("notes.ini");
    }
}

/*Function Name :updateconfig
  Parameters    :two parameter(list object and char)
  Return Type   :int return type
  Usage         :to update the duplicate values*/

void updateconfig(list<config> &std)
{
    config c;
   	char ckey[1000];
    list<config>:: iterator Itr;
    ofstream outfile("notes.ini",ios::trunc|ios::out);
    cout<<"Enter the key to update:";
    getchar();
    cin.get(ckey, 1000,'\n');
    for(Itr=std.begin();Itr!=std.end();++Itr)
    {
        c=*Itr;
        if(strcmp(c.putkey(),ckey)==0)
        {
            std.erase(Itr);
            cout<<"Enter value to update"<<endl;
            c.setvalue();
            //the new value is pushed into file
            std.push_back(c);
	}
    }
    for(Itr=std.begin();Itr!=std.end();Itr++)
    {
        c=*Itr;
            outfile<<c.putkey()<<"="<<c.putvalue()<<"\n";
        //the file again written with updated values
    }
    outfile.close();
}
/*Function Name :addconfig
  Parameters    :one list object parameter
  Return Type   :no return type
  Usage         :to add records in to file and store them in to a list*/

void addconfig()
{
    config c;
    ofstream outfile("notes.ini",ios::out|ios::app);
    c.setkey();
    c.setvalue();
    outfile<<c.putkey()<<"="<<c.putvalue()<<endl;
    outfile.close();
    
}

/*Function Name :deleteconfig
  Parameters    :one list object parameter
  Return Type   :no return type
  Usage         :to delete a record from file*/

void deleteconfig(list<config> &std)
{
   char ckey[100];
    config cn;
    list<config>:: iterator it;
    ofstream outfile("notes.ini",ios::trunc|ios::out);
    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,100,'\n');
    
    for(it=std.begin();it!=std.end();it++)
    {
        	cn=*it;
        if((strcmp(cn.putkey(),ckey)==0))
        {
            std.erase(it);
	    cout<<"deleted"<<endl;
		break;
        }
	
   	
    }
   	removefile();
    for(it=std.begin();it!=std.end();it++)
	{
		cn=*it;
            outfile<<cn.putkey()<<"="<<cn.putvalue()<<"\n";
	}
    outfile.close();
}
/*Function Name :displayconfig
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the contents in the file*/

void displayconfig()
{
    config cg;
    ifstream infile("notes.ini",ios::in);
    char info[100];
    while(!infile.eof())
    {
        infile.getline(info,100);
        cout<<info<<endl;
    }
}
/*Function Name :searchconfigaration
  Parameters    :one list object parameter
  Return Type   :no return type
  Usage         :to search for a key or value and displaying*/

void searchconfig(list<config> &std)
{
    config ch;
    char option;
    char Searchkey[500];
    char Searchvalue[100];
    list<config>:: iterator iTR;
    ifstream infile("notes.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>option;
    if(option=='k'||option=='K')
    {
        cout<<"Enter key u want to search:";
        getchar();
        cin.get(Searchkey,500,'\n');
        for(iTR=std.begin();iTR!=std.end();iTR++)
        {
            ch=*iTR;
            if(strcmp(Searchkey,ch.putkey())==0)
                cout<<ch.putkey()<<"="<<ch.putvalue()<<endl;
        }
    }
    else if(option=='v'||option =='V')
    {
        cout<<"Enter value u want to search:";
        getchar();
        cin.get(Searchvalue,100,'\n');
        for(iTR=std.begin();iTR!=std.end();iTR++)
        {
            ch=*iTR;
            if(strcmp(Searchvalue,ch.putvalue())==0)
                cout<<ch.putkey()<<"="<<ch.putvalue()<<endl;
        }
    }
    else

        cout<<"Enter k or v"<<endl;
}
int main(int argc,char* argv[]) 

{
    
	if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
		
        cout << "usage of" << argv[0] << endl ;
    	cout<<"select required option"<<endl;
    }
    else
    {
        list<config> std;
        list<config>:: iterator Itr;
        char Opt;
        while(1)
        {
            cout<<"Select your option:"<<endl<<" 1.add"<<endl<<" 2.delete"<<endl<<" 3.display"<<endl<<" 4.update"<<endl<<"5.search"<<endl<<"6.exit"<<endl;
            cin>>Opt;
            switch(Opt)
            {
                case '1':
                        addconfig();
                        break;
                case '2':
                        deleteconfig(std);
                        break;
                case '3':
                        displayconfig();
                        break;
				case '4':
						updateconfig(std);
						break;
				case '5':
						searchconfig(std);
						break;
				case '6':	
						exit(0);
						break;
                default:
                        return 0;
            }
        }
    }
return 0;
}
