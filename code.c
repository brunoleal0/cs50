//cheat sheet incluindo (mas não limitando) as principais informações do seguinte curso: https://www.youtube.com/watch?v=LfaMVlDaQ24

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> // inclui o tipo bool

//prototypes <- serve pra rodar no main as funções que são declaradas depois do main
void swap_wrong(int x, int y);
void swap_right(int *x, int*y);
void loop (int tamanho);
void recursion(int tamanho);
int fatorial(int numero);
void selection_sort();
void LL2BC();
void linked_list_2branches_crescente();
void BPLUS();

int main(void)
{
    printf("Hello, World!\n"); //<- Tem quer ser double quotes por isso: https://stackoverflow.com/questions/3683602/single-quotes-vs-double-quotes-in-c-or-c
    selection_sort();
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
    int *pAge2 = malloc(sizeof(pAge)); //malloc retorna NULL se nao houver mais memoria no programa
    //realloc serve pra realocar uma memoria previamente allocada (qdo vc quer aumentar o tamanho (fixo) de uma lista, por exemplo) https://youtu.be/LfaMVlDaQ24?t=43249
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

    printf("\n-------LINKED LIST-------\n");
    // Linked List https://youtu.be/ZNjg_7nxsz4?t=390
    LL2BC(); //Linked List 2 Branches Crescentes - eh uma BST com 2 branches, com excessao do original, cada node soh tem um filho

    // Binary Search Tree (BST): Pointers sao as estrutura basica de um arvore https://youtu.be/LfaMVlDaQ24?t=46940 https://www.youtube.com/watch?v=COZK7NATh4k https://www.youtube.com/watch?v=UbhlOk7vjVY https://www.geeksforgeeks.org/types-of-binary-tree/
    printf("\n-------B+ TREE-------\n");
    //BPLUS TREE O(logn) - usado em SQL https://youtu.be/UuncWF0Kuhw?list=PLXAjOiPf89kP8wP-njE2o0y9qnrwt6xUd&t=312 https://www.youtube.com/watch?v=K1a2Bk8NrYQ&t=79s
    BPLUS(); //https://www.geeksforgeeks.org/implementation-of-b-plus-tree-in-c/
    return 0;
}

typedef struct btreenode{
    int *values; //array com os valores daquele node
    int *idas; //pointers de ida daquele node
    bool leaf; //se o node eh leaf
    bool root; //se o node eh root
} btreenode;

typedef struct dados_no_sql{
    char *nome; //"string"
    int idade; //idade
    bool sexo; //Boolean: Feminino==true e Masculino==false
    char estado_civil; //caractere indicando Estado Civil
} dados_no_sql;

void btree_create();
void btree_insert();
void cria_dados(dados_no_sql *dado, char *nome, int idade, bool sexo, char estado_civil);

void BPLUS(){
    dados_no_sql *dado1=malloc(sizeof(dados_no_sql));
    char *nome1="Bruno";
    cria_dados(dado1,nome1,33,false,'S');


    int btree_order = 4;
    // criando o node0 da tree
    btreenode *node0= malloc(sizeof(btreenode));
    node0->root=true; node0->leaf=false;

    btree_insert(btree_order, node0, 20);
    printf("%p\n",node0);
}

void cria_dados(dados_no_sql *dado, char *nome, int idade, bool sexo, char estado_civil){
    printf("Roda cria_dados");
}

//-------------------------------------------------------------------- CRIANDO UMA B+ TREE --------------------------------------------------------------------//

void btree_insert(int order,btreenode *node, int value){ //insere um value num leaf node e executa todos os procedimentos necessarios pra balancear a tree
    if ((node->root)==true){
        if(1==1){
            printf("asdasd");
        }
    }
    else{
        printf("adsasd");
    }
}



//-------------------------------------------------------------------- ACABOU DE CRIAR UMA B+ TREE --------------------------------------------------------------------//

// struct: https://www.youtube.com/watch?v=oKXP1HZ8xIs <- eh basicamente uma classe
typedef struct treenode{ //4 dados em um no: o Valor armazenado, um pointer pra esquerda, um pointer pra direita, um pointer de volta
    int value;
    struct treenode *leftida;
    struct treenode *rightida;
    struct treenode *volta;
} treenode;

