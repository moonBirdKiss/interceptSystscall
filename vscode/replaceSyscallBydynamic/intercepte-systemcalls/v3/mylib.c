#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

void *lib_handle = NULL;
int (*socketpair_ptr)(int d, int type, int protocol, int sv[2]);
int (*socket_ptr)(int, int, int) = NULL;
ssize_t (*read_ptr) (int, void*, size_t) = NULL;
ssize_t (*write_ptr) (int, const void*, size_t) = NULL;
int (*close_ptr) (int) = NULL;
int (*bind_ptr) (int sockfd, const struct sockaddr *, socklen_t ) = NULL;
bool inted = false;


static void find_original_functions(){
    if(inted)
        return;
    
    lib_handle = dlopen("libc.so.6", RTLD_LAZY);
    if (lib_handle == NULL)
    {
        printf("can't open libc.so.6f\n");
        return;
    }

    socket_ptr = dlsym(lib_handle, "socket");
    if(socket_ptr == NULL){
        printf("can't find socket()");
        return;
    }

    socketpair_ptr = dlsym(lib_handle, "socketpair");
    if(socketpair_ptr == NULL){
        printf("can't find socketpair");
        return;
    }


    read_ptr = dlsym(lib_handle, "read");
    if(read_ptr == NULL){
        printf("can't find read()");
        return;
    }
    
    write_ptr = dlsym(lib_handle, "write");
    if(write_ptr == NULL){
        printf("can't open write()");
        return;
    }

    close_ptr = dlsym(lib_handle, "close");
    if(close_ptr == NULL){
        printf("can't find close");
        return;
    }

    bind_ptr = dlsym(lib_handle, "bind");
    if (bind_ptr == NULL){
        printf("can't find bind()\n");
        return ;
    }

    inted = true;
    return;
}

ssize_t read(int fd, void*buf, size_t count){
    find_original_functions();
    printf("you want to read(), right?\n");
    return (*read_ptr)(fd, buf, count);
}

int socket(int af, int type, int protocol){
    find_original_functions();
    printf("you want to socket(), right?\n");
    return (*socket_ptr)(af, type, protocol);
}


ssize_t write(int fd, const void*buf, size_t nbyte){
    find_original_functions();
    printf("you want to write(), right?\n");
    return (*write_ptr)(fd, buf, nbyte);
}

int close(int fd){
    find_original_functions();
    printf("you want to close(), right?\n");
    return (*close_ptr)(fd);
}

int socketpair(int d, int type, int protocol, int sv[2]){
    find_original_functions();
    printf("you want to socketpair(), right?\n");
    return (*socketpair_ptr)(d, type, protocol, sv);
}

int bind(int sockfd, const struct sockaddr *my_addr, socklen_t addrlen){
    find_original_functions();
    printf("you want to use bind(), right?\n");
    return (*bind_ptr)(sockfd, my_addr, addrlen);
}