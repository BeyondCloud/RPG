#include "prompt.h"
#include <algorithm>
#include "utils.h"
#include <cstring>
#include "eventcontroller.h"
#include <curses.h>
#include "json/reader.h"
#include "json/value.h"


using namespace std;

eventController::eventController(std::string eventlist, std::deque< std::vector<void*> >& s) : ctlCallStack(s), userInputRequired(0)
{
	std::string in = get_file_contents(eventlist.c_str());

	Json::Value root;
	Json::Reader reader;
	if (reader.parse( in, root )){
	    event_count = root.get("Count", 0 ).asInt();
	    for(unsigned int i = 0; i < event_count; i++){
	            std::string in2 = get_file_contents(root["Path"][i].asCString());

	            Json::Value root2;
	            Json::Reader reader2;
	            if (reader.parse( in2, root2 )){
	            	event trigger;

	                trigger.stk.resize(root2["Command"].size());
	                for(unsigned int i = 0; i < root2["Command"].size(); i++){
	                    trigger.stk[i] = root2["Command"][i].asString();
	                }

                    std::reverse(trigger.stk.begin(), trigger.stk.end());

	                trigger.trigBy = root2["Name"].asString();

	                trigger.triggerType = root2["triggerType"].asInt();

	                event_list.insert (event_list.begin(), std::pair<std::string, event>(trigger.trigBy, trigger));
	            }else{
	                std::cout << "Failed to parse configuration\n"  << reader.getFormatedErrorMessages();
	                exit(128);
	            }
	    }

	}else{
	    std::cout << "Failed to parse configuration\n"  << reader.getFormatedErrorMessages();
	    exit(128);
	}
}

eventController::~eventController()
{
    //dtor
}

int eventController::processInput(int c){
    if(userInputRequired){
        switch (c) {
            case KEY_LEFT:

                break;
            case KEY_RIGHT:

                break;
            case KEY_UP:

                break;
            case KEY_DOWN:

                break;
            case 'z':
                execTopEvent();
                break;
            case 'x':
                ctlCallStack.push_back(loadStack(1, new int(svc::restoreStat)));
                break;
            case KEY_END:
                ctlCallStack.push_back(loadStack(1, new int(svc::endGame)));
                break;
        }
    }else{
        execTopEvent();
    }
    return 1;
}

void eventController::popEventStack(){
    if(eventStack.size() > 0){
        eventStack.pop_back();
    }
    return;
}

int eventController::execTopEvent(){
    if(eventStack.back().stk.size() == 0){
        ctlCallStack.push_back(loadStack(1, new int(svc::restoreStat)));
        return -1;
    }

    std::vector<std::string> ss = split(eventStack.back().stk.back(), '|');

    int commd = atoi(ss[0].c_str());
    switch(commd){
        case 0:
            /*currBattle = battle(ss[1]);
            currBattle.exec();
            return 0;*/
        case eventCode::showPrompt:
            ctlCallStack.push_back(loadStack(3, new int(svc::loadPrompt), stringToAllocChar(ss[2]), stringToAllocChar(ss[1])));
            userInputRequired = 1;
            break;
        case eventCode::endEvent:
            ctlCallStack.push_back(loadStack(1, new int(svc::clearPrompt)));
            ctlCallStack.push_back(loadStack(1, new int(svc::restoreStat)));
            break;
        case eventCode::transferMap:
            ctlCallStack.push_back(loadStack(4, new int(svc::changeMap), stringToAllocChar(ss[1]), new int(atoi(ss[2].c_str())), new int(atoi(ss[3].c_str()))));
            userInputRequired = 0;
            break;
    }

    eventStack.back().stk.pop_back();
    return 1;
}

int eventController::pushEvent(std::string name){
	eventStack.push_back(event_list[name]);
	userInputRequired = 0;
	return 0;
}
