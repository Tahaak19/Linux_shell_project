#include <stdio.h>

int main(int argc, char *argv[], char** envp){
    if(argv[0][0]<48 || argv[0][0]>57){
        printf("'%s' tanimli degildir sayi girmeniz gerekiyor.\n",argv[0]);
        return 0;
    }
    int i;
    int tekrarSayisi = atoi(argv[0]);
    for(i=0;i<tekrarSayisi;i++){
        printf("%s\n",argv[1]);
    }
}
