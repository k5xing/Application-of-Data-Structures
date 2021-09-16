#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
	
	private:
	vector<int> hashtable; //create a vector for hashtable
	int current_size;
	
	public: //functions
	
	//constructor and destructor
	HashTable();
	~HashTable();
	
	//functions
	void setsize(int size);
	int search(int key);
	void insert(int key);
	void erase (int key);
	void print ();
};