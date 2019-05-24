#include "obj.h"
#include <iostream>
#include <algorithm>
#include "utils.h"
#include "ref.h"
#include "app.h"
using namespace noname;
using std::endl;
using std::find;

Obj::Obj(){
    this->ID = CA.getOMInstance().regObj(*this);
}
const string Obj::getClassName() const{
    return "Obj";
}
void Obj::onMessage(const string msg, const vector<BaseObj *> par){
    CA.MGout()<<"WARN: Obj recevied a msg: "<<msg<<endl;
}
void Obj::retain(BaseRef &r){
    this->refList.push_back(&r);
}
void Obj::release(BaseRef &r){
    auto it = find(this->refList.begin(), this->refList.end(), &r);
    
    if(it == this->refList.end()){
        CA.MGcrash()<<"THIS SHOULD NOT HAPPEN--Cannot release- ref "<<&r<<" is not in refList."<<endl;
    }

    this->refList.erase(it);
    if(this->refList.size() == 0){
        delete this;
    }
}
void Obj::setNick(const string s){
    this->nick = s;
}
const string Obj::getNick() const{
    return this->nick;
}
const int Obj::getId() const{
    return this->ID;
}
Obj::~Obj(){
    for(auto *e : this->refList){
        e->onTargetObjDie(*this);
    }

    CA.getOMInstance().delObj(this->ID);
}
