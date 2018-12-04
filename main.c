#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TADMATRIZVOOS.h"//Incluíndo o TAD que possuí as funções da Matriz de Voos
#include "TADVetor.h"//Incluíndo o TAD que possuí os algoritmos de ordenação e as funções do Vetor de Matrizes

int main(){
  srand(time(NULL));//Função que gera valores aleatórios diferentes a cada compilação
  int Opcao_Entrada, Opcao_Cenario;//Declaração das variáveis que controlam que tipo de entrada e qual cenário será
  do{//Começo da estrutura de repetição
      printf("******************************************************************************\n");
      printf("1 - Modo iterativo\n2 - Modo Arquivo\n0 - Sair\n");
      printf("******************************************************************************\n\n");
      printf("Digite a Opcao de Entrada que deseja:\n");
      scanf("%d", &Opcao_Entrada);//Recebe que tipo de entrada o usuário escolher
      printf("------------------------------------------------------------------------------\n\n");
      if(Opcao_Entrada == 1){//Se a entrada for o modo iterativo
          //Declaração das variáveis a serem utilizadas para criação do vetor a ser ordenado
          int i, j, TAM, TAM_div, In, Opcao_Algoritmo;
          TipoVoo Voo;//Variável que receberá os voos a serem inseridos
          do{//Começo da estrutura de repetição para o usuário escolher cenários diferentes em um mesmo modo de entrada
            printf("******************************************************************************\n");
            printf("Cenarios: 1 ao 12\n0 - Voltar\n");
            printf("******************************************************************************\n\n");
            printf("Digite qual cenario deseja:\n");
            scanf("%d", &Opcao_Cenario);//Recebe qual cenário o usuário desejar
            printf("------------------------------------------------------------------------------\n\n");
            TipoVetor *Vetor, *Vetor2;//Variáveis como ponteiro para criar os vetores dinamicamente alocados
            if(Opcao_Cenario == 1){//Se o usuário escolher o cenário 1
              TAM = 365;//Tamanho do Vetor
              TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
              In = 10;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 2){//Se o usuário escolher o cenário 2
               TAM = 365;//Tamanho do Vetor
               TAM_div = TAM;//Atribuição para pegar 100% das matrizes
               In = 10;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 3){//Se o usuário escolher o cenário 3
                TAM = 365;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 4){//Se o usuário escolher o cenário 4
                TAM = 365;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 5){//Se o usuário escolher o cenário 5
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 6){//Se o usuário escolher o cenário 6
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 7){//Se o usuário escolher o cenário 7
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 8){//Se o usuário escolher o cenário 8
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 9){//Se o usuário escolher o cenário 9
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 10){//Se o usuário escolher o cenário 10
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 11){//Se o usuário escolher o cenário 11
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 12){//Se o usuário escolher o cenário 12
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(Opcao_Cenario == 0){//Se o usuário escolher 0, sai da escolha de cenário
              break;//Para a execução de escolha de cenário
            }
            Vetor = (TipoVetor *)malloc(TAM*sizeof(TipoVetor));//Criando o vetor dinamicamente alocado
            Vetor2 = (TipoVetor *)malloc(TAM*sizeof(TipoVetor));//Criando o vetor auxiliar dinamicamente alocado
            InicializaVetor(Vetor, TAM);//Inicializando o Vetor de matrizes
            for(i=0; i<TAM_div; i++){
              for(j=0; j<In; j++){
                geraVoos(&Voo);//Gerando os Voos aleatoriamente
                InserirVoo(&Vetor[i].Matriz, Voo);//Inserindo o voo na matriz correspondente à posição do vetor
              }
              Vetor2[i] = Vetor[i];//Atribuíndo ao segundo vetor os dados do vetor principal
            }
            do{//Começo da estrutura de repetição para o usuário ordenar o mesmo vetor com algoritmos diferentes
              printf("******************************************************************************\n");
              printf("1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Shell Sort\n5 - Quick Sort\n6 - Heap Sort\n0 - Voltar\n");
              printf("******************************************************************************\n\n");
              printf("Digite qual algoritmo deseja usar:\n");
              scanf("%d", &Opcao_Algoritmo);//Recebe a opção de algoritmo que o usuário escolher
              printf("------------------------------------------------------------------------------\n");
              switch(Opcao_Algoritmo){//Verifica qual algoritmo será usado para ordenar o vetor
                case 0://Se o usuário quiser voltar
                       break;
                case 1://Caso for 1, será o Bubble Sort
                       bubble_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 2://Caso for 2, será o Selection Sort
                       selection_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 3://Caso for 3, será o Insertion Sort
                       insertion_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 4://Caso for 4, será o Shell Sort
                       shell_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 5://Caso for 5, será o Quick sort
                       quick_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 6://Caso for 6, será o Heap Sort
                       heap_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
              }
            }while(Opcao_Algoritmo != 0);//Condição de parada de escolha do algoritmo de ordenação
            //O seguinte comando Free libera espaço na memória ao excluir os dois vetores utilizados
            free(Vetor);
            free(Vetor2);
            printf("------------------------------------------------------------------------------\n\n");
          }while(Opcao_Cenario != 0);//Condição de parada de escolha de cenário
      }
      else if(Opcao_Entrada == 2){//Se a entrada for o modo arquivo
          FILE *Arquivo;
          char NomeArq[100];//Variável para guardar o nome do arquivo
          //Declaração das variáveis a serem utilizadas para criação do vetor a ser ordenado
          int i, j, k, pista, TAM, TAM_div, In, Opcao_Algoritmo;
          char c, horadec[6], horapou[6], aerodec[4], aeropou[4];
          TipoVoo Voo;//Variável que receberá os voos a serem inseridos
          do{//Começo da estrutura de repetição para o usuário escolher cenários diferentes em um mesmo modo de entrada
            printf("******************************************************************************\n");
            printf("Nome do arquivo: cenario(N).txt\nN - 1 ao 12\n0 - Voltar\n");
            printf("******************************************************************************\n\n");
            printf("Digite o nome do arquivo com sua extensao:\n");
            scanf("%s", NomeArq);//Recebendo o nome do arquivo do usuário
            printf("------------------------------------------------------------------------------\n\n");
            TipoVetor *Vetor, *Vetor2;//Variáveis como ponteiro para criar os vetores dinamicamente alocados
            if(strcmp(NomeArq, "cenario1.txt") == 0){//Se o usuário digitar o cenário 1
              TAM = 365;//Tamanho do Vetor
              TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
              In = 10;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario2.txt") == 0){//Se o usuário digitar o cenário 2
               TAM = 365;//Tamanho do Vetor
               TAM_div = TAM;//Atribuição para pegar 100% das matrizes
               In = 10;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario3.txt") == 0){//Se o usuário digitar o cenário 3
                TAM = 365;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario4.txt") == 0){//Se o usuário digitar o cenário 4
                TAM = 365;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario5.txt") == 0){//Se o usuário digitar o cenário 5
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario6.txt") == 0){//Se o usuário digitar o cenário 6
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario7.txt") == 0){//Se o usuário digitar o cenário 7
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario8.txt") == 0){//Se o usuário digitar o cenário 8
                TAM = 3650;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario9.txt") == 0){//Se o usuário digitar o cenário 9
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario10.txt") == 0){//Se o usuário digitar o cenário 10
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 10;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario11.txt") == 0){//Se o usuário digitar o cenário 11
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM*0.2;//Cálculo para pegar 20% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(strcmp(NomeArq, "cenario12.txt") == 0){//Se o usuário digitar o cenário 12
                TAM = 36500;//Tamanho do Vetor
                TAM_div = TAM;//Atribuição para pegar 100% das matrizes
                In = 100;//Quantidade de voos para esse cenário
            }
            else if(NomeArq[0] == '0'){//Se o usuário digitar 0, sai da escolha de cenário
              break;//Para a execução de escolha de cenário
            }
            Arquivo = fopen(NomeArq, "r");//Abertura do arquivo desejado
            int VetorPos[TAM_div];//Declaração do vetor de posições que terão matrizes preenchidas
            for(i=0; i<TAM_div; i++){
                fscanf(Arquivo, "%d", &VetorPos[i]);//Lê do arquivo os índices do vetor que terão matrizes preenchidas
            }
            Vetor = (TipoVetor *)malloc(TAM*sizeof(TipoVetor));//Criando o vetor dinamicamente alocado
            Vetor2 = (TipoVetor *)malloc(TAM*sizeof(TipoVetor));//Criando o vetor auxiliar dinamicamente alocado
            InicializaVetor(Vetor, TAM);//Inicializando o Vetor de matrizes
            for(i=0; i<TAM_div; i++){
              for(j=0; j<In; j++){//As linhas seguintes realizam o processo de recebimento dos dados de um voo para inserí-lo
                k=0;//Pegando caracter a caracter os dados de Hora de Decolagem
        			  c=fgetc(Arquivo);
        			  while((c = fgetc(Arquivo)) != ':'){
          				horadec[k] = c;
          				k++;
               	}
        			  if(k==1){
          				horadec[1]=horadec[0];
          				horadec[0]='0';
           			  }
        			  horadec[2]=':';
        			  k=3;
        			  while((c = fgetc(Arquivo)) != ' '){
          				horadec[k] = c;
          				k++;
        			  }
        			  if(k==4){
          				horadec[4]=horadec[3];
          				horadec[3]='0';
        			  }
        			  horadec[5]='\0';

        			  k=0;//Pegando caracter a caracter os dados de Hora de Pouso
        			  c=fgetc(Arquivo);
        			  while((c = fgetc(Arquivo)) != ':'){
          				horapou[k] = c;
          				k++;
        			  }
        			  if(k==1){
          				horapou[1]=horapou[0];
          				horapou[0]='0';
        			  }
        			  horapou[2]=':';
        			  k=3;
        			  while((c = fgetc(Arquivo)) != ' '){
          				horapou[k] = c;
          				k++;
        			  }
        			  if(k==4){
          				horapou[4]=horapou[3];
          				horapou[3]='0';
        			  }
        			  horapou[5]='\0';
                //Recebendo o Aeroporto de Decolagem e de pouso, como também o número da pista
        			  fscanf(Arquivo, "%s", aerodec);
        			  fscanf(Arquivo, "%s", aeropou);
        			  fscanf(Arquivo, "%d", &pista);
                //Inserindo na variável voo os dados coletados acima
                SetHoraDeco(&Voo, horadec);//Hora de decolagem
                SetHoraPouso(&Voo, horapou);//Hora de pouso
                SetAeroDeco(&Voo, aerodec);//Aeroporto de decolagem
                SetAeroPouso(&Voo, aeropou);//Aeroporto de pouso
        			  SetNpista(&Voo, pista);//Número da pista
                SetVID(&Voo, rand()%40000);//VID do Voo
                InserirVoo(&Vetor[VetorPos[i]].Matriz, Voo);//Inserindo o voo na matriz correspondente à posição do vetor
              }
              Vetor2[i] = Vetor[i];//Atribuíndo ao segundo vetor os dados do vetor principal
            }
            fclose(Arquivo);//Fechamento do arquivo
            do{//Começo da estrutura de repetição para o usuário ordenar o mesmo vetor com algoritmos diferentes
              printf("******************************************************************************\n");
              printf("1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Shell Sort\n5 - Quick Sort\n6 - Heap Sort\n0 - Voltar\n");
              printf("******************************************************************************\n\n");
              printf("Digite qual algoritmo deseja usar:\n");
              scanf("%d", &Opcao_Algoritmo);//Recebe a opção de algoritmo que o usuário escolher
              printf("------------------------------------------------------------------------------\n");
              switch(Opcao_Algoritmo){//Verifica qual algoritmo será usado para ordenar o vetor
                case 0://Se o usuário quiser voltar
                       break;
                case 1://Caso for 1, será o Bubble Sort
                       bubble_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 2://Caso for 2, será o Selection Sort
                       selection_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 3://Caso for 3, será o Insertion Sort
                       insertion_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 4://Caso for 4, será o Shell Sort
                       shell_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 5://Caso for 5, será o Quick sort
                       quick_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
               case 6://Caso for 6, será o Heap Sort
                       heap_sort(Vetor2, TAM);
                       for(i=0; i<TAM; i++){
                         Vetor2[i] = Vetor[i];//Desordena o vetor auxiliar para ser usado novamente
                       }
                       break;
              }
            }while(Opcao_Algoritmo != 0);//Condição de parada de escolha do algoritmo de ordenação
            //O seguinte comando Free libera espaço na memória ao excluir os dois vetores utilizados
            free(Vetor);
            free(Vetor2);
            printf("------------------------------------------------------------------------------\n\n");
          }while(NomeArq[0] != '0');//Condição de parada de escolha do algoritmo de ordenação
      }
  }while(Opcao_Entrada != 0);//Condição de parada do while quando o usuário digitar 0
  return 0;
}
