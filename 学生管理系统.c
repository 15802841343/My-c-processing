//
//  main.c
//  homework
//
//  Created by 杨红开 on 2018/11/13.
//  Copyright © 2018 no. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 20

// 定义结构体：存储学生基本信息
struct STUDENT_NODE {
    long int id;
    char name[MAX_LEN];
    char sex;
    int  age;
    // 指针指向下一个结点，用以形成链表
    struct STUDENT_NODE *next;
};

//
struct STUDENT_LINK{
    struct STUDENT_NODE *top;
};
//初始化学生链表
void iniStudentLink(struct STUDENT_LINK * L);

void clearStudentLink(struct STUDENT_LINK * L); //清空学生链表

//判断该学号的学生信息是否存在
int isExist(struct STUDENT_LINK * L, long int id);
//添加一个新同学的信息
int Add(struct STUDENT_LINK * L,long int id,char name[],char sex, int age);
//根据该学号修改信息
int Modify(struct STUDENT_LINK * L, long int id,char name[],char sex, int age);
// 根据学号，输出显示该同学信息
int Search(struct STUDENT_LINK * L,long int id);

int Delete(struct STUDENT_LINK * L, long int id); // 根据学号，从链表中删除该同学的信息

void ShowALL(const struct STUDENT_LINK * L);           // 从头到尾，输出当前所有的同学信息

int main(){
    struct STUDENT_LINK L;
    struct STUDENT_NODE *new = (struct STUDENT_NODE *)malloc(sizeof(struct STUDENT_NODE));
    new->age = 18;
    new->id = 1234;
    new->sex = 'm';
    strcpy(new->name, "yang");
    new->next = NULL;
    L.top = new;
    
    printf("是否存在学号 1234 == %d\n",isExist(&L, 1234));
    printf("添加学号1235 年龄18 性别‘f’ 名字“hong”\n");
    printf("%p\n",L.top->next);
    Add(&L, 1235,"hong", 'f', 18);
    printf("%p\n",L.top->next);
    printf("%p\n",L.top->next->next);
    ShowALL(&L);
    printf("test func for show_all\n");
    printf("%p\n",L.top->next);
    printf("%p\n",L.top->next->next);
    printf("%ld\n",L.top->id);
    iniStudentLink(&L);
    ShowALL(&L);
    clearStudentLink(&L);
    return 0;
}
//不能乱更改指针
void iniStudentLink(struct STUDENT_LINK * L){
    struct STUDENT_NODE *temp = L->top;
    while (1) {
        if (temp == NULL){
            printf("have initialized!\n");
            break;
        }
        else{
            temp->age = 0;
            temp->id = 0;
            temp->sex = '0';
            strcpy(temp->name, "0");
            temp = temp->next;
        }
    }
}

int isExist(struct STUDENT_LINK * L, long int id){
    while(1){
        if (L->top->id == id)
            return 1;
        if (L->top == NULL) {
            return 0;
        }
        L->top = L->top->next;
    }
}
//有问题！！！static关键字！！！
int Add(struct STUDENT_LINK * L,long int id,char name[],char sex, int age){
    //遍历到最后一块
    while (L->top->next != NULL) {
        L->top = L->top->next;
        printf("warning :jinru!\n");
    }
    struct STUDENT_NODE *second = (struct STUDENT_NODE *)malloc(sizeof(struct STUDENT_NODE));
    second->id = id;
    second->age = age;
    second->sex = sex;
    strcpy(second->name, name);
    second->next = NULL;
    L->top->next = second;

    return 1;
}

int Modify(struct STUDENT_LINK * L, long int id,char name[],char sex, int age){
    while(1){
        if (L->top->id == id){
            L->top->age = age;
            L->top->sex = sex;
            strcpy(L->top->name, name);
            return 1;
        }
        if (L->top == NULL) {
            return 0;
        }
        L->top = L->top->next;
    }
}
int Delete(struct STUDENT_LINK * L, long int id){
    if (L->top == NULL) {
        return 0;
    }
    if (L->top->id == id) {
        L->top = NULL;
    }
    while(1){
        if (L->top->next->id == id){
            
            if (L->top->next->next == NULL) {
                L->top->next = NULL;
                printf("ok!\n");
            }else{
                L->top->next = L->top->next->next;
            }
            return 1;
        }else{
            L->top = L->top->next;
        }
    }
}
int Search(struct STUDENT_LINK * L,long int id){
    while(1){
        if (L->top->id == id){
            fread(L->top,sizeof(struct STUDENT_NODE) ,1, stdout);
            return 1;
        }
        if (L->top == NULL) {
            return 0;
        }
        L->top = L->top->next;
    }
}
//当指针的值改变时，是真的改变所以只能使用副本防止改变指针！
void ShowALL(const struct STUDENT_LINK * L){
    //建立副本
    struct STUDENT_NODE *temp = L->top;
    while (temp!= NULL) {
        printf("age = %d id = %ld name = %s sex = %c\n",temp->age,temp->id,temp->name,temp->sex);
        temp= temp->next;
    }
}

void clearStudentLink(struct STUDENT_LINK * L){
    while (L->top != NULL) {
        free(L->top);
        L->top = L->top->next;
    }
}
