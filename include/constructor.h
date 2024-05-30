#pragma once
#include "common.h"
/**
 * @brief 
 * 在C++中，对象的构造方式主要有以下几种：

 * √ 1.默认构造函数：这是没有参数或者参数全部有默认值的构造函数。如果没有为类定义任何构造函数，编译器会生成一个默认的构造函数。

 * √ 2.带参数的构造函数：通过提供带参数的构造函数，可以在对象创建时初始化其成员变量。

 * √ 3.拷贝构造函数：用于创建一个现有对象的副本。它接受一个对同类型对象的常量引用作为参数。

 * 4.移动构造函数（C++11及以后）：用于将资源从一个临时对象“移动”到目标对象，通常用于提升性能，避免不必要的拷贝。

 * 5.列表初始化：使用花括号{}来初始化对象，这可以适用于内置类型、聚合类型以及自定义类型的对象。

 * 6.委托构造函数（C++11及以后）：一个构造函数可以调用同一个类的另一个构造函数来执行其初始化任务。

 * 7.转换构造函数：接受一个其他类型的参数，并用于将该类型的对象转换为当前类的对象。

 * 8.拷贝赋值运算符：用于将一个对象的值复制到另一个已经存在的对象中。

 * 9.移动赋值运算符（C++11及以后）：用于将一个临时对象的资源“移动”到另一个对象中。

 * 10.初始化列表：在构造函数的函数体执行之前，使用初始化列表来初始化成员变量。

 * 11.在函数内部构造对象：可以在函数内部直接构造对象，这通常是通过调用构造函数来完成的。

 * 12.聚合初始化：对于聚合类型（如数组和结构体，其中结构体没有用户定义的构造函数、没有私有或受保护的成员、没有基类也没有虚函数），可以使用初始化列表来初始化。

 * 13.使用new关键字动态构造：通过new关键字在堆上动态地创建对象。

 * 14.使用std::make_unique或std::make_shared（C++11及以后）：在智能指针的上下文中构造对象，以确保对象的正确生命周期管理。

*/

/**
 * @brief 
 * 构造函数调用接口
 */
void constructExperss();

/**
 * @brief 
 * 默认构造函数包含：
 * 无参数构造
 * 有参数构造
 */
class defaultConstruct
{
    private:
        s_ content;
    public:
        //以后用这种初始化方式不用下面的那种，太啰嗦
        defaultConstruct():content("default"){};
        defaultConstruct(s_ value):content(value){};

        /*啰嗦版
        defaultConstruct()
        {
            num = 1;
        }

        defaultConstruct(int value)
        {
            num = value;
        }
        */
        void outPutNum()
        {
            c_<<content<<e_;
        }
};

/**
 * @brief 
 * 拷贝构造
 */
class copyConstruct
{
    private:
        s_ content;

    public:
        copyConstruct():content("param self")
        {
            c_<<"default construct"<<e_;
        };

        copyConstruct(s_ value):content(value)
        {
            c_<<"default construct with param"<<e_;
        };

        copyConstruct(const copyConstruct& other):content(other.content)
        {
            c_<<"copy Construct"<<e_;
        };
        
        void outPutNum()
        {
            c_<<content<<e_;
        }

};
