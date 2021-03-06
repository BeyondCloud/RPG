#ifndef TEAMMENU_H
#define TEAMMENU_H

#include "menu.h"
#include "team.h"
#include "render.h"

class Engine;

class TeamMenu : public Menu
{
    public:
        TeamMenu(Engine*, std::map< std::string, variant<paraVarType> >&);
        virtual ~TeamMenu();

        int hKeyUp();
        int hKeyDown();
        int hKeyZ();
        int hKeyX();
        int hKeyQ();

        int hRender(render&);

        void init(int m, Team* t);
    protected:
    private:
        unsigned int currentPos;
        unsigned int _limiter;
        unsigned int mode;
        Team* team;
};

#endif // TEAMMENU_H
