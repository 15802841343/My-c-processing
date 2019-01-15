//hdoj 1003
//  main.c
//  homework
//
//  Created by 杨红开 on 2018/11/13.
//  Copyright © 2018 no. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    //5 6 -1 5 4 -7
    //多次for循环找出最大值
    int number;
    scanf("%d",&number);
    int array[number];
    for (int i = 0; i<number; i++) {
        scanf("%d",&array[i]);
    }
    
    //初始化 start = 0,end = 0;
    int start = 0,end = 0;
    int max = array[start];
    
    for (int i = 0; i<number; i++) {
        
        for (int temp = number; temp>=0;temp-- ) {
            //累加
            int n_max = 0;
            int signal = 0;
            for (int k = i; k<temp; k++) {
                n_max += array[k];
                signal = 1;
            }
            printf("此时n_max = %d signal = %d\n",n_max,signal);
            //判断大小前，判断n_max是否被改变
            if (signal == 1) {
                if (n_max>=max) {
                    max = n_max;
                    start = i;
                    end = temp;
                }
            }
            
        }
        
    }
    printf("%d %d %d\n",max,start+1,end);
    return 0;
}
