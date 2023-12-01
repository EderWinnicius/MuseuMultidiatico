#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#define MAX_NAME_LENGTH 200
#define MAX_TEXT_LENGTH 600
#include "UserFunctions.h"
#include "MenegerFunctions.h"
#include "TextDisplay.h"

// ---------------------- DEFININDO O CABEÇALHO CRIADO -------------------------------------

int ValidEmail(const char *email)
{ // Validador de char tipo e-mail
  int i;
  int Rcount = 0, Dcount = 0;

  for (i = 0; email[i] != '\0'; i++)
  {
    if (email[i] == '@')
    {
      Rcount++;
    }
    else if (email[i] == '.')
    {
      Dcount++;
    }
  }

  if (Rcount == 1 && Dcount >= 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int AdminEmail(int Id)
{ // Validador de char tipo e-mail
  int Admin;

  if (Id < 5)
  {
    Auxiliar = 1;
  }
  else
  {

    Auxiliar = 0;
  }

  return;
}

int UserRegister()
{

  setlocale(LC_ALL, "Portuguese_Brazil.1252");


  char *Meses_do_Ano[12] = {
      "Janeiro", "Fevereiro", "Março", "Abril",
      "Maio", "Junho", "Julho", "Agosto",
      "Setembro", "Outubro", "Novembro", "Dezembro"};

  struct tm *data_hora_atual; // ponteiro para o struct que obtém data e hora

  time_t segundos;                        // variável do tipo time_t para armazenar o tempo em segundos
  time(&segundos);                        // obtendo o tempo em segundos
  data_hora_atual = localtime(&segundos); // utilizamos a função localtime para converter de segundos para o tempo local

  int AnoAtual = data_hora_atual->tm_year + 1900;
  char InsertEmail[MAX_NAME_LENGTH];
  int ReturnEmail, ReturnLogin;

  FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "ab");
  UserSingUp SingIn;
  fseek(UserFile, 0, SEEK_SET);
  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  do
  {

    system("cls");
    TittleHeader("CADASTRE-SE");
    printf("\n\t\tNome Completo: ");
    fflush(stdin);
    fgets(SingIn.NameUser, sizeof SingIn.NameUser, stdin);

    printf("\n\t\tDia do nascimento: ");
    scanf("%d", &SingIn.DayUser);

    printf("\n\t\tMês de nascimento(1 a 12): ");
    scanf("%d", &SingIn.MonthUser);
    SingIn.MonthUser = SingIn.MonthUser - 1;

    printf("\n\t\tAno de nascimento: ");
    scanf("%d", &SingIn.YearUser);
    fflush(stdin);
    SingIn.AgeUser = AnoAtual - SingIn.YearUser;

    if (AnoAtual - SingIn.YearUser <= 17)
    {
      printf("\n\t\tVocê ainda não tem idade para realizar a reserva e compra de um ingresso");
      printf("\n\t\t\tContacte um responsável para poder realizar a compra de um ingresso\n");
      system("pause");
      return 0;
    }

    do
    {
      printf("\n\t\tInsira aqui o seu E-mail: ");
      fflush(stdin);
      fgets(SingIn.Email, sizeof SingIn.Email, stdin);

      if (ValidEmail(SingIn.Email) != 0)
      {
        printf("\n\t\t%s", SingIn.Email);
        ReturnEmail = 1;
      }
      else
      {
        printf("\n\t\t %s, não é um e-mail válido\n", SingIn.Email);
        system("pause");
        system("cls");
        TittleHeader("CADASTRE-SE");
      }

    } while (ReturnEmail != 1);
    srand(time(NULL));

    SingIn.Id_User = 2; //rand() % 10000;

    printf("\n\t\tInsira uma senha: ");
    fgets(SingIn.UserPassword, sizeof SingIn.UserPassword, stdin);
    fflush(stdin);
    printf("%s", SingIn.UserPassword);

    system("cls");
    TittleHeader("CADASTRE-SE");
    printf("\n\t\tOlá %s", SingIn.NameUser);
    printf("\n\t\tId de usuário: #%d", SingIn.Id_User);
    printf("\n\t\tData do nascimento: %d de %s de %d // %d Anos", SingIn.DayUser, Meses_do_Ano[SingIn.MonthUser], SingIn.YearUser, SingIn.AgeUser);
    printf("\n\t\tE-mail: %s", SingIn.Email);
    printf("\n\n");
    printf("\n\t\tDeseja confirmar o cadastro?");
    printf("\n\t\t1 - sim // 2 - não");
    printf("\n\t\tEscolha uma opção: ");
    scanf("%d", &ReturnLogin);
  } while (ReturnLogin != 1);

  SingIn.TicketUser = 0;
  SingIn.ExpoTicket = 0;
  SingIn.AdminUser = 0;
  fwrite(&SingIn, sizeof(UserSingUp), 1, UserFile);
  fclose(UserFile);

  return 1;
}

void AlterarCadastro(int Id)
{

  setlocale(LC_ALL, "Portuguese_Brazil.1252");


  char *Meses_do_Ano[12] = {
      "Janeiro", "Fevereiro", "Março", "Abril",
      "Maio", "Junho", "Julho", "Agosto",
      "Setembro", "Outubro", "Novembro", "Dezembro"};
  struct tm *data_hora_atual; // ponteiro para o struct que obtém data e hora

  time_t segundos;                        // variável do tipo time_t para armazenar o tempo em segundos
  time(&segundos);                        // obtendo o tempo em segundos
  data_hora_atual = localtime(&segundos); // utilizamos a função localtime para converter de segundos para o tempo local

  int AnoAtual = data_hora_atual->tm_year + 1900;

  //-----------------------------------------------------------------------------------CABEÇALHOS DE RESPONSIVIDADE ----------------------------

  char NewName[MAX_NAME_LENGTH], NewEmail[MAX_NAME_LENGTH];
  int NewDay, NewMonth, NewYear, NewAge, confirm, CadastroOption, Confirm, OpcaoSair, ReturnEmail;

  FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "r+b");
  UserSingUp SingIn;
  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  system("cls");
  TittleHeader("ALTERAR CADASTRO");
  printf("\n          |                                                                       |");
  printf("\n          |    1 - Alterar Nome                                                   |");
  printf("\n          |    2 - Alterar Data de nacimento                                      |");
  printf("\n          |    3 - Alterar Email cadastrado                                       |");
  printf("\n          |    4 - Sair                                                           |");
  printf("\n          |_______________________________________________________________________|");
  printf("\n\n");
  printf("\n\t\t\t\tQual opção deseja acessar:");
  scanf("%d", &CadastroOption);
  fseek(UserFile, 0, SEEK_SET);

  while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile))
  {
    if (SingIn.Id_User == Id)
    {

      switch (CadastroOption)
      {
      case 1:

        TittleHeader("ALTERAR NOME");
        printf("\n\t\t\tNome Atual: %s", SingIn.NameUser);
        printf("\n\t\t\tNovo Nome: ");
        fflush(stdin);
        fgets(NewName, sizeof NewName, stdin);
        LineDivider();

        printf("\n\t\t1 - Confirmar Allteração // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {

          fseek(UserFile, -sizeof(UserSingUp), SEEK_CUR);
          strcpy(SingIn.NameUser, NewName);                 // atualiza apenas o campo desejado
          fwrite(&SingIn, sizeof(UserSingUp), 1, UserFile); // escreve a estrutura modificada de volta

          printf("\n\t\t\t\tAlteração Confirmada!");
          rewind(UserFile);
        }
        else
        {
          printf("\n\t\t\t\tAlteração Cancelada!");
        }

        break;

      case 2:

        do
        {
          TittleHeader("ALTERAR DATA DE NASCIMENTO");
          printf("\n\t\tData do nascimento atual: %d de %s de %d // %d Anos", SingIn.DayUser, Meses_do_Ano[SingIn.MonthUser], SingIn.YearUser, SingIn.AgeUser);
          LineDivider();
          printf("\n\t\tDia do nascimento: ");
          scanf("%d", &NewDay);

          printf("\n\t\tMês de nascimento(1 a 12): ");
          scanf("%d", &NewMonth);
          NewMonth = NewMonth - 1;

          printf("\n\t\tAno de nascimento: ");
          scanf("%d", &NewYear);
          fflush(stdin);
          NewAge = AnoAtual - NewYear;

          if (NewAge <= 17)
          {
            printf("\n\t\tData inválida!! 1 - Tentar novamente // 2 - Voltar ao Menu");
            printf("\n\t\tQual opção deseja acessar: ");
            scanf("%d", &OpcaoSair);

            if (OpcaoSair == 2)
            {
              system("pause");
              break;
            }
          }
          else
          {
            OpcaoSair = 2;
          }
        } while (OpcaoSair != 2);

        printf("\n\t\t1 - Confirmar Allteração // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {
          fseek(UserFile, -sizeof(UserSingUp), SEEK_CUR);
          SingIn.DayUser = NewDay;
          SingIn.MonthUser = NewMonth;
          SingIn.AgeUser = NewAge;
          SingIn.YearUser = AnoAtual;                       // atualiza apenas o campo desejado
          fwrite(&SingIn, sizeof(UserSingUp), 1, UserFile); // escreve a estrutura modificada de volta

          printf("\n\t\t\t\tAlteração Confirmada!");
          rewind(UserFile);
        }
        else
        {
          printf("\n\t\t\t\tAlteração Cancelada!");
        }

        break;

      case 3:

        do
        {
          TittleHeader("ALTERAR E-MAIL");
          printf("\n\t\t\tE-mail Atual: %s", SingIn.Email);
          printf("\n\t\t\tNovo E-mail: ");
          fflush(stdin);
          fgets(NewEmail, sizeof NewEmail, stdin);
          LineDivider();

          if (ValidEmail(NewEmail) != 0) // VALIDADOR DE E-MAIL DENTRO DOS PARÂMETROS DO PROGRAMA
          {
            printf("\n\t\t%s", NewEmail);
            ReturnEmail = 1;
          }
          else
          {
            printf("\n\t\t %s, não é um e-mail válido\n", NewEmail);
            system("pause");
            system("cls");
            TittleHeader("ALTERAR E-MAIL");
          }
        } while (ReturnEmail != 1);

        system("pause");

        printf("\n\t\t1 - Confirmar Allteração // 2 - Cancelar");
        LineDivider();
        printf("\n\t\t\t\tQual opcao deseja acessar: ");
        scanf("%d", &Confirm);

        if (Confirm == 1)
        {

          fread(&SingIn, sizeof(UserSingUp), 1, UserFile);  // lê os dados antigos
          strcpy(SingIn.Email, NewEmail);                   // atualiza apenas o campo desejado
          fwrite(&SingIn, sizeof(UserSingUp), 1, UserFile); // escreve a estrutura modificada de volta

          printf("\n\t\t\t\tAlteração Confirmada!");
          rewind(UserFile);
        }
        else
        {
          printf("\n\t\t\t\tAlteração Cancelada!");
        }

        break;
      case 4:

        printf("SAINDO DO PROGRMA");
        system("pause");
        fclose(UserFile);
        return;

      default:
        printf("Opção inválida. Tente novamente.\n");

        break;
      }
      break;
    }
  }

  fclose(UserFile);
}

