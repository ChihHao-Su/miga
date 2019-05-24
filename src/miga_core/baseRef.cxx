#include "baseRef.h"
#include "utils.h"

using namespace noname;
BaseRef::BaseRef(Obj &p){
	this->set(p);
}
void BaseRef::onTargetObjDie(Obj &o){
	if(this->data != &o){
		CA.MGcrash()<<"THAT SHOULD NOT HAPPED- o is not refed obj!"<<endl;
	}
	this->data = nullptr;
}
void BaseRef::set(Obj& o){
	if(&o == nullptr){
		CA.MGcrash()<<"THAT SHOULD NOT HAPPED- Cannot set a nullptr!"<<endl;
	}

	if(this->data != nullptr){
		this->data->release(*this);
	}
	o.retain(*this);
}
Obj& BaseRef::get() const{
	return *this->data;
}

void BaseRef::clear(){
	if(this->data != nullptr){
   		this->data->release(*this);
   	}
	this->data = nullptr;
}


