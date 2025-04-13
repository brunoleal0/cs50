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
    printf("Hello, World!\n"); //<- Tem quer ser double quotes por isso: https://stackoverflow.com/questions/3683602/single-quotes-vs-double-quotes-in-c-or-c

    //ARRAYS
    int v[4];
    for (int i=0;i<4;i++){
        v[i]=i+10;
        printf("v[%i]=%i\n",i,v[i]);
    }

    //POINTERS
    int age=20;
    int age2=20;
    int age3=age;
    int *pAge = &age;
    printf("age= %i | age= %p | age2= %i | age2= %p | age3= %i | age3= %p | pAge= %i | pAge= %p\n",age,&age,age2,&age2,age3,&age3,*pAge,&pAge);
    age = 21;
    printf("age= %i | age= %p | age2= %i | age2= %p | age3= %i | age3= %p | pAge= %i | pAge= %p\n",age,&age,age2,&age2,age3,&age3,*pAge,&pAge);

    char *idade="vinte";
    char *idade2="vinte";
    char *idade3=idade;
    char *pIdade = idade;
    printf("idade= %s | idade= %p | idade2= %s | idade2= %p | idade3= %s | idade3= %p | pidade= %i | pidade= %p\n",idade,&idade,idade2,&idade2,idade3,&idade3,*pIdade,&pIdade);
    idade = "vinteeum";
    printf("idade= %s | idade= %p | idade2= %s | idade2= %p | idade3= %s | idade3= %p | pidade= %i | pidade= %p\n",idade,&idade,idade2,&idade2,idade3,&idade3,*pIdade,&pIdade);

    //CHAR
    char singlecharacter='c';
    printf("single character= %c\n",singlecharacter);
    singlecharacter='d';
    printf("single character= %c\n",singlecharacter);

    //STRINGS = Dois tipos: Character Pointer or Array (Ambos têm \0 no final pra identificar o final da strng)
    // Character Pointer -> Aponta pro começo e para no \0
    char *s1 = "uhul1"; //<- SALVA "uhul!\0" na memória e aponta para o começo do caractere u
    printf("s1= %s ",s1);
    printf("pointer de s1= %p %p %p\n",*s1,s1,&s1);
    for (int i=0;i<10;i++){
        printf("caractere de s1[%i]=%c, o código desse caractere é %i, o pointer desse caractere é %p\n",i,s1[i],s1[i],&s1[i]); //a string sempre finaliza com \0, o programa tá lendo a memória-lixo após a string
    }
    // Array -> Salva cada i do array
    char s2[]="uhul2";
    printf("s2=%s ",s2);
    printf("pointer de s2= %p %p %p\n",*s2,s2,&s2);
    for (int i=0;i<10;i++){
        printf("caractere de s2[%i]=%c, o código desse caractere é %i, o pointer desse caractere é %p\n",i,s2[i],s2[i],&s2[i]); //a string sempre finaliza com \0, o programa tá lendo a memória-lixo após a string
    }
    // Não dá pra modificar s1[0], mas dá pra modificar s2[0]
    printf("s1[0]=%c s2[0]=%c \n",s1[0],s2[0]);
    s2[0]='g'; // Array é modificável <- Tem quer ser single quotes por isso: https://stackoverflow.com/questions/3683602/single-quotes-vs-double-quotes-in-c-or-c
    printf("s1[0]=%c s2[0]=%c \n",s1[0],s2[0]);
    printf("%s %s",s1,s2);
    // s1[1]='b'; // Erro de Segmentation (pointer não é modificável)
    // printf("s1[0]=%c s2[0]=%c \n",s1[0],s2[0]);

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