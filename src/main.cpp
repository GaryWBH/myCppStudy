/**
 * @file main.cpp
 * @author Gary.WBH (gary.wbh@hotmail.com)
 * @brief 
 * 
 * 常用设计模式学习
 * 
 * 以下是一些C++中常用的设计模式：
 * √ 1.单例模式 (Singleton Pattern): 当一个类只能创建一个对象，并且提供一个全局访问点来访问这个对象时，可以使用单例模式。这在需要频繁访问或配置某些资源或功能时非常有用，例如日志记录器或配置管理器。
 * 2.工厂模式 (Factory Pattern): 当需要创建一系列相关或依赖对象，而不希望指定具体的类时，可以使用工厂模式。工厂模式通过抽象创建过程来隐藏具体的实现细节，使得代码更加灵活和可扩展。
 * 3.观察者模式 (Observer Pattern): 当一个对象的状态发生改变时，需要通知其他依赖它的对象时，可以使用观察者模式。这种模式实现了发布-订阅机制，使得对象之间可以松耦合地通信。
 * 4.策略模式 (Strategy Pattern): 当有多种算法或行为，并且这些算法或行为可以在运行时动态地改变时，可以使用策略模式。策略模式定义了一系列可以互相替换的算法，使得算法独立于使用它的客户端。
 * 5.状态模式 (State Pattern): 当一个对象的行为取决于它的内部状态时，可以使用状态模式。状态模式将行为封装在不同的状态类中，并通过状态对象来管理这些行为，使得对象在内部状态改变时表现出不同的行为。
 * 6.装饰器模式 (Decorator Pattern): 当需要动态地给一个对象添加一些额外的职责，并且希望这些职责可以被灵活地添加和撤销时，可以使用装饰器模式。装饰器模式通过包装对象来添加功能，而不是通过继承。
 * 7.适配器模式 (Adapter Pattern): 当需要将一个类的接口转换成客户端期望的另一个接口时，可以使用适配器模式。适配器模式使得原本不兼容的类可以一起工作。
 * 8.模板方法模式 (Template Method Pattern): 当一个方法中的某些步骤是固定的，而某些步骤是可变的，并且这些步骤需要在子类中实现时，可以使用模板方法模式。这种模式在算法框架中非常有用，可以确保算法的关键步骤按照预期的顺序执行。
 *
 * @version 1.0
 * @date 2024-05-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include "singleton.h"
#include "factory.h"

/**
 * @brief 
 * 单例模式入口
 */
void singletonMain() 
{
    /**
     * @brief 
     * 单例模式调用
     */
    singleton* sg = singleton::getInstance();
    
    sg->mySingleton("hello my singleton-240525");

    auto sgm = singleton_sm::getInstance();
    sgm->mySingleton("hello my singleton-2405256"); 

    return ;
}

/**
 * @brief 
 * lambdaMain学习
 */
void lambdaMain()
{
    /**
     * @brief 
     * 无捕获、无参数、无返回值的lambda表达式，打印一条消息
     */
    auto lambda0 = []() 
    {
        std::cout << "lambda 0 " << std::endl;
    };
    lambda0(); // 调用lambda

    /**
     * @brief 
     * 捕获指定外部变量-按值、带参数、有返回值的lambda表达式
     * 此处[value]是按指定变量捕获的，只读不可修改
     */
    int value = 1;
    auto lambda1 = [value](int x) -> int 
    {
        return value*x;
    };
    std::cout << "lambda 1 = " << lambda1(66) <<std::endl;

     /**
     * @brief 
     * 捕获全部外部变量-按引用、带参数、有返回值的lambda表达式
     * 此处 [&] 是按引用捕获的，可以捕获作用于内所有变量的引用，可读可修改
     */
    int value2 = 666;
    auto lambda2 = [&]()->int
    {
        value = value2;
        return ++value2;
    };
    lambda2();
    std::cout << "after lambda2: value = " << value <<" value 2 = "<< value2 <<std::endl;

    /**
     * @brief 
     * 捕获全部外部变量-按值、带参数、有返回值的lambda表达式
     * 此处 [=] 是按值捕获的，可以捕获作用于内所有变量的值，可读不可修改
     */
    auto lambda3 = [=](int x)->int
    {
        //value = value2;错误，不能修改
        return (value+value2)*x;
    };
    std::cout << "lambda 3 = " << lambda3(0) <<std::endl;
    
}

void factoryMain()
{
    ShapeFactory& factory = ShapeFactory::getInstance();

    // 从配置文件或其他输入中获取要创建的形状类型
    ShapeType type = CIRCLE;

    auto shape = factory.createShape(type);
    if (shape) 
    {
      
        shape->draw();
    } 
    else 
    {
       
    }
}

int main()
{
    //singletonMain();
    //lambdaMain();
    factoryMain();
    return 0;
}