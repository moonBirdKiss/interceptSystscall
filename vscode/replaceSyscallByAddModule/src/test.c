#include <syscall.h>
#include <stdio.h>
#include <sys/types.h>
#include <linux/unistd.h>
int main(void)
{
	printf("%d\n",syscall(335));
	printf("%d\n",syscall(336));
	return 0;
}
