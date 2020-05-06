#include <stdexcept>
#include <iostream>
#include <vector> 
#include<bits/stdc++.h> 

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        std::vector<std::string> playlist;
        std::vector<std::string>::iterator it; 
        playlist.push_back(this->name);
        for(Song* cur = this->nextSong;cur!=NULL;cur = cur->nextSong){ 
            it = std::find (playlist.begin(), playlist.end(), cur->name); 
            if (it != playlist.end()) 
            { 
                return true;
            } 
            else
                playlist.push_back(cur->name); 
        }
        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif