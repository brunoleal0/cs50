#include <stdio.h>
#include <stdlib.h> 

//prototypes <- serve pra rodar no main as funções que são declaradas depois do main
void swap_wrong(int x, int y);
void swap_right(int *x, int*y);
void loop (int tamanho);
void recursion(int tamanho);
int fatorial(int numero);

int main(void)
{
    printf("Hello, World!\n");

    int a=1;
    int b=2;
    printf("a=%i b=%i\n",a,b);
    swap_wrong(a,b);
    printf("swap_wrong: a=%i b=%i\n",a,b);
    int c=3;
    int d=4;
    printf("c=%i d=%i\n",c,d);
    printf("c=%i d=%i\n",&c,&d);    
    swap_right(&c,&d);
    printf("swap_right: c=%i d=%i\n",c,d);

    //ARRAYS
    int v[4];
    for (int i=0;i<4;i++){
        v[i]=i+10;
        printf("v[%i]=%i\n",i,v[i]);
    }

    //POINTERS
    int age=20;
    int *pAge = &age;
    printf("age = %i | age = %p | pAge = %p | pAge = %p\n",age,&age,*pAge,pAge);
    *pAge = 21;
    printf("age = %i | pAge = %p\n",age,pAge);

    //STRINGS = char = pointer = array com \0 no final
    char *s = "uhul!"; //<- SALVA "uhul!\0" na memória e aponta para o começo da string (que é o caractere u)
    printf("s= %s\n",s);

    for (int i=0;i<10;i++){
        printf("caractere de s[%i]=%c, o código desse caractere é %i\n",i,s[i],s[i]); //a string sempre finaliza com \0, o programa tá lendo a memória-lixo após a string
    }

    //Recursion vs Loop
    // loop(4);
    recursion(5);
    int dsad = fatorial(5);
    printf("%i",dsad);
    return 0;
}


void swap_wrong(int x, int y){ //https://youtu.be/LfaMVlDaQ24?t=39496
    int temp = x;
    x=y;
    y=temp;
    printf("dentro x=%i y=%i\n",x,y);
}
void swap_right(int *x, int*y){ //https://youtu.be/LfaMVlDaQ24?t=40126
    int temp = *x;
    *x=*y;
    *y=temp;
    printf("dentro x=%i y=%i\n",&x,&y);
}

void loop (int tamanho){ //progressivo
    printf("LOOP\n");
    for (int i=0;i<tamanho;i++){
        int j=i+1;
        for (int i=0;i<j;i++){
            printf("#");
        }
        printf("\n");
    }
}

void recursion(int tamanho){ //a função se chama como num algoritmo de stack
if (tamanho>0){
    recursion (tamanho-1);
    for (int i=0;i<tamanho;i++){
        printf("#");
    }
    printf("\n");
}
}

int fatorial(int numero){
    if (numero>1){
        return numero*fatorial(numero-1);
    }
    if (numero==1){
        return 1;
    }
}