int LoginPage(int Id, int Administrador)
{

  char *Meses_do_Ano[12] = {
      "Janeiro", "Fevereiro", "Março", "Abril",
      "Maio", "Junho", "Julho", "Agosto",
      "Setembro", "Outubro", "Novembro", "Dezembro"};

  struct tm *data_hora_atual; // ponteiro para o struct que obtém data e hora

  time_t segundos;                        // variável do tipo time_t para armazenar o tempo em segundos
  time(&segundos);                        // obtendo o tempo em segundos
  data_hora_atual = localtime(&segundos); // utilizamos a função localtime para converter de segundos para o tempo local

  int AnoAtual = data_hora_atual->tm_year + 1900;

  FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "r+b");
  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  int OpcaoLogin, OpcaoSair, i, Confirm, ReturnEmail, c;

  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "rb");
  referencia Exposicoes;

  if (ExposicaoBD == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  system("cls");

  UserSingUp SingIn;
  fseek(UserFile, 0, SEEK_SET);
  while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile))
  {
    if (SingIn.Id_User == Id)
    {
      while (OpcaoLogin != 6)
      {
        system("cls");
        rewind(UserFile);
        TittleHeader("      SEJA BEM VINDO");
        SubtitleHeader(SingIn.NameUser);
        if (Administrador == 1)
        {
          system("color F1");
          printf("\n          |                                                                       |");
          printf("\n          |    1 - Comprar um novo ingresso                                       |");
          printf("\n          |    2 - Exibir ingresso comprado                                       |");
          printf("\n          |    3 - Alterar Cadastro                                               |");
          printf("\n          |    4 - Exibir dados                                                   |");
          printf("\n          |    5 - Feedback Exposição                                             |");
          printf("\n          |    6 - Sair                                                           |");
          printf("\n          |    7 - Gerenciar Páginas                                              |");
          printf("\n          |_______________________________________________________________________|");
          printf("\n\n");
        }
        else
        {
          printf("\n          |                                                                       |");
          printf("\n          |    1 - Comprar um novo ingresso                                       |");
          printf("\n          |    2 - Exibir ingresso comprado                                       |");
          printf("\n          |    3 - Alterar Cadastro                                               |");
          printf("\n          |    4 - Exibir dados                                                   |");
          printf("\n          |    5 - Feedback Exposição                                             |");
          printf("\n          |    6 - Sair                                                           |");
          printf("\n          |_______________________________________________________________________|");
          printf("\n\n");
        }
        printf("\n\t\t\t\tQual opção deseja acessar:");
        scanf("%d", &OpcaoLogin);

        switch (OpcaoLogin)
        {
        case 1:
          fclose(UserFile);
          return 1;
          break;

        case 2:
          if (SingIn.TicketUser != 0)
          {
            IngressoTeamplate(SingIn.Id_User, SingIn.ExpoTicket);
            system("pause");
          }
          else
          {
            SubtitleHeader("Você ainda não comprou um de nossos ingressos!!!");
            printf("\n\t\tTente novamente após sua compra\n");
            system("pause");
          }

          break;

        case 3:
          AlterarCadastro(SingIn.Id_User);
          fseek(UserFile, 0, SEEK_SET);
          LoginPage(SingIn.Id_User, Administrador);
          break;

        case 4:

          printf("\n\t\tOlá %s", SingIn.NameUser);
          printf("\n\t\tId de usuário: #%d", SingIn.Id_User);
          printf("\n\t\tData do nascimento: %d de %s de %d // %d Anos", SingIn.DayUser, Meses_do_Ano[SingIn.MonthUser], SingIn.YearUser, SingIn.AgeUser);
          printf("\n\t\tComprou a Exposição número %d", SingIn.ExpoTicket);
          printf("\n\t\tE-mail: %s", SingIn.Email);
          printf("\n\n");
          system("pause");

          //---------------------------------------------------------------------------------------------------------

          TittleHeader("MUSEU PIMEXPO");
          printf("\n\t\tNota para as nossas exposições: %d", SingIn.FeedbackNote);
          printf("\n\t\tNota para as descrições das exposições: %d", SingIn.FeedbackDescription);
          if (SingIn.AnaliticsUser == 1)
          {
            printf("\n\t\tSim, as avaliações me ajudaram a escolher uma atração");
          }
          else
          {
            printf("\n\t\tNão, influenciaram na minha escolha mas eu escolhi o que mais gostei");
          }

          if (SingIn.BeforeVisitFeedback == 1)
          {
            printf("\n\t\tSim, eu já visitei outras exposições antes");
          }
          else
          {
            printf("\n\t\tNão, nunca havia visitado outra exposição antes");
          }

          if (SingIn.RecomendationFeedback == 1)
          {
            printf("\n\t\tSim, eu recomendaria esta Esposição");
          }
          else
          {
            printf("\n\t\tNão, eu não recomendaria esta exposição");
          }
          printf("\n");
          fseek(ExposicaoBD, 0, SEEK_SET);

          while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
          {
            if (SingIn.BetterAvaliation == Exposicoes.Posicao)
            {
              printf("\t\tO tema que mais me chamou a atenção foi %s", Exposicoes.nomeExposicao0);
            }
          }

          fseek(ExposicaoBD, 0, SEEK_SET);

          while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
          {
            if (SingIn.InferiorAvaliation == Exposicoes.Posicao)
            {
              printf("\t\tO tema que menos me chamou a atenção foi %s", Exposicoes.nomeExposicao0);
            }
          }

          if (SingIn.ReturnMuseum == 1)
          {
            printf("\n\t\tSim, eu tenho interesse em retornar ao museu\n");
          }
          else
          {
            printf("\n\t\tNão, eu não pretendo retornar ao museu\n");
          }

          if (SingIn.SugestaoExpoTheme == 1)
          {
            printf("\n\t\tEu gostaria de visitar uma exposição com tema histórico, onde prevalece a relevância histórica");
          }
          else
          {
            printf("\n\t\tEu gostaria de visitar uma exposição com tema Artistico, onde o \n\t\tacervo é constituído exclusivamente de obras de arte");
          }

          LineDivider();
          system("pause");
          fclose(ExposicaoBD);

          //--------------------------------------------------------------------------------------------------------

          break;

        case 5:
          feedbackUser(Id);
          break;

        case 6:
          fclose(UserFile);
          return 0;
          break;

        case 7:
          if (Administrador != 1)
          {
            TittleHeader("MUSEU PIMEXPO");
            printf("\n\n\n\t\tOpção Incorreta, retornando ao menu!\n");
            system("pause");
          }
          else
          {
            FILE *ExposicaoBD;
            ExposicaoBD = fopen("BDExposicoes.txt", "rb");
            MenuMeneger(ExposicaoBD, ExpositionCounter);
            fclose(ExposicaoBD);
          }
          break;
        default:
          TittleHeader("MUSEU PIMEXPO");
          printf("\n\n\n\t\tOpção Incorreta, retornando ao menu!");
          break;
        }
      }

      rewind(UserFile);
      break;
    }
  }
  return 0;
}

