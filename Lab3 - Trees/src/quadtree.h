#include <iostream>
using namespace std;

struct City{
	string name;
	double x;
	double y;
	int p;
	int r;
	int s;
	
	
};


class Tree {
	public:
	struct TreeNode{
	City city;
	TreeNode* NW;
	TreeNode* NE;
	TreeNode* SW;
	TreeNode* SE;
};
	int size;
	TreeNode* root;
    // class functions
   
	
    Tree();
    ~Tree();
	bool insert(City city,TreeNode* node);
	TreeNode* search(double x, double y,TreeNode* node);
	TreeNode* findnode(TreeNode* node, string d);
	int maximum(TreeNode* node, string attr);
	int minimum(TreeNode* node, string attr);
	int total(TreeNode* node, string attr,int sum);
	void print(TreeNode* node);
	void clear(TreeNode* node);
	int count();
	

};
