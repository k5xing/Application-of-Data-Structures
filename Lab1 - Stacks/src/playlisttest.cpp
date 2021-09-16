#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <vector>
using namespace std;


#include "Playlist.h"
bool Playlist::search(string title, string artist)
{
	int i=0;
	int size=playlist.size();//get the size of the playlist
	while(i<size)
	{
		//check whether the song is already in the playlist
		if(playlist[i].title==title && playlist[i].artist==artist)
			return 1;
		i++;
	}
	return 0;
	
}

void Playlist::newsong(string title, string artist)
{
	bool exist= search(title,artist); //avoid the same song be inserted multiple times
	if(exist==1)
	{
		cout<<"can not insert "<<title<<";"<<artist;
	}
	else
	{
		//create a new song and insert
		Song song; 
		song.title=title;
		song.artist=artist;
		playlist.push_back(song);
		cout<<"success";
	}
	
}

void Playlist::play(int position)
{
	int size=playlist.size();//get the size of the playlist
	
	if(position>size ||position<1 ) //check illegal parameters 
	{
		cout<<"could not play "<<position;
	}
		
	else
	{
		cout<<"played "<<position<<" "<<playlist[position-1].title<<";"<<playlist[position-1].artist;
	}
}

void Playlist::erase(int position)
{
	int size=playlist.size(); //get the size of the playlist
	
	if(position>size ||position<1 ) //check illegal parameters 
	{
		cout<<"could not erase "<<position;
	}
	else
	{
		cout<<"success";
		playlist.erase(playlist.begin()+position-1); //erase the song
	}
	
}
int main() 
{
	Playlist playlist;
    string line;
    while (getline(cin, line)&& !line.empty()) 
	{
     
		istringstream iss(line);
		string command;
		string position;
		iss>>command; //get the required command 
		
		
		if(command=="i")
		{
			//use substring to get title and artist of the song separately
			size_t found = line.find(";"); 
			int semi;
			if(found != string::npos) 
			{
				semi=found;
			}
			string title=line.substr(2,semi-2);
			string artist=line.substr(semi+1);
			//insert new song
			playlist.newsong(title,artist);
		}
		else if(command=="p")
		{
			//get the position and play the song
			iss>>position;
			playlist.play(stoi(position));
		}
		else if(command=="e")
		{
			//get the position and erase the song
			iss>>position;
			playlist.erase(stoi(position));
		}
		else
		{	//illegal commands
			cout<<endl;
		}
		cout<<endl;
	}
}