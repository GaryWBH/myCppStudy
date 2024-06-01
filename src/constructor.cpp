#include "constructor.h"

/**
 * @brief 
 * 默认构造
 */
static void defaultConstructEnter()
{
    defaultConstruct* df = new defaultConstruct();
    df->outPutNum();

    defaultConstruct* df2 = new defaultConstruct("input param",1,"Gary1");
    df2->outPutNum();

    return;
}

/**
 * @brief 
 * 拷贝构造
 */
static void copyConstructEnter()
{ 
    //默认构造
    copyConstruct* cc = new copyConstruct();
    cc->outPutNum();
    //传参默认构造
    copyConstruct* cc2 = new copyConstruct("input param2",2,"Gary2");
    cc2->outPutNum();
    
    myStruct src;
    src.id = 3;
    src.name = "Gary3";
    cc2->ApiChangeStruct(src);

    //拷贝构造-显式
    copyConstruct* cc3 = new copyConstruct(*cc2);
    cc3->outPutNum();
    //cc2依然还在
    cc2->outPutNum();
    //这里很重要
    //1、copyConstruct* cc(cc3),并不是一个隐式调用拷贝构造函数的方式，而是执行了一个指针的复制，把cc4指向了cc3
    //2、真正的隐式拷贝构造是需要copyConstruct cc5(*cc3)酱紫的。显式的就在上面
    copyConstruct* cc4(cc3);
    //拷贝构造-隐式
    copyConstruct cc5(*cc3);
    cc5.outPutNum();

    return;
}

/**
 * @brief 
 * 移动构造
 *
*/
static void moveConstructEnter()
{
    //moveConstruct* mm1 = new moveConstruct("input parma",1,"Gary");
    //mm1->outPutNum();

    //moveConstruct mm2(std::move(*mm1));
    //mm1->outPutNum();
    //mm2.outPutNum();

    //moveConstruct* mm3 = new  moveConstruct(std::move(*mm1));
    //mm1->outPutNum();
    //mm2.outPutNum();
    //mm3->outPutNum();

    // 直接创建一个 moveConstruct 对象，而不是使用 new
    moveConstruct mm1("input parma", 1, "Gary");
    mm1.outPutNum();

    // 使用 new 创建一个动态分配的 moveConstruct 对象
    moveConstruct* mm2_ptr = new moveConstruct("input parma 2", 2, "John");
    moveConstruct& mm2 = *mm2_ptr; // 获取对动态分配对象的引用
    mm2.outPutNum();

    // 现在，我们可以安全地使用移动赋值来将 mm2 的资源移动到 mm1 中
    mm1 = std::move(mm2);
    mm1.outPutNum(); // 应该显示 mm2 的内容，因为资源已经被移动

    return;
}

/**
 * @brief 
 * 操作入口
 */
void constructExperss()
{
    line_;
    //defaultConstructEnter();
    line_;
    //copyConstructEnter();
    line_;
    moveConstructEnter();
    line_;
    return;
}
