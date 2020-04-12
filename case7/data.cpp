
/*Name of program:add,delete,display,serchupdate in a file 
filename:notes.cpp
Author:l.keerthi
Date:12-04-2020
*/
#include<iostream>
#include<set>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;
class Notes
{
		// private data members
        int key;
        char data[100];
public:
	// public data members
	//friend function
        friend ostream& operator<<(ostream &,Notes &);
        friend istream& operator>>(istream &,Notes &);
        bool operator<(const Notes &n)const
        {
                return key<n.key;
        }
        bool operator==(const Notes &n)const
        {
                return key==n.key;
        }
        int getkey()
        {
                return key;
        }
};
ostream& operator<<(ostream &out,Notes &n)
{
        out<<"key: "<<n.key<<endl;
        out<<"data: "<<n.data<<endl;

        return out;
}
istream& operator>>(istream &in,Notes &n)
{
        cout<<"key:";
        cin>>n.key;
        cout<<"Enter data:";
        getchar();
 		in.get(n.data,100,'\n');
        return in;
}
/*function name:addconfig
return type:void
input parameter:set<student> &std
*/
void addconfig(set<Notes>&std)
{
        Notes n;
        set<Notes>:: iterator it;
        char option='y';
        while(option=='y')
        {
                ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
                cin>>n;
                std.insert(n);
                for(it=std.begin();it!=std.end();it++)
                outfile.write((char*)&(*it),sizeof(n));
                cout<<"Do you want to append data(y/n)?";
                getchar();
                cin>>option;
                
    	}
}
/*function name:deleteconfig
return type:void
input parameter:set<student> &std
*/
void deleteconfig(set<Notes> &std)
{
        int no;
        Notes n;
        set<Notes>:: iterator it;
        ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);        
		cout<<"Enter the key to delete from file";        
		cin>>no;
        for(it=std.begin();it!=std.end();it++)
        {
                n=*it;
                if(n.getkey()==no)
                std.erase(it);
   }
        for(it=std.begin();it!=std.end();it++)
        outfile.write((char*)&(*it),sizeof(n));
    	outfile.close();
}
/*function name:displayconfig
return type:void
*/

void displayconfig()
{
        Notes n ;
        ifstream in("notes.ini",ios::in|ios::binary);
        while(1)
        {
                in.read((char*)&n,sizeof(n));
                if(in.eof())break;
                cout<<n;
        }
        in.close();
}
/*function name:serchupdateconfig
return type:void
input parameter:set<student> &std
*/
void searchupdateconfig(set<Notes> &std)
{
        int no;
        Notes n;
        set<Notes>:: iterator it;
        ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
        cout<<"Enter the key to update details in file";
        cin>>no;
        for(it=std.begin();it!=std.end();it++)
        {
                n=*it;
                if(n.getkey()==no)
                {
                        std.erase(it);
                        break;
                }
        }
        cout<<"Enter details to update";
        cin>>n;
        std.insert(n);
        cout<<"Updated"<<endl;
        for(it=std.begin();it!=std.end();it++)
        outfile.write((char*)&(*it),sizeof(n));
        outfile.close();
}
int main(int argc,char **argv)
{
	if(argc==2)
	{
	cout<<"program.exe"<<endl;
	cout<<"this program is used add ,delete,update data to file"<<endl;
	}
	else
	{
	set<Notes> std;
	set<Notes>:: iterator it;
        Notes n;
        char option;
        addconfig(std);
        while(1)
        {
        cout<<"Select your option"<<endl<<" 1.add"<<endl<<" 2.delete"<<endl<<" 3.search"<<endl<<"4.display"<<endl<<"5.exit"<<endl;
        getchar();
        cin>>option;
        switch(option){
                case '1':
                        addconfig(std);
                        break;
                case '2':
                        deleteconfig(std);
                        break;
                case '3':
                        searchupdateconfig(std);
                        break;
                case '4':
                        displayconfig();
                        break;
                case '5':
			exit(0);
			break;        
                default:
                        return 0;
        }
        }
	}

}
