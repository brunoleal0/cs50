//cheat sheet incluindo (mas não limitando) as principais informações do seguinte curso: https://www.youtube.com/watch?v=LfaMVlDaQ24

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
        v[i]=10+i;
        printf("v[%i]=%i\n",i,v[i]);
    }

    //POINTERS <- & retorna o Memory Adress de qualquer variável e * "Dereferencia" um pointer //https://youtu.be/2GDiXG5RfNE?t=404
    printf("\n-------POINTERS-------\n");
    int *pAge = NULL;
    int age = 20;
    printf("int age = %i;\nint *pAge = NULL;\n",age);

    // printf("%f",*pAge); //Não dá pra derefenciar algo que ainda não tem referência
    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge     |   %p   |  |   %p   |  |  Segmentation Fault |\n",&pAge,pAge);
    printf("    age      |   %p   |  |          %i          |  |                     |\n",&age,age);

    printf("\npAge = &age;\n");
    pAge = &age;

    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge     |   %p   |  |---%p---|  |         %i          |\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |          %i          |  |                     |\n",&age,age);

    printf("\n*pAge = 21;\n");
    *pAge = 21;

    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge     |   %p   |  |---%p---|  |         %i          |\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |          %i          |  |                     |\n",&age,age);

    printf("\nage = 22;\n");
    age = 22;

    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge     |   %p   |  |---%p---|  |         %i          |\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |          %i          |  |                     |\n",&age,age);
    printf("\n");

    // Memmory Deallocation (freeing memory to avoid memory leak)
    int *pAge2 = malloc(sizeof(pAge));
    *pAge2 = *pAge; // A dereferencia eh igual, mas o Value Stored eh diferente .:. se mudar a derefenrecia em pAge nao muda automaticamente em pAge2
    printf("int *pAge2 = malloc(sizeof(pAge));\n");
    printf("*pAge2 = *pAge; <- A dereferencia eh igual, mas o Value Stored eh diferente .:. se mudar a derefenrecia em pAge nao muda automaticamente em pAge2\n");
    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge2    |   %p   |  |   %p   |  |---------%i----------|\n",&pAge2,pAge2,*pAge2);
    printf("    pAge     |   %p   |  |---%p---|  |---------%i----------|\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |----------%i----------|  |                     |\n",&age,age);
    printf("\n");

    age=23;
    printf("age=23;\n");
    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge2    |   %p   |  |   %p   |  |         %i          |\n",&pAge2,pAge2,*pAge2);
    printf("    pAge     |   %p   |  |---%p---|  |---------%i----------|\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |----------%i----------|  |                     |\n",&age,age);
    printf("\n");

    free(pAge2);
    printf("free(pAge2);\n");
    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge2    |   %p   |  |   %p   |  |       %i       |\n",&pAge2,pAge2,*pAge2);
    printf("    pAge     |   %p   |  |---%p---|  |---------%i----------|\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |----------%i----------|  |                     |\n",&age,age);
    printf("\n");

    pAge2=NULL;
    printf("pAge2=NULL;\n");
    printf("____________  ______________________    ______________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored      |  | Dereference Pointer |\n");
    printf("    pAge2    |  Segmentation Fault  |  |  Segmentation Fault  |  |  Segmentation Fault |\n");
    printf("    pAge     |   %p   |  |---%p---|  |---------%i----------|\n",&pAge,pAge,*pAge);
    printf("    age      |---%p---|  |----------%i----------|  |                     |\n",&age,age);
    printf("\n");

    printf("\nSWAP WRONG\n");
    int a=1;
    int b=2;
    printf("a=%i b=%i\n",a,b);
    swap_wrong(a,b);
    printf("swap_wrong: a=%i b=%i\n\n",a,b);

    printf("\nSWAP RIGHT\n");
    int c=3;
    int d=4;
    printf("c=%i d=%i\n",c,d);  
    swap_right(&c,&d);
    printf("swap_right: c=%i d=%i\n",c,d);

    // int number_typed;
    // printf("Digite um Número: \n");
    // scanf("%d",&number_typed); //scan f pede como argumento o Memory Adress da variável
    // printf("Número digitado= %d",number_typed);2

    //STRINGS = Dois tipos: Character Pointer ou Array de Caracteres (Ambos têm \0 no final pra identificar o final da strng)
    printf("\n-------STRINGS-------\n");
    char singlecharacter='e';
    printf("single character= %c\n",singlecharacter);

    printf("\n::::::::::::::::::::Character Pointer::::::::::::::::::::\n");
    // Character Pointer -> Aponta pro começo e para no \0
    char *s1 = NULL;
    s1 = "uhul1"; //<- SALVA "uhul!\0" na memória e aponta para o começo do caractere u

    printf("char *s1 = NULL;\ns1 = \"uhul1\";\n");
    printf("____________  ______________________    ____________________    _____________________    _____________________    _____________________    _____________________    _____________________    _____________________\n");
    printf("VariableName |     Memory Adress    |  |    Value Stored    |  | Dereference Pointer |  |Dereference Pointer+1|  |Dereference Pointer+2|  |Dereference Pointer+3|  |Dereference Pointer+4|  |Dereference Pointer+5|\n");
    printf("    s1       |   %p   |  |         %s      |  |           %c         |  |           %c         |  |           %c         |  |           %c         |  |           %c         |  |           %c          |\n",s1,s1,*s1,*(s1+1),*(s1+2),*(s1+3),*(s1+4),*(s1+5));
    printf("\n");
    for (int i=0;i<10;i++){
        printf("caractere de *(s1+%i)=%c, o código desse caractere é %i, o memory adress desse caractere é %p\n",i,*(s1+i),*(s1+i),(s1+i));
    }
    printf("\n");
    
    // Array de caracteres -> Salva cada i no array
    printf("\n::::::::::::::::::::Array de caracteres::::::::::::::::::::\n");
    char s2[]="uhul2";

    printf("char s2 = \"uhul2\";\n");
    printf("____________  ______________________    ____________________    _____________________    _____________________    _____________________    _____________________    _____________________    _____________________\n");
    printf("VariableName |    Memory Adress     |  |    Value Stored    |  | Dereference Pointer |  |Dereference Pointer+1|  |Dereference Pointer+2|  |Dereference Pointer+3|  |Dereference Pointer+4|  |Dereference Pointer+5|\n");
    printf("    s2       |   %p   |  |         %s      |  |           %c         |  |           %c         |  |           %c         |  |           %c         |  |           %c         |  |           %c          |\n",&s2,s2,*s2,*(s2+1),*(s2+2),*(s2+3),*(s2+4),*(s2+5));
    printf("    s2       |   %p   |  |         %s      |  |           %c         |  |           %c         |  |           %c         |  |           %c         |  |           %c         |  |           %c          |\n",&s2,s2,s2[0],s2[1],s2[2],s2[3],s2[4],s2[5]);    
    printf("\n");
    for (int i=0;i<10;i++){
        printf("caractere de s2[%i]=%c, o código desse caractere é %i, o memory adress desse caractere é %p\n",i,s2[i],s2[i],&s2[i]);
    }

    // Não dá pra modificar s1[0], mas dá pra modificar s2[0]
    printf("*s1=%c s2[0]=%c \n",*s1,s2[0]);
    s2[0]='a'; // Array é modificável <- Tem quer ser single quotes por isso: https://stackoverflow.com/questions/3683602/single-quotes-vs-double-quotes-in-c-or-c
    printf("*s1=%c s2[0]=%c \n",*s1,s2[0]);
    printf("s1=%s s2=%s\n",s1,s2);
    // s1[0]='a'; // Erro de Segmentation (pointer não é modificável)
    // printf("s1[0]=%c s2[0]=%c \n",s1[0],s2[0]);

    // idealmente inicializa variaveis com malloc pra garantir espaoc na memoria
    char *s3 = malloc(6);
    for (int i = 0; i<6 ; i++){
        s3[i]=s2[i];
        printf("s2[%i]=%c s3[%i]=%c\n",i,s2[i],i,s3[i]);
    }
    printf("s3=%s\n",s3);

    //Recursion vs Loop
    printf("\n-------RECURSION vs LOOP-------\n");
    loop(4);
    recursion(5);
    int fat = fatorial(5);
    printf("%i\n",fat);

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
    printf("dentro x=%i y=%i\n",*x,*y);
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