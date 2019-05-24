#pragma once
#define DCL_EXCP(name) \
    class name : public IThrowAble, exception \
    { \
    public: \
        name(string msg); \
        const string getInfo() const noexcept override; \
        const string getName() const noexcept override; \
        const char* what() const noexcept override; \
        \
    private: \
        string msg; \
    };

#define IMP_EXCP(name) \
    name::name(string msg){ \
        this->msg = msg; \
    } \
    const string name::getInfo() const noexcept{ \
        return this->msg; \
    } \
    const string name::getName() const noexcept{ \
        return #name; \
    } \
    const char* name::what() const noexcept{ \
        return this->msg.c_str(); \
    }

