#ifndef Josephus_h
#define Josephus_h

#include <stdio.h>
struct node;
typedef struct node * PtrNode;
typedef PtrNode LoopList;

struct node{
    int num;
    PtrNode next;
};
#endif /* Josephus_h */
