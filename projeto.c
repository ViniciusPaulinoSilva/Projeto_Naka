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
};

void insereAnimal (no *pInicio, no *pFim) {
  no *pAux = NULL, *pNovo = (no*)malloc(sizeof(no));

  if(pNovo == NULL)
    printf("Heap overflow \n");

  if (pInicio == NULL) { //SE FOR PRIMEIRO NÓ
    pInicio = pNovo;
    printf("Inicio = NULL");
    pFim = pNovo;
  }

  for (pAux=pInicio; pAux->prox!=NULL; pAux=pAux->prox) {
    pFim = pAux;
  }

  fflush(stdin);
  printf("Nome: ");
  gets(pNovo->name);
  printf("Espécie: ");
  gets(pNovo->type);
  printf("Raça: ");
  gets(pNovo->species);
  printf("Sexo: ");
  scanf("%c", &pNovo->sex);
  printf("Idade: ");
  scanf("%d", &pNovo->age);
  fflush(stdin);
  printf("Observação: ");
  gets(pNovo->obs);
  printf("\n\n");
  pNovo->id = (pFim->id) + 1;
  pFim->prox = pNovo;
  pNovo->prox = NULL;

  printf("Animal cadastrado!");
}

int main ()
{
  system("cls");
  int opcao = 0;
  int contadorTotal = 0; // contador de animais, colocar pra reduzir contador quanto fizer a função 2
  no *pInicio = NULL, *pFim = NULL;
  while(opcao!=11) {
    printf("Escolha o que deseja fazer:\n\n 1- Adicionar novo registro \n 2- Remover Registro \n 3- Alterar Registro \n 4- Busca por Nome \n 5- Busca por Espécie \n 6- Busca por Espécie e Raça \n 7- Busca por Espécie, Raça e Sexo \n 8- Quantidade de Registros \n 9- Quantidade Específica por Espécie \n 10- Listagem de Cadastros \n 11- Sair \n");
    printf("\n\n");
    scanf("%d", &opcao);
    printf("\n\n");
    switch(opcao)
    {
      case 1:
        insereAnimal(pInicio, pFim);
        contadorTotal++;
        break;

      case 2:
        contadorTotal--;
        break;

      case 4:
      
        break;

      case 5:
      
        break;

      case 6:
      
        break;

      case 7:
      
        break;

      case 8:
      
        break;

      case 9:
      
        break;

      case 10:
      
        break;

    }
  }
}
