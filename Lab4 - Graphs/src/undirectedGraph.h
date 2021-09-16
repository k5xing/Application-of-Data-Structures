#include<iostream>
using namespace std;
 
struct Citynode
{
	bool visitedcity;
	string name;
	double distance;
	Citynode* citynext;
};
 

class Citylist
{
	public:
	int degree;
	Citynode* cityhead;
	Citylist();
	~Citylist();
	void insertcity(string name,double distance);
	Citynode* searchcity(string name);
};
 

struct Graphnode
{
	double shortd;
	bool visited;
	Citylist citylist;
	Graphnode* parent;
	Graphnode* child;
	Graphnode* graphnext;
	
};
class Graph
{
	public:
	int node_num;
	int edge_num;
	Graphnode* graphhead;
	Graph();
	~Graph();
	Graphnode* searchgraph(string name);
	bool insertgraph(string name);
	bool setedge(string name1,string name2,double distance);
	int degree(string name);
	double adjdistance(string name1, string name2);
	void clear();
	double shortdistance(string name1,string name2);
	void print(string name1,string name2);
	string min();
	void relax(Graphnode* city1, Graphnode* city2);
};


