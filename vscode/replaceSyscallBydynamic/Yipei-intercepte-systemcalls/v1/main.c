#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i = 0;
    for(; i<5;i++){
        char * c = (char*)malloc(sizeof(char));
        printf("%u\n", c);
    }
    return 0;
}