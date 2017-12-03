#include <stdio.h>
#include <malloc.h>
#include "SeList.h"


/**
*����һ������˳���
*����ֵ * ˳���ָ��
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
* ����һ��˳���
*/
void SeList_Destory(SeList * psList){
    free(psList);
    return;
}

/**
* ���һ��˳���
*/
void SeList_Clear(SeList * psList){
    if(psList != NULL){
        psList->_length=0;
    }
    return ;
}

/**
* ˳���ĳ���
*/
int SeList_Length(SeList * psList){
    int default_len=-1;
    if(psList != NULL){
        default_len=psList->_length;
    }
    return default_len;
}

/**
* ˳��������
*/
int SeList_Capacity(SeList * psList){
    int default_cap=-1;
    if(psList != NULL){
        default_cap=psList->_capacity;
    }
    return default_cap;
}

/**
* ˳���Ĳ���һ���ڵ�
* ˳����ڵ㣬�ڵ�λ��
*/
bool SeList_Insert(SeList * psList,SeListElem psNode,int pos){
   int i;

   if(psList == NULL){
        return false;
   }

   // ��������
   if(
        pos <0  ||
        psList->_capacity == 0 ||
        psList->_length < pos   ||
        (psList->_length+1)>psList->_capacity
      ){
        return false;
   }

    //����pos֮��ĺ���һ��
   for(i=psList->_length;i>pos;i--){
        psList->_elem[i]=psList->_elem[i-1];
   }
   psList->_elem[pos]=psNode;
   psList->_length++;

   return true;
}

/**
* ˳����ɾ��һ���ڵ�
* ˳����ڵ�λ��
*/
bool SeList_Delete(SeList * psList,int pos){
   int i;

   if(psList == NULL){
        return false;
   }

   // ��������
   if(
        pos <0  ||
        psList->_length <= pos
      ){
        return false;
   }

    //����ǰ��һ��
   for(i=pos;i<psList->_length;i++){
        psList->_elem[i]=psList->_elem[i+1];
   }
   psList->_length--;

   return true;
}

/**
* ˳�����޸�һ���ڵ�
* ˳����ڵ�λ��
*/
bool SeList_Edit(SeList * psList,SeListElem psNode,int pos){

   if(psList == NULL){
        return false;
   }

   // ��������
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
* ˳���Ĵ�ӡ
* ˳���
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
