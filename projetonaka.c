#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PETS no;

struct PETS
{
    char name[20];
    char type[20];
    char species[20];
    char sex;
    int age;
    char obs[30];
    struct PETS *prox;
};


void insert (no **inicio);//Insere novo registro
void name_search (no *inicio); // Busca por nome
void type_search (no *inicio); // Busca por raça
void TS_search (no *inicio); // Busca por raça e especie
void TSS_search (no *inico); // Busca por raça. especie e sexo
void counti (int count);// Contagem de animais nos registros
void T_counti (no *inicio); //Contagem por Especie
void list(no *inicio);// Listar os registros



int main ()
{

    no *inicio=NULL;
    int choice=0;
    int count=0; // contador de animais, colocar pra reduzir contador quanto fizer a função 2
    while(choice!=11)
    {
    printf("Escolha o que deseja fazer:\n\n 1- Adicionar novo registro \n 2- Remover Registro \n 3- Alterar Registro \n 4- Busca por Nome \n 5- Busca por Espécie \n 6- Busca por Espécie e Raça \n 7- Busca por Espécie, Raça e Sexo \n 8- Quantidade de Registros \n 9- Quantidade Específica por Espécie \n 10- Listagem de Cadastros \n 11- Sair \n");
    printf("\n\n");
    scanf("%d", &choice);
    printf("\n\n");
    switch(choice)
    {
        case 1:
        insert(&inicio);
        count++;
        break;

        case 4:
        name_search(inicio);
        break;

        case 5:
        type_search(inicio);
        break;

        case 6:
        TS_search(inicio);
        break;

        case 7:
        TSS_search(inicio);
        break;

        case 8:
        counti(count);
        break;

        case 9:
        T_counti(inicio);
        break;

        case 10:
        list(inicio);
        break;

    }
    }
}

void insert (no **inicio)
{
    no *aux;
    aux=(no*)malloc(sizeof(no));
    if(aux==NULL) {
        printf("Heap overflow \n");
    }
    fflush(stdin);
    printf("Nome: ");
    gets(aux->name);
    printf("Espécie: ");
    gets(aux->type);
    printf("Raça: ");
    gets(aux->species);
    printf("Sexo: ");
    scanf("%c", &aux->sex);
    printf("Idade: ");
    scanf("%d", &aux->age);
    fflush(stdin);
    printf("Observação: ");
    gets(aux->obs);
    printf("\n\n");
    aux->prox=(no*)(*inicio);
}

void name_search (no *inicio)

{
    char search[20];
    printf("Nome a ser buscado: ");
    gets(search);

    while(inicio!=NULL)
    {
       if(strcmp(inicio->name,search)==0)
       {
           printf("%s \n", inicio->name);
           printf("%s \n", inicio->type);
           printf("%s \n", inicio->species);
           printf("%c \n", inicio->sex);
           printf("%d \n", inicio->age);
           printf("%s \n", inicio->obs);
       }
       else
       {
           printf(" \n Registro não encontrado! \n\n");
       }
       inicio=inicio->prox;
    }
}



void type_search ( no *inicio)


{
    char search[20];
    printf("Grupo a ser procurado: ");
    gets(search);

    while (inicio->prox!=NULL)
    {
        if(strcmp(inicio->type,search)==0)
        {
           printf("%s \n", inicio->name);
           printf("%s \n", inicio->type);
           printf("%s \n", inicio->species);
           printf("%c \n", inicio->sex);
           printf("%d \n", inicio->age);
           printf("%s \n", inicio->obs);
        }
        else
        {
            printf("Sem animais dessa espécie disponíveis! \n\n");
        }
        inicio=inicio->prox;
    }
}


void TS_search( no *inicio)


{
    char search[20];
    char search2[20];
    printf("Especie a ser procurada: \n");
    gets(search);
    printf("Raça a ser procurada: \n");
    gets(search2);

    while (inicio->prox!=NULL)
    {
        if((strcmp(inicio->species,search)==0) && (strcmp(inicio->type,search2)==0))
        {
           printf("%s \n", inicio->name);
           printf("%s \n", inicio->type);
           printf("%s \n", inicio->species);
           printf("%c \n", inicio->sex);
           printf("%d \n", inicio->age);
           printf("%s \n", inicio->obs);
        }
        else
        {
            printf("Animais não encontrados: \n");
        }
        inicio=inicio->prox;
    }
}

void TSS_search( no *inicio)


{
    char search[20];
    char search2[20];
    char search3;
    printf("Especie a ser procurada: \n");
    gets(search);
    printf("Raça a ser procurada: \n");
    gets(search2);
    printf("Sexo do animal: \n F para femeas \n M para machos");
    scanf("%c", &search3);
    while (inicio->prox!=NULL)
    {
        if((strcmp(inicio->species,search)==0) && (strcmp(inicio->type,search2)==0) && (inicio->sex==search3))
        {
           printf("%s \n", inicio->name);
           printf("%s \n", inicio->type);
           printf("%s \n", inicio->species);
           printf("%c \n", inicio->sex);
           printf("%d \n", inicio->age);
           printf("%s \n", inicio->obs);
        }
        else
        {
            printf("Animais não encontrados: \n");
        }
        inicio=inicio->prox;
    }
}


void counti (int count)
{
    printf("Numero de animais nos registros: %d \n\n", count);
}


void T_counti(no *inicio)
{
    int count=0;
    char search[20];
    printf("Especie a contar: ");
    gets(search);

    while(inicio!=NULL)
    {
       if(strcmp(inicio->type,search)==0)
       {
           count++;
       }
    }
    printf("Numero de animais dessa espécie: %d \n\n", count);
}

void list (no *inicio)
{
    while(inicio->prox!=NULL)
    {
        printf("%s \n", inicio->name);
        printf("%s \n", inicio->type);
        printf("%s \n", inicio->species);
        printf("%c \n", inicio->sex);
        printf("%d \n", inicio->age);
        printf("%s \n", inicio->obs);
    }
}