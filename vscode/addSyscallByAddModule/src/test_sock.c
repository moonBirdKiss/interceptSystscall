#include <syscall.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main(void)
{
	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	return 0;
}
