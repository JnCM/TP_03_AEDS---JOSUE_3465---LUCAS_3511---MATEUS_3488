#ifndef TADLISTAVOOS_H_INCLUDED
#define TADLISTAVOOS_H_INCLUDED

#include "TADDADOSVOO.h"//Inclus�o do cabe�alho TAD_Voo;

typedef struct TipoCelula *TipoApontador;//Renomeando um Ponteiro para o TipoCelula para TipoApontador;
//Motivo: Necessidade de usar dentro da pr�pria struct TipoCelula;

//Cria��o da estrutura TipoCelula para armazenar as informa��es de um Voo e o Ponteiro para Pr�xima C�lula;
typedef struct TipoCelula{
    TipoVoo Voo;//Variavel voo do tipo Voo;
    TipoApontador Prox;//Ponteiro prox do tipo Apontador;
}TipoCelula;

//Cria��o da estrutura TipoLista para armazenar os ponteiros para a Primeira e �ltima C�lula;
typedef struct{
    TipoApontador Primeiro;//Ponteiro primeiro do tipo Apontador;
    TipoApontador Ultimo;//Ponteiro �ltimo do tipo Apontador;
    int ContaVoo;//variavel do tipo int para contar numero de voos em uma lista;
}TipoLista;

void InicializaLista(TipoLista *Lista);//inicializa a estrutura de dados, criando uma lista linear vazia;
int ConverteHoraD(TipoVoo Voo);//Convers�o da hora de decolagem, pois a hora est� no formato HH:MM de tipo char;
int ConverteMinD(TipoVoo Voo);//Convers�o do minuto de decolagem, pois os minutos est� no formato HH:MM de tipo char;
int ConverteHoraP(TipoVoo Voo);//Convers�o da hora de pouso, pois a hora est� no formato HH:MM de tipo char;
int ConverteHora(char *hora);//Convers�o do hor�rio de atualiza��o, pois a hora est� no formato HH:MM de tipo char;
int ConverteMin(char *mint);//Convers�o do minuto de atualiza��o, pois o minuto est� no formato HH:MM de tipo char;
void Insere(TipoLista *Lista, TipoVoo x);//Insere um voo na lista(Antes do primeiro voo encontrado na lista com hor�rio de decolagem maior ou igual ao dele);
int Remove(TipoLista *Lista, TipoVoo *y, int IdentVoo);//Remove um voo pelo Identficador e guardando-o para que possa ser utilizado;
int ProcuraVoo(TipoLista Lista, TipoVoo *z, int SearchVoo);//Procura um voo em espec�fico a partir do VID e o guarda para utiliza��o;
void ImprimeLista(TipoLista Lista);//Imprime toda a lista contendo todos os voos e suas respectivas informa��es;

#endif // TADLISTAVOOS_H_INCLUDED
