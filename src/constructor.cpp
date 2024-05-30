#include "constructor.h"


void constructExperss()
{
    /**
     * @brief 
     * 默认构造
     */
    defaultConstruct* df = new defaultConstruct();
    df->outPutNum();

    defaultConstruct* df2 = new defaultConstruct("input param");
    df2->outPutNum();
    line_;
    /**
     * @brief 
     * 拷贝构造
     */
    //默认构造
    copyConstruct* cc = new copyConstruct();
    cc->outPutNum();
    //传参默认构造
    copyConstruct* cc2 = new copyConstruct("input param2");
    cc2->outPutNum();
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
    line_;
    
  

}