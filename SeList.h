#include <stdio.h>
#include <stdbool.h>

#define IS_NULL 0
#define IS_INT 1
#define IS_LONG 2
#define IS_FLOAT 3
#define IS_DOUBLE 4
#define IS_STRING 5


typedef union _DataElem{
    int ival;
    long lval;
    float fval;
    double dval;
}DataElem;

typedef void PSeList;
typedef int  SeListElem;

/**
*顺序表的结构体
*/
typedef struct _SeList{
    int _capacity;
    int _length;
    int _val_type;
    SeListElem *_elem;

}SeList;

//创建顺序表
SeList * SeList_Create(int capacity);

//销毁顺序表
void SeList_Destory(SeList * PsList);

//清空一个顺序表，其实只是将其长度设置为0；
void SeList_Clear(SeList * psList);


//插入一个元素
bool SeList_Insert(SeList * psList,SeListElem psNode,int pos);

//删除一个元素
bool SeList_Delete(SeList * psList,int pos);

//编辑一个元素
bool SeList_Edit(SeList * psList,SeListElem psNode,int pos);

//打印序列表
void SeList_Print(SeList * psList);
