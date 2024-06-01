#pragma once
#include "common.h"
/**
 * @brief 
 * 在C++中，对象的构造方式主要有以下几种：

 * √ 1.默认构造函数：这是没有参数或者参数全部有默认值的构造函数。如果没有为类定义任何构造函数，编译器会生成一个默认的构造函数。

 * √ 2.带参数的构造函数：通过提供带参数的构造函数，可以在对象创建时初始化其成员变量。

 * √ 3.拷贝构造函数：用于创建一个现有对象的副本。它接受一个对同类型对象的常量引用作为参数。

 * √ 4.移动构造函数（C++11及以后）：用于将资源从一个临时对象“移动”到目标对象，通常用于提升性能，避免不必要的拷贝。

 * √ 5.列表初始化：使用花括号{}来初始化对象，这可以适用于内置类型、聚合类型以及自定义类型的对象。

*/

/**
 * @brief 
 * 构造函数调用接口
*/

void constructExperss();

typedef struct myStruct
{
    int id;
    s_  name;
    //初始化列表
    myStruct():id(-1),name(""){};
    myStruct(int id,const s_& name):id(id),name(name){};
}myStruct;

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
        myStruct ms;
    public:
        //以后用这种初始化列表的方式,不用下面的那种，太啰嗦
        defaultConstruct():content("default"){};
        defaultConstruct(s_ value,int id,const s_& name):content(value),ms{id,name}{};

        /*啰嗦版
        defaultConstruct()
        {
            content = "1";
        }

        defaultConstruct(string value)
        {
            content = value;
        }
        */
        void outPutNum()
        {
            c_<<"content = "<<content<<e_;
            c_<<"ms.id: "<<ms.id<<" ms.name: "<<ms.name<<e_;
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
        myStruct ms;

    public:
        copyConstruct():content("param self")
        {
            c_<<"default construct"<<e_;
        };

        copyConstruct(const s_& value,int id,const s_& name):content(value),ms{id,name}
        {
            c_<<"default construct with param"<<e_;
        };

        copyConstruct(const copyConstruct& other):content(other.content),ms(other.ms)
        {
            c_<<"copy Construct"<<e_;
        };
        
        void outPutNum()
        {
            c_<<"content = "<<content<<e_;
            c_<<"ms.id: "<<ms.id<<" ms.name: "<<ms.name<<e_;

        }

        void ApiChangeStruct(const myStruct& src)
        {
            ms.id = src.id;
            ms.name = src.name;
        }
    
};

/**
 * @brief 
 * 移动构造
 */
class moveConstruct
{
    private:
        s_ content;
        myStruct ms;
    public:
  
        moveConstruct(const s_& value,int id,const s_& name):content(value),ms{id,name}
        {
            c_<<"parma construction"<<e_;
        };
        //右值引用
        //左值引用主要用于避免有名字变量的复制，而右值引用则主要用于实现移动语义，以高效处理临时对象和即将被销毁的对象。
        //右值引用通常用语处理大量数据的移动，接管一个临时变量等，详情见对应的章节
        moveConstruct(moveConstruct&& other) noexcept :content(std::move(other.content)),ms(std::move(other.ms))
        {
             c_<<"move construction"<<e_;
            other.content = "already release";
            other.ms.id = -1;
            other.ms.name = "null";
        }
        // 移动赋值运算符
        moveConstruct& operator=(moveConstruct&& other) noexcept 
        {
            if (this != &other) { // 防止自赋值
                content = std::move(other.content);
                ms = std::move(other.ms);
                // 在移动之后，other对象的状态可能是未定义的，这里简单设置为无效值
                other.content = "already release-2";
                other.ms.id = -1;
                other.ms.name = "null=2";
                std::cout << "move assignment" << std::endl;
            }
            return *this;
        }

        void outPutNum()
        {
            c_<<"content = "<<content<<e_;
            c_<<"ms.id: "<<ms.id<<" ms.name: "<<ms.name<<e_;
            return;
        }

        moveConstruct(const moveConstruct&) = delete;
        moveConstruct& operator=(moveConstruct& ) = delete;
};
