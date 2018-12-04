#include <stdio.h>
#include <stdlib.h>
#include "LISTAVIDS.h"//Inclus�o do cabe�alho Lista_VIDs;

//Detalhamento das Opera��es da Lista_VID;
void FListaVID(TipoListaVID *vIDs){//Inicializa uma nova lista de VID;
	vIDs->primeiro = (TAponta)malloc(sizeof(TCelula));//Cria uma nova c�lula na lista;
	vIDs->ultimo = vIDs->primeiro;//Faz o ponteiro �ltimo apontar para a mesma c�lula que Primeiro aponta;
	vIDs->ultimo->prox = NULL;//Faz o Ponteiro prox da C�lula criada apontar para nulo;
}

void InsereVID(TipoListaVID *vIDs, int id){//Insere um novo elemento ao final da lista;
	vIDs->ultimo->prox = (TAponta)malloc(sizeof(TCelula));//Cria uma nova c�lula na lista;
	vIDs->ultimo = vIDs->ultimo->prox;//Faz o Ponteiro �ltimo apontar para a nova �ltima c�lula;
	vIDs->ultimo->ID = id;//Faz a atribui��o do novo VID;
	vIDs->ultimo->prox = NULL;//Faz o Ponteiro prox da C�lula criada apontar para nulo;
}

int ComparaVID(TipoListaVID *vIDs, int ID){//Compara um novo VID com cada VID existente na lista;
	int cont = 0;
	TAponta aux;//Cria��o do Ponteiro auxiliar para percorrer a lista;
	aux = vIDs->primeiro->prox;
	if(vIDs->primeiro==vIDs->ultimo){//Verificando se a lista � vazia;
		InsereVID(vIDs, ID);
	}
	else{
		while(aux != NULL){//Percorrendo a lista at� o final;
			if(aux->ID == ID){//Caso o novo VID for igual a um j� existente;
				cont ++;
				break;//Encerra o while;
			}
			aux = aux->prox;//Percorrendo a lista;
		}
		if(cont != 0){//Caso j� haja esse VID na lista;
			return 1;//Retorna 1;
		}
		else{//Caso n�o haja esse VID na lista;
			InsereVID(vIDs, ID);
		}
	}
	return 0;//Retorna 0;
}
