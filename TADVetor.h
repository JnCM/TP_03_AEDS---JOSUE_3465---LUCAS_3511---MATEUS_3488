#include "TADMATRIZVOOS.h"//Inclusão do TAD da Matriz de Voos

typedef struct{//Estrutura de um elemento do vetor de matrizes
  TipoMatriz Matriz;//Matriz de voos
  int ID;//Identificador da matriz
}TipoVetor;

void InicializaVetor(TipoVetor *Vetor, int TAM);//Função para inicializar o vetor
void geraVoos(TipoVoo *Voo);//Função para gerar os voos aleatórios do modo iterativo
void bubble_sort(TipoVetor *Vetor, int TAM);//Algoritmo bolha
void selection_sort(TipoVetor *num, int tam);//Algoritmo de Seleção
void insertion_sort(TipoVetor *vetor, int tamanhoVetor);//Algoritmo de Inserção
void shell_sort(TipoVetor *vetor, int n);//Algoritmo Shell Sort
void Particao(int Esq, int Dir, int *i, int *j, TipoVetor *vetor, int *Comp, int *Mov);//Função Partição do Quick Sort
void Ordena(int Esq, int Dir, TipoVetor *vetor, int *Comp, int *Mov);//Função Ordena do Quick Sort
void quick_sort(TipoVetor *vetor, int n);//Algoritmo Quick Sort
void heap_sort(TipoVetor *a, int n);//Algoritmo Heap Sort
