#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#define MAX_NAME_LENGTH 200
#define MAX_TEXT_LENGTH 600
// ---------------------- DEFININDO O CABE�ALHO -------------------------------------

#include "MenegerFunctions.h"
#include "TextDisplay.h"

// ---------------------- DEFININDO O CABE�ALHO CRIADO -------------------------------------

int MenuMeneger(FILE *ExposicaoBD, int Position)
{

  setlocale(LC_ALL, "Portuguese_Brazil.1252");

  int OpcaoLogin, OpcaoSair, ExposicaoEscolhida, SenhaUsuario, i, Quantidade, Confirm;
  referencia Exposicoes;

  while (OpcaoLogin != 6)
  {
    while (OpcaoSair != 1)
    {
      system("cls");
      TittleHeader("SEJA BEM VINDO");
      printf("\n          |                                                                       |");
      printf("\n          |    1 - Adicionar exposi��o                                            |");
      printf("\n          |    2 - Exibir cadastro de exposi��o                                   |");
      printf("\n          |    3 - Alterar Cadastro de exposi��o                                  |");
      printf("\n          |    4 - Excluir exposi��o                                              |");
      printf("\n          |    5 - Informa��es do sistema                                         |");
      printf("\n          |    6 - Sair                                                           |");
      printf("\n          |_______________________________________________________________________|");
      printf("\n\n");
      printf("\n\t\t\t\tQual op��o deseja acessar:");
      scanf("%d", &OpcaoLogin);

      switch (OpcaoLogin)
      {
      case 1:
        system("cls");
        TittleHeader("CADASTRO DE EXPOSI��ES");
        AddExposicao(Position);
        rewind(ExposicaoBD);
        break;
      case 2:

        system("cls");
        TittleHeader("CADASTRO DE EXPOSI��ES");
        printf("\n\t\t1 - Exibir uma exposi��o // 2 - Exibir Exposi��es");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);
        if (Confirm == 1)
        {
          rewind(ExposicaoBD);
          fseek(ExposicaoBD, 0, SEEK_SET);
          i = 0;
          while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
          {
            // Um contador que exibe as exposi��es j� cadastradas
            printf("\n\t\t%d - %s", i + 1, Exposicoes.nomeExposicao0);
            i++;
          }

          printf("\n\t\t\tQUAL EXPOSI��O DESEJA EXIBIR: ");
          scanf("%d", &i);
          rewind(ExposicaoBD);
          ViewerExposicao(i);
          getch();
        }
        else
        {
          printf("\n\t\t\tQUANTAS EXPOSI��ES DESEJA EXIBIR: ");
          scanf("%d", &Quantidade);
          for (i = 0; i < Quantidade; i++)
          {
            ViewerExposicao(i + 1);
            getch();
          }
        }

        break;

      case 3:

        system("cls");
        TittleHeader("ALTERAR CADASTRO");

        fseek(ExposicaoBD, 0, SEEK_SET);
        i = 1;
        while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
        {
          // Um contador que exibe as exposi��es j� cadastradas
          printf("\n\t\t%d - %s", i, Exposicoes.nomeExposicao0);
          i++;
        }

        printf("\n\t\t\tQUAL EXPOSI��O DESEJA ALTERAR: ");
        scanf("%d", &ExposicaoEscolhida);
        ChangeExposicao(ExposicaoEscolhida);

        break;

        case 4:
          //CRIAR L�GICA DE EXCLUIR
        break;

      case 5:
          ExitProgramInfo();
        break;

      case 6:
          return 0;
        break;

      default:
        system("cls");
        TittleHeader("\t    MUSEU PIMEXPO");
        printf("\n\t\t\tOpcao invalida. Retornando ao menu.\n");
        break;
      }
    }
  }
}

