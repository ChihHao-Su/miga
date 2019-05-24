#include "objMan.h"
#include "utils.h"
#include "app.h"
#include "excp/unImplExcp.h"
#include "excp/eleNotFound.h"
#include <iostream>

using namespace noname;
using std::endl;
using std::find;

ObjMan::ObjMan(){
    App::get_curr_app().MGout()<<"WARN: ObjMan CREATING!"<<endl;
}
const Obj& ObjMan::getObj(const int ID){
    if(auto it = this->objPool.find(ID); it == this->objPool.end()){
        throw eleNotFound("Obj ID " + ID + " not found!");
    }
}
int ObjMan::regObj(Obj& obj){
    this->objPool.insert({this->next_ID, &obj});
    this->next_ID ++;

	return this->next_ID -1;
}
void ObjMan::delObj(const int ID){
    /* if(this->objPool.count(ID) == 0) {
        App::MGcrash()<<"THIS SHOULD NOT HAPPEN--Cannot del- ID"<<ID<<" is not in objPool."<<endl;
        }*/
    this->objPool.erase(ID);
    
}
ObjMan::~ObjMan(){
    App::get_curr_app().MGout()<<"WARN: ObjMan DYING!"<<endl;
}
