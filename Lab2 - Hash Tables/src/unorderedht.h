#include <iostream>
#include <vector>
using namespace std;

class HashList 
{
	private:
	//struct of HashNode to represent keys
	struct HashNode
	{
		int key;
		HashNode* next;
	};
	HashNode* head;
	HashNode* back;
	
	public: 
	//constructor and destructor
	HashList();
	~HashList();
	//functions
	bool insert_list(int key);
	bool search_list(int key);
	bool erase_list(int key);
};
class HashTable
{
	
	private:
	vector<HashList> hashtable; //create a vector for hashtable
	
	public: 
	//constructor and destructor
	HashTable();
	~HashTable();
	//functions
	void setsize(int input_size);
	void search(int key);
	void insert(int key);
	void erase (int key);
};
