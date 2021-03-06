#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>
#include "inventory.h"
#include "team.h"
#include "monsterfactory.h"
#include "render.h"
#include "genericcontorller.h"
#include "team.h"
#include "render.h"

class Engine;

class Battle : public genericContorller
{
    public:
        Battle(Engine*, std::map< std::string, variant<paraVarType> >*);
        Battle(std::string monsterList, Engine*, std::map< std::string, variant<paraVarType> >*);
        ~Battle();

        int hKeyUp();
        int hKeyDown();
        int hKeyLeft();
        int hKeyRight();
        int hKeyZ();
        int hKeyX();

        int hDoEvent();

        int hRender(render&);

        int loadBattle(Team* t, std::vector<std::string>& monsters, int chance = 0);

        std::vector<Monster>& getMonsters() { return _monsters; };

        enum process{
            prePlayer = 0,
            BattleMenu,
            MonsterMenu,
            PlayerNormalAttack,
            skillMonsterMenu,
            PlayerSkill,
            PostPlayer,
            MonsterTurn,
            PostBattle,
        };
    protected:
    private:
        std::map< std::string, variant<paraVarType> >* varMap;

        MonsterFactory _monsterCache;
        std::vector<Monster> _monsters;
        std::vector<Monster> _monstersBak;
        unsigned int _memberCount = 0;
        int _chance = 0;

        Team* team;
        unsigned int _currentChara = 0;

        std::vector<int> charaAttackBuff;
        std::vector<int> charaDefenseBuff;

        int processStat;

        unsigned int battleMenuCurrentPos = 0;
        unsigned int MonsterMenuCurrentPos = 0;

        bool isMonsterWipeOut();
        void calculateExp();
};

#endif // BATTLE_H
