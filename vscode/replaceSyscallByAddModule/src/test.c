#include <syscall.h>
#include <stdio.h>
#include<sys/socket.h> 
#include<netinet/in.h>
int main(void)
{
	int t_fd = socket(AF_INET, SOCK_STREAM, 0);
	printf("that is the end\n, and the t_fd is %d", t_fd);
	close(t_fd);
	return 0;
}
