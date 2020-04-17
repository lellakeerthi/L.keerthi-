#include <iostream>
#include <fstream>
#include  <string.h>

using namespace std;

// function to delete data
void delete_data()
{

    fstream data;
    fstream temp;

    data.open("data.txt", ios::in);
    temp.open("temp.txt",ios::out);
    char key [100];
    char value[100];
    char a[25];
    cin.ignore();
    cout<<" enter key to delete data : ";

    while(!data.eof())
    {
        data.getline(key,100);
        data.getline(value,100);
        
        if(strcmp(key,a)==0)
        {
            cout<<key << " " << value ;
        }
        else
        {
            cout<<" key not found" << endl ;
        }


    }
    temp.close();
    data.close();

    data.open("notes.ini", ios::out);
    temp.open("temp.txt", ios::in);
    while(!temp.eof())
    {
        temp.getline(key, 100);
        temp.getline(value, 100);
    
        data << key << value ;
    }
    temp.close();
    data.close();
    remove("temp.txt");
   
}
// function to update data
void update_data()
{
    fstream data;
    fstream temp;

    data.open("notes.ini", ios::in);
    temp.open("temp.txt", ios::out);
    char key [100];
    char value[100];
 
    char a[25];
    
    cout<<" enter key to update : ";
    cin.getline(a,100);
    while(!data.eof())
    {
        data.getline(key,25);
        data.getline(value,25);
        
        if(strcmp(key,a)==0)
        {

            cout<<" enter new value of record  \n "<< endl ;
            cout<<"  key : "<< endl ;
            cin.getline(key,25);
            cout<<" value : "<< endl ;
            cin.getline(value,25);
            cout<<" age : "<< endl ;
            temp<< key <<value << endl ;
        }
        else
        {
            temp<< key << value << endl ;
        }


    }
    temp.close();
    data.close();

    data.open("notes.ini",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(key,100);
        temp.getline(value,100);
        
        data<< key << value << endl ;
    }
    temp.close();
    data.close();
    remove("temp.txt");
    
}
// function to dispaly data
void display_data()
{
    char value [100];
    char key[100];

    fstream data;
    data.open("notes.ini", ios::in);

    while(!data.eof())
    {
        data.getline(key,100);
        data.getline(value,100);
        
        cout << key << "\t" << value <<endl;

    }
}

// function for searching data
void search_data(   )
{

    fstream data;
    data.open("notes.ini",ios::in);
    char key [100];
    char value[100];
   
    char a[100];
    cout<<" \n enter the phone to search about it : ";
   
    cin.getline(key,100);
    int x=0;

    while(!data.eof())
    {
        data.getline(key,100);
        data.getline(value,100);
        
        if(strcmp(key, a)==0)
        {
            cout << key << "\t"<<value <<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n not found !!!!\n";
    }
    data.close();
}
// function to add data to file
void  insert_data()
{

    char value [100];
    char key[100];
    
    fstream data;
    data.open("notes.ini", ios::app);
    cin.ignore();
    cout<<" key : ";
    cin.getline(key,100);
    cout<<" value : ";
    cin.getline(value,100);
   
    data<< key << value <<endl ;
    data.close();
}


int main(int argc, char* argv[])
{
    // checking arguments to display -h 
    
	if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
        cout << "usage of square" << endl <<argv[0] ;
    }
	
    else
	{

    int choice ;
    while (1)
    {
        cout << " \n 1 Add data  \n 2 search  \n 3 display \n 4 update \n 5 delete \n 6 exit "<< endl ;
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1 :
            insert_data();
            break;
        case 2:
            search_data();
            break;
        case 3:
            display_data();
            break;
        case 4 :
            update_data();
            break;
        case 5 :
            delete_data();
            break;
        case 6:
        	exit(0) ;
        	break ;
        default :
            return 0 ;
        }
        
    }
    return 0;
	}
}


