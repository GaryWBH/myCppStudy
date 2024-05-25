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