void feedbackUser(int Id)
{
  setlocale(LC_ALL, "Portuguese_Brazil.1252");

  int opcaoFeedback, Confirm;
  //------------------------------------------------------------------------------------DEFININDO VARIÁVEIS -----------------------------------------

  //------------------------------------------------------------------------------------MANIPULANDO 2 ARQUIVOS DE UMA VEZ -----------------------------------------
  FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "r+b");
  UserSingUp SingIn;
  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "rb");
  referencia Exposicoes;

  if (ExposicaoBD == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }
  //------------------------------------------------------------------------------------MANIPULANDO 2 ARQUIVOS DE UMA VEZ -----------------------------------------

  system("cls");

  int ConfirmFeedback, Nota, AntesVisita, Recomendar, Favorito, NaoRecomendo, Descricao, Sugestao, Estastistico, Retornar;
  fseek(UserFile, 0, SEEK_SET); // Reposiciona o ponteiro do arquivo para o início

  while (opcaoFeedback < 1 || opcaoFeedback > 2)
  {
    TittleHeader("     PÁGINA DE LOGIN");
    printf("\n\t\tFicamos felizes pelo seu interesse em nossas exposições!\n\n");
    printf("\n\t\tPoderia nos apoiar em uma pesquisa sobre o tema? \n");
    printf("\n\t\t1-Sim 2-Não");
    printf("\n\t\tEcolha uma das opções: ");
    scanf("%d", &opcaoFeedback);
    system("cls");
  }

  if (opcaoFeedback == 1)
  {

    system("cls");
    while (Nota < 1 || Nota > 5)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tDe 1 a 5, qual nota você daria para nossas exposições?");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &Nota);
      system("cls");
    }

    while (Descricao < 1 || Descricao > 5)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tDe 1 a 5, qual nota você daria para os resumos apresentados?");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &Descricao);
      system("cls");
    }

    while (Estastistico < 1 || Estastistico > 2)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\t  As avaliações ao fim do resumo das exposições te ajudaram\n\t\tna escolha da melhor exposição para você? \n\n\t\t1-Sim 2-Não\n");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &Estastistico);

      system("cls");
    }

    while (AntesVisita < 1 || AntesVisita > 2)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tVocê já tinha visitado outras exposições antes?");
      printf("\n\t\t1-Sim 2-Não");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &AntesVisita);
      system("cls");
    }

    while (Recomendar < 1 || Recomendar > 2)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tRecomenendaria nossa exposição para outras pessoas?");
      printf("\n\t\t1-Sim 2-Não");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &Recomendar);
      system("cls");
    }

    while (Favorito < 1 || Favorito > 4)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tQual foi o tema que MAIS chamou sua atenção em nosso museu?\n");

      fseek(ExposicaoBD, 0, SEEK_SET);
      i = 0;
      while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
      {
        // Um contador que exibe as exposições já cadastradas
        printf("\n\t\t%d - %s", i + 1, Exposicoes.nomeExposicao0);
        i++;
      }

      printf("\n\t\tEscolha um número: ");
      scanf("%d", &Favorito);
      system("cls");
    }

    if (AntesVisita == 1)
    {

      while (NaoRecomendo < 1 || NaoRecomendo > 4)
      {
        TittleHeader("FALE CONOSCO");
        printf("\n\t\tQual foi o tema que MENOS chamou sua atenção em nosso museu? \n");

        fseek(ExposicaoBD, 0, SEEK_SET);
        i = 0;
        while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
        {
          // Um contador que exibe as exposições já cadastradas
          printf("\n\t\t%d - %s", i + 1, Exposicoes.nomeExposicao0);
          i++;
        }

        printf("\n\t\tEscolha um número: ");
        scanf("%d", &NaoRecomendo);
        system("cls");
      }
    }

    while (Retornar < 1 || Retornar > 2)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tTem interesse em voltar ao museu para visitar outro tema? \n\t\t1-Sim 2-Não");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &Retornar);
      system("cls");
    }

    while (Sugestao < 1 || Sugestao > 2)
    {
      TittleHeader("FALE CONOSCO");
      printf("\n\t\tQual tema que você gostaria de visitar em uma nova exposição? \n\t\t1-Histórico, onde prevalece a relevância histórica \n\t\t2-Arte-onde o acervo é constituído exclusivamente de obras de arte");
      printf("\n\t\tOpção Escolhida: ");
      scanf("%d", &Sugestao);
      system("cls");
    }

    system("cls");
    TittleHeader("MUSEU PIMEXPO");
    printf("\n\t\tNota para as nossas exposições: %d", Nota);
    printf("\n\t\tNota para as descrições das exposições: %d", Descricao);
    if (Estastistico == 1)
    {
      printf("\n\t\tSim, as avaliações me ajudaram a escolher uma atração");
    }
    else
    {
      printf("\n\t\tNão, influenciaram na minha escolha mas eu escolhi o que mais gostei");
    }

    if (AntesVisita == 1)
    {
      printf("\n\t\tSim, eu já visitei outras exposições antes");
    }
    else
    {
      printf("\n\t\tNão, nunca havia visitado outra exposição antes");
    }

    if (Recomendar == 1)
    {
      printf("\n\t\tSim, eu recomendaria esta Esposição");
    }
    else
    {
      printf("\n\t\tNão, eu não recomendaria esta exposição");
    }
    printf("\n");
    fseek(ExposicaoBD, 0, SEEK_SET);

    while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
    {
      if (Favorito == Exposicoes.Posicao)
      {
        printf("\t\tO tema que mais me chamou a atenção foi %s", Exposicoes.nomeExposicao0);
      }
    }

    if (AntesVisita == 1)
    {
      fseek(ExposicaoBD, 0, SEEK_SET);
      while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
      {
        if (NaoRecomendo == Exposicoes.Posicao)
        {
          printf("\t\tO tema que menos me chamou a atenção foi %s", Exposicoes.nomeExposicao0);
        }
      }
    }

    if (Retornar == 1)
    {
      printf("\n\t\tSim, eu tenho interesse em retornar ao museu\n");
    }
    else
    {
      printf("\n\t\tNão, eu não pretendo retornar ao museu\n");
    }

    if (Sugestao == 1)
    {
      printf("\n\t\tEu gostaria de visitar uma exposição com tema histórico, onde prevalece a relevância histórica");
    }
    else
    {
      printf("\n\t\tEu gostaria de visitar uma exposição com tema Artistico, onde o \n\t\tacervo é constituído exclusivamente de obras de arte");
    }

    LineDivider();
    printf("\n\n");

    printf("\n\t\t1 - Confirmar Allteração // 2 - Cancelar");
    LineDivider();
    printf("\n\t\t\t\tQual opcao deseja acessar: ");
    scanf("%d", &Confirm);

    if (Confirm == 1)
    {
      fseek(UserFile, 0, SEEK_CUR);
      while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile))
      {
        if (SingIn.Id_User == Id)
        {

          fseek(UserFile, -sizeof(UserSingUp), SEEK_CUR);

          SingIn.FeedbackNote = Nota;
          SingIn.FeedbackDescription = Descricao;
          SingIn.AnaliticsUser = Estastistico;
          SingIn.BeforeVisitFeedback = AntesVisita;
          SingIn.RecomendationFeedback = Recomendar;
          SingIn.BetterAvaliation = Favorito;
          SingIn.InferiorAvaliation = NaoRecomendo;

          fwrite(&SingIn, sizeof(UserSingUp), 1, UserFile); // escreve a estrutura modificada de volta
          printf("\n\t\t\tAlteração Confirmada!");
          rewind(UserFile);
        }
        break;
      }
    }
    else
    {
      TittleHeader("MUSEU PIMEXPO");
      printf("\n\t\tFeedback Cancelado! Volte novamente!");
    }
  }
  else
  {
    TittleHeader("MUSEU PIMEXPO");
    printf("\n\n\n\t\tTudo bem, você pode retornar sempre que quiser, obrigado pela visita!");
  }

  fclose(UserFile);
  fclose(ExposicaoBD);
}

