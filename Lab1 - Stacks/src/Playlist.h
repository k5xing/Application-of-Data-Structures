#include <iostream>
#include <vector>
using namespace std;

class Song
{
	public:
	string title;
	string artist;
};

class Playlist
{
	
	private:
	vector<Song> playlist; //create a vector for playlist
	
	public: //functions
	
	bool search(string title, string artist);
	void newsong(string title, string artist);
	void play(int position);
	void erase(int position);
};