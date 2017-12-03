#include <stdio.h>
#include <malloc.h>
#include "SeList.h"


/**
*创建一个线性顺序表
*返回值 * 顺序表指针
*/
SeList *SeList_Create(int capacity){
    SeList * psList =NULL;

    if(capacity>=0){
        psList = (SeList *) malloc(sizeof(SeList)+sizeof(SeListElem)*capacity);
    }

    if(psList != NULL){
        psList->_capacity = capacity;
        psList->_length=0;
        psList->_elem = (SeListElem *)(psList+1);
    }

    return psList;
}

/**
* 销毁一个顺序表
*/
void SeList_Destory(SeList * psList){
    free(psList);
    return;
}

/**
* 清空一个顺序表
*/
void SeList_Clear(SeList * psList){
    if(psList != NULL){
        psList->_length=0;
    }
    return ;
}

/**
* 顺序表的长度
*/
int SeList_Length(SeList * psList){
    int default_len=-1;
    if(psList != NULL){
        default_len=psList->_length;
    }
    return default_len;
}

/**
* 顺序表的容量
*/
int SeList_Capacity(SeList * psList){
    int default_cap=-1;
    if(psList != NULL){
        default_cap=psList->_capacity;
    }
    return default_cap;
}

/**
* 顺序表的插入一个节点
* 顺序表，节点，节点位置
*/
bool SeList_Insert(SeList * psList,SeListElem psNode,int pos){
   int i;

   if(psList == NULL){
        return false;
   }

   // 限制条件
   if(
        pos <0  ||
        psList->_capacity == 0 ||
        psList->_length < pos   ||
        (psList->_length+1)>psList->_capacity
      ){
        return false;
   }

    //所有pos之后的后移一步
   for(i=psList->_length;i>pos;i--){
        psList->_elem[i]=psList->_elem[i-1];
   }
   psList->_elem[pos]=psNode;
   psList->_length++;

   return true;
}

/**
* 顺序表的删除一个节点
* 顺序表，节点位置
*/
bool SeList_Delete(SeList * psList,int pos){
   int i;

   if(psList == NULL){
        return false;
   }

   // 限制条件
   if(
        pos <0  ||
        psList->_length <= pos
      ){
        return false;
   }

    //所有前移一步
   for(i=pos;i<psList->_length;i++){
        psList->_elem[i]=psList->_elem[i+1];
   }
   psList->_length--;

   return true;
}

/**
* 顺序表的修改一个节点
* 顺序表，节点位置
*/
bool SeList_Edit(SeList * psList,SeListElem psNode,int pos){

   if(psList == NULL){
        return false;
   }

   // 限制条件
   if(
        pos <0  ||
        psList->_length <= pos
      ){
        return false;
   }
   psList->_elem[pos]=psNode;
   return true;
}

/**
* 顺序表的打印
* 顺序表
*/
void SeList_Print(SeList * psList){
    int i=0;
    if(psList ==NULL){
        printf("Sequence List is NULL\n");
        return ;
    }
    printf("Sequence List\n capacity:%d \t length:%d \n",
           psList->_capacity,psList->_length);
    for(i=0;i<psList->_length;i++){
        printf("\t%d\t%d \n",i,psList->_elem[i]);
    }
    return ;
}