void IngressoTeamplate(int Id, int ExposicaoSelecionada)
{

  setlocale(LC_ALL, "Portuguese_Brazil.1252");


  FILE *ExposicaoBD;
  ExposicaoBD = fopen("BDExposicoes.txt", "rb");
  referencia Exposicoes;
  rewind(ExposicaoBD);
  fseek(ExposicaoBD, 0, SEEK_SET);
  i = 0;
  while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
  {
    // Um contador que exibe as exposições já cadastradas

    if (ExposicaoSelecionada == Exposicoes.Posicao)
    {
      TittleHeader(Exposicoes.nomeExposicao0);
      break;
    }
  }

  FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "r+b");
  UserSingUp SingIn;
  if (UserFile == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  fseek(UserFile, 0, SEEK_SET);

  while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile))
  {
    if (SingIn.Id_User == Id)
    {
      if (SingIn.TicketUser == 0)
      { // VALIDADOR DE MENSAGEM CASO O USUÁRIO JÁ POSSSUA UM TICKET EM SEU REGISTRO

        fseek(UserFile, -sizeof(UserSingUp), SEEK_CUR);
        SingIn.ExpoTicket = ExposicaoSelecionada;
        SingIn.TicketUser = 1; // Flag para validação de compra do ingresso
        fwrite(&SingIn, sizeof(UserSingUp), 1, UserFile);
        printf("\n\t\t\tParabéns!! Sua reserva foi realizada com sucesso %s!!\n", SingIn.NameUser);
        rewind(UserFile);
      }
      else
      {

        printf("\n\t\t\tAqui está sua reserva %s\n", SingIn.NameUser);
        ExposicaoSelecionada = SingIn.ExpoTicket;
      }

      printf("\n                      ENTRADA MUSEU PIMEXPO 2023             ");
      printf("\n\t           +-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ ");
      printf("\n\t\t                    #%d", SingIn.Id_User);
      break;
    }
  }

  fseek(ExposicaoBD, 0, SEEK_SET);
  i = 0;
  while (fread(&Exposicoes, sizeof(referencia), 1, ExposicaoBD))
  {
    // Um contador que exibe as exposições já cadastradas

    if (ExposicaoSelecionada == Exposicoes.Posicao)
    {
      printf("\n\t           +-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ ");
      printf("\n\t          +                                                  ");
      printf("\n\t          |  %s ", Exposicoes.dataExposicao); // DATA
      printf("\t          +");
      printf("\n\t          |                                                  ");
      printf("\n\t          +  Valor da exposição: %2.f Reais", Exposicoes.precoExposicao0); // PREÇO
      printf("\n\t          |                                                  ");           // DATA DA EXPOSIÇÃO
      printf("\n\t           +-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ ");
      printf("\n\n");
      system("pause");
      break;
    }
  }

  rewind(UserFile);
  fclose(UserFile);
  fclose(ExposicaoBD);
  LoginPage(Id, 0);
}

