#include "factory.h"


std::unique_ptr<way,std::function<void(factory*)>> factory::instance(nullptr,[](factory*){});

std::mutex factory::lock;

void way::theWay2Company()
{
        std::cout<<"you walk to company"<<std::endl;
}

void bike::theWay2Company()
{
    std::cout<<"you ride bike to company"<<std::endl;
}

void driver::theWay2Company()
{
    std::cout<<"you driver a car to company"<<std::endl;
}

void factory::creatInstance(means type)
{
    switch (type)
    {
        case BIKE:
            instance.reset(new bike());
            break;
        case DRIVER:
            instance.reset(new driver());
            break;
        default:
            instance.reset(new way());
            break;
    }

}

way* factory::getInstance(means type)
{
       std::lock_guard(lock);

       return instance.get();
}
