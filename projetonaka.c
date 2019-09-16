#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PETS no;

struct PETS
{
    int id;
    char name[20];
    char type[20];
    char species[20];
    char sex;
    int age;
    char obs[30];
    short int adotado;
    struct PETS *prox;
} *inicio = NULL, *aux = NULL;

void insert (int id);
void removeNode (no **inicio);
void name_search (int maximo); // Busca por nome
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
        system("cls");
        printf("Escolha o que deseja fazer:\n\n 1- Adicionar novo registro \n 2- Remover Registro \n 3- Alterar Registro \n 4- Busca por Nome \n 5- Busca por Espécie \n 6- Busca por Espécie e Raça \n 7- Busca por Espécie, Raça e Sexo \n 8- Quantidade de Registros \n 9- Quantidade Específica por Espécie \n 10- Listagem de Cadastros \n 11- Sair \n");
        printf("\n\n");
        scanf("%d", &choice);
        printf("\n\n");
        switch(choice)
        {
            case 1:
                count++;
                insert(count);
                break;

            case 2:
                removeNode(&inicio);
                count--;
                break;

            case 4:
            name_search(count);
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

void insert (int id) {
    //create a link
    no *pNovo = (no*) malloc(sizeof(no));

    pNovo->id = id;
    fflush(stdin);
    printf("Nome: ");
    gets(pNovo->name);
    printf("Espécie: ");
    gets(pNovo->type);
    printf("Raça: ");
    gets(pNovo->species);
    printf("Sexo (M ou F): ");
    scanf("%c", &pNovo->sex);
    printf("Idade: ");
    scanf("%d", &pNovo->age);
    fflush(stdin);
    printf("Observação: ");
    gets(pNovo->obs);
    printf("\n\n");
	
   //point it to old first node
   pNovo->prox = inicio;
	
   //point first to new first node
   inicio = pNovo;
}

void removeNode (no **inicio) {

    int id;

    printf("Digite o ID do animal o qual deseja excluir o registro: ");
    scanf("%d", &id);

    no *pPaux = NULL, *pProx = NULL;
    pPaux = *inicio;
    pProx = pPaux->prox;
    for (; pPaux != NULL; pPaux=pPaux->prox) {
        pProx = pPaux->prox;
        if (pProx->id == id) {
            pPaux->prox = pProx->prox;
            free(pProx);
            break;
        }            
    }

    printf("Registro excluído!");
}

void name_search (int maximo)
{
    char search[20];
    int cont = 1;
    printf("Nome a ser buscado: ");
    fflush(stdin);
    gets(search);
    no *pAux = inicio;

    while(pAux!=NULL)
    {
       if(strcmp(pAux->name,search)==0)
       {
           printf("\n\nNome: %s \n", pAux->name);
           printf("Espécie: %s \n", pAux->type);
           printf("Raça: %s \n", pAux->species);
           printf("Sexo (M ou F): %c \n", pAux->sex);
           printf("Idade: %d \n", pAux->age);
           printf("Observações: %s \n\n\n", pAux->obs);
           break;
       }
       else if (cont == maximo)
       {
           printf(" \n Registro não encontrado! \n\n");
       }
       pAux=pAux->prox;
       cont++;
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