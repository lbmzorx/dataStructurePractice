#include <stdio.h>
#include "SeLink.h"



/**
* 创建链表
*/
SeLink * SeLink_CreateLink(int length){
    SeLink * link;
    ElemLink elems[1]={0};

    link =(SeLink *)malloc(sizeof(SeLink));
    link->_length=length;
    link->nodes=SeLink_CreateNodes(length,elems);
    return link;
}


/**
* 链表长度
*/
int SeLink_Length(SeLink * link){
    return link->_length;
}

/**
* 创建多个节点,双链接
*/
NodeLink * SeLink_CreateNodes(int node_num,ElemLink elems[]){
    NodeLink * tmpNode,* startNode;
    int i;
    int elem_len=0;

    elem_len=sizeof(elems)/sizeof(ElemLink);

    if(node_num == 0){
        return NULL;
    }

    tmpNode = (NodeLink*)malloc(sizeof(NodeLink));
    tmpNode->pre    = NODE_START;
    tmpNode->_elem  = (elem_len>0)?elems[0]:0;
    tmpNode->_key   = 0;
    startNode       = tmpNode;

    if(node_num==1){
        tmpNode->next=NODE_END;
        return startNode;
    }

    for(i=1;i<node_num;i++){
        tmpNode->next=(NodeLink *)malloc(sizeof(NodeLink));
        tmpNode->next->pre=tmpNode;
        tmpNode=tmpNode->next;
        tmpNode->_elem=(elem_len>i)?elems[i]:0;
        tmpNode->_key =i;
    }
    tmpNode->next=NODE_END;
    return startNode;
}

/**
* 插入链表
*/
bool SeLink_Insert(SeLink * link,int pos,SeLink * link_insert){
    NodeLink * tmpNode,*tmpNode_insert;
    int i;

    tmpNode=link->nodes;
    tmpNode_insert=link_insert->nodes;

    if(link->_length==0){
      link=link_insert;
      return true;
    }


    if(pos>=link->_length){
        pos=link->_length;
    }



    for(i=0;i<pos;i++){
        if(tmpNode->next==NODE_END){
            break;
        }
        tmpNode=tmpNode->next;
    }

    tmpNode_insert->pre =tmpNode->pre;
    if(tmpNode->pre != NODE_START){
        tmpNode->pre->next=tmpNode_insert;
    }

    for(i=0;i<link_insert->_length;i++){
        if(tmpNode_insert->next == NODE_END){
            break;
        }
        tmpNode_insert=tmpNode_insert->next;
    }
    tmpNode_insert->next=tmpNode;
    tmpNode->pre=tmpNode_insert;

    link->_length += link_insert->_length;

    return true;
}




/**
* 打印链表
*/
void SeLink_Print(SeLink * link){
    int i;
    NodeLink * tmpNode;

    SeLink_Reset(link);
    printf("Link message length is :%d\n",link->_length);
    tmpNode=link->nodes;
    for(i=0;i<link->_length;i++){
        if(tmpNode==NODE_END){
            break;
        }
        printf("node key:%d\t value:%d \t i=%d\n",tmpNode->_key,
              tmpNode->_elem,i);
        tmpNode=tmpNode->next;

    }
    return ;
}

/**
* 重新设置链表的起始位置
*/
void SeLink_Reset(SeLink * link){
    int i;
    NodeLink * tmpNode;
    if(link->_length==0){
        return link;
    }
    tmpNode=link->nodes;
    for(i=0;i<link->_length;i++){
        if(tmpNode->pre==NODE_START){
            break;
        }
        tmpNode=tmpNode->pre;
    }
    link->nodes=tmpNode;
    return ;
}

/**
* 删除一个节点,默认向后查找
*/
bool SeLink_Unset(SeLink * link,LRank r){
    int i;
    NodeLink *tmpNode,*tmpStart;

    tmpNode=link->nodes;
    for(i=0;i<r;i++){
        if(tmpNode->next==NODE_END){
            return false;
        }else{
            tmpNode=tmpNode->next;
        }
    }

    tmpStart=tmpNode->pre;
    tmpStart->next=tmpNode->next;
    free(tmpNode);
    link->_length--;
    return true;
}


