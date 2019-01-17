//
//  main.c
//  homework
//
//  Created by 杨红开 on 2018/11/13.
//  Copyright © 2018 no. All rights reserved.
//
#include<stdio.h>
#include <string.h>
//贺卡制作系统
int main(){
    int lenth;
    scanf("%d",&lenth);
    char string[200];
    scanf("%s",string);
    int string_len = strlen(string);
    
    for (int i = 0; i<lenth; i++) {
        printf("** ");
    }
    printf(" \n");
    
    for (int i = 0; i<lenth/2; i++) {
        printf("**");
        if (i == lenth/4) {
            for (int k = 0; k<((lenth-2)*3+1)/2-string_len/2; k++) {
                printf(" ");
            }
            printf("%s",string);
            if (string_len%2!=0) {
                for (int j = 0; j<((lenth-2)*3+1)/2-string_len/2; j++)
                    printf(" ");
            }else
                for (int j = 0; j<((lenth-2)*3+1)/2-string_len/2+1; j++)
                    printf(" ");
                
            
        }else{
            for (int i = 0; i<3*lenth-5; i++) {
                printf(" ");
            }
        }
        printf("**\n");
    }
    
    for (int i = 0; i<lenth; i++) {
        printf("** ");
    }
    putchar('\n');
    return 0;
}
