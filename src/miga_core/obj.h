#pragma once
#include <string>
#include "baseObj.h"
#include "utils.h"
using std::string;
using noname::BaseObj;

namespace noname{
class BaseRef;
class App;
class Obj : public BaseObj
{
public:
    Obj();
    virtual const string getClassName() const override;
    virtual void onMessage(const string msg, const vector<BaseObj *> par) override;
    void retain(BaseRef &r);
    void release(BaseRef &r);

    //void setAutoRelease();
    //void unsetAutoRelease();
    void setNick(const string s);
    const string getNick() const;
    const int getId() const;

    virtual ~Obj();


private:
    vector<BaseRef *> refList;
    string nick;
    //bool isAutoRelease;
    int ID;


deleted:
    Obj(const Obj &) = delete;
    Obj(Obj &&) = delete;
    
};
}
