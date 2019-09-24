#include "Josephus.h"
#include <stdlib.h>

void append(LoopList L,int num){
    //判断该l是否为空
    if (L == NULL) {
        PtrNode new = malloc(sizeof(struct node));
        new->next = NULL;
        new->num = num;
        L = new;
    }else{
        //判断头节点
        PtrNode head = L;
        //找到尾节点:一定存在某个节点指向头节点
        PtrNode tail = L;
        while (tail->next != head) {
            tail = tail->next;
    }
        //生成新节点并加入到list中
        PtrNode new = malloc(sizeof(struct node));
        new->num = num;
        new->next = head;
        tail->next = new;
    }
}
//n是第n个节点删除
void deleteNode(LoopList L,int n){
    PtrNode ptr = L;
    PtrNode head = L;
    if (n==1) {
        //找到尾节点
        while (L ->next != head) {
            L = L->next;
        }
        PtrNode tail = L;
        L = head;
        // 将第一个节点删除
        tail->next = head->next;
        free(ptr);
        //一旦删除该节点要报告
    }else{
        //找到要删除节点的前一个节点
        for (int i = 1; i<n; i++) {
            ptr = ptr->next;
        }
        PtrNode ptrlast = ptr;
        ptr = ptr->next;
        ptrlast->next = ptr->next;
        free(ptr);
    }
}

LoopList Josephus(int M,int N){
    LoopList L = NULL;;
    //生成n个人
    for (int i = 0; i<N; i++) {
        append(L, 0);
    }
    //找到头节点
    PtrNode head = L;
    //判断尾节点
    PtrNode tail = L;
    while (tail ->next != head) {
        tail = tail->next;
    }
    //游戏最后只会剩下一个人
    while (L->next != head) {
        deleteNode(L, N+1);
    }
    return L;
}
