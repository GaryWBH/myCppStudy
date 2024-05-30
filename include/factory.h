#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <iostream>
#include <string>
#include <mutex>
#include <memory>
#include <functional>


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
    static std::unique_ptr<factory,std::function<void(factory*)>> instance;
    static void createInstance();
public:
    static factory* getInstance();
    static std::unique_ptr<way> wayInstance;
    way* getWayInstance(means);
    

    factory(const factory&) = delete;
    factory& operator=(const factory&) = delete;
    

};
















#endif