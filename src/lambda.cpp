#include "lambda.h"


void lambdaExpression()
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