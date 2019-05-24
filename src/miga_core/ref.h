#include "app.h"
#include "baseRef.h"
#include <type_traits>
using std::is_base_of;
using std::is_same;

namespace noname{
template <class T>
class Ref : public BaseRef
{
 public:
    Ref(const T& obj){
		if(&obj != nullptr){
			this->set(obj);
		}else{
			CA.MGout()<<"WARN: You put an nullptr-obj-ref, that maybe a wrong."<<endl;
			this->clear();
		}
	}
	Ref(const nullptr_t nptr){
		this->clear();
	}

    template <class U>
	Ref(const Ref<U>& ref){
        static_assert(is_base_of<T, U>::value || is_same<T, U>::value, "U is not base of T, and U is not same as T.");
		this->set(ref.get());
    } 
		
	Ref& operator =(const Ref<T>& ref){
		if(&ref.get() != nullptr){
			this->set(ref.get());
		}else{
			CA.MGout()<<"WARN: You put an nullptr-obj-ref, that maybe a wrong."<<endl;
       		this->clear();
		}
	}
	Ref& operator =(const nullptr_t nptr){
		this->clear();
	}

    T* operator ->(){
        return this->get();
    }
	
};
}
