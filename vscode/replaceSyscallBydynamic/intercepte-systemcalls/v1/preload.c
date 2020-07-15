#include <stdio.h>
#include <stdlib.h>

void * malloc(size_t size)
{
    printf("you are fooled!\n");
    return NULL;
}