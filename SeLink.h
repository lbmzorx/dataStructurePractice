#include <stdbool.h>
#include <malloc.h>
#include <stdbool.h>

#define NODE_START  NULL
#define NODE_END    NULL

typedef int LRank;
typedef int ElemLink;

typedef struct _NodeLink{
    ElemLink _elem;
    int _key;
    struct _NodeLink *pre;
    struct _NodeLink *next;
}NodeLink;


typedef struct _SeLink{
    NodeLink *nodes;
    int _length;
}SeLink;


// 创建链表
SeLink * SeLink_CreateLink(int length);

// 创建节点
NodeLink * SeLink_CreateNodes(int node_num,ElemLink elems[]);

//插入节点
bool SeLink_Insert(SeLink * link,int pos,SeLink * link_insert);

//打印链表
void SeLink_Print(SeLink * link);

//重新将链表指针归零
void SeLink_Reset(SeLink * link);

//删除一个节点
bool SeLink_Unset(SeLink * link,LRank r);
