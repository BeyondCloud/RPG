#ifndef RENDER_H
#define RENDER_H

#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "point.h"
#include "mapobject.h"
#include "inventory.h"
#include "team.h"
#include "character.h"
#include "monster.h"
#include "texture.h"

class prompt;
class mapObject;
class gmap;

class render
{
    public:
        render();
        render(std::string);
        ~render();

        void render_map(gmap, mapObject);
        void render_prompt(prompt& P);

        void render_MainMenu(int curPos, std::vector<std::string> options);
        void render_TeamMenu(Team&, unsigned int curPos);
        void render_InvMenu(inventory& inv, int curPos);
        void render_CharMenu(Character& chara, int curPos);
        void render_SkillMenu(Character& chara, int curPos);

        void render_BattleScene(std::vector<Monster> m, int tag = -1);
        void render_BattleTeam(Team& team, unsigned int turn);
        void render_BattleMenu(unsigned int curPos);

        void render_VenderMenu(int curPos, std::vector<std::string> options);

        void render_StartMenu(int curPos, std::vector<std::string> options);
        void render_gameOver();
        void render_HelpMenu();

        void update();
    protected:
    private:
        int WINDOW_SIZE_X;
        int WINDOW_SIZE_Y;
        int TILE_SIZE;

        std::string FONT_NAME_COMIC;
        std::string FONT_NAME_ARIAL;

        SDL_Window *win = NULL;
        SDL_Renderer *ren = NULL;

        TTF_Font* font_arial16 = NULL;
        TTF_Font* font_comic16 = NULL;
        TTF_Font* font_comic32 = NULL;
        TTF_Font* font_comic50 = NULL;

        std::string BATTLEBACKGROUND;

        std::string FRAME;
        std::string FRAME_SIDE;
        std::string FRAME_TITLE;
        std::string CHAR_MENU;
        std::string CHAR_MENU_SELECTED;
        std::string PROMPT;
        std::string BATTLEMENU;

        Texture texture;

        int getmaxx() { return WINDOW_SIZE_X; };
        int getmaxy() { return WINDOW_SIZE_Y; };

        void clear();

        int _currX = 0;
        int _currY = 0;

        void mvaddstr(int y, int x, const char*);
        void addstr (const char*);
        void mvaddch(int y, int x, char);
        void mvaddch(int y, int x, wchar_t);
        void mvaddwstr(int y, int x, const wchar_t*);
};

#endif // RENDER_H

