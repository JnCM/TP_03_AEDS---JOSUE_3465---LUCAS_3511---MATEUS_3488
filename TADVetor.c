#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TADVetor.h"//Incusão do TAD que contém os cabeçalhos das funções

void InicializaVetor(TipoVetor *Vetor, int TAM){//Inicializa o Vetor de Matrizes
  srand(time(NULL));//Função que gera valores aleatórios diferentes a cada compilação
  int i, j, var, cont = 0;//Declaração das variáveis a serem utilizadas na função
  int *vetorID;//Ponteiro para criação do vetor dinamicamente alocado de identificadores das matrizes
  vetorID = (int *)malloc(TAM*sizeof(int));//Criação do vetor dinâmico
  for(i=1; i<TAM; i++){
    vetorID[i] = 0;//Inicializando o vetor de identificadores com chaves igual a 0
  }
  var = 1 + (rand()%1000);//Gerando o primeiro identificador
  vetorID[0] = var;//Atribuíndo à primeira posição do vetor o primeiro identificador gerado
  for(i=0; i<TAM; i++){
    InicializaMatriz(&Vetor[i].Matriz);//Inicializa a matriz de voos
    //As linhas seguintes realizam o processo de geração de identificadores aleatórios não repetidos
    if(i==0){//Se for a primeira posição do vetor de matrizes, receberá o primeiro identificador gerado
      Vetor[i].ID = var;//Atribuí ao vetor de matrizes, o identificador da primeira matriz
    }
    else{//Se não for a primeira posição do vetor de matrizes, entrará no else
      var = 1 + (rand()%1000);//Gerando outro identificador aleatório
      for(j=0; j<TAM; j++){
        if(var == vetorID[j]){//Se o identificador gerado for igual a algum identificador já gerado, será necessário gerar um novo
          while(var == vetorID[j]){//Enquanto o novo identificador for repetido, fica gerando um novo identificador
            var = 1 + (rand()%1000);//Geração de um novo identificador
          }
        }
        if(vetorID[j+1] == 0){//Se a próxima posição conter uma chave igual a 0, significará que não há mais identificadores a serem comparados
          break;//Para a execução das comparações
        }
      }
      Vetor[i].ID = var;//Atribuí o novo identificador gerado ao vetor de matrizes
      vetorID[i+1] = var;//Atribuí o novo identificador gerado ao vetor de identificadores para não haver outro igual
    }
  }
}

