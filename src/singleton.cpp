/**
 * @file singleton.cpp
 * @author Gary.WBH (gary.wbh@hotmail.com)
 * @brief 
 * 单例模式
 * @version 1.0
 * @date 2024-05-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "singleton.h"

/**
 * @brief 
 * 古老指针方式实现的单例 
 */
singleton* singleton::instance = nullptr;

std::once_flag singleton::onceFlag;

void singleton::createInstance()
{
    instance = new singleton();
    return ;
}

singleton* singleton::getInstance()
{
    std::call_once(onceFlag,&singleton::createInstance);
    return instance;
}

void singleton::mySingleton(std::string src)
{
    std::cout<<src<<std::endl;
}



/**
 * @brief 
 * 一个更加现代的使用smart ptr的单例例子
 */
std::unique_ptr<singleton_sm, std::function<void(singleton_sm*)>> singleton_sm::instance(nullptr,[](singleton_sm*)
{
    //删除器，但不操作删除，单例不能在生命周期外删除指针
    std::cout<<"delete unique ptr"<<std::endl;
    //unqiue这个东西最后会调用类之析构，但我们析构是私有，因此会出问题，需要自己写一个删除器防止调用到私有析构函数
}
);

std::once_flag singleton_sm::onceFlag;

void singleton_sm::createInstance()
{
    instance.reset(new singleton_sm());
}
singleton_sm* singleton_sm::getInstance()
{
    std::call_once(onceFlag,&singleton_sm::createInstance);
    return instance.get();
}
void singleton_sm::mySingleton(std::string src)
{
    std::cout<<"smart-ptr:"<<src<<std::endl;
}