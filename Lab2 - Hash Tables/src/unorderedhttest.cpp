#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <vector>
using namespace std;


#include "unorderedht.h"
//HashList
//default constructor
HashList::HashList()
{
	head=NULL;
	back=NULL;
}
//destructor
HashList::~HashList()
{
	head=NULL;
	back=NULL;
}
//search in the linked list
bool HashList::search_list(int key)
{

	HashNode* headtmp=this->head;

	while(headtmp!=NULL && headtmp->key!=key)
	{
		headtmp=headtmp->next;
	}
	if(headtmp)
		return 1;
	else
		return 0;
}
//insert a key in the linked list
bool HashList::insert_list(int key)
{
	bool exist=search_list(key);
	
	if(exist==1)
		return 0;
	else
	{
		HashNode* newkey=new HashNode();
		newkey->key=key;
		if(this->head==NULL)//insert the first element in the linked list
		{
			this->head=newkey;
			newkey->next=NULL;
			this->back=newkey;
		}
		else
		{
			HashNode* backtmp=this->back;
			backtmp->next=newkey;
			newkey->next=NULL;
			this->back=newkey;
		}
	}
	return 1;
}
//delete a key in the linkedlist
bool HashList::erase_list(int key)
{
	bool exist=search_list(key);
	if(exist==0)
		return 0;
	else
	{
		HashNode* headtmp=this->head;
		HashNode* previous=this->head;
		while(headtmp->key!=key)
		{
			previous=headtmp;
			headtmp=headtmp->next;
		}
		if(this->head==headtmp && this->back==headtmp)//the only element in the linked list
		{
			this->head=NULL;
			this->back=NULL;
		}
		else if(this->head==headtmp)//delete head
		{
			this->head=headtmp->next;
		}
		else if(this->back==headtmp)//delete back
		{
			previous->next=NULL;
			this->back=previous;
		}
		else
		{
			previous->next=headtmp->next;
		}
		
	}
	return 1;
}
//HashTable
//default constructor 
HashTable::HashTable()
{
	hashtable.resize(0);
}
//destructor
HashTable:: ~HashTable()
{
	hashtable.resize(-1);
}
//resize the HashTable 
void HashTable::setsize(int input_size)
{
	hashtable.resize(input_size);
}
//search through HashTable using search_list function
void HashTable::search(int key)
{
	int mod=key%hashtable.size();
	bool search_table=hashtable[mod].search_list(key);
	if(search_table==1)
		cout<<"found in "<<mod;
	else
		cout<<"not found";
}
//insert using insert_list function
void HashTable::insert (int key)
{
	int mod=key%hashtable.size();
	bool success=hashtable[mod].insert_list(key);
	if(success==0)
	{
		cout<<"failure";
	}
	else
	{
		cout<<"success";
	}
		
}
//delete using erase_list function
void HashTable::erase (int key)
{
	int mod=key%hashtable.size();
	bool success=hashtable[mod].erase_list(key);
	if(success==0)
	{
		cout<<"failure";
	}
	else
	{
		cout<<"success";
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
			cout<<"success";
		}
		else if(command=="i")
		{
			int key;
			iss>>key;
			hashtable->insert(key);
		}
		else if(command=="s")
		{
			int key;
			iss>>key;
			hashtable->search(key);
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
