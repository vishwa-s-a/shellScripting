#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    fork();// for one time we get 2 hello
    fork();//for two times we get 4 hello
    fork();//for three times we get 8 hello
    fork();// for four times we get 16 hellos
    printf("hello\n");
}