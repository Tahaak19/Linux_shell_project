#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void copyArray(char*, char*, int);
int control(char**, int,char**);
int length(char*);
int charCount(char*, char);
void printWords(char**, int);
char** split(char*,char*);
int hasOr(char*, char);


int main(int argc, char *argv[], char** envp){
    int bexit;
    char str[50];
    char temp[50];
     printf("myshell>> ");
    while(scanf("%[^\n]",str)==1){ 
        copyArray(str, temp,50);     
        short wordCount=charCount(str, ' ')+1;
        short orCount=charCount(str, '|');
        char **words=split(str, " ");
        //printf("word count: %d\n",orCount);      
        //printWords(words, wordCount);
        if(hasOr(temp,'|')){
            bexit=control(words, wordCount, envp);   
            int i,x=0;
            for(i=0;i<wordCount;i++){
                if(strcmp("|",*words) == 0){
                    words++;
                    bexit=control(words, wordCount-(i+1), envp);
                    x++;
                    if(orCount==x || bexit)break;      
                }else{ 
                    words++;
                }
            }  
        }else{
            bexit=control(words, wordCount, envp);
        }
        if(bexit){
           break;        
        }
        printf("myshell>> ");
        scanf("%[^\n]",str);
        getchar();
    }
    
    return 0;

}


/**********************************functions**********************************/
/**********************************functions**********************************/
/**********************************functions**********************************/
/**********************************functions**********************************/

int length(char* str){
    int counter = 0;
    while(*str != '\0'){
        str++;
        counter++;
    }
    return counter;
}
int charCount(char* str,char c){
    int i,counter,len;
    counter = 0;
    len = length(str);
    for(i=0;i<len;i++){
        if(*(str+i) == c){
            counter +=1;
        }
    }
    return counter;
}
void printWords(char** words, int size){
    int i;
    for(i=0;i<size;i++){
        printf("words[%d] = %s\n", i, words[i]);
    }
}
char** split(char* str,char* c){
    short wordCount=charCount(str, c)+1;
    char **words = (char**) malloc(wordCount* sizeof(char *));
    char *token = strtok(str, c);// Returns first token
    // Keep printing tokens while one of the
    // delimiters present in str[].
    int counter =0;
    while (token != NULL){   
        *(words+counter++)=token;
        token = strtok(NULL, c);
    }
    return words;
}
int hasOr(char* str, char c){
    int i,len;
    len = length(str);
    for(i=0;i<len;i++){
        if(*(str+i) == c){
            return 1;
        }
    }
    return 0;
}
void copyArray(char* str1, char* str2, int size){
    int i;
    for(i=0;i<size;i++){
        str2[i]=str1[i];
    }
}
int control(char** words, int wordCount, char** envp){
    char* newargv[4];
    if(strcmp("exit",*(words)) == 0){
            return 1;
        }else if(strcmp("clear",*(words)) == 0){
            system("clear");
        }else if(strcmp("ls",*(words)) == 0){
            system("ls");
        }else if(strcmp("cat",*(words)) == 0){
            int i;
            printf("cat: ");
            for(i=1;i<wordCount;i++){
                printf("%s ", words[i]);
            }
            printf("\n");
        }else if(strcmp("tekrar",*(words)) == 0){
            int i, pid;

            pid = fork();
            if (pid == 0) {
                newargv[0]=*(words+2);
                newargv[1]=*(words+1);
                newargv[2]=NULL;
                i=execve("tekrar", newargv, envp);
                perror("error\n");
                exit(1);
            }
        }else if(strcmp("bash",*(words)) == 0){
            //int i;
            int pid, h, status;

            pid = fork();

            if (pid > 0) {
                wait(&status);
            } else {
                newargv[0]="bash>>";
                newargv[1]=NULL;
                status=execve("/bin/bash", newargv, envp);
                perror("error\n");
                exit(1);
            }
        }else if(strcmp("islem",*(words)) == 0){
            //int i;
            int pid, status;

            pid = fork();

            if (pid > 0) {
                wait(&status);
            } else {
                newargv[0]=*(words+1);
                newargv[1]=*(words+2);
                newargv[2]=*(words+3);
                newargv[3]=NULL;
                status=execve("islem", newargv, envp);
                perror("error\n");
                exit(1);
            }
        }else{
            printf("yanlis bir komut girdiniz\n");
        }
        return 0;

}

/*
            if (k > 0) {
                h = wait(&status);
            } else {
                newargv[0]=*(words+2);
                newargv[1]=*(words+1);
                newargv[2]=NULL;
                i=execve("tekrar", newargv, envp);
                perror("error\n");
                exit(1);
            }



if(hasOr(temp,'|')){
            printf("orrrrrrrrr\n");
            char **orWords =(char**) malloc(4* sizeof(char *));   
            int i,x=0;
            for(i=0;i<wordCount;i++){
                printf("%d %s\n",i,words[i] );
                if(strcmp("|",words[i]) == 0){
                    printf("||\n");
                    control(orWords, wordCount, envp);
                    x=0;    
                    continue;          
                } 
                orWords[x++]=words[i];
            }  
        }//////
*/
