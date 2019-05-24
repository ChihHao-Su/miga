#include "app.h"
using namespace noname;
using std::cout;
using std::endl;

App::App(string name) {
    this->MGout()<<"[App::CREA]WARN: APP "<<name<<" CRETEING!"<<endl;
    this->setName(name);
}
ObjMan& App::getOMInstance() {
    return this->OM;
}
void App::setName(string name) {
    this->name = name;
}
string App::getName() const {
    return this->name;
}
ostream& App::MGout() const{
	return cout;
}
void App::MGcrash(string msg) const{
	cout<<msg<<endl;

}
App::~App() {
    this->MGout()<<"[App::DEST]WARN: APP"<<name<<" DYING!"<<endl;
}

App &App::get_curr_app(){
    if(App::curr_app == nullptr){
        App::curr_app = new App("DUMMY");
    }

    return *App::curr_app;
}

void App::cut_over_app(App &app){
    App::curr_app->MGcrash("[App::cut_over_app]CRASH: THIS FUNCTION IS DISCARDED!");

    //if not inited
    /*
    if(App::curr_app != nullptr){
        for(auto [k, e] : App::curr_app->OM.objPool){
            app.getOMInstance().regObj(*e);
            App::curr_app->name = app.getName();
        }

        delete App::curr_app;
    }
    
    App::curr_app = &app;
    */
}

