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
*˳���Ľṹ��
*/
typedef struct _SeList{
    int _capacity;
    int _length;
    int _val_type;
    SeListElem *_elem;

}SeList;

//����˳���
SeList * SeList_Create(int capacity);

//����˳���
void SeList_Destory(SeList * PsList);

//���һ��˳�����ʵֻ�ǽ��䳤������Ϊ0��
void SeList_Clear(SeList * psList);


//����һ��Ԫ��
bool SeList_Insert(SeList * psList,SeListElem psNode,int pos);

//ɾ��һ��Ԫ��
bool SeList_Delete(SeList * psList,int pos);

//�༭һ��Ԫ��
bool SeList_Edit(SeList * psList,SeListElem psNode,int pos);

//��ӡ���б�
void SeList_Print(SeList * psList);
