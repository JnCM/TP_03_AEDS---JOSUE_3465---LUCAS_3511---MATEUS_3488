#include <stdio.h>
#include <stdlib.h>
#include "TADLISTAVOOS.h"

void InicializaLista(TipoLista *Lista){//Inicializa uma nova lista encadeada;
    Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    InicializaVoo(&(Lista -> Ultimo -> Voo));
    Lista -> Ultimo -> Prox = NULL;
    Lista -> ContaVoo = 0;
}
int ConverteHoraD(TipoVoo Voo){//Converte a hora recebida em string para int
    int Hora;
    int HD[2];
    HD[0] = ((int)Voo.HoraDecolagem[0]);
    HD[1] = ((int)Voo.HoraDecolagem[1]);
    Hora = ((HD[0]-48)*10)+(HD[1]-48);//Convers�o de char para int(ASCII), e depois para decimal e unidade da hora
    return Hora;
}
int ConverteHoraP(TipoVoo Voo){//Converte a hora recebida em string para int
    int Hora;
    int HP[2];
    HP[0] = ((int)Voo.HoraPouso[0]);
    HP[1] = ((int)Voo.HoraPouso[1]);
    Hora = ((HP[0]-48)*10)+(HP[1]-48);//Convers�o de char para int(ASCII), e depois para decimal e unidade da hora
    return Hora;
}
int ConverteHora(char *hora){//Converte a hora recebida em string para int
    int Hora;
    int H[2];
    H[0] = ((int)hora[0]);
    H[1] = ((int)hora[1]);
    Hora = ((H[0]-48)*10)+(H[1]-48);//Convers�o de char para int(ASCII), e depois para decimal e unidade da hora
    return Hora;
}
int ConverteMin(char *mint){ //Converte o minuto recebido em string para int
    int Min;
    int M[2];
    M[0] = ((int)mint[3]);
    M[1] = ((int)mint[4]);
    Min = ((M[0]-48)*10)+(M[1]-48);//Convers�o de char para int(ASCII), e depois para decimal e unidade do minuto
    return Min;
}
int ConverteMinD(TipoVoo Voo){//Converte o minuto recebido em string para int
    int Min;
    char m[2];
    m[0] = ((int)Voo.HoraDecolagem[3]);
    m[1] = ((int)Voo.HoraDecolagem[4]);
    Min = ((m[0]-48)*10)+(m[1]-48);//Convers�o de char para int(ASCII), e depois para decimal e unidade do minuto
    return Min;
}
void Insere(TipoLista *Lista, TipoVoo x){//Fun��o para inserir uma c�lula na lista
    TipoApontador suc = NULL;
    TipoApontador ant = NULL;
    TipoApontador aux = NULL;
    int H1, M1, H2, M2, cont = 0;
    if(Lista -> Ultimo == Lista -> Primeiro){//Verifica se a lista � vazia
        Lista -> ContaVoo = Lista -> ContaVoo + 1;//Contando o n�mero de voos na lista a medida que adiciona e remove da mesma
        Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));//Alocando espa�o na mem�ria para a c�lula
        Lista -> Ultimo = Lista -> Ultimo -> Prox;
        Lista -> Ultimo -> Voo = x;//Aqui a c�lula recebe os valores da entrada
        Lista -> Ultimo -> Prox = NULL;
    }
    else{//Aqui a lista � percorrida para encontrar onde a c�lula deve ser colocada, de acordo com o hor�rio de decolagem do voo
        ant = Lista -> Primeiro;
        suc = Lista -> Primeiro;
        H1 = ConverteHoraD(x);
        M1 = ConverteMinD(x);
        while(suc -> Prox != NULL){//S� vai parar quando for a �ltima posi��o, ou a c�lula ser inserida antes
            suc = suc -> Prox;
            H2 = ConverteHoraD(suc -> Voo);//Fun��o para que possa converter de string para int, para ent�o comparar hor�rios
            M2 = ConverteMinD(suc -> Voo);
            if(H2 > H1){//Compara se o hor�rio do voo a ser inserido com um voo j� existente na lista
                Lista -> ContaVoo = Lista -> ContaVoo + 1;
                aux = (TipoApontador)malloc(sizeof(TipoCelula));//Voo ser� adicionado a lista
                aux -> Prox = suc;
                ant -> Prox = aux;
                aux -> Voo = x;
                cont ++;
                break;
            }
            else if(H2 == H1){
                if(M2 >= M1){//Se a hora dos voo forem iguais, o minuto de cada voo ser� comparado, para ent�o alocar a c�lula
                    Lista -> ContaVoo = Lista -> ContaVoo + 1;
                    aux = (TipoApontador)malloc(sizeof(TipoCelula));
                    aux -> Prox = suc;
                    ant -> Prox = aux;
                    aux -> Voo = x;
                     cont ++;
                    break;
                }
            }
            ant = ant -> Prox;
        }//FIM WHILE
        if(cont == 0){//Se a c�lula tem o maior hor�rio de voo que todas as outras, ent�o ela � inserida na �ltima posi��o
            aux = (TipoApontador)malloc(sizeof(TipoCelula));
            aux -> Voo = x;
            suc -> Prox = aux;
            Lista -> Ultimo = aux;
            Lista -> Ultimo -> Prox = NULL;
        }
    }
}
int Remove(TipoLista *Lista, TipoVoo *y, int IdentVoo){//Esta fun��o ir� ser usada para remover uma c�lula da lista de acordo com o identificador de voo
    TipoApontador temp = NULL;
    TipoApontador r = NULL;
    int cont = 0;
    temp = Lista -> Primeiro;
    r = Lista -> Primeiro;
    if(Lista->Primeiro==Lista->Ultimo){//Verifica se a lista � vazia
        return cont;
    }
    else{
        while(temp -> Prox != NULL){ //A lista ser� percorrida procurando o voo pelo seu identificador
            temp = temp -> Prox;
            if(temp -> Voo.VID == IdentVoo){//Ao encontrar o voo, ele � removido da lista
                cont = 1;
                Lista -> ContaVoo = Lista -> ContaVoo - 1;//Retira-se um do "ContaVoo" para que seja poss�vel saber o n�mero de c�lulas na lista sem precisar percorrer a mesma
                *y = temp -> Voo;
                r -> Prox = temp -> Prox;
                if(r -> Prox == NULL){
                    Lista -> Ultimo = r;
                    Lista -> Ultimo -> Prox = NULL;
                }
                free(temp);
                break;
            }
            r = r -> Prox;
        }
    }
//� retornado cont para saber se a c�lula foi ou n�o retirada, se cont = 1, ent�o foi retirada, se cont = 0, n�o foi
    return cont;
}
int ProcuraVoo(TipoLista Lista, TipoVoo *z, int SearchVoo){
    TipoApontador q = NULL;
    int cont = 0;
    q = Lista.Primeiro;
    if(Lista.Primeiro==Lista.Ultimo){//Verifica se a lista � vazia
        return cont;
    }
    else{
            while(q -> Prox != NULL){//Percorre-se a lista a procura do voo com o identificador de voo recebido
            q = q -> Prox;
            if(q -> Voo.VID == SearchVoo){//Ao encontrar o voo, um ponteiro � usado para guardar seu endere�o, para que esse voo possa ser usado futuramente
                *z = q -> Voo;
                cont = 1;
            }
            if(q -> Prox == NULL){
                break;
            }
        }
    }
    return cont;//� retornado cont para saber se a c�lula foi ou n�o encontrada, se cont = 1, ent�o foi encontrada, se cont = 0, n�o foi
}
void ImprimeLista(TipoLista Lista){//Percorre-se a lista e chama a fun��o para que ela seja mostrada na tela
    TipoApontador x;
    x = Lista.Primeiro -> Prox;
    while(x != NULL){
        ImprimeVoo(x -> Voo);
        printf("\n");
        x = x -> Prox;
    }
}
