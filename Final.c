

/*********************************************************************************************
* Nomes: Gabriel Freitas Yamamoto e Vinicius Paulino da Silva       RAs: 19241611 e 18713529 *
* Opcionais funcionando: 1 e 2 e 4                                                           *
* Valor do Projeto: 10 pontos                                                                *
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include "tela.h"

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
    time_t criado;
    time_t alteracao;
    struct PETS *prox;
};

void insert (int id, no *head, time_t inicio); // insere nó
void removeNode (int *maximo, no **head); // remove nó
void alterNode (int maximo, no *head); //altera nó
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
	time_t inicio, atual;
	clock_t milisseg;
	struct tm * timeinfo;
    time(&inicio);        // Pega o horario inicial

    textbackground(AZUL_ESCURO);
    textcolor(CINZA);
    setlocale(LC_ALL, "portuguese");
    no *head = (no*)malloc(sizeof(no));
    head->id = 0;
    head->prox = NULL;
    int choice=0;
    int count=0; // contador de animais
    while(choice!=13)
    {
        system("cls");
        printf("Escolha o que deseja fazer:\n\n 1- Adicionar novo registro \n 2- Remover Registro \n 3- Alterar Registro \n 4- Busca por Nome \n 5- Busca por Espécie \n 6- Busca por Espécie e Raça \n 7- Busca por Espécie, Raça e Sexo \n 8- Quantidade de Registros \n 9- Quantidade Específica por Espécie \n 10- Listagem de Cadastros \n 11 - Listar Animais já Adodatos \n 12 - Buscar por espécie de animais já adotados \n 13 - Sair \n");
        printf("\n\nDigite a opção: ");
		scanf("%d", &choice);
        printf("\n\n");
        textcolor(CINZA);
        switch(choice)
        {
            case 1:
                insert((head->id) + 1, head, inicio);
                count++;
                break;

            case 2:
                removeNode(&count, &head);
                break;

            case 3:
                alterNode(count, head);
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

void insert (int id, no *head, time_t inicio) {
    //create a link
    no *pNovo = (no*) malloc(sizeof(no));
    if (pNovo == NULL) {
        printf("Heap overflow!");
        return;
    }

    time_t atual;

    pNovo->id = id;
    fflush(stdin);
    printf("Nome: ");
    fflush(stdin);
    gets(pNovo->name);
    printf("Espécie: ");
    fflush(stdin);
    gets(pNovo->type);
    printf("Raça: ");
    fflush(stdin);
    gets(pNovo->species);
    printf("Sexo (M ou F): ");
    fflush(stdin);
    scanf("%c", &pNovo->sex);
    printf("Idade: ");
    fflush(stdin);
    scanf("%d", &pNovo->age);
    fflush(stdin);
    printf("Observação: ");
    gets(pNovo->obs);
    printf("Status (Disponível/Adotado): ");
    fflush(stdin);
    gets(pNovo->status);
    printf("\n\n");
    time(&atual);
    pNovo->criado = atual;
    pNovo->alteracao = pNovo->criado;
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
    printf("Digite o ID do animal que deseja excluir dos registros: ");
    fflush(stdin);
    scanf("%d", &id);

    no *pAux = NULL;

    if ((*head)->prox->id == id) {
        pAux = (*head)->prox;
        (*head)->prox = (*head)->prox->prox;
        free(pAux);
        *maximo = *maximo-1;
        printf("\nRegistro excluído!\n\n");
        system("pause");
        return;
    }

    int cont = 1;
    pAux=(*head)->prox;

    if (pAux->prox==NULL) {
        printf("\nRegistro não encontrado!\n\n");
        system("pause");
        return;
    }

    for (; pAux->prox!=NULL; pAux=pAux->prox) {
        if (pAux->prox->id == id) {
            no *pAux2 = pAux->prox;
            pAux->prox = pAux->prox->prox;
            free(pAux2);
            *maximo = *maximo-1;
            printf("\nRegistro excluído!\n\n");
            system("pause");
            return;
        }
        cont++;
        if (cont == *maximo) {
            printf("\nRegistro não encontrado!\n\n");
            system("pause");
            return;
        }
    }
}

void alterNode (int maximo, no *head) {
    if (head->prox == NULL) {
        printf("\nNão há animais cadastrados!\n\n");
        system("pause");
        return;
    }
    no *pAux = NULL;
    int id=0, cont = 1;
    int choice=0;
    fflush(stdin);
    printf("Digite o ID do registro que deseja alterar: \n");
    scanf("%d", &id);

    for (pAux=head->prox; pAux!=NULL; pAux=pAux->prox) {
        if (pAux->id == id) {
            textbackground(CIANO_ESCURO);
            textcolor(AMARELO);
            system("cls");
            while (choice != 9) {
                printf("\n\nQual informação deseja alterar?\n\n1 - Nome\n2 - Espécie\n3 - Raça\n4 - Sexo\n5 - Idade\n6 - Observações\n7 - Status\n8 - Refazer Cadastro\n9 - Sair\n");
                printf("\nDigite a opção: ");
                scanf("%d", &choice);
                printf("\n\n");
                time_t atual;
                switch(choice) {
                    case 1:
                        fflush(stdin);
                        printf("Novo Nome: ");
                        gets(pAux->name);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    case 2:
                        fflush(stdin);
                        printf("Nova Espécie: ");
                        gets(pAux->type);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    case 3:
                        fflush(stdin);
                        printf("Nova Raça: ");
                        gets(pAux->species);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    case 4:
                        fflush(stdin);
                        printf("Novo Sexo: ");
                        scanf("%c", &pAux->sex);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    case 5:
                        fflush(stdin);
                        printf("Nova Idade: ");
                        scanf("%d", &pAux->age);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    case 6:
                        fflush(stdin);
                        printf("Novas Observações: ");
                        gets(pAux->obs);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    case 7:
                        fflush(stdin);
                        printf("Atualizar Status: ");
                        gets(pAux->status);
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
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
                        time(&atual);
                        pAux->alteracao = atual;
                        printf("\nRegistro alterado! \n\n");
                        system("pause");
                        break;

                    default:
                        textbackground(AZUL_ESCURO);
                        textcolor(CINZA);
                        return;
                }
                system("cls");
            }
            return;
        }
    }

    printf("\nID não registrado nos registros!\n\n");
    system("pause");
}

void name_search (no *head) {
    if (head->prox == NULL) {
        printf("\nNenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }

    char search[20];
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;
    fflush(stdin);
    printf("\nNome dos Pets que deseja procurar: ");
    gets(search);

    head=head->prox;

    while (head != NULL) {
        if (strcmp(head->type, search) == 0) {
            textcolor(VERDE);
            struct tm* timeinfo = localtime(&head->criado);
            printf("\n\nNome: %s \n", head->name);
            printf("Espécie: %s \n", head->type);
            printf("Raça: %s \n", head->species);
            printf("Sexo: %c \n", head->sex);
            printf("Idade: %d \n", head->age);
            printf("Observação: %s \n", head->obs);
            printf("Status: %s \n", head->status);
            struct tm* criadoInfo = localtime(&head->criado);
            printf("Criado dia: %d/%d/%d as %d:%d\n",
                criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
            if (difftime(head->alteracao, head->criado) != 0) {
                struct tm* alterInfo = localtime(&head->alteracao);
                printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                    alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
            }
            printf("\n");
            achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("\nSem animais com esse nome disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
    textcolor(CINZA);
}

void type_search (no *head)
{
    if (head->prox == NULL) {
        printf("\nNenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }

    char search[20];
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;
    fflush(stdin);
    printf("\nEspécie dos Pets que deseja procurar: ");
    gets(search);

    head=head->prox;

    while (head != NULL) {
        if (strcmp(head->type, search) == 0) {
            textcolor(VERDE);
            struct tm* timeinfo = localtime(&head->criado);
            printf("\n\nNome: %s \n", head->name);
            printf("Espécie: %s \n", head->type);
            printf("Raça: %s \n", head->species);
            printf("Sexo: %c \n", head->sex);
            printf("Idade: %d \n", head->age);
            printf("Observação: %s \n", head->obs);
            printf("Status: %s \n", head->status);
            struct tm* criadoInfo = localtime(&head->criado);
            printf("Criado dia: %d/%d/%d as %d:%d\n",
                criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
            if (difftime(head->alteracao, head->criado) != 0) {
                struct tm* alterInfo = localtime(&head->alteracao);
                printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                    alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
            }
            printf("\n");
            achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("\nSem animais dessa espécie disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
    textcolor(CINZA);
}


void TS_search(no *head)
{
    if (head->prox == NULL) {
        printf("Nenhum animal cadastrado!\n\n");
        system("pause");
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
            textcolor(VERDE);
           printf("\n\nNome: %s \n", head->name);
           printf("Espécie: %s \n", head->type);
           printf("Raça: %s \n", head->species);
           printf("Sexo: %c \n", head->sex);
           printf("Idade: %d \n", head->age);
           printf("Obs: %s \n", head->obs);
           printf("Status: %s \n\n", head->status);
            struct tm* criadoInfo = localtime(&head->criado);
            printf("Criado dia: %d/%d/%d as %d:%d\n",
                criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
            if (difftime(head->alteracao, head->criado) != 0) {
                struct tm* alterInfo = localtime(&head->alteracao);
                printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                    alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
            }
            printf("\n");
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("Sem animais desse tipo disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
    textcolor(CINZA);
}

void TSS_search(no *head)
{
    if (head->prox == NULL) {
        printf("Nenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }

    char searchSpecies[20];
    char searchType[20];
    char searchSex;
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;

    printf("Especie a ser procurada: ");
    fflush(stdin);
    gets(searchSpecies);
    printf("Raça a ser procurada: ");
    fflush(stdin);
    gets(searchType);
    printf("Sexo do animal (F/M): ");
    fflush(stdin);
    scanf("%c", &searchSex);

    head=head->prox;

    while (head!=NULL)
    {
        if((strcmp(head->type, searchSpecies) == 0) && (strcmp(head->species, searchType) == 0) && (tolower(head->sex) == tolower(searchSex)))
        {
            textcolor(VERDE);
           printf("\n\nNome: %s \n", head->name);
           printf("Espécie: %s \n", head->type);
           printf("Raça: %s \n", head->species);
           printf("Sexo: %c \n", head->sex);
           printf("Idade: %d \n", head->age);
           printf("Obs: %s \n", head->obs);
           printf("Status: %s \n", head->status);
            struct tm* criadoInfo = localtime(&head->criado);
            printf("Criado dia: %d/%d/%d as %d:%d\n",
                criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
            if (difftime(head->alteracao, head->criado) != 0) {
                struct tm* alterInfo = localtime(&head->alteracao);
                printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                    alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
            }
            printf("\n");
           achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("\nSem animais desse tipo disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
    textcolor(CINZA);
}


void counti (no *head, int count)
{
    if (count == 0) {
        printf("\nNenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }
    textcolor(VERDE);
    printf("\nNumero de animais nos registros: %d \n\n", count);
    system("pause");
    textcolor(CINZA);
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
            textcolor(VERDE);
        printf("\n\nNão há animais dessa espécie cadastrados!\n");
        system("pause");
        textcolor(CINZA);
        return;
    }
    textcolor(VERDE);
    printf("\n\nNumero de animais dessa espécie: %d \n\n", count);
    system("pause");
    textcolor(CINZA);
}

void list (no *head)
{

    head = head->prox;

    while(head!=NULL)
    {
        textcolor(VERDE);
        printf("\nID: %d\n", head->id);
        printf("Nome: %s \n", head->name);
        printf("Especie: %s \n", head->type);
        printf("Raça: %s \n", head->species);
        printf("Sexo: %c \n", head->sex);
        printf("Idade: %d \n", head->age);
        printf("Obs: %s \n", head->obs);
        printf("Status: %s\n", head->status);
        struct tm* criadoInfo = localtime(&head->criado);
        printf("Criado dia: %d/%d/%d as %d:%d\n",
            criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
        if (difftime(head->alteracao, head->criado) != 0) {
            struct tm* alterInfo = localtime(&head->alteracao);
            printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
        }
        printf("\n");
        head = head->prox;
    }
    system("pause");
    textcolor(CINZA);
}

void statusList (no *head){
    if (head->prox == NULL){
        printf("\nNenhum animal cadastrado!\n\n");
        system("pause");
        return;
    }
    int maximo = head->id;
    int cont = 1;
    short int achou = 0;
    fflush(stdin);

    head=head->prox;

    while (head != NULL) {
        if (strcmp(head->status, "Adotado") == 0) {
            textcolor(VERDE);
            struct tm* timeinfo = localtime(&head->criado);
            printf("\n\nNome: %s \n", head->name);
            printf("Espécie: %s \n", head->type);
            printf("Raça: %s \n", head->species);
            printf("Sexo: %c \n", head->sex);
            printf("Idade: %d \n", head->age);
            printf("Observação: %s \n", head->obs);
            printf("Status: %s \n", head->status);
            struct tm* criadoInfo = localtime(&head->criado);
            printf("Criado dia: %d/%d/%d as %d:%d\n",
                criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
            if (difftime(head->alteracao, head->criado) != 0) {
                struct tm* alterInfo = localtime(&head->alteracao);
                printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                    alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
            }
            printf("\n");
            achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("\nSem animais com esse nome disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
    textcolor(CINZA);
}

void TStatusList (no *head)
{
    if (head->prox == NULL) {
        printf("\nNenhum animal cadastrado!\n\n");
        system("pause");
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
        if (strcmp((head->type), search) == 0 && (strcmp((head->status), "Adotado") == 0)){
            textcolor(VERDE);
            struct tm* timeinfo = localtime(&head->criado);
            printf("\n\nNome: %s \n", head->name);
            printf("Espécie: %s \n", head->type);
            printf("Raça: %s \n", head->species);
            printf("Sexo: %c \n", head->sex);
            printf("Idade: %d \n", head->age);
            printf("Observação: %s \n", head->obs);
            printf("Status: %s \n", head->status);
            struct tm* criadoInfo = localtime(&head->criado);
            printf("Criado dia: %d/%d/%d as %d:%d\n",
                criadoInfo->tm_mday, (criadoInfo->tm_mon)+1, (criadoInfo->tm_year)+1900, criadoInfo->tm_hour, criadoInfo->tm_min);
            if (difftime(head->alteracao, head->criado) != 0) {
                struct tm* alterInfo = localtime(&head->alteracao);
                printf("Última alteração feita dia: %d/%d/%d as %d:%d\n\n",
                    alterInfo->tm_mday, (alterInfo->tm_mon)+1, (alterInfo->tm_year)+1900, alterInfo->tm_hour, alterInfo->tm_min);
            }
            printf("\n");
            achou = 1;
        }
        else if (cont == maximo && achou != 1) {
            printf("\nSem animais com esse nome disponíveis! \n\n");
        }
        head=head->prox;
        cont++;
    }
    system("pause");
    textcolor(CINZA);
}

