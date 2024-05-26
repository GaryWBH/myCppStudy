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
/*回顾错误：
*将智能指针初始化写为了如下的样子：
    std::unique_ptr<singleton,std::function<singleton*()>> singleton::instance = std::make_unique(singleton,[]
    {
        std::cout<<"delete ptr"<<std::endl;
    });
*问题1.std::function使用错误，没有理解这个东西的函数创建意义，他的内部是一个完整的函数结构： <函数返回值(入参)> 我的自定义删除器需要一个无返回值类型的入参为singleton*的函数，而不是一个singleton*返回值，没有入参的函数
*问题2.混淆了初始化的意思，全局初始化时只是将它给一个初值，防止野内存，同时初始化一个删除器函数，而非直接创建这个指针
*问题3.lambda表达式使用错误，lambda表达式有多种表达形式，目前使用的是：有参数，无捕获，无返回值：[](int n)｛n++;｝
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