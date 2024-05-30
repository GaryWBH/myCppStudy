/**
 * @file main.cpp
 * @author Gary.WBH (gary.wbh@hotmail.com)
 * @brief 
 * 各类主函数入口
 * @version 1.0
 * @date 2024-05-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include "singleton.h"
#include "factory.h"
#include "lambda.h"
#include "constructor.h"

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
    singleton* sg2 = singleton::getInstance();
    sg->mySingleton("hello my singleton-240525");

    auto sgm = singleton_sm::getInstance();
    auto sgm2 = singleton_sm::getInstance();
    sgm->mySingleton("hello my singleton-2405256"); 
    

    if(sg == sg2)
    {
        std::cout << "the same " << std::endl;
    }
    else
    {
        std::cout << "the derffient " << std::endl;
    }   

    if(sgm == sgm2)
    {
        std::cout << "the same " << std::endl;
    }
    else
    {
        std::cout << "the derffient " << std::endl;
    }   


    return ;
}

/**
 * @brief 
 * lambdaMain学习
 */
void lambdaMain()
{
    lambdaExpression();
    return;
}

void factoryMain()
{
    
    factory* wayFactory = factory::getInstance();
  
    way* myWay1 = wayFactory->getWayInstance(BIKE);
    myWay1->theWay2Company();

    way* myWay2 = wayFactory->getWayInstance(DRIVER);
    myWay2->theWay2Company();

    way*  myWay3 = wayFactory->getWayInstance(DEFAULT);
    myWay3->theWay2Company();


    factory* wayFactory2 = factory::getInstance();
    way* myWay4 = wayFactory2->getWayInstance(BIKE);
    myWay4->theWay2Company();


    if(wayFactory == wayFactory2)
    {
        std::cout<<"the same class"<<std::endl;
    }
    else
    {
        std::cout<<"the different class"<<std::endl;
    }

    if(myWay1 == myWay4)
    {
        std::cout<<"the same ptr"<<std::endl;
    }
    else
    {
        std::cout<<"the different ptr"<<std::endl;
    }
}

void constructMain()
{
    constructExperss();
    return;
}

int main()
{
    //singletonMain();
    //lambdaMain();
    //factoryMain();
    constructMain();
    return 0;
}