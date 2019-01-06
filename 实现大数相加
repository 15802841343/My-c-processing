#include <stdio.h>
#include <string.h>
//实现大数相加
int main( ){
    
    char s1[21];
    char s2[21];
    char s4[21];
    scanf("%s",s1);
    scanf("%s",s2);
    
    long len1 = strlen(s1),len2 = strlen(s2);
    //倒序存放
    for (int i = 0; i<len1/2; i++) {
        char temp = s1[i];
        s1[i] = s1[len1-1-i];
        s1[len1-1-i] = temp;
    }
    for (int i = 0; i<len2 / 2; i++) {
        char temp = s2[i];
        s2[i] = s2[len2-1-i];
        s2[len2-1-i] = temp;
    }

    char s3[21];
    //处理尾部添加0
    if (len1>len2) {
        for (int i = len2; i<len1; i++) {
            s2[i] = '0';
        }
        s2[len1] = '\0';
        s1[len1] = '\0';
    }else{
        for (int n = len1; n<len2; n++) {
            s1[n] = '0';
        }
        s1[len2] = '\0';
        s2[len2] = '\0';
    }
    
    int i = 0,count = 0;
    //较短的 逆序存放！
    while (s1[i] != '\0') {
        s3[i] = ((s1[i]-'0') + (s2[i]-'0')+count)%10 + '0';
        count = ((s1[i]-'0') + (s2[i]-'0')+count)/10;
        i++;
    }
    
    //处理尾部
    if (count == 1) {
        s3[i++] = 1+'0';
        s3[i] = '\0';
    }else
        s3[i] = '\0';
    //此时得到s3 需要反序输出,i为s3元素个数
    for (int c = i-1; c>=0; c--) {
        putchar(s3[c]);
    }
    putchar('\n');

    
    return 0;
}
