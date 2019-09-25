
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
    char status[10];
    struct PETS *prox;
};

void insert (int id, no *head); // insere nó
void removeNode (int *maximo, no **head); // remove nó
void alterNode (no *head); //altera nó
void name_search (no *head); // Busca por nome
void type_search (no *head); // Busca por raça
void TS_search (no *head); // Busca por raça e especie
void TSS_search (no *head); // Busca por raça. especie e sexo
void counti (no *head, int count);// Contagem de animais nos registros
void T_counti (no *head); //Contagem por Especie
void list(no *head);// Listar os registros
void statusList (no *head); //Listar os animais já adotados
void TStatusList (no *head); //Listar animais de uma espécie já adotados



int main ()
{
    setlocale(LC_ALL, "portuguese");
    no *head = (no*)malloc(sizeof(no));
    head->id = 0;
    head->prox = NULL;
    int choice=0;
    int count=0; // contador de animais, colocar pra reduzir contador quanto fizer a função 2
    while(choice!=13)
    {
        system("cls");
        printf("Escolha o que deseja fazer:\n\n 1- Adicionar novo registro \n 2- Remover Registro \n 3- Alterar Registro \n 4- Busca por Nome \n 5- Busca por Espécie \n 6- Busca por Espécie e Raça \n 7- Busca por Espécie, Raça e Sexo \n 8- Quantidade de Registros \n 9- Quantidade Específica por Espécie \n 10- Listagem de Cadastros \n 11 - Listar Animais já Adodatos \n 12 - Buscar por espécie de animais já adotados \n 13 - Sair \n");
        printf("\n\nDigite a opção: ");
        scanf("%d", &choice);
        printf("\n\n");
        switch(choice)
        {
            case 1:
                insert((head->id) + 1, head);
                count++;
                break;

            case 2:
                removeNode(&count, &head);
                break;

            case 3:
                alterNode(head);
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
                counti(head, count);
                break;

            case 9:
                T_counti(head);
                break;

            case 10:
                list(head);
                break;

            case 11:
                statusList(head);
                break;

            case 12:
            TStatusList(head);

            default:
                break;
        }
    }
}