void geraVoos(TipoVoo *Voo){//Função para gerar voos aleatoriamente
  srand(time(NULL));//Função que gera valores aleatórios diferentes a cada compilação
  //Declaração das variáveis a serem utilizadas na função
  int var, i;
  char Deco[4], Pouso[4], horaD[6], horaP[6];
  SetVID(Voo, rand()%40000);//Inserindo no voo o VID gerado
  SetNpista(Voo, rand()%20);//Inserindo no voo o Número da pista gerado
  //As linhas seguintes geram uma letra aleatória para compor a sigla de um aeroporto
  for(i=0; i<3; i++){
    var = 65 + (rand()%26);
    Deco[i] = (char)var;
  }//Ao acabar de gerar as letras, insere no Voo o Aeroporto de Decolagem gerado
  SetAeroDeco(Voo, Deco);
  for(i=0; i<3; i++){
    var = 65 + (rand()%26);
    Pouso[i] = (char)var;
  }//Ao acabar de gerar as letras, insere no Voo o Aeroporto de Pouso gerado
  SetAeroPouso(Voo, Pouso);
  //As linhas seguintes geram a hora de pouso e a hora de decolagem de forma aleatória, dígito por dígito
  for(i=0; i<6; i++){
    if(i==0){
      var = 48 + (rand()%3);
      horaD[i] = (char)var;
    }
    if((i==1) && (horaD[0] != '2')){
        var = 48 + (rand()%10);
        horaD[i] = (char)var;
    }
    if((i==1) && (horaD[0] == '2')){
        var = 48 + (rand()%5);
        horaD[i] = (char)var;
    }
    if(i==2){
      horaD[i] = ':';
    }
    if(i==3){
      var = 48 + (rand()%6);
      horaD[i] = (char)var;
    }
    if(i==4){
      var = 48 + (rand()%10);
      horaD[i] = (char)var;
    }
  }//Ao acabar de gerar os dígitos, insere no Voo a hora de decolagem gerada
  SetHoraDeco(Voo, horaD);
  for(i=0; i<6; i++){
    if(i==0){
      var = 48 + (rand()%3);
      horaP[i] = (char)var;
    }
    if((i==1) && (horaD[0] != '2')){
        var = 48 + (rand()%10);
        horaP[i] = (char)var;
    }
    if((i==1) && (horaD[0] == '2')){
        var = 48 + (rand()%5);
        horaP[i] = (char)var;
    }
    if(i==2){
      horaP[i] = ':';
    }
    if(i==3){
      var = 48 + (rand()%6);
      horaP[i] = (char)var;
    }
    if(i==4){
      var = 48 + (rand()%10);
      horaP[i] = (char)var;
    }
  }//Ao acabar de gerar os dígitos, insere no Voo a hora de pouso gerada
  SetHoraPouso(Voo, horaP);
}
/*As próximas funções contém os 6 algoritmos de ordenação, bubble, selection, insertion, shell, quick e heap, respectivamente
Comp e Mov são variáveis usadas em todos os algoritmos, destinadas a serem contadores para comparações e movimentações*/
void bubble_sort(TipoVetor *Vetor, int TAM){
  int i, j, troca, Comp = 0, Mov = 0;
  clock_t TempFinal, TempInicial;
  double Tempo_ms;
  TipoVetor Aux;
  TempInicial = clock();
  for(i=0; i<TAM-1; i++){
    troca = 0;
    for(j=1; j<TAM-i; j++){
      Comp ++;
      if(Vetor[j].ID < Vetor[j-1].ID){
        Aux = Vetor[j];
        Vetor[j] = Vetor[j-1];
        Vetor[j-1] = Aux;
        Mov += 3;
        troca = 1;
      }
    }
    if(troca = 0){
      break;
  }
  }
  TempFinal = clock();
  Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
  printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
  printf("------------------------------------------------------------------------------\n\n");
}

void selection_sort(TipoVetor *num, int tam) {
  int i, j, min, Comp = 0, Mov = 0;
  clock_t TempFinal, TempInicial;
  double Tempo_ms;
  TipoVetor aux;
  TempInicial = clock();
  for (i = 0; i < (tam-1); i++){
     min = i;
     for (j = (i+1); j < tam; j++) {
       Comp ++;
       if(num[j].ID > num[min].ID){
         min = j;
       }
     }
     if (num[i].ID != num[min].ID) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
       Mov += 3;
     }
  }
  TempFinal = clock();
  Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
  printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
  printf("------------------------------------------------------------------------------\n\n");
}

void insertion_sort(TipoVetor *vetor, int tamanhoVetor) {
    int i, j, Comp = 0, Mov = 0;
    clock_t TempFinal, TempInicial;
    double Tempo_ms;
    TipoVetor escolhido;
    TempInicial = clock();
    for (i = 1; i < tamanhoVetor; i++) {
  		escolhido = vetor[i];
      Mov ++;
  		j = i - 1;
      Comp ++;
  		while ((j >= 0) && (vetor[j].ID < escolhido.ID)) {
        vetor[j + 1] = vetor[j];
        Mov ++;
        j--;
        Comp ++;
  		}
  		vetor[j + 1] = escolhido;
      Mov ++;
	}
  TempFinal = clock();
  Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
  printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
  printf("------------------------------------------------------------------------------\n\n");
}

