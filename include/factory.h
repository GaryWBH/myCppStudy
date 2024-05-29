#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <iostream>
#include <string>
#include <mutex>
#include <memory>
#include <functional>

enum means
{
    BIKE,
    DRIVER
};

class way
{
    public:
    virtual void theWay2Company();
    virtual ~way(){};
};

class bike:public way
{
    public:
    void theWay2Company() override;
};

class driver: public way
{
    public:
    void theWay2Company() override;
};

class factory
{
    private:
    factory(){};
    ~factory(){};
    static std::unique_ptr<way,std::function<void(factory*)>> instance;
    static std::mutex lock;
    static void creatInstance(means);

    public:
    static way* getInstance(means);
};














#endif