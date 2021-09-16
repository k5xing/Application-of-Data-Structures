#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <vector>
using namespace std;


#include "openht.h"
HashTable::HashTable()
{
	hashtable.resize(0);
	current_size=0;
}
HashTable::~HashTable()
{
	hashtable.resize(-1);
	current_size=-1;
}
//setsize and assign -1 to represent empty
void HashTable::setsize(int size)
{
	hashtable.resize(size);
	hashtable.assign(size,-1);
	cout<<"success";
}
//search
int HashTable::search(int key)
{
	int mod = key % hashtable.size();
	int searchtime=0;
	while(hashtable[mod%hashtable.size()]!=key && hashtable[mod%hashtable.size()]!=-1 && searchtime<hashtable.size())
	{
		mod++;
		searchtime++;
	}
	if(searchtime==hashtable.size() || hashtable[mod%hashtable.size()]==-1)
	{
		return -1;
	}
	return mod%hashtable.size();
}
//insert
void HashTable::insert (int key)
{
	int searchkey = search(key);
	if(searchkey!=-1 ||current_size==hashtable.size())
	{
		cout<<"failure";
	}
	else
	{
		int mod=key%hashtable.size();
		while(hashtable[mod%hashtable.size()]!=-1&&hashtable[mod%hashtable.size()]!=-2)
		{
			mod++;
		}
		hashtable[mod%hashtable.size()]=key;
		current_size=current_size+1;
		cout<<"success";
	}
		
}
//delete
void HashTable::erase (int key)
{
	int found=search(key);
	if(found==-1)
	{
		cout<<"failure";
	}
	else
	{
		hashtable[found]=-2;
		current_size=current_size-1;
		cout<<"success";
	}
}
//print for debug
void HashTable::print ()
{
	int i=0;
	while(i<hashtable.size())
	{
		cout<<hashtable[i]<<" ";
		i++;
	}
}
int main() 
{
	HashTable* hashtable=new HashTable();
    string line;
    while (getline(cin, line)&& !line.empty()) 
	{
     
		istringstream iss(line);
		string command;
		string position;
		iss>>command; //get the required command 
		
		
		if(command=="n")
		{
			int size;
			iss>>size;
			hashtable->setsize(size);
		}
		else if(command=="i")
		{
			int key;
			iss>>key;
			hashtable->insert(key);
			//hashtable->print();
		}
		else if(command=="s")
		{
			int key;
			iss>>key;
			int found=hashtable->search(key);
			if(found==-1)
			{
				cout<<"not found";
			}
			else
			{
				cout<<"found in "<<found;
			}
		}
		else if(command=="d")
		{
			int key;
			iss>>key;
			hashtable->erase(key);
		}
		else
		{	//illegal commands
			cout<<endl;
		}
		cout<<endl;
	}
}