void shell_sort(TipoVetor *vetor, int n){
  int i, j, Comp = 0, Mov = 0;
  int h = 1;
  clock_t TempFinal, TempInicial;
  double Tempo_ms;
  TipoVetor x;
  do{
    h = (h*3)+1;
  }while(h < n);
  TempInicial = clock();
  do{
    h = h/3;
    for(i=h; i<n; i++){
      x = vetor[i];
      Mov ++;
      j = i;
      Comp ++;
      while(vetor[j-h].ID > x.ID){
        vetor[j] = vetor[j-h];
        Mov ++;
        j -= h;
        if(j < h){
          break;
        }
        Comp ++;
      }
      vetor[j] = x;
      Mov ++;
    }
  }while(h != 1);
  TempFinal = clock();
  Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
  printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
  printf("------------------------------------------------------------------------------\n\n");
}

void Particao(int Esq, int Dir, int *i, int *j, TipoVetor *vetor, int *Comp, int *Mov){
  int pivo;
  TipoVetor aux;
  *i = Esq;
  *j = Dir;
  pivo = vetor[(*i + *j)/2].ID;
  do{
    (*Comp) ++;
    while(pivo > vetor[*i].ID){
      (*i)++;
      (*Comp) ++;
    }
    (*Comp) ++;
    while(pivo < vetor[*j].ID){
      (*j)--;
      (*Comp) ++;
    }
    if(*i <= *j){
      aux = vetor[*i];
      vetor[*i] = vetor[*j];
      vetor[*j] = aux;
      (*Mov) += 3;
      (*i)++;
      (*j)--;
    }
  }while(*i <= *j);
}

void Ordena(int Esq, int Dir, TipoVetor *vetor, int *Comp, int *Mov){
  int i, j;
  Particao(Esq, Dir, &i, &j, vetor, Comp, Mov);
  if(Esq < j){
    Ordena(Esq, j, vetor, Comp, Mov);
  }
  if(i < Dir){
    Ordena(i, Dir, vetor, Comp, Mov);
  }
}

void quick_sort(TipoVetor *vetor, int n){
  int Comp=0, Mov=0;
  clock_t TempFinal, TempInicial;
  double Tempo_ms;
  TempInicial = clock();
  Ordena(0, n-1, vetor, &Comp, &Mov);
  TempFinal = clock();
  Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
  printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
  printf("------------------------------------------------------------------------------\n\n");
}

void troca(TipoVetor *a, TipoVetor *b){
	TipoVetor t = *a;
	*a = *b;
	*b = t;
}

void heapify(TipoVetor *vetor, int n, int i, int *Mov, int *Comp){
  int Maior = i;
  int Esq = 2*i + 1;
  int Dir = 2*i + 2;
  (*Comp) ++;
  if((Esq < n) && (vetor[Esq].ID > vetor[Maior].ID)){
    Maior = Esq;
	}
  (*Comp) ++;
  if((Dir < n) && (vetor[Dir].ID > vetor[Maior].ID)){
    Maior = Dir;
	}
  if(Maior != i){
    troca(&vetor[i], &vetor[Maior]);
    (*Mov) += 3;
    heapify(vetor, n, Maior, Mov, Comp);
  }
}

void heap_sort(TipoVetor *vetor, int n){
  int i, Mov = 0, Comp = 0;
  clock_t TempFinal, TempInicial;
  double Tempo_ms;
  TempInicial = clock();
  for(i = n / 2 - 1; i >= 0; i--){
    heapify(vetor, n, i, &Mov, &Comp);
  }
  for(i=n-1; i>=0; i--){
    troca(&vetor[0], &vetor[i]);
    Mov += 3;
    heapify(vetor, i, 0, &Mov, &Comp);
  }
  TempFinal = clock();
  Tempo_ms = (TempFinal - TempInicial) * 1000.0 / CLOCKS_PER_SEC;
  printf("Comparacoes: %d\nMovimentacoes: %d\nTempo gasto: %lf ms\n", Comp, Mov, Tempo_ms);
  printf("------------------------------------------------------------------------------\n\n");
}
