/* 文件名：hack.c */
#include <stdio.h>
#include <string.h>
int strcmp1(const char *s1, const char *s2)
{
    printf("you are fooled!\n");
    /* 永远返回0，表示两个字符串相等 */
    return 0;
}
