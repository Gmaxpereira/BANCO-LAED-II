#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int dia, mes, ano;
}Date;

typedef struct {
    char siglaEstado[3], cidade[100], bairro[100], rua[100];
    int numero;
}Adress;

typedef struct {
    int id;
    char nome[255];
    Date dataNascimento;
    Adress endereco;
    double saldo;
    double limite;
    struct Cliente *prox;
} Cliente;

// typedef struct cliente Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
    int tam;
} Lista;

// Funções de Manipulação
void cria(Lista *l);
int insereOrdenado(Lista *l, int id, char nome[], int dia, int mes, int ano, char siglaEstado[], char cidade[], char bairro[], char rua[], int numero);
int retira(Lista *l, int id);

// Funções de Visualização
int estaVazia(Lista l);
int getInicio(Lista l);
int getFim(Lista l);
int getTamanho(Lista l);
void exibe(Lista l);

int main () {
    Lista l;
    int sucesso, opcao = 1;

    int id;
    char nome[255];

    setlocale(LC_ALL, "Portuguese");
    cria(&l);

    sucesso = insereOrdenado(&l, 1, "Lionel Messi", 24, 6, 1987, "SP", "São Paulo", "Alphaville", "Rua Boca Júnior", 7);
    sucesso = insereOrdenado(&l, 2, "Cristiano Ronaldo", 5, 2, 1985, "RJ", "Rio de Janeiro", "Bangu", "Rua Sou o Milior", 5);
    sucesso = insereOrdenado(&l, 3, "Neymar", 5, 2, 1992, "SP", "Santos", "Sapo", "Rua Bruna Marquezine", 2);
    sucesso = insereOrdenado(&l, 4, "Karim Benzema", 19, 12, 1987, "RS", "Porto Alegre", "Chimarrão", "Rua das Araucárias", 1);


    if (!estaVazia(l)) {
        exibe(l);
    }

    while (opcao == 1) {
        printf("\n-------------------------------------------------\n");
        printf("Qual ID deseja remover? ");
        scanf("%d", &id);

        sucesso = retira(&l, id);
        if (!sucesso)
            printf("FALHA EM REMOVER O ID: %d\n\n", id);

        exibe(l);

        printf("\nDeseja remover mais algum elemento? \n1 - Sim \n2 - Nao\n");
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

int insereOrdenado(Lista *l, int id, char nome[], int dia, int mes, int ano, char siglaEstado[], char cidade[], char bairro[], char rua[], int numero) {
    Cliente *aux = (Cliente *) malloc(sizeof(Cliente));

    if (aux == NULL)
        return 0;

    aux->id = id;
    strcpy(aux->nome, nome);
    aux->dataNascimento.dia = dia;
    aux->dataNascimento.mes = mes;
    aux->dataNascimento.ano = ano;
    strcpy(aux->endereco.siglaEstado, siglaEstado);
    strcpy(aux->endereco.cidade, cidade);
    strcpy(aux->endereco.bairro, bairro);
    strcpy(aux->endereco.rua, rua);
    aux->endereco.numero = numero;
    l->tam++;

    if (l->inicio == NULL) {
        (*aux).prox = NULL;
        l->inicio = aux;
        l->fim = aux;
    }
    else if(id < l->inicio->id) {
        aux->prox = (l)->inicio;
        l->inicio = aux;
    }
    else if(id > l->fim->id) {
        (*aux).prox = NULL;
        l->fim->prox = aux;
        l->fim = aux;
    }
    else {
        Cliente *anterior = l->inicio;
        Cliente *atual = anterior->prox;

        while (id > atual->id) {
            anterior = atual;
            atual = atual->prox;
        }

        aux->prox = atual;
        anterior->prox = aux;
    }

    return 1;
}

int retira(Lista *l, int id) {
    Cliente *aux;
    Cliente *auxFim;

    if (l->inicio == NULL) {
        printf("A lista esta vazia!\n");
        return 0;
    }

    if ((id == l->inicio->id) && (l->inicio == l->fim)) {
        aux = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        l->tam--;

        return 1;
    }

    if (id == l->inicio->id) {
        aux = l->inicio;
        l->inicio = aux->prox;
        free(aux);
        l->tam--;

        return 1;
    }

    if (id == l->fim->id) {
        aux = l->inicio;
        auxFim = l->inicio->prox;

        while (auxFim != l->fim) {
            aux = aux->prox;
            auxFim = auxFim->prox;
        }

        aux->prox = NULL;
        l->fim = aux;

        free(auxFim);
        l->tam--;

        return 1;
    }

    auxFim = l->inicio->prox;
    aux = l->inicio;

    while ((id != auxFim->id) && (auxFim != l->fim)) {
        auxFim = auxFim->prox;
        aux = aux->prox;
    }

    if (auxFim == l->fim) {
        printf("O elemento %d nao esta na lista.\n", id);
        return 0;
    }

    aux->prox = auxFim->prox;
    free(auxFim);
    l->tam--;

    return 1;
}

int estaVazia(Lista l) {
    return l.inicio == NULL;
}

int getInicio(Lista l) {
    return l.inicio->id;
}

int getFim(Lista l) {
    return l.fim->id;
}

int getTamanho(Lista l) {
    return l.tam;
}

void exibe(Lista l) {
    Cliente *aux;

    if (l.inicio == NULL) {
        printf("Lista vazia!\n");
    } else {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t      Clientes\n\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        aux = l.inicio;
        while (aux != NULL) {
            printf("ID: %d\n", aux->id);
            printf("Nome: %s\n", aux->nome);
            printf("Data de Nascimento: %d/%d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            printf("Endereço: %s, %d, %s, %s - %s\n", aux->endereco.rua, aux->endereco.numero, aux->endereco.bairro, aux->endereco.cidade, aux->endereco.siglaEstado);
            printf("\n");
            aux = aux->prox;
        }
    }
}
