CC = gcc

all: tekrar topla cikar islem myshell

tekrar: tekrar.c
	$(CC) tekrar.c -o tekrar

topla: topla.c
	$(CC) topla.c -o topla


cikar: cikar.c
	$(CC) cikar.c -o cikar
islem: islem.c
	$(CC) islem.c -o islem


myshell: myshell.c
	$(CC) myshell.c -o myshell

clean:
	rm -rf *o all
