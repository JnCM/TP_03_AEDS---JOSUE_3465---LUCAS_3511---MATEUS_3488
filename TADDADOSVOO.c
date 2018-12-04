#include <stdio.h>
#include <string.h>
#include "TADDADOSVOO.h"//Inclus�o do cabe�alho do TAD e suas opera��es;

//Detalhamento das opera��es do TAD Voo
void InicializaVoo(TipoVoo *Voo){//Inicializando os elementos que comp�em um Voo;
    Voo -> VID = 0;//Valor nulo do tipo int para o Identificador de voo;
    strcpy(Voo -> HoraDecolagem , "NULL");//Valor nulo do tipo char para a Hora de decolagem;
    strcpy(Voo -> HoraPouso, "NULL");//Valor nulo do tipo char para a Hora de pouso;
    strcpy(Voo -> AeroDecolagem, "NULL");//Valor nulo do tipo char para o Aeroporto de decolagem;
    strcpy(Voo -> AeroPouso, "NULL");//Valor nulo do tipo char para o Aeroporto de pouso;
    Voo -> Npista = 0;//Valor nulo do tipo int para o Numero da pista;
}//strcpy foi utilizado para inserir os valores NULL para dentro dos par�metros do tipo char do TAD;

int GetVID(TipoVoo Voo){//Adquire o VID para utiliza��o;
        return Voo.VID;
}//fun��o tipo int pois deve retornar o Identficador de voo para o usuario;

void SetVID(TipoVoo *Voo, int NewID){//Altera para um novo valor para VID;
        Voo -> VID = NewID;
}

char *GetHoraDeco(TipoVoo *Voo){//Adquire o Horario de Decolagem para utiliza��o;
        return Voo -> HoraDecolagem;
}//fun��o tipo char pois deve retornar o Horario de decolagem para o usuario;

void SetHoraDeco(TipoVoo *Voo, char *NewHour){//Altera para um novo valor para Hora de Decolagem;
        strcpy(Voo -> HoraDecolagem, NewHour);
}

char *GetHoraPouso(TipoVoo *Voo){
        return Voo -> HoraPouso;
}//fun��o tipo char pois deve retornar o Horario de pouso para o usuario;

void SetHoraPouso(TipoVoo *Voo, char *NewHour2){//Altera para um novo valor para Hora de Pouso;
        strcpy(Voo->HoraPouso, NewHour2);
}

char *GetAeroDeco(TipoVoo *Voo){
        return Voo -> AeroDecolagem;
}//fun��o tipo char pois deve retornar o Aeroporto de decolagem para o usuario;

void SetAeroDeco(TipoVoo *Voo, char *NewAero){//Altera para um novo valor para Aeroporto de Decolagem;
        strcpy(Voo -> AeroDecolagem, NewAero);
}

char *GetAeroPouso(TipoVoo *Voo){
        return Voo -> AeroPouso;
}//fun��o tipo char pois deve retornar o Aeroporto de pouso para o usuario;

void SetAeroPouso(TipoVoo *Voo, char *NewAero2){//Altera para um novo valor para Aeroporto de Pouso;
        strcpy(Voo -> AeroPouso, NewAero2);
}

int GetNpista(TipoVoo Voo){
        return Voo.Npista;
}//fun��o tipo int pois deve retornar o Numero da pista para o usuario;

void SetNpista(TipoVoo *Voo, int newNpista){//Altera para um novo valor para N�mero da Pista;
        Voo -> Npista = newNpista;
}

void ImprimeVoo(TipoVoo Voo){//Imprime um �nico Voo;
    int id, npista;
    char *hd, *hp, *ad, *ap;
    //Atribu�ndo cada elemento de Voo para uma vari�vel;
    id = GetVID(Voo);
    npista = GetNpista(Voo);
    hd = GetHoraDeco(&Voo);
    hp = GetHoraPouso(&Voo);
    ad = GetAeroDeco(&Voo);
    ap = GetAeroPouso(&Voo);
    printf("VID: %d\nNumero da pista: %d\nHora de Decolagem: %s\nHora de Pouso: %s\nAeroporto de Decolagem: %s\nAeroporto de Pouso: %s\n", id, npista, hd, hp, ad, ap);
}