void AddExposicao(int Position)
{
  setlocale(LC_ALL, "Portuguese_Brazil.1252");

  int i, Confirm, Quantidade;
  system("color F1");
  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "ab");
  referencia Exposicoes;

  if (ExposicaoBD == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  system("cls");
  TittleHeader("CADASTRO DE EXPOSI��ES");
  printf("\n\t\t\tEXPOSICAO NUMERO %d", Position);

  fseek(ExposicaoBD, 0, SEEK_SET);
  Exposicoes.Posicao = Position;

  LineDivider();
  printf("\n\n\t\t\tNOME DA EXPOSICAO: ");
  fflush(stdin);
  fgets(Exposicoes.nomeExposicao0, sizeof Exposicoes.nomeExposicao0, stdin);
  LineDivider();
  printf("\n\t\t\tDESCRICAO DA EXPOSI��O: ");
  fflush(stdin);
  fgets(Exposicoes.descricaoExposicao, sizeof Exposicoes.descricaoExposicao, stdin);
  LineDivider();
  printf("\n\t\t\tDATA DA EXPOSI��O: ");
  fflush(stdin);
  fgets(Exposicoes.dataExposicao, sizeof Exposicoes.dataExposicao, stdin);
  fflush(stdin);
  LineDivider();
  printf("\n\t\t\tVALOR DA EXPOSI��O: ");
  scanf("%f", &Exposicoes.precoExposicao0);

  system("cls"); // APRESENTAR EXPOSI��O CADASTRADA
  TittleHeader("CADASTRO DE EXPOSI��ES");

  printf("\n\t\t\tEXPOSI��O NUMERO %d \n", Position);
  LineDivider();
  printf("\n\t\t\tNOME DA EXPOSI��O: %s \n", Exposicoes.nomeExposicao0);
  fflush(stdin);
  LineDivider();
  printf("\n\t\t\tPOSI��O DA EXPOSI��O: %d", Exposicoes.Posicao);
  LineDivider();
  printf("\n\t\t\tDESCRICAO DA EXPOSI��O: %s \n", Exposicoes.descricaoExposicao);
  fflush(stdin);
  LineDivider();
  printf("\n\t\t\tDATA DA EXPOSI��O: %s \n", Exposicoes.dataExposicao);
  fflush(stdin);
  LineDivider();
  printf("\n\t\t\tVALOR DA EXPOSI��O: %.2f reais", Exposicoes.precoExposicao0);
  fflush(stdin);
  LineDivider();
  printf("\n\t\t\t TECLE ENTER PARA CONFIRMAR\n");
  Exposicoes.Status = 1;
  getch();

  fwrite(&Exposicoes, sizeof(referencia), 1, ExposicaoBD);
  fclose(ExposicaoBD);
}

void ViewerExposicao(int Count)
{
  setlocale(LC_ALL, "Portuguese_Brazil.1252");

  int i;
  system("color F1");
  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "rb");
  referencia Exposicoes;

  if (ExposicaoBD == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }
  rewind(ExposicaoBD);
  fseek(ExposicaoBD, 0, SEEK_SET);
  while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
  {

    if (Count == Exposicoes.Posicao)
    {
      printf("\n\t\t\tEXPOSI��O NUMERO %d \n", Count);
      LineDivider();
      printf("\n\t\t\tNOME DA EXPOSI��O: %s \n", Exposicoes.nomeExposicao0);
      fflush(stdin);
      LineDivider();
      printf("\n\t\t\tPOSI��O DA EXPOSI��O: %d", Exposicoes.Posicao);
      LineDivider();
      printf("\n\t\t\tDESCRICAO DA EXPOSI��O: %s \n", Exposicoes.descricaoExposicao);
      fflush(stdin);
      LineDivider();
      printf("\n\t\t\tDATA DA EXPOSI��O: %s \n", Exposicoes.dataExposicao);
      fflush(stdin);
      LineDivider();
      printf("\n\t\t\tVALOR DA EXPOSI��O: %.2f reais", Exposicoes.precoExposicao0);
      fflush(stdin);
      LineDivider();
    }
  }

  fclose(ExposicaoBD);
}

