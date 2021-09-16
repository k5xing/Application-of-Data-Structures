#include<iostream>

using namespace std;
 
#include "undirectedGraph.h"

Citylist::Citylist()
{
	degree=0;
	cityhead=NULL;
}
Citylist::~Citylist()
{
	degree=-1;
	cityhead=NULL;
}
Citynode* Citylist::searchcity(string name)
{
	Citynode* tmp=cityhead;
	while(tmp!=NULL && tmp->name!=name)
	{
		tmp=tmp->citynext;
	}
	return tmp;
}
void Citylist::insertcity(string name,double distance)
{
	Citynode* newnode=new Citynode();
	newnode->name=name;
	newnode->distance=distance;
	if(cityhead==NULL)
	{
		cityhead=newnode;
		newnode->citynext=NULL;
	}
	else
	{
		Citynode* tmp=cityhead;
		while(tmp->citynext!=NULL)
		{
			tmp=tmp->citynext;
		}
		tmp->citynext=newnode;
		newnode->citynext=NULL;
		degree++;
	}
		
}

Graph::Graph()
{
	node_num=0;
	edge_num=0;
	graphhead=NULL;
}
Graph::~Graph()
{
	node_num=-1;
	edge_num=-1;
	graphhead=NULL;
}

Graphnode* Graph::searchgraph(string name)
{
	Graphnode* tmp=graphhead;
	while(tmp!=NULL && tmp->citylist.cityhead->name!=name)
	{
		tmp=tmp->graphnext;
	}
	return tmp;
}

bool Graph::insertgraph(string name)
{
	Graphnode* exist=searchgraph(name);
	if(exist!=NULL)
	{
		cout<<"failure";
		cout<<endl;
		return 0;
	}
	Citylist list;
	list.insertcity(name,0);
	Graphnode* newnode=new Graphnode();
	newnode->citylist=list;
	if(graphhead==NULL)
	{
		graphhead=newnode;
		newnode->graphnext=NULL;
	}
	else
	{
		Graphnode* tmp=graphhead;
		while(tmp->graphnext!=NULL)
			tmp=tmp->graphnext;
		
		tmp->graphnext=newnode;
		newnode->graphnext=NULL;
	}
	node_num++;
	cout<<"success";
	cout<<endl;
	return 1;
}

bool Graph::setedge(string name1,string name2,double distance)
{
	Graphnode* city1=searchgraph(name1);
	Graphnode* city2=searchgraph(name2);
	if(city1==NULL||city2==NULL||name1==name2)
	{
		cout<<"failure";
		cout<<endl;
		return 0;
	}
	Citynode* exist=city1->citylist.searchcity(name2);
	if(exist!=NULL)
	{
		Citynode* exist2=city2->citylist.searchcity(name1);
		exist->distance=distance;
		exist2->distance=distance;
		cout<<"success";
		cout<<endl;
		return 1;
	}
	city1->citylist.insertcity(name2,distance);
	city2->citylist.insertcity(name1,distance);
	edge_num++;
	cout<<"success";
	cout<<endl;
	return 1;
}
int Graph::degree(string name)
{
	Graphnode* exist=searchgraph(name);
	if(exist==NULL)
		return -1;
	else
		return exist->citylist.degree;
}
double Graph::adjdistance(string name1, string name2)
{
	Graphnode* city1=searchgraph(name1);
	Graphnode* city2=searchgraph(name2);
	if(city1==NULL||city2==NULL)
	{
		return -1;
	}
	Citynode* exist=city1->citylist.searchcity(name2);
	if(exist==NULL)
	{
		return -1;
	}
	return exist->distance;
}
void Graph::clear()
{
	Graphnode* tmp=graphhead;
	Graphnode* prev=graphhead;
	while(tmp!=NULL)
	{
		prev=tmp;
		tmp=tmp->graphnext;
		delete prev;
	}
	node_num=0;
	edge_num=0;
	graphhead=NULL;
}
string Graph::min()
{
	double m=2147483647;
	string name="none";
	Graphnode* tmp=graphhead;
	while(tmp!=NULL)
	{
		if(tmp->shortd<m && tmp->visited==0)
		{
			m=tmp->shortd;
			name=tmp->citylist.cityhead->name;
			//cout<<name<<endl;
		}
		tmp=tmp->graphnext;
	}
	return name;
}
void Graph::relax(Graphnode* city1, Graphnode* city2)
{
	Citynode* exist=new Citynode();
	exist=city1->citylist.searchcity(city2->citylist.cityhead->name);
	if(exist==NULL || exist->visitedcity==1)
		return;
	double d=exist->distance;
	if(city2->shortd > city1->shortd+d)
	{
		city2->shortd=city1->shortd+d;
		city2->parent=city1;
	}
}

double Graph::shortdistance(string name1,string name2)
{

	Graphnode* city1=searchgraph(name1);
	Graphnode* city2=searchgraph(name2);
	if(city1==NULL||city2==NULL)
	{
		return -1;
	}
	
	Graphnode* tmp=graphhead;
	while(tmp!=NULL)
	{
		tmp->parent=NULL;
		tmp->visited=0;
		tmp->shortd=2147483647;
		Citynode* tmpcity=tmp->citylist.cityhead;
		while(tmpcity!=NULL)
		{
			tmpcity->visitedcity=0;
			tmpcity=tmpcity->citynext;
		}
		tmp=tmp->graphnext;
	}
	
	
	city1->shortd=0;
	int i=0;
	while(city2->visited==0 && min()!="none")
	{
		string min_d=min();
		Graphnode* minc=new Graphnode();
		minc=searchgraph(min_d);
		if(minc!=NULL)
			minc->visited=1;
		tmp=graphhead;
		
		while(tmp!=NULL)
		{
			Citynode* search=new Citynode();
			search=tmp->citylist.searchcity(min_d);
			if(search!=NULL)
				search->visitedcity=1;
			tmp=tmp->graphnext;
		}
		
		tmp=graphhead;
		while(tmp!=NULL )
		{
			relax(minc,tmp);
			tmp=tmp->graphnext;
		}
		
		i++;
		
	}
	
	return city2->shortd;
		
}
void Graph::print(string name1,string name2)
{
	Graphnode* tmp=graphhead;
	while(tmp!=NULL)
	{
		tmp->child=NULL;
		tmp=tmp->graphnext;
	}
	double d=shortdistance(name1,name2);
	if(d==-1||d==2147483647)
	{
		cout<<"failure";
		cout<<endl;
		return;
	}
	
	Graphnode* pres=new Graphnode();
	Graphnode* prev=new Graphnode();
	prev=searchgraph(name2);
	pres=prev->parent;
	pres->child=prev;
	while(pres!=NULL)
	{
		pres->child=prev;
		prev=pres;
		pres=pres->parent;
	}
	while(prev!=NULL)
	{
		cout<<prev->citylist.cityhead->name<<" ";
		prev=prev->child;
	}
		
		
}