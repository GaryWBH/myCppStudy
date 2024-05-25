/**
 * @file singleton.h
 * @author Gary.WBH (gary.wbh@hotmail.com)
 * @brief 
 * 一、单例模式-选用：
 *  1、call_once
 *  2、未用智能指针管理
 * 二、使用static关键字修饰成员变量和成员函数有几个关键原因：
 *   1、限制访问：
 *   对于单例类内部的私有成员变量（如instance指针和onceFlag），使用static意味着这些变量是类级别的，而不是对象级别的。也就是说，这些变量不属于单例类的任何特定实例，而是属于类本身。
 *   此外，static也确保这些成员只能在类内部访问，不能直接通过类的对象访问，从而符合单例模式的设计要求。
 *   2、确保唯一性：
 *   对于单例模式来说，确保全局只有一个实例是关键。通过将instance指针设为static，我们确保这个指针在类的所有实例之间是共享的。
 *   无论创建多少个Singleton类的对象（尽管在单例模式中我们实际上不会这么做），它们都会访问同一个instance指针。
 *   3、线程安全初始化：
 *   std::once_flag也被声明为static，以确保它同样是类级别的。这个标志用于std::call_once函数，该函数确保关联的初始化函数（如createInstance）只被调用一次，
 *   即使多个线程同时尝试调用getInstance方法。static确保onceFlag在所有线程之间是共享的，从而确保线程安全的单例初始化。
 *   4、无需实例即可访问：
 *   将获取单例的getInstance方法和创建单例的createInstance方法设为static意味着这些方法属于类本身，而不是类的任何特定实例。
 *   这样，我们可以在没有创建类的实例的情况下调用这些方法，这是单例模式的一个关键要求。
 * 
 *   综上所述，static修饰的意义是，让这些修饰的变量对于类来讲是唯一的，而不是每个实例都会有一个对应的变量。
 * @version 1.0
 * @date 2024-05-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <mutex>
#include <string>

class singleton
{
    private:
        singleton(){};
        ~singleton(){};
        static singleton* instance;
        static std::once_flag onceFlag;

        //make wrong:static singleton* createInstance();
        static void createInstance();

        void deleteSingleton()
        {
            if(instance)
            {
                delete instance;
                instance = nullptr;
            }
        }

    public:
        static singleton* getInstance();
        void mySingleton(std::string);

};
#endif //SINGLETON_H