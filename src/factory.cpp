#include "factory.h"


// 初始化静态成员变量
std::unique_ptr<factory, std::function<void(factory*)>> factory::instance(nullptr, [](factory* ptr)
{
   std::cout<<"delete ptr"<<std::endl;
});
std::unique_ptr<way> factory::wayInstance(nullptr);
std::once_flag factory::onceFlag;

std::mutex factory::lock;

void way::theWay2Company()
{
        std::cout<<"you walk to company"<<std::endl;
}

void bike::theWay2Company()
{
    std::cout<<"you ride to company"<<std::endl;
}

void driver::theWay2Company()
{
    std::cout<<"you driver to company"<<std::endl;
}

void factory::createInstance()
{
    instance.reset(new factory());
    return;
}

factory* factory::getInstance()
{
    std::call_once(factory::onceFlag,&factory::createInstance);
    return instance.get();
    
}

way* factory::getWayInstance(means type)
{
        std::lock_guard<std::mutex> lock_guard(factory::lock);
       
        switch (type) 
        {
            case BIKE:
                wayInstance = std::make_unique<bike>();
                break;
            case DRIVER:
                wayInstance = std::make_unique<driver>();
                break;
            default:
                wayInstance = std::make_unique<way>();
                break;
        }
        
        return wayInstance.get();
}