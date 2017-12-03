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


// ��������
SeLink * SeLink_CreateLink(int length);

// �����ڵ�
NodeLink * SeLink_CreateNodes(int node_num,ElemLink elems[]);

//����ڵ�
bool SeLink_Insert(SeLink * link,int pos,SeLink * link_insert);

//��ӡ����
void SeLink_Print(SeLink * link);

//���½�����ָ�����
void SeLink_Reset(SeLink * link);

//ɾ��һ���ڵ�
bool SeLink_Unset(SeLink * link,LRank r);