void insert (int id, no *head) {
    //create a link
    no *pNovo = (no*) malloc(sizeof(no));
    if (pNovo == NULL) {
        printf("Heap overflow!");
        return;
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
    printf("Status(Disponível/Adotado): ");
    gets(pNovo->status);
    printf("\n\n");
    printf("Animal cadastrado!\n\n");
    system("pause");

   //point it to old first node
   pNovo->prox = head->prox;
   head->prox = pNovo;
   (head->id)++;
}

void removeNode(int *maximo, no **head) {
    if ((*head)->prox == NULL) { //LISTA VAZIA
        printf("Não há animais cadastrados!\n\n");
        system("pause");
        return;
    }

    int id;
    printf("Digite o ID do animal que deseja excluir do registro: ");
    fflush(stdin);
    scanf("%d", &id);

    no *pAux = NULL;

    if ((*head)->prox->id == id) {
        pAux = (*head)->prox;
        (*head)->prox = (*head)->prox->prox;
        free(pAux);
        printf("Registro excluído!\n\n");
        system("pause");
        return;
    }

    for (pAux=(*head)->prox; pAux!=NULL; pAux=pAux->prox) {
        if (pAux->prox->id == id) {
            no *pAux2 = pAux->prox;
            pAux->prox = pAux->prox->prox;
            free(pAux2);
            printf("Registro excluído!\n\n");
            system("pause");
            return;
        }
    }
}

void alterNode (no *head) {
    no *pAux = NULL;
    int id=0;
    int choice=0;
    fflush(stdin);
    printf("Digite o ID do registro que deseja alterar: \n");
    scanf("%d", &id);

    while(head !=NULL){
        pAux = head->prox;
        if(head->id == id){
            fflush(stdin);
            while(choice!=9)
            {
                system("cls");
                printf("\n\nQual informação deseja alterar?\n\n1 - Nome\n2 - Espécie\n3 - Raça\n4 - Sexo\n5 - Idade\n6 - Observações\n7 - Status\n8 - Refazer Cadastro\n9 - Sair\n");
                printf("\nDigite a opção: ");
                scanf("%d", &choice);
                printf("\n\n");
                switch(choice)
                {
                    case 1:
                        fflush(stdin);
                        printf("Novo Nome: ");
                        gets(pAux->name);
                        break;

                    case 2:
                        fflush(stdin);
                        printf("Nova Espécie: ");
                        gets(pAux->type);
                        break;

                    case 3:
                        fflush(stdin);
                        printf("Nova Raça: ");
                        gets(pAux->species);
                        break;

                    case 4:
                        fflush(stdin);
                        printf("Novo Sexo: ");
                        scanf("%c", &pAux->sex);
                        break;

                    case 5:
                        fflush(stdin);
                        printf("Nova Idade: ");
                        scanf("%d", &pAux->age);
                        break;

                    case 6:
                        fflush(stdin);
                        printf("Novas Observações: ");
                        gets(pAux->obs);
                        break;

                    case 7:
                        fflush(stdin);
                        printf("Atualizar Status: ");
                        gets(pAux->status);
                        break;

                    case 8:
                        fflush(stdin);
                        printf("Nome: ");
                        gets(pAux->name);
                        printf("Espécie: ");
                        gets(pAux->type);
                        printf("Raça: ");
                        gets(pAux->species);
                        printf("Sexo (M ou F): ");
                        scanf("%c", &pAux->sex);
                        printf("Idade: ");
                        scanf("%d", &pAux->age);
                        fflush(stdin);
                        printf("Observação: ");
                        gets(pAux->obs);
                        printf("Status: ");
                        gets(pAux->status);
                        break;

                    default:
                        return;
                }
            }
        }
    }
}

void name_search (no *head)
{
    char search[20];
    int cont = 1;
    int maximo = head->id;
    printf("Nome do Pet que deseja procurar: ");
    fflush(stdin);
    gets(search);
    no *pAux = head->prox;

    while(pAux!=NULL)
    {
       if(strcmp(pAux->name, search)==0)
       {
           printf("\nNome: %s \n", pAux->name);
           printf("Espécie: %s \n", pAux->type);
           printf("Raça: %s \n", pAux->species);
           printf("Sexo (M ou F): %c \n", pAux->sex);
           printf("Idade: %d \n", pAux->age);
           printf("Observações: %s \n", pAux->obs);
           printf("Status: %s \n", head->status);
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
        printf("\nNenhum animal cadastrado!");
        return;
    }

    char search[20];
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;
    printf("maximo: %d \n\n", maximo);
    fflush(stdin);
    printf("Espécie dos Pets que deseja procurar: ");
    gets(search);

    head=head->prox;

    while (head != NULL) {
        if (strcmp(head->type, search) == 0) {
           printf("Nome: %s \n", head->name);
           printf("Espécie: %s \n", head->type);
           printf("Raça: %s \n", head->species);
           printf("Sexo: %c \n", head->sex);
           printf("Idade: %d \n", head->age);
           printf("Obs: %s \n", head->obs);
           printf("Status %s \n", head->status);
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
           printf("Nome: %s \n", head->name);
           printf("Espécie: %s \n", head->type);
           printf("Raça: %s \n", head->species);
           printf("Sexo: %c \n", head->sex);
           printf("Idade: %d \n", head->age);
           printf("Obs: %s \n", head->obs);
           printf("Status: %s \n", head->status);
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
        printf("Nenhum animal cadastrado!\n");
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
           printf("Nome: %s \n", head->name);
           printf("Espécie: %s \n", head->type);
           printf("Raça: %s \n", head->species);
           printf("Sexo: %c \n", head->sex);
           printf("Idade: %d \n", head->age);
           printf("Obs: %s \n", head->obs);
           printf("Status: %s \n", head->status);
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("\nSem animais desse tipo disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
}


void counti (no *head, int count)
{
    if (count == 0) {
        printf("\nNenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }
    printf("\nNumero de animais nos registros: %d \n\n", count);
    system("pause");
}


void T_counti(no *head)
{
    int count=0;
    char search[20];
    printf("\nEspecie que deseja contar: ");
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
        printf("\nNão há animais dessa espécie cadastrados!\n");
        system("pause");
        return;
    }

    printf("\nNumero de animais dessa espécie: %d \n\n", count);
    system("pause");
}

void list (no *head)
{

    head = head->prox;

    while(head!=NULL)
    {
        printf("ID: %d\n", head->id);
        printf("Nome: %s \n", head->name);
        printf("Especie: %s \n", head->type);
        printf("Raça: %s \n", head->species);
        printf("Sexo: %c \n", head->sex);
        printf("Idade: %d \n", head->age);
        printf("Obs: %s \n", head->obs);
        printf("Status: %s\n\n", head->status);
        head = head->prox;
    }
    system("pause");
}

void statusList (no *head)
{
    int cont = 1;
    int maximo = head->id;
    no *pAux = head->prox;

    while(pAux!=NULL){
       if(strcmp(pAux->status, "Adotado")==0)
       {
           printf("\nNome: %s \n", pAux->name);
           printf("Espécie: %s \n", pAux->type);
           printf("Raça: %s \n", pAux->species);
           printf("Sexo (M ou F): %c \n", pAux->sex);
           printf("Idade: %d \n", pAux->age);
           printf("Observações: %s \n\n\n", pAux->obs);
           break;
       }
       else if (cont == maximo)
       {
           printf(" \n Nenhum animal foi adotado ainda! \n\n");
       }
       pAux=pAux->prox;
       cont++;
    }
    system("pause");
}

void TStatusList (no *head)
{
    if (head->prox == NULL) {
        printf("\nNenhum animal cadastrado!");
        return;
    }

    char search[20];
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;
    fflush(stdin);
    printf("Espécie dos Pets que deseja procurar: ");
    gets(search);

    head=head->prox;

    while (head != NULL) {
        if (strcmp((head->type), search) == 0 && (strcmp((head->status), "Adotado") == 0))
        {
           printf("Nome: %s \n", head->name);
           printf("Espécie: %s \n", head->type);
           printf("Raça: %s \n", head->species);
           printf("Sexo: %c \n", head->sex);
           printf("Idade: %d \n", head->age);
           printf("Obs: %s \n", head->obs);
           printf("Status %s \n", head->status);
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("Sem animais dessa espécie adotados! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
}

