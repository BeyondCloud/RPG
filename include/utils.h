#include <fstream>
#include <string>
#include <cerrno>
#include <vector>
#include <deque>

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

enum Stats{
    pending = 0,
    onMap,
    inEvent,
    menu
};

struct event{
    std::vector<std::string> stk;
    std::string trigBy;
    int triggerType;
};

enum trigType{
    buttonTrig = 1,
    stepOnTrig
};

enum faceing{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
};

enum svc{
    loadEvent = -1,     // EventName
    restoreStat,        //
    setStat,            // stat Number
    loadPrompt,         // data, whom
    clearPrompt,        //
    changeMap,          // mapName, x, y
    waitUserInput,      // Enable?
    endGame = 255       //
};

enum eventCode{
    showPrompt = 1, // whom, data
    endEvent,
    transferMap //  mapName, x, y
};

char* stringToAllocChar(std::string);
void recycleMem(std::deque< std::vector<void*> >);
std::vector<void*> loadStack(unsigned int n, ... );

std::string get_file_contents(const char*);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

#endif // UTILS_H_INCLUDED
