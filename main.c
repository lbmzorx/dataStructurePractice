#include <stdio.h>
#include <stdlib.h>
#include "SeList.h"
#include "SeLink.h"

int main()
{

//    À≥–Ú±Ì≤‚ ‘
//    SeList *list_arry;
//    bool insert_status;
//    SeListElem psNode;
//    int pos;
//
//
//    psNode = 3;
//    list_arry = SeList_Create(5);
//
//    insert_status=SeList_Insert(list_arry,psNode,0);
//    psNode=4;
//    insert_status=SeList_Insert(list_arry,psNode,1);
//    psNode=5;
//    insert_status=SeList_Insert(list_arry,psNode,1);
//
//
//    pos = SeList_Length(list_arry);
//
//    insert_status=SeList_Delete(list_arry,pos-1);
//
//    SeList_Print(list_arry);

//  À≥–Ú¡¥±Ì≤‚ ‘
    LRank   lrank;
    SeLink * link,*link_insert;
//    NodeLink * node1;
    bool    status;
//    ElemLink elem[1];

    link = SeLink_CreateLink(5);
    SeLink_Print(link);

//    lrank=2;
//    status=SeLink_Unset(link,lrank);
//    if(status==false){
//        printf("Unset failed!\n");
//    }else{
//        printf("Unset success unset node:%d!\n",lrank);
//    }

    link_insert=SeLink_CreateLink(2);
    SeLink_Insert(link,0,link_insert);

    SeLink_Print(link);
    return 0;
}
