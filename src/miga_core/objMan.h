#pragma once
#include <string>
#include <map>
#include "obj.h"
using noname::Obj;
using std::map;

#define OM_NEW(type, ...) \
    new type(__VA_ARGS__)

namespace noname{
class ObjMan
{
public:
    ObjMan();
    friend class Obj;
	friend class App;
    const Obj& getObj(const int ID);
    ~ObjMan();

    /*template<class T, class... Args>
    T *create(Args&&... args){
        using T_nc = remove_const<T>::type;
        return new T_nc(forward<Args>(args) ...);
    }

    template<class T, class InitListType>
    T *create(initializer_list<InitListType>&& arg){
        using T_nc = remove_const<T>::type;
        return new T_nc(arg);
    }*/

    
private:
    string nick;
    int regObj(Obj& obj);//returns ID, User cannot call
    void delObj(const int ID);//User cannot call

    map<int, Obj *> objPool;
    int next_ID;

};
}
