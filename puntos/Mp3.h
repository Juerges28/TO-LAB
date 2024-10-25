#ifndef MP3_H
#define MP3_H

#include <vector>
#include <string>

class MP3 {
private:
    std::vector<std::string> songList;
    int currentSong;

public:
    MP3();
    std::string play() const;
    std::string stop() const;
    std::string nextSong();
    std::string previousSong();
};

#endif // MP3_H