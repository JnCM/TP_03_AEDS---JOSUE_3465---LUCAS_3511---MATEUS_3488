#ifndef LISTAVIDS_H_INCLUDED
#define LISTAVIDS_H_INCLUDED

typedef struct TCelula* TAponta;//Renomeando um Ponteiro para o TCelula para TAponta;
//Motivo: Necessidade de usar dentro da pr�pria struct TCelula;

//Cria��o da estrutura TCelula para armazenar um VID e o Ponteiro para Pr�xima C�lula;
typedef struct TCelula{
	int ID;//VID presente em uma c�lula;
	TAponta prox;//Ponteiro para proxima c�lula do tipo TAponta;
}TCelula;

//Cria��o da estrutura TipoListaVID para armazenar os ponteiros para a Primeira e �ltima C�lula;
typedef struct{
	TAponta primeiro;//Ponteiro primeiro do tipo TAponta;
	TAponta ultimo;//Ponteiro �ltimo do tipo TAponta;
}TipoListaVID;

void FListaVID(TipoListaVID *vIDs);//inicializa a lista encadeada de VIDs, criando uma lista linear vazia;
void InsereVID(TipoListaVID *vIDs, int id);//Insere um VID n�o repetido ao final da lista encadeada;
int ComparaVID(TipoListaVID *vIDs, int ID);//Compara um VID com cada VID presente na lista para ver se � repetido ou n�o;

#endif // LISTAVIDS_H_INCLUDED
