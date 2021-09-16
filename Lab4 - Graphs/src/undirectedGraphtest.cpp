#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <stdlib.h>
using namespace std;

#include "undirectedGraph.h"
int main() 
{
	Graph* graph=new Graph();
    string line;
    while (getline(cin, line)&& !line.empty()) 
	{
		
		istringstream iss(line);
		string command;
		iss>>command; 
		
		
		if(command=="i")
		{
			string name=line.substr(2);
			graph->insertgraph(name);
			//cout<<name<<" ";
		}
		else if(command=="setd")
		{
			size_t found = line.find(";"); 
			int semi1;
			int semi2;
			if(found != string::npos) 
			{
				semi1=found;
			}
			found=line.find(";",found+1);
			if(found != string::npos) 
			{
				semi2=found;
			}
			string name1=line.substr(5,semi1-5);
			string name2=line.substr(semi1+1,semi2-semi1-1);
			double distance=stod(line.substr(semi2+1));
			graph->setedge(name1,name2,distance);
		}
		else if(command=="s")
		{
			string name=line.substr(2);
			Graphnode* exist=graph->searchgraph(name);
			if(exist==NULL)
			{
				cout<<"not found";
				cout<<endl;
			}
			else
			{
				cout<<"found "<<exist->citylist.cityhead->name;
				cout<<endl;
			}
		}
		else if(command=="degree")
		{
			string name=line.substr(7);
			int deg=graph->degree(name);
			cout<<"degree of "<<name<<" "<<deg;
			cout<<endl;
		}
		else if(command=="graph_nodes")
		{
			cout<<"number of nodes "<<graph->node_num;
			cout<<endl;
		}
		else if(command=="graph_edges")
		{
			cout<<"number of edges "<<graph->edge_num;
			cout<<endl;
		}
		else if(command=="d")
		{
			size_t found = line.find(";"); 
			int semi;
			if(found != string::npos) 
			{
				semi=found;
			}
			string name1=line.substr(2,semi-2);
			string name2=line.substr(semi+1);
			double d=graph->adjdistance(name1,name2);
			if(d==-1)
			{
				cout<<"failure";
				cout<<endl;
			}
			else
			{
				cout<<"direct distance "<<name1<<" to "<<name2<<" "<<d;
				cout<<endl;
			}
		}
		else if(command=="clear")
		{
			graph->clear();
			cout<<"success";
			cout<<endl;
		}
		else if(command=="shortest_d")
		{
			size_t found = line.find(";"); 
			int semi;
			if(found != string::npos) 
			{
				semi=found;
			}
			string name1=line.substr(11,semi-11);
			string name2=line.substr(semi+1);
			//cout<<name1<<" "<<name2;
			double d=graph->shortdistance(name1,name2);
			if(d==-1||d==2147483647)
				cout<<"failure";
			else
				cout<<"shortest distance "<<name1<<" to "<<name2<<" "<<graph->shortdistance(name1,name2)<<endl;
		}
		else if(command=="print_path")
		{
			size_t found = line.find(";"); 
			int semi;
			if(found != string::npos) 
			{
				semi=found;
			}
			string name1=line.substr(11,semi-11);
			string name2=line.substr(semi+1);
			graph->print(name1,name2);
			cout<<endl;
		}
		else
			cout<<endl;
	}
}