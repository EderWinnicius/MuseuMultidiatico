#ifndef USERFUNCTIONS_H_INCLUDED
#define USERFUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#define MAX_NAME_LENGTH 200
#define MAX_TEXT_LENGTH 600
// ---------------------- DEFININDO O CABEÇALHO -------------------------------------

int i, Status[MAX_TEXT_LENGTH], ExposicaoEscolhida, Auxiliar;

typedef struct
{

  char NameUser[MAX_NAME_LENGTH], Email[MAX_NAME_LENGTH], UserPassword[MAX_NAME_LENGTH];
  int AgeUser, YearUser, MonthUser, DayUser, Id_User, TicketUser, ExpoTicket, AdminUser;

  //  -----------------------------------DADOS DE USUÁRIO------------------------------------------------

  int FeedbackNote, BeforeVisitFeedback, RecomendationFeedback, BetterAvaliation, InferiorAvaliation;
  int BeforeVisit, FeedbackiTema, FeedbackDescription, SugestaoExpoTheme, AnaliticsUser, ReturnMuseum;

  //  -----------------------------------FEEDBACK DE USUÁRIO------------------------------------------------

} UserSingUp; // DEFININDO ESTRUTURA DE DADO DE USUÁRIO

int ValidEmail(const char *email);
int AdminEmail(int Id); //VERIFICA SE O USUÁRIO É UM ADMINISTRADOR
int UserRegister();
void AlterarCadastro(int Id);
int LoginPage(int id, int Administrador);
void feedbackUser(int Id);
void IngressoTeamplate(int Id, int ExposicaoSelecionada);
void UserHome(int MenuOpcao);

#endif // USERFUNCTIONS_H_INCLUDED
