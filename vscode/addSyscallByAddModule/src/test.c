#include <syscall.h>
#include <stdio.h>
int main(void)
{
	printf("%d\n",sys_mycall(335));
	return 0;
}
