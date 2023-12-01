#ifndef MENEGERFUNCTIONS_H_INCLUDED
#define MENEGERFUNCTIONS_H_INCLUDED
#define MAX_NAME_LENGTH 200
#define MAX_TEXT_LENGTH 600

typedef struct
{

    char nomeExposicao0[MAX_NAME_LENGTH], nomeExposicao1[MAX_NAME_LENGTH], descricaoExposicao[MAX_TEXT_LENGTH], dataExposicao[MAX_NAME_LENGTH];

    char obraNome[MAX_NAME_LENGTH], descricaoObra[MAX_TEXT_LENGTH];

    int Status, Posicao, PosicaoObras;
    float precoExposicao0;

}referencia;// DEFININDO ESTRUTURA DE DADO DE EXPOSIÇÃO

int ExpositionCounter;

int MenuMeneger(FILE *ExposicaoBD, int Position);
void AddExposicao(int Position);
void ViewerExposicao(int Count);
void ChangeExposicao(int Option);


#endif // MENEGERFUNCTIONS_H_INCLUDED
