#pragma once
#include <string>
#include <iostream>
#include "objMan.h"
using std::string;
using std::ostream;

namespace noname{
class App
{
private:
    ObjMan OM;
    string name;

    static App *curr_app;

public:
    App(string name);
    ~App();
    
    void setName(string name);
    string getName() const;
    ObjMan& getOMInstance();

	ostream& MGout() const;
	void MGcrash(string msg) const;	

    static App &get_curr_app();
	static void cut_over_app(App &app);

};
}
