#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <stdlib.h>
using namespace std;

#include "quadtree.h"
int main() 
{
	Tree* quadtree=new Tree();
    string line;
	string result;
    while (getline(cin, line)&& !line.empty()) 
	{
		
		size_t pos1;
		while ((pos1 = line.find(";")) != std::string::npos) 
		{
			line.replace(pos1, 1, " ");
         
		}
		const size_t step = 1;

		size_t count(0);
		size_t pos2(0) ;

		while( (pos2=line.find(" ", pos2)) !=std::string::npos) 
		{
			pos2 +=step;
			++count ;
		}
		string input[count+1];
		istringstream iss(line);
		int i=0;
		string inputs;
		while(i<=count)
		{
			iss>>inputs;
			input[i]=inputs;
			i++;
			
		}
		
		if(input[0]=="i")
		{
			City newcity;
			newcity.name=input[1];
			newcity.x=stod(input[2]);
			newcity.y=stod(input[3]);
			newcity.p=stoi(input[4]);
			newcity.r=stoi(input[5]);
			newcity.s=stoi(input[6]);
			bool insert_result=quadtree->insert(newcity,quadtree->root);
			if(insert_result==1)
			{
				cout<<"success";
				cout<<endl;
				quadtree->size+=1;
			}
			else
			{
				cout<<"failure";
				cout<<endl;
			}
		}
		else if(input[0]=="s")
		{
			double x=stod(input[1]);
			double y=stod(input[2]);
			Tree::TreeNode* result = quadtree->search(x,y,quadtree->root);
			if(result==NULL)
			{
				cout<<"not found";
				cout<<endl;
			}
			
			else
			{
				cout<<"found "<<result->city.name;
				cout<<endl;
			}
		}
		else if(input[0]=="print")
		{
			quadtree->print(quadtree->root);
			cout<<endl;
		}
		else if(input[0]=="size")
		{
			cout<<"tree size "<<quadtree->count();
			cout<<endl;
		}
		else if(input[0]=="clear")
		{
			quadtree->clear(quadtree->root);
			quadtree->size=0;
			quadtree->root=NULL;
			cout<<"success";
			cout<<endl;
		}
		else if(input[0]=="q_max")
		{
			double x=stod(input[1]);
			double y=stod(input[2]);
			string d=input[3];
			string attr=input[4];
			Tree::TreeNode* result = quadtree->search(x,y,quadtree->root);
			if(result==NULL)
			{
				cout<<"failure";
				cout<<endl;
			}
			else
			{
				Tree::TreeNode* foundnode=quadtree->findnode(result,d);
				if(foundnode==NULL)
				{
					cout<<"failure";
					cout<<endl;
				}
				else
				{
					cout<<"max "<<quadtree->maximum(foundnode,attr);
					cout<<endl;
				}
			}
		}
		else if(input[0]=="q_min")
		{
			double x=stod(input[1]);
			double y=stod(input[2]);
			string d=input[3];
			string attr=input[4];
			Tree::TreeNode* result = quadtree->search(x,y,quadtree->root);
			if(result==NULL)
			{
				cout<<"failure";
				cout<<endl;
			}
			else
			{
				Tree::TreeNode* foundnode=quadtree->findnode(result,d);
				if(foundnode==NULL)
				{
					cout<<"failure";
					cout<<endl;
				}
				else
				{
					cout<<"min "<<quadtree->minimum(foundnode,attr);
					cout<<endl;
				}
			}
		}
		else if(input[0]=="q_total")
		{
			double x=stod(input[1]);
			double y=stod(input[2]);
			string d=input[3];
			string attr=input[4];
			Tree::TreeNode* result = quadtree->search(x,y,quadtree->root);
			if(result==NULL)
			{
				cout<<"failure";
				cout<<endl;
			}
			else
			{
				Tree::TreeNode* foundnode=quadtree->findnode(result,d);
				if(foundnode==NULL)
				{
					cout<<"failure";
					cout<<endl;
				}
				else
				{
					cout<<"total "<<quadtree->total(foundnode,attr,0);
					cout<<endl;
				}
			}
		}
		else
			cout<<endl;
	}
}
