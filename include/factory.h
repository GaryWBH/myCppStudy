#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "common.h"

// 枚举表示方式
enum means {
    DEFAULT,
    BIKE,
    DRIVER
};

// 基类way
class way {
public:
    virtual void theWay2Company();
    virtual ~way() {}
};

// 派生类bike
class bike : public way {
public:
    void theWay2Company() override ;
};

// 派生类driver
class driver : public way {
public:
    void theWay2Company() override ;
};

// 工厂类
class factory 
{
private:
    factory() {}
    ~factory() {}
private:    
    static std::once_flag onceFlag;
    static std::mutex lock;
    //工厂类保证单例即可
    static std::unique_ptr<factory,std::function<void(factory*)>> instance;
    static void createInstance();
public:
    static factory* getInstance();
    static std::unique_ptr<way> wayInstance;
    way* getWayInstance(means);
    
    //删除拷贝构造，表示factory类没有拷贝构造函数，你不能创建这个类的一个对象，并将其拷贝给另一个同类型的对象。这通常是为了确保factory类的对象不能被复制
    factory(const factory&) = delete;
    //删除拷贝运算符‘=’，意味着 factory 类没有拷贝赋值运算符，你不能将一个 factory 对象的状态赋值给另一个 factory 对象。这通常是为了防止对象被不当地赋值
    factory& operator=(const factory&) = delete;
    

};
















#endif