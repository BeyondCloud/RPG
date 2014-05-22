#ifndef TEAM_H
#define TEAM_H

#include <map>
#include <string>
#include "character.h"
#include "RoleFactory.h"

class Team
{
    public:
        Team(std::string);
        virtual ~Team();

        Character& operator[](std::string subscript) { return _team[subscript]; };
    protected:
    private:

        RoleFactory roleCache;

        std::map<std::string, Character> _team;

        unsigned int _cacheCount;
        std::map<std::string, Character> _cache;
};

#endif // TEAM_H
