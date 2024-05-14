#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[], char** envp){
    char s[10];
    sprintf(s,"%dl",atoi(argv[1])-atoi(argv[2]));
    write(4, s, strlen(s));
    
}