void UserHome(int MenuOpcao)
{

  // ÁREA DE USUÁRIO
  FILE *UserFile;
  UserFile = fopen("BDUsuario.txt", "rb");
  UserSingUp SingIn;

  int ExposicaoSelecionada = 1;
  char InsertEmail[MAX_NAME_LENGTH], InsertPassword[MAX_NAME_LENGTH];
  int encontrou = 0, LoginOption, OpcaoUserArea, UserOption, Id_User, CompareEmail, ComparePassword, Administrador;
  setlocale(LC_ALL, "Portuguese_Brazil.1252");

  while (OpcaoUserArea != 3)
  {
    system("cls");
    fseek(UserFile, 0, SEEK_SET);
    TittleHeader("ACESSO A SUA RESERVA");
    printf("\n\n");
    LineDivider();
    printf("\n          |          1 - Login // 2 - Criar Cadastro // 3 - voltar                |");
    LineDivider();
    printf("\n\n");
    printf("\n\t\t\t\tQual opcao deseja acessar: ");
    scanf("%d", &OpcaoUserArea);
    switch (OpcaoUserArea)
    {
    case 1:
      do
      {
        system("cls");
        TittleHeader("PÁGINA DE LOGIN");

        printf("\n\t\tInsira aqui o seu E-mail:");
        fflush(stdin);
        fgets(InsertEmail, sizeof InsertEmail, stdin);

        printf("\n\t\tInsira sua Senha:");
        fflush(stdin);
        fgets(InsertPassword, sizeof InsertPassword, stdin);

        fseek(UserFile, 0, SEEK_SET);
        while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile) == 1)
        {

          CompareEmail = strcmp(SingIn.Email, InsertEmail);
          ComparePassword = strcmp(InsertPassword, SingIn.UserPassword);

          if (CompareEmail == 0 && ComparePassword == 0)
          {
            Id_User = SingIn.Id_User;
            encontrou = 1;
            break; // Se encontrado, podemos sair do loop
          }
        }

        if (encontrou == 0)
        {

          printf("\n\t\t\tEmail ou Senha incorretos deseja tentar novamente?");
          printf("\n\t\t\t1 - Sim // 2 - Não");
          printf("\n \t\t\tQual opcao deseja acessar: ");
          scanf("%d", &LoginOption);
          if (LoginOption == 2)
          {
            return;
          }
        }

      } while (encontrou != 1);

      AdminEmail(Id_User);
      Administrador = Auxiliar;
      UserOption = LoginPage(Id_User, Administrador);
      if (UserOption == 1 && MenuOpcao != NULL)
      {
        ExposicaoEscolhida = MenuOpcao;
        IngressoTeamplate(Id_User, MenuOpcao);
        rewind(UserFile);
        LoginPage(Id_User, Administrador);
      }
      else
      {
        return;
      }

      break;

    case 2:

      UserRegister();
      rewind(UserFile);
      break;

    case 3:
      return;
      break;

    default:
      TittleHeader("MUSEU PIMEXPO");
      printf("\n\n\n\t\tOpção Incorreta, retornando ao menu!");
      break;
    }
  }

  fclose(UserFile);
  return 0;
}
