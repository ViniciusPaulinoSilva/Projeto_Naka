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

int insert (int id, no *head);
void removeNode (no **inicio);
void name_search (no *head); // Busca por nome
void type_search (no *head); // Busca por raça
void TS_search (no *head); // Busca por raça e especie
void TSS_search (no *head); // Busca por raça. especie e sexo
void counti (no *head);// Contagem de animais nos registros
void T_counti (no *head); //Contagem por Especie
void list(no *head);// Listar os registros



int main ()
{
    no *head = (no*)malloc(sizeof(no));
    head->id = 0;
    head->prox = NULL;
    int choice=0;
    int count=0; // contador de animais, colocar pra reduzir contador quanto fizer a função 2
    while(choice!=11)
    {
        system("cls");
        printf("Escolha o que deseja fazer:\n\n 1- Adicionar novo registro \n 2- Remover Registro \n 3- Alterar Registro \n 4- Busca por Nome \n 5- Busca por Espécie \n 6- Busca por Espécie e Raça \n 7- Busca por Espécie, Raça e Sexo \n 8- Quantidade de Registros \n 9- Quantidade Específica por Espécie \n 10- Listagem de Cadastros \n 11- Sair \n");
        printf("\n\nDigite a opção: ");
        scanf("%d", &choice);
        printf("\n\n");
        switch(choice)
        {
            case 1:
                insert((head->id) + 1, head);
                break;

            case 2:
                removeNode(&head);
                count--;
                break;

            case 4:
                name_search(head);
                break;

            case 5:
                type_search(head);
                break;

            case 6:
                TS_search(head);
                break;

            case 7:
                TSS_search(head);
                break;

            case 8:
                counti(head);
                break;

            case 9:
                T_counti(head);
                break;

            case 10:
                list(head);
                break;
            
            default:
                break;

        }
    }
}

int insert (int id, no *head) {
    //create a link
    no *pNovo = (no*) malloc(sizeof(no));
    if (pNovo == NULL) {
        printf("Heap overflow!");
        return -1;
    }

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
   pNovo->prox = head->prox;
   head->prox = pNovo;
   (head->id)++;
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

void name_search (no *head)
{
    char search[20];
    int cont = 1;
    int maximo = head->id;
    printf("Nome a ser buscado: ");
    fflush(stdin);
    gets(search);
    no *pAux = head->prox;

    while(pAux!=NULL)
    {
       if(strcmp(pAux->name, search)==0)
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
    system("pause");
}



void type_search (no *head)
{
    if (head->prox == NULL) {
        printf("Nenhum animal cadastrado!");
        return;
    }

    char search[20];
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;
    printf("maximo: %d \n\n", maximo);
    fflush(stdin);
    printf("Espécie a ser procurado: ");
    gets(search);
    
    head=head->prox;

    while (head != NULL) {
        if (strcmp(head->type, search) == 0) {
           printf("%s \n", head->name);
           printf("%s \n", head->type);
           printf("%s \n", head->species);
           printf("%c \n", head->sex);
           printf("%d \n", head->age);
           printf("%s \n", head->obs);
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("Sem animais dessa espécie disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
}


void TS_search(no *head)
{
    if (head->prox == NULL) {
        printf("Nenhum animal cadastrado!");
        return;
    }

    char searchSpecies[20];
    char searchType[20];
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;

    printf("Especie a ser procurada: \n");
    fflush(stdin);
    gets(searchSpecies);
    printf("Raça a ser procurada: \n");
    fflush(stdin);
    gets(searchType);

    head=head->prox;

    while (head!=NULL)
    {
        if((strcmp(head->type, searchSpecies) == 0) && (strcmp(head->species, searchType) == 0))
        {
           printf("%s \n", head->name);
           printf("%s \n", head->type);
           printf("%s \n", head->species);
           printf("%c \n", head->sex);
           printf("%d \n", head->age);
           printf("%s \n", head->obs);
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("Sem animais desse tipo disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
}

void TSS_search( no *head)
{
    if (head->prox == NULL) {
        printf("Nenhum animal cadastrado!");
        return;
    }

    char searchSpecies[20];
    char searchType[20];
    char searchSex;
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;

    printf("Especie a ser procurada: \n");
    fflush(stdin);
    gets(searchSpecies);
    printf("Raça a ser procurada: \n");
    fflush(stdin);
    gets(searchType);
    printf("Sexo do animal (F/M): \n");
    fflush(stdin);
    scanf("%c", &searchSex);

    head=head->prox;

    while (head!=NULL)
    {
        if((strcmp(head->type, searchSpecies) == 0) && (strcmp(head->species, searchType) == 0) && (head->sex == searchSex))
        {
           printf("%s \n", head->name);
           printf("%s \n", head->type);
           printf("%s \n", head->species);
           printf("%c \n", head->sex);
           printf("%d \n", head->age);
           printf("%s \n", head->obs);
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("Sem animais desse tipo disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
}


void counti (no *head)
{
    if (head->id == 0) {
        printf("Nenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }
    printf("Numero de animais nos registros: %d \n\n", head->id);
    system("pause");
}


void T_counti(no *head)
{
    int count=0;
    char search[20];
    printf("Especie a contar: ");
    fflush(stdin);
    gets(search);

    head = head->prox;

    while(head!=NULL)
    {
       if(strcmp(head->type,search)==0)
       {
           count++;
       }
       head = head->prox;
    }
    if (count == 0) {
        printf("Não há animais dessa espécie cadastrados!");
        system("pause");
        return;
    }

    printf("Numero de animais dessa espécie: %d \n\n", count);
    system("pause");
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
    system("pause");
}