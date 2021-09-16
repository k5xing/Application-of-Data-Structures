#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <vector>
using namespace std;

#include "quadtree.h"

Tree::Tree()
{
	size=0;
	root=NULL;
}

Tree::~Tree()
{
	size=-1;
	root=NULL;
}

bool Tree::insert(City city,TreeNode* node)
{
	TreeNode* search_result=search(city.x,city.y,node);
	if(search_result!=NULL)
	{
		return 0;
	}
	else
	{
		if(root==NULL)
		{
			TreeNode* newnode=new TreeNode();
			newnode->city=city;
			newnode->NE=NULL;
			newnode->NW=NULL;
			newnode->SE=NULL;
			newnode->SW=NULL;
			root=newnode;
		}
		else
		{
			if(city.x>=node->city.x && city.y>node->city.y)
			{
				if(node->NE!=NULL)
					insert(city,node->NE);
				else
				{
					TreeNode* newnode=new TreeNode();
					newnode->city=city;
					newnode->NE=NULL;
					newnode->NW=NULL;
					newnode->SE=NULL;
					newnode->SW=NULL;
					node->NE=newnode;
					return 1;
				}
			}
			else if(city.x<node->city.x && city.y>=node->city.y)
			{
				if(node->NW!=NULL)
					insert(city,node->NW);
				else
				{
					TreeNode* newnode=new TreeNode();
					newnode->city=city;
					newnode->NE=NULL;
					newnode->NW=NULL;
					newnode->SE=NULL;
					newnode->SW=NULL;
					node->NW=newnode;
					return 1;
				}
			}
			else if(city.x<=node->city.x && city.y<node->city.y)
			{
				if(node->SW!=NULL)
					insert(city,node->SW);
				else
				{
					TreeNode* newnode=new TreeNode();
					newnode->city=city;
					newnode->NE=NULL;
					newnode->NW=NULL;
					newnode->SE=NULL;
					newnode->SW=NULL;
					node->SW=newnode;
					return 1;
				}
			}
			else if(city.x>node->city.x && city.y<=node->city.y)
			{
				if(node->SE!=NULL)
					insert(city,node->SE);
				else
				{
					TreeNode* newnode=new TreeNode();
					newnode->city=city;
					newnode->NE=NULL;
					newnode->NW=NULL;
					newnode->SE=NULL;
					newnode->SW=NULL;
					node->SE=newnode;
					return 1;
				}
			}
		}
	}
}
Tree::TreeNode* Tree::search(double x, double y,TreeNode* node)
{
	if(node==NULL)
		return NULL;
	else
	{
		if(node->city.x==x && node->city.y==y)
			return node;
		else if(x>=node->city.x && y>node->city.y)
			return search(x,y,node->NE);
		else if(x<node->city.x && y>=node->city.y)
			return search(x,y,node->NW);
		else if(x<=node->city.x && y<node->city.y)
			return search(x,y,node->SW);
		else if(x>node->city.x && y<=node->city.y)
			return search(x,y,node->SE);
	}
}
Tree::TreeNode* Tree::findnode(TreeNode* node, string d)
{
	if(d=="NE")
	{
		if(node->NE!=NULL)
			return node->NE;
		else 
			return NULL;
	}
	else if(d=="NW")
	{
		if(node->NW!=NULL)
			return node->NW;
		else 
			return NULL;
	}
	else if(d=="SW")
	{
		if(node->SW!=NULL)
			return node->SW;
		else 
			return NULL;
	}
	else if(d=="SE")
	{
		if(node->SE!=NULL)
			return node->SE;
		else 
			return NULL;
	}
	else
		return NULL;
}
int Tree::maximum(TreeNode* node, string attr)
{
	if(attr=="p")
	{
		if(node==NULL)
			return -1;
		int rootvalue=node->city.p;
		int NEvalue=maximum(node->NE,attr);
		int NWvalue=maximum(node->NW,attr);
		int SEvalue=maximum(node->SE,attr);
		int SWvalue=maximum(node->SW,attr);
		int max=rootvalue;
		if(NEvalue>max)
			max=NEvalue;
		if(NWvalue>max)
			max=NWvalue;
		if(SEvalue>max)
			max=SEvalue;
		if(SWvalue>max)
			max=SWvalue;
			
		return max;
	}
	else if(attr=="r")
	{
		if(node==NULL)
			return -1;
		int rootvalue=node->city.r;
		int NEvalue=maximum(node->NE,attr);
		int NWvalue=maximum(node->NW,attr);
		int SEvalue=maximum(node->SE,attr);
		int SWvalue=maximum(node->SW,attr);
		int max=rootvalue;
		if(NEvalue>max)
			max=NEvalue;
		if(NWvalue>max)
			max=NWvalue;
		if(SEvalue>max)
			max=SEvalue;
		if(SWvalue>max)
			max=SWvalue;
			
		return max;
	}
	else if(attr=="s")
	{
		if(node==NULL)
			return -1;
		int rootvalue=node->city.s;
		int NEvalue=maximum(node->NE,attr);
		int NWvalue=maximum(node->NW,attr);
		int SEvalue=maximum(node->SE,attr);
		int SWvalue=maximum(node->SW,attr);
		int max=rootvalue;
		if(NEvalue>max)
			max=NEvalue;
		if(NWvalue>max)
			max=NWvalue;
		if(SEvalue>max)
			max=SEvalue;
		if(SWvalue>max)
			max=SWvalue;
			
		return max;
	}
	else 
		return 0;
}
int Tree::minimum(TreeNode* node, string attr)
{
	if(attr=="p")
	{
		if(node==NULL)
			return 2147483647;
		int rootvalue=node->city.p;
		int NEvalue=minimum(node->NE,attr);
		int NWvalue=minimum(node->NW,attr);
		int SEvalue=minimum(node->SE,attr);
		int SWvalue=minimum(node->SW,attr);
		int min=rootvalue;
		if(NEvalue<min)
			min=NEvalue;
		if(NWvalue<min)
			min=NWvalue;
		if(SEvalue<min)
			min=SEvalue;
		if(SWvalue<min)
			min=SWvalue;
			
		return min;
	}
	else if(attr=="r")
	{
		if(node==NULL)
			return 2147483647;
		int rootvalue=node->city.r;
		int NEvalue=minimum(node->NE,attr);
		int NWvalue=minimum(node->NW,attr);
		int SEvalue=minimum(node->SE,attr);
		int SWvalue=minimum(node->SW,attr);
		int min=rootvalue;
		if(NEvalue<min)
			min=NEvalue;
		if(NWvalue<min)
			min=NWvalue;
		if(SEvalue<min)
			min=SEvalue;
		if(SWvalue<min)
			min=SWvalue;
			
		return min;
	}
	else if(attr=="s")
	{
		if(node==NULL)
			return 2147483647;
		int rootvalue=node->city.s;
		int NEvalue=minimum(node->NE,attr);
		int NWvalue=minimum(node->NW,attr);
		int SEvalue=minimum(node->SE,attr);
		int SWvalue=minimum(node->SW,attr);
		int min=rootvalue;
		if(NEvalue<min)
			min=NEvalue;
		if(NWvalue<min)
			min=NWvalue;
		if(SEvalue<min)
			min=SEvalue;
		if(SWvalue<min)
			min=SWvalue;
			
		return min;
	}
	else 
		return 0;
}
int Tree::total(TreeNode* node, string attr,int sum)
{
	int newsum=sum;
	if(attr=="p")
	{
		if(node==NULL)
			return 0;
		int rootvalue=node->city.p;
		int NEvalue=total(node->NE,attr,newsum);
		int NWvalue=total(node->NW,attr,newsum);
		int SEvalue=total(node->SE,attr,newsum);
		int SWvalue=total(node->SW,attr,newsum);
		newsum+=rootvalue+NEvalue+NWvalue+SEvalue+SWvalue;
			
		return newsum;
	}
	else if(attr=="r")
	{
		if(node==NULL)
			return 0;
		int rootvalue=node->city.r;
		int NEvalue=total(node->NE,attr,newsum);
		int NWvalue=total(node->NW,attr,newsum);
		int SEvalue=total(node->SE,attr,newsum);
		int SWvalue=total(node->SW,attr,newsum);
		newsum+=rootvalue+NEvalue+NWvalue+SEvalue+SWvalue;
			
		return newsum;
	}
	else if(attr=="s")
	{
		if(node==NULL)
			return 0;
		int rootvalue=node->city.s;
		int NEvalue=total(node->NE,attr,newsum);
		int NWvalue=total(node->NW,attr,newsum);
		int SEvalue=total(node->SE,attr,newsum);
		int SWvalue=total(node->SW,attr,newsum);
		newsum+=rootvalue+NEvalue+NWvalue+SEvalue+SWvalue;
			
		return newsum;
	}
	else 
		return 0;
}
void Tree::print(TreeNode* node)
{
	if(node==NULL)
		return;
	print(node->NE);
	print(node->NW);
	cout<<node->city.name<<" ";
	print(node->SW);
	print(node->SE);	
}
void Tree::clear(TreeNode* node)
{
	if(node==NULL)
		return;
	clear(node->NE);
	clear(node->NW);
	clear(node->SE);
	clear(node->SW);
	delete node;
}
int Tree::count()
{
	return size;
}