void LL2BC(){
    printf("\nsizeof(treenode)==%i\n",sizeof(treenode));

    printf("--criando node0\n");
    treenode *node0 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node0 -> value = 0;
    node0 -> leftida = NULL;
    node0 -> rightida = NULL;
    node0 -> volta = NULL;
    printf("value node0==%i\n", node0 -> value);
    printf("lugar na memória de node0==%p\n",node0);

    printf("--criando node1\n");
    treenode *node1 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node1 -> value = -100;
    node1 -> leftida = NULL;
    node1 -> rightida = NULL;
    node1 -> volta = NULL;
    printf("value node1==%i\n", node1 -> value);
    printf("lugar na memória de node1==%p\n",node1);

    printf("--criando node2\n");
    treenode *node2 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node2 -> value = -50;
    node2 -> leftida = NULL;
    node2 -> rightida = NULL;
    node2 -> volta = NULL;
    printf("value node1==%i\n", node2 -> value);
    printf("lugar na memória de node2==%p\n",node2);

    printf("--criando node3\n");
    treenode *node3 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node3 -> value = -70;
    node3 -> leftida = NULL;
    node3 -> rightida = NULL;
    node3 -> volta = NULL;
    printf("value node1==%i\n", node3 -> value);
    printf("lugar na memória de node3==%p\n",node3);

    printf("--criando node4\n");
    treenode *node4 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node4 -> value = 100;
    node4 -> leftida = NULL;
    node4 -> rightida = NULL;
    node4 -> volta = NULL;
    printf("value node1==%i\n", node4 -> value);
    printf("lugar na memória de node4==%p\n",node4);

    printf("--criando node5\n");
    treenode *node5 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node5 -> value = 50;
    node5 -> leftida = NULL;
    node5 -> rightida = NULL;
    node5 -> volta = NULL;
    printf("value node1==%i\n", node5 -> value);
    printf("lugar na memória de node5==%p\n",node5);

    printf("--criando node6\n");
    treenode *node6 = malloc(sizeof(treenode)); //https://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct
    node6 -> value = 70;
    node6 -> leftida = NULL;
    node6 -> rightida = NULL;
    node6 -> volta = NULL;
    printf("value node1==%i\n", node6 -> value);
    printf("lugar na memória de node6==%p\n",node6);

    linked_list_2branches_crescente(node0, node1);
    linked_list_2branches_crescente(node0, node2);
    linked_list_2branches_crescente(node0, node3);
    linked_list_2branches_crescente(node0, node4);
    linked_list_2branches_crescente(node0, node5);
    linked_list_2branches_crescente(node0, node6);

    printf("\n--APÓS TODAS AS ALOCAÇÕES:\n");
    printf("node0: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node0->value,node0,node0->leftida,node0->rightida,node0->volta);
    printf("node1: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node1->value,node1,node1->leftida,node1->rightida,node1->volta);
    printf("node2: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node2->value,node2,node2->leftida,node2->rightida,node2->volta);
    printf("node3: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node3->value,node3,node3->leftida,node3->rightida,node3->volta);
    printf("node4: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node4->value,node4,node4->leftida,node4->rightida,node4->volta);
    printf("node5: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node5->value,node5,node5->leftida,node5->rightida,node5->volta);
    printf("node6: valor=%i memória=%p leftida=%p rightida=%p volta=%p\n",node6->value,node6,node6->leftida,node6->rightida,node6->volta);
}

void linked_list_2branches_crescente(treenode *node0, treenode *node){
    printf("\n--Rodando alocação");
    treenode *ptr = node0; //pointer inicial do loop eh sempre no node0
    // printf("++node0=%p ptr=%p\n",node0,ptr);
    
    int loop=1;
    while(loop==1){ //isso eh basicamente uma linked list dupla em ordem crescente
        if((node->value)<=(ptr->value)){
            if(ptr->leftida==NULL){
                node->volta=ptr;
                ptr->leftida=node;
                loop=0;
            }
            else if ((node->value)<=((ptr->leftida)->value)){
                //pula pro proximo
                ptr=ptr->leftida;
            }
            else if ((node->value)>((ptr->leftida)->value)){
                //pluga, muda as conexões e encerra o while
                node->volta=ptr;
                (node->leftida)=(ptr->leftida);
                (ptr->leftida)->volta=node;
                ptr->leftida=node;
                loop=0;
            }
        }
        //
        else{
            if(ptr->rightida==NULL){
                ptr->rightida=node;
                node->volta=ptr;
                loop=0;
            }
            else if((node->value)<=((ptr->rightida)->value)){
                //pluga, muda as conexões e encerra o while
                node->volta=ptr;
                (node->rightida)=(ptr->rightida);
                (ptr->rightida)->volta=node;
                ptr->rightida=node;
                loop=0;
            }
            else if((node->value)>((ptr->rightida)->value)){
                //pula pro proximo
                ptr=ptr->rightida;
            }
        }
        printf("roda while\n");
    }

    printf("lugar na memória do node0==%p\n",node0);
    printf("value node0==%i\n", node0 -> value);
    printf("lugar na memória do node==%p\n",node);
    printf("value node==%i\n", node -> value);
    printf("node0leftida=%p\n",(node0->leftida));
    printf("node0rightida=%p\n",(node0->rightida));
    printf("nodeleftida=%p\n",(node->leftida));
    printf("noderightida=%p\n",(node->rightida));
    printf("nodevolta=%p\n",(node->volta));
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

void bubble_sort(){ // O(n²) trocar posicoes 2 a 2 ate sortear

}

void selection_sort(){ // O(n²) https://www.youtube.com/watch?v=EwjnF7rFLns <- eh diferente do selection sort do cs50
    int *vetor1 = malloc(7*sizeof(int));
    vetor1[0]=12;
    vetor1[1]=23;
    vetor1[2]=4;
    vetor1[3]=30;
    vetor1[4]=7;
    vetor1[5]=45;
    vetor1[6]=32;
    vetor1[7]=1;
    int tamanho=8;
    int lixo;
    int xminvalor;
    int xminposicao;

    for (int i=0;i<tamanho;i++){
        printf("vetor1[%i]=%i\n",i,vetor1[i]);
    }

    for (int i=0;i<tamanho;i++){
        printf("\niteracao %i\n",i);
        lixo = vetor1[i]; //salva o valor da celula
        xminvalor = vetor1[i];
        xminposicao=i;
        for (int x=i;x<tamanho;x++){
            if (vetor1[x]<xminvalor){
                xminvalor = vetor1[x];
                xminposicao = x;
            }
        }
        if (xminposicao != i){
            vetor1[xminposicao]=vetor1[i];
            vetor1[i]=xminvalor;
        }

        for (int i=0;i<tamanho;i++){
            printf("vetor1[%i]=%i\n",i,vetor1[i]);
        }
    }

    for (int i=0;i<tamanho;i++){
        printf("numeros do vetor: %i \n",vetor1[i]);
    }
}

void heap_sort(){ //O(n*log(n))

}

