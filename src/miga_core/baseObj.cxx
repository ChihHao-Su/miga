#include "baseObj.h"
using namespace noname;

BaseObj::BaseObj() {

}
const string BaseObj::getClassName() const {
    return "BaseObj";
};
void BaseObj::onMessage(const string msg, const vector<BaseObj *> par) {

}
void BaseObj::sendMessage(BaseObj &o,const string msg, const vector<BaseObj *> par) {
    o.onMessage(msg, par);
}
BaseObj::~BaseObj() {

}


