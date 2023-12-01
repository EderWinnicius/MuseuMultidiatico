#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include "TextDisplay.h"
#include "UserFunctions.h"



float FeedbackGood(int MenuOpcao) {
    int ContadorAvaliacoes = 0, ContadorDeUsuarios = 0;
    float Porcentagem;

    setlocale(LC_ALL, "");

    FILE *UserFile;
    UserFile = fopen("BDUsuário.txt", "rb");
    if (UserFile == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    UserSingUp SingIn;

    fseek(UserFile, 0, SEEK_SET);
    while (fread(&SingIn, sizeof(UserSingUp), 1, UserFile) == 1) {
        if (SingIn.Id_User != 0) {
            ContadorDeUsuarios++;
        }

        if (MenuOpcao == SingIn.BetterAvaliation) {
            ContadorAvaliacoes++;
        }
    }

    Porcentagem = (ContadorDeUsuarios > 0) ? (ContadorAvaliacoes * 100.0) / ContadorDeUsuarios : 0;

    fclose(UserFile);
    return Porcentagem;



Porcentagem = (ContadorDeUsuarios > 0) ? (ContadorAvaliacoes * 100.0) / ContadorDeUsuarios : 0;

fclose(UserFile);
return Porcentagem;
}






void TittleHeader(char *Title)
{ // POSICIONA E DIVIDE COM UM TÍTULO DESEJADO NA PAGINA CORRETA

    printf("\n          -------------------------------------------------------------------------");
    printf("\n\t\t\t    %s", Title);
    printf("\n          -------------------------------------------------------------------------");
    printf("\n");
}

void LineDivider()
{ // DIVISOR DE LINHA PARA SESSÃO DE CÓDIGO

    printf("\n\n          -------------------------------------------------------------------------");
    printf("\n");
}

void SubtitleHeader(char *Subtitle)
{ // DIVISOR DE LINHA PARA SESSÃO DE CÓDIGO


    printf("\n          _________________________________________________________________________");
    printf("\n\t\t\t\t%s", Subtitle);
    printf("\n");

}


void ExitProgramInfo()
{

    printf("\n          -------------------------------------------------------------------------");
    printf("\n\t\t\t\tDESENVOLVEDORES DO PROJETO");
    printf("\n          -------------------------------------------------------------------------");
    printf("\n          |                                                                       |");
    printf("\n          |                                                                       |");
    printf("\n          |                                                                       |");
    printf("\n          |    1 - Bruno Serafini;                                                |");
    printf("\n          |    2 - Danilo Santos;                                                 |");
    printf("\n          |    3 - Eder Oliveira;                                                 |");
    printf("\n          |    4 - Kevin Luan;                                                    |");
    printf("\n          |    5 - Vitoria Cristinni;                                             |");
    printf("\n          |                                                                       |");
    printf("\n          |       você pode retornar sempre que quiser, obrigado pela visita!     |");
    printf("\n          |                         Saindo do Museu...                            |");
    printf("\n          |                                                                       |");
    printf("\n          |                                                                       |");
    printf("\n          |_______________________________________________________________________|");
    printf("\n");
}