void ChangeExposicao(int Option)
{

  setlocale(LC_ALL, "Portuguese_Brazil.1252");

  int i, AlterarCadastro, Confirm;
  char descricaoExposicao0[MAX_TEXT_LENGTH], dataExposicao0[MAX_NAME_LENGTH];
  float precoExposicao;
  system("color F1");
  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "r+b");
  referencia Exposicoes;

  if (ExposicaoBD == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  system("cls");
  TittleHeader("ALTERAR CADASTRO");

  system("cls");
  // A logica de altera��o se baseia na sobreposi��o de dados para substituir o nome escolhido pelo usuario
  TittleHeader("ALTERAR DADOS DAS EXPOSI��ES");
  printf("\n          |                                                                       |");
  printf("\n          |    1 - Alterar nome da exposi��o                                      |");
  printf("\n          |    2 - Alterar descricao da exposi��o                                 |");
  printf("\n          |    3 - Alterar data da exposi��o                                      |");
  printf("\n          |    4 - Alterar Valor da exposi��o                                     |");
  printf("\n          |    5 - Voltar para o menu principal                                   |");
  printf("\n          |                                                                       |");
  printf("\n          |_______________________________________________________________________|");
  printf("\n\n");
  printf("\n \t\t\t\tQual opcao deseja acessar: ");
  scanf("%d", &AlterarCadastro);

  fseek(ExposicaoBD, 0, SEEK_SET);

  while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
  {
    if (Option == Exposicoes.Posicao)
    {

      TittleHeader(Exposicoes.nomeExposicao0);
      switch (AlterarCadastro)
      {
      case 1:
        printf("\n\n\t\t\tNome Atual: %s", Exposicoes.nomeExposicao0);
        printf("\n\n\t\t\tNovo nome da Exposi��o: ");
        fflush(stdin);
        fgets(Exposicoes.nomeExposicao1, sizeof Exposicoes.nomeExposicao1, stdin);
        printf("\n\t\t1 - Confirmar Alltera��o // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {
          fseek(ExposicaoBD, -sizeof(referencia), SEEK_CUR);
          strcpy(Exposicoes.nomeExposicao0, Exposicoes.nomeExposicao1);
          fwrite(&Exposicoes, sizeof(referencia), 1, ExposicaoBD);
          printf("\n\t\t\t\tAltera��o Confirmada!");
          rewind(ExposicaoBD);
        }
        else
        {
          printf("\n\t\t\t\tAltera��o Cancelada!");
        }
        break;

      case 2:

        printf("\n\n\t\t\tDescri��o Atual: %s", Exposicoes.descricaoExposicao);
        printf("\n\n\t\t\tNovo Descri��o da Exposi��o: ");
        fflush(stdin);
        fgets(descricaoExposicao0, sizeof descricaoExposicao0, stdin);
        printf("\n\t\t1 - Confirmar Alltera��o // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {
          fseek(ExposicaoBD, -sizeof(referencia), SEEK_CUR);
          strcpy(Exposicoes.descricaoExposicao, descricaoExposicao0);
          fwrite(&Exposicoes, sizeof(referencia), 1, ExposicaoBD);
          printf("\n\t\t\t\tAltera��o Confirmada!");
          rewind(ExposicaoBD);
        }
        else
        {
          printf("\n\t\t\t\tAltera��o Cancelada!");
        }

        break;

      case 3:

        printf("\n\n\t\t\tData Atual: %s", Exposicoes.dataExposicao);
        printf("\n\n\t\t\tNova Data da Exposi��o: ");
        fflush(stdin);
        fgets(dataExposicao0, sizeof dataExposicao0, stdin);
        printf("\n\t\t1 - Confirmar Alltera��o // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {
          fseek(ExposicaoBD, -sizeof(referencia), SEEK_CUR);
          strcpy(Exposicoes.dataExposicao, dataExposicao0);
          fwrite(&Exposicoes, sizeof(referencia), 1, ExposicaoBD);
          printf("\n\t\t\t\tAltera��o Confirmada!");
          rewind(ExposicaoBD);
        }
        else
        {
          printf("\n\t\t\t\tAltera��o Cancelada!");
        }

        break;

      case 4:

        printf("\n\n\t\t\tValor Atual: %f", Exposicoes.precoExposicao0);
        printf("\n\n\t\t\tNovo nome da Exposi��o: ");
        fflush(stdin);
        scanf("%f", &precoExposicao);
        printf("\n\t\t1 - Confirmar Alltera��o // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {
          fseek(ExposicaoBD, -sizeof(referencia), SEEK_CUR);
          Exposicoes.precoExposicao0 = precoExposicao;
          fwrite(&Exposicoes, sizeof(referencia), 1, ExposicaoBD);
          printf("\n\t\t\t\tAltera��o Confirmada!");
          rewind(ExposicaoBD);
        }
        else
        {
          printf("\n\t\t\t\tAltera��o Cancelada!");
        }

        break;
      default:
        system("cls");
        TittleHeader("\t    MUSEU PIMEXPO");
        printf("\n\t\t\tOpcao invalida. Retornando ao menu.\n");
        break;
      }
      break;
    }
  }

  fclose(ExposicaoBD);
}
