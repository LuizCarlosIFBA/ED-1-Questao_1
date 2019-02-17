#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
 int info;
 struct nodo *prox;
}Nodo;

//CRIAR
Nodo * criar_no(){
    Nodo *novo =(Nodo*)malloc(sizeof(Nodo));
    return novo;
}

//INSERIR
Nodo* inserir_no_inicio(Nodo * Lista, int dado){
    Nodo *novo_no=criar_no();
    novo_no->info=dado;

    if(Lista == NULL){
        Lista=novo_no;
        novo_no->prox=NULL;
    }else{ novo_no->prox=Lista;
           Lista=novo_no;
         }
         return Lista;
}

void imprimir(Nodo* lista){
        Nodo *aux=lista;

        while(aux!=NULL){
            printf("%d ",aux->info);
            aux=aux->prox;
        }
}


int vet[3];
void organizar(Nodo *Lista){
    Nodo *aux = Lista;

    int i = -1;
    while(aux!=NULL){
            i++;
            vet[i]=aux->info;
            aux=aux->prox;
    }
}

void apagar(Nodo *Lista, int i) {
    Nodo *aux = Lista;
    int j = 0;
    do{aux->info;
       aux = aux->prox;
       j++;
    }while(j != i-1);
    Nodo *prox = aux->prox;
    aux->prox = prox->prox;
    free(prox);
}

int main(){
    Nodo * Lista=NULL;

    Lista=inserir_no_inicio(Lista,10);
    Lista=inserir_no_inicio(Lista,0);
    Lista=inserir_no_inicio(Lista,2);

    organizar(Lista);

    int posi = 0;

    if(vet[2]<vet[0] || vet[2]<vet[1]){
        posi=3;
    }else if(vet[0]>vet[2] || vet[0]>vet[1]){
            //posi=1; Não onsegui apagar a primeira posição
          }else if(vet[1]<vet[0] || vet[1]>vet[2]){
                    posi=2;
                }

    if(posi>0){
        apagar(Lista,posi);
    }
    imprimir(Lista);
    free(Lista);
    return 0;
}
