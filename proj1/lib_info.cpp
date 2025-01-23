#include <iostream>
#include <set>
#include <sstream>

using namespace std;
class Song {
	
	protected:

		string name, time;
		int trackNum;

	public:

		Song(string n, string t, int track)
		{
			name = n;
			time = t;
			trackNum = track;
		}

		string getName() const { return name; }
		string getTime() const { return time; }
		string getTrackNum() const { return trackNum; }
	



};

class Album {
	
	protected:
		
		string name;
		map<int, Song> songs;

	public:

		Album(string n)
		{
			name = n
		}

		string getName() const { return name; }


};

class Artist {

	public:
	
		Artist(string name)
		{
			artistName = name;
		}

	protected:

		string artistName;
		set<Album> Albums;
		

};

int main()
{
nt main() {

	string line;

	string title, time, artist, album, genre, track

	while (getline(cin, line))
	{

			stringstream musicLine(line);
			musicLine >> title >> time >> artist >> album >> genre >> track

return 0;
}
