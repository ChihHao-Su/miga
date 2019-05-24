#pragma once
#include "utils.h"
#include "app.h"
#include "baseObj.h"
#include "obj.h"
#include <iostream>
using std::endl;

namespace noname{
class BaseRef : public BaseObj
{
 public:
	BaseRef(Obj &p);
    void onTargetObjDie(Obj &o);

    void set(Obj &o);

	Obj& get() const;

	void clear();

 private:
    Obj *data;
};
}