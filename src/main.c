#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct {
    int dia, mes, ano;
}Date;
*/

typedef struct {
    int id;
    char nome[255];
    struct no *prox;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
    int tam;
} Lista;

// Funções de Manipulação
void cria(Lista *l);
int insereOrdenado(Lista *l, int dado, char nome[])
int retira(Lista *l, int dado);

// Funções de Visualização
int estaVazia(Lista l);
int getInicio(Lista l);
int getFim(Lista l);
int getTamanho(lista l);
void exibe(Lista l);

int main () {
    Lista l;
    int sucesso, opcao = 1;
    int id, char nome[255];

    cria(&l);

    sucesso = insereOrdenado(&l, 1, "Lionel Messi");

    if (!estaVazia(l)) {
        exibe(l);
    }

    while (opcao == 1) {
        printf("\n-------------------------------------------------\n");
        printf("Qual ID deseja remover?");
        scanf("%d", &id);

        sucesso = retira(&l, id);
        if (!sucesso)
            printf("FALHA EM REMOVER O ID: %d\n\n", id);

        mostra(l);

        printf("\nDeseja remover mais algum elemento? \n1 - sim \n2 - nao\n");
        scanf("%d", &opcao);
    }

    while (!estaVazia(l)) {
        sucesso = retira(&l, getInicio(l));
    }

    return 0;

}

void cria(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereOrdenado(Lista *l, int id, char nome[]) {
    No *aux = (No *) malloc(sizeof(No));

    if (aux == NULL)
        return 0;

    aux->id = id;
    l->tam++;
}
