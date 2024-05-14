#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char** envp){
    char* oprationName = argv[0];
    //int a = atoi(argv[1]);
    //int b = atoi(argv[2]);
    if(strcmp("topla",oprationName) != 0 && strcmp("cikar",oprationName) != 0){
         printf("'%s' tanimli bir islem degildir. topla veya cikar islemlerini deneyebilirsiniz.\n",oprationName);
        return 0;
    }
    if(argv[1][0]<48 || argv[1][0]>57 ||argv[2][0]<48 || argv[2][0]>57){
        printf("topla ve cikar islemlerinde sadece sayilar kullanilir.\nTekara deneyiniz.\n");
    return 0;
    }
    
    int pipefd[2];
    int pid;
    char s[10];
    int c;
    if (pipe(pipefd) < 0) {
       perror("pipe");
       exit(1);
    }

    if(strcmp("topla",oprationName) == 0){
        //printf("%d + %d = %d\n", a, b, a+b);
      pid = fork();

      if (pid == 0) {
        c = execve("topla", argv);
        perror("");
        close(pipefd[1]);
      } else {
        wait(&c);
        read(pipefd[0], s, 10);
        printf("%s + %s = ",argv[1],argv[2]);
        int x=0;
        while(s[x] != 'l'){
             printf("%c",s[x++]);
             
        }
        printf("\n");
      }
    }else if(strcmp("cikar",oprationName) == 0){
        //printf("%d - %d = %d\n", a, b, a-b);
      pid = fork();

      if (pid == 0) {
        c = execve("cikar", argv);
        perror("");
        close(pipefd[1]);
      } else {
        wait(&c);
        read(pipefd[0], s, 10);
        printf("%s - %s = ",argv[1],argv[2]);
        int x=0;
        while(s[x] != 'l'){
             printf("%c",s[x++]);
             
        }
        printf("\n");
      }
    }
          
    return 0;
}
