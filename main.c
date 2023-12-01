#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#define MAX_NAME_LENGTH 200
#define MAX_TEXT_LENGTH 600
// ---------------------- DEFININDO O CABEÇALHO -------------------------------------

#include "MenegerFunctions.h"
#include "UserFunctions.h"
#include "TextDisplay.h"

// ---------------------- DEFININDO O CABEÇALHO CRIADO -------------------------------------

int main()
{
  int MenuOpcao, OpcaoExposicao, UserOption, TodosUsuarios, i = 0;
  float MelhorAvaliado=0;
  setlocale(LC_ALL, "Portuguese_Brazil.1252");// Função para utilizar acentuação nos textos do programa

  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "rb");
  referencia Exposicoes;

   FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "rb");
  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }
    UserSingUp SingIn;


  while (MenuOpcao != 12)
  { // while para controle voltar do menu
    system("cls");
    system("color f");
    TittleHeader("\t    MUSEU PIMEXPO");
    printf("\n\t\tExplore as infinitas facetas do conhecimento e da expressão humana\n\t ao adentrar as exposições do nosso museu. Aqui, você terá a oportunidade\n\t única de mergulhar em narrativas fascinantes que abrangem as maravilhas da\n\t arte, a riqueza da história, os segredos da ciência e as profundezas das\n\t tradições culturais de diversos cantos do globo.\n");

    LineDivider();
    rewind(ExposicaoBD);
    fseek(ExposicaoBD, 0, SEEK_SET);
    i = 0;
    while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
    {
      // Um contador que exibe as exposições já cadastradas
      printf("\n\t\t%d - %s", i + 1, Exposicoes.nomeExposicao0);
      i++;
    }
    ExpositionCounter = i + 1;

    printf("\n\n\t\t11- Meus ingressos");
    printf("\n\t\t12- Sair do museu");

    LineDivider();
    printf("\n\n\t\t\t\tQual opcao deseja acessar: ");
    scanf("%d", &MenuOpcao);

    if (MenuOpcao == 11)
    {
      system("cls");
        MenuOpcao = NULL;
        UserHome(MenuOpcao);
        main();
    }
    else if (MenuOpcao == 12)
    {
      TittleHeader("\t    MUSEU PIMEXPO");

      ExitProgramInfo();
      LineDivider();
      system("pause");
      fclose(ExposicaoBD); // Fecha o arquivo antes de encerrar o programa
      return 0;
    }
    else
    {
      system("cls");
      fseek(ExposicaoBD, 0, SEEK_SET);
      while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
      {
        if (MenuOpcao == Exposicoes.Posicao)
        {
          i = 1;
          TittleHeader(Exposicoes.nomeExposicao0);
          printf("\n\t  %s", Exposicoes.descricaoExposicao);
          printf("\n\t  A exposição ocorrerá: %s \n\t  Valor da exposição: %2.f Reais\n\n",Exposicoes.dataExposicao, Exposicoes.precoExposicao0);
            if(TodosUsuarios!=0){
          fseek(UserFile, 0, SEEK_SET);
        while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile) == 1)
        {
            TodosUsuarios++;
            if(MenuOpcao==SingIn.BetterAvaliation){
                MelhorAvaliado++;
            }

        }
        }

          MelhorAvaliado = TodosUsuarios/MelhorAvaliado;

          break;
        }
      }
      if (i != 1)
      {
        system("cls");
        TittleHeader("\t    MUSEU PIMEXPO");
        printf("\n\t\t\tOpcao inválida. Retorne ao menu principal.\n");
      }

      printf("\n\t          |    %.2f%%  Dos nossos usuários recomendam essa exposição |", MelhorAvaliado);

    }

    if (MenuOpcao < 11)
    { // esse if junto com o if irá adicionar estas 3 opcoes dentro de cada uma das paginas de exposicao

      TittleHeader("\t    MENU DE OPÇÕES");
      printf("\n          |                                                                       |");
      printf("\n          |                                                                       |");
      printf("\n          |                                                                       |");
      printf("\n          |    2 - Fazer reserva                                                  |");
      printf("\n          |    3 - Fale conosco                                                   |");
      printf("\n          |    4 - Voltar ao menu inicial                                         |");
      printf("\n          |                                                                       |");
      printf("\n          |                                                                       |");
      printf("\n          |_______________________________________________________________________|");
      printf("\n");
      printf("\n \t\t\t\tQual opcao deseja acessar: ");
      scanf("%d", &OpcaoExposicao);

      switch (OpcaoExposicao)
      {
      case 1: // adicionar aqui o caminho da tela de calendário
        system("cls");
        printf("Tela de calendario\n");
        break;

      case 2: // adicionar aqui o caminho da tela de reserva
        system("cls");
        UserHome(MenuOpcao);
        break;

      case 3: // adicionar aqui o caminho para a página de feedback
        // FeedbackUser();
        MenuOpcao = NULL;
        UserHome(MenuOpcao);
        break;

      case 4: // retorna ao menu
        break;

      default: // caso o usuario insira uma opcao invalida
        system("cls");
        TittleHeader("\t    MUSEU PIMEXPO");
        printf("\n\t\t\tOpcao invalida. Retornando ao menu principal.\n");
        break;
      }

      system("cls");
    }
    else
    {
      system("cls");
      TittleHeader("\t    MUSEU PIMEXPO");
      printf("\n\t\t\tPressione qualquer tecla para voltar ao menu...\n");
      getch();
      system("cls");
    }
  }

  fclose(UserFile);
  fclose(ExposicaoBD);
  return 0;
}
