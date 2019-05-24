#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;

namespace noname{
class BaseObj
{
public:
    BaseObj();
    virtual const string getClassName() const;
    virtual void onMessage(const string msg, const vector<BaseObj *> par);
    static void sendMessage(BaseObj &o,const string msg, const vector<BaseObj *> par);
    virtual ~BaseObj();
};
}
