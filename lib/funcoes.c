//Protótipos de funções e implementação
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>


// Funções de Criação, Inserção e Retirada:

void cria(Lista *l);
int insereOrdenado(Lista *l, int id, char nome[], int dia, int mes, int ano, char siglaEstado[], char cidade[], char bairro[], char rua[], int numero, double saldo, double limite);
int retira(Lista *l, int id);

// Funções de Visualização:

int estaVazia(Lista l);
int getInicio(Lista l);
int getFim(Lista l);
int getTamanho(Lista l);
void exibe(Lista l);

// Funções de Pesquisa, Ordenação e Modificação de Saldo:
void buscaCliente(Lista *l, char nome[]);
int comparePorSaldo(const void *cliente1, const void *cliente2);
int comparePorID(const void *cliente1, const void *cliente2);
void ordena(Lista *l, int sortOption);
void exibeClientesPorEstado(Lista l, char siglaEstado[]);
double getSaldo(Lista l, int id, int tam);
int realizarSaque(Lista *lista, int id, double valorSaque);
int realizarDeposito(Lista *lista, int id, double valorDeposito);

int main () {
  printf("Aqui virao as funcoes!");
 
  return 0;
}

void cria(Lista *l) // Função para criar a lista
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereOrdenado(Lista *l, int id, char nome[], int dia, int mes, int ano, char siglaEstado[], char cidade[], char bairro[], char rua[], int numero, double saldo, double limite) // Função para inserir os IDs de forma ordenada
{
    Cliente *aux = (Cliente *)malloc(sizeof(Cliente));

    if (aux == NULL) // alocando no na memoria e checando se deu certo
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
    aux->saldo = saldo;
    aux->limite = limite;
    l->tam++;

    if (l->inicio == NULL) // 1° Caso: primeiro elemento. Se ao inserir, a lista estiver vazia, significa que esse eh o primeiro elemento.
    {
        (*aux).prox = NULL;
        l->inicio = aux;
        l->fim = aux;
    }
    else if (id < l->inicio->id) // 2° Caso: dado menor que o dado do inicio, insere no inicio. Se ao inserir, o dado for menor do que o dado do início, insere no início.
    {
        aux->prox = (l)->inicio;
        l->inicio = aux;
    }
    else if (id > l->fim->id) // 3° Caso: dado maior que o dado do fim, insere no fim. Se ao inserir, o dado for maior que o dado do fim, insere no fim.
    {
        (*aux).prox = NULL;
        l->fim->prox = aux;
        l->fim = aux;
    }
    else
    {
        Cliente *anterior = l->inicio;
        Cliente *atual = anterior->prox;

        while (id > atual->id)
        {
            anterior = atual;
            atual = atual->prox;
        }

        aux->prox = atual;
        anterior->prox = aux;
    }

    return 1;
}

int retira(Lista *l, int id) // Função que remove um ID.
{
    Cliente *aux;
    Cliente *auxFim;

    if (l->inicio == NULL)
    {
        printf("A lista esta vazia!\n");
        return 0;
    }

    if ((id == l->inicio->id) && (l->inicio == l->fim)) // 1° Caso: lista unitaria. Se ao retirar, a lista apresentar apenas um elemento, retira esse elemento e libera a memória.
    {
        aux = l->inicio;  // Aux aponta para o no que vou remover.
        l->inicio = NULL; // Inicio aponta pra Null.
        l->fim = NULL;    // Fim aponta pra Null.
        free(aux);        // Liberando memoria.
        l->tam--;

        return 1;
    }

    if (id == l->inicio->id) // 2° Caso: removendo primeiro elemento.
    {
        aux = l->inicio;       // Aux aponta para o no que vou remover.
        l->inicio = aux->prox; // Inicio aponta para o novo inicio.
        free(aux);             // Liberando memoria.
        l->tam--;

        return 1;
    }

    if (id == l->fim->id)
    {
        aux = l->inicio;
        auxFim = l->inicio->prox;

        while (auxFim != l->fim)
        {
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

    while ((id != auxFim->id) && (auxFim != l->fim))
    {
        auxFim = auxFim->prox;
        aux = aux->prox;
    }

    if (auxFim == l->fim)
    {
        printf("O elemento %d nao esta na lista.\n", id);
        return 0;
    }

    aux->prox = auxFim->prox;
    free(auxFim);
    l->tam--;

    return 1;
}

int estaVazia(Lista l) // Funcão que verifica se a lista está vazia
{
    return l.inicio == NULL;
}

int getInicio(Lista l)
{
    return l.inicio->id;
}

int getFim(Lista l)
{
    return l.fim->id;
}

int getTamanho(Lista l)
{
    return l.tam;
}

void exibe(Lista l) // Função que mostra a lista com seus IDs
{
    Cliente *aux;

    if (l.inicio == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t      Clientes\n\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        aux = l.inicio;
        while (aux != NULL)
        {
            printf("ID: %d\n", aux->id);
            printf("Nome: %s\n", aux->nome);
            if (aux->dataNascimento.dia < 10 && aux->dataNascimento.mes < 10)
            {
                printf("Data de Nascimento: 0%d/0%d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            }
            else if (aux->dataNascimento.dia >= 10 && aux->dataNascimento.mes < 10)
            {
                printf("Data de Nascimento: %d/0%d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            }
            else if (aux->dataNascimento.dia < 10 && aux->dataNascimento.mes >= 10)
            {
                printf("Data de Nascimento: 0%d/%d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            }
            else
            {
                printf("Data de Nascimento: %d/%d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            }
            printf("Endereço: %s, %d, %s, %s - %s\n", aux->endereco.rua, aux->endereco.numero, aux->endereco.bairro, aux->endereco.cidade, aux->endereco.siglaEstado);
            printf("Saldo: R$ %.2f\n", aux->saldo);
            printf("Limite: R$ %.2f\n", aux->limite);
            printf("\n");
            aux = aux->prox;
        }
    }
}

void buscaCliente(Lista *l, char nome[])
{
    Cliente *aux = l->inicio;
    int encontrado = 0;

    while (aux != NULL)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            printf("\nID: %d\n", aux->id);
            printf("Nome: %s\n", aux->nome);
            printf("Data de Nascimento: %02d/%02d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            printf("Endereço: %s, %d, %s, %s - %s\n", aux->endereco.rua, aux->endereco.numero, aux->endereco.bairro, aux->endereco.cidade, aux->endereco.siglaEstado);
            printf("Saldo: R$ %.2f\n", aux->saldo);
            printf("Limite: R$ %.2f\n", aux->limite);
            encontrado = 1;
            break;
        }
        aux = aux->prox;
    }

    if (!encontrado)
    {
        printf("Cliente não encontrado.\n");
    }
}

// Função de comparação para a ordenação por saldo
int comparePorSaldo(const void *cliente1, const void *cliente2)
{
    const Cliente *c1 = *(const Cliente **)cliente1;
    const Cliente *c2 = *(const Cliente **)cliente2;

    if (c1->saldo < c2->saldo)
        return 1;
    else if (c1->saldo > c2->saldo)
        return -1;
    else
        return 0;
}

int comparePorID(const void *cliente1, const void *cliente2)
{
    const Cliente *c1 = *(const Cliente **)cliente1;
    const Cliente *c2 = *(const Cliente **)cliente2;

    if (c1->id < c2->id)
        return -1;
    else if (c1->id > c2->id)
        return 1;
    else
        return 0;
}

void ordena(Lista *l, int sortOption)
{
    Cliente **array = malloc(l->tam * sizeof(Cliente *));
    if (array == NULL)
    {
        printf("Erro de alocação de memória.\n");
        return;
    }

    Cliente *aux = l->inicio;
    int i = 0;
    while (aux != NULL)
    {
        array[i] = aux;
        aux = aux->prox;
        i++;
    }

    if (sortOption == 1)
    {
        qsort(array, l->tam, sizeof(Cliente *), comparePorSaldo);
    }
    else if (sortOption == 2)
    {
        qsort(array, l->tam, sizeof(Cliente *), comparePorID);
    }

    l->inicio = array[0];
    l->fim = array[l->tam - 1];
    for (int j = 0; j < l->tam - 1; j++)
    {
        array[j]->prox = array[j + 1];
    }
    array[l->tam - 1]->prox = NULL;

    free(array);
}

void exibeClientesPorEstado(Lista l, char siglaEstado[])
{
    Cliente *aux = l.inicio;
    int encontrado = 0;

    printf("\nClientes do estado %s:\n", siglaEstado);

    while (aux != NULL)
    {
        if (strcmp(aux->endereco.siglaEstado, siglaEstado) == 0)
        {
            printf("\nID: %d\n", aux->id);
            printf("Nome: %s\n", aux->nome);
            printf("Data de Nascimento: %02d/%02d/%d\n", aux->dataNascimento.dia, aux->dataNascimento.mes, aux->dataNascimento.ano);
            printf("Endereço: %s, %d, %s, %s - %s\n", aux->endereco.rua, aux->endereco.numero, aux->endereco.bairro, aux->endereco.cidade, aux->endereco.siglaEstado);
            printf("Saldo: R$ %.2f\n", aux->saldo);
            printf("Limite: R$ %.2f\n", aux->limite);
            printf("\n");
            encontrado = 1;
        }
        aux = aux->prox;
    }

    if (!encontrado)
    {
        printf("Nenhum cliente encontrado nesse estado.\n");
    }
}

double getSaldo(Lista l, int id, int tam)
{
    Cliente *aux = l.inicio;

    while (aux != NULL)
    {
        if (id == aux->id)
        {
            return aux->saldo;
        }

        aux = aux->prox;
    }

    printf("O cliente com esse ID não existe!");
}

int realizarSaque(Lista *lista, int idCliente, double valorSaque)
{
    Cliente *aux = lista->inicio;

    while (aux != NULL)
    {
        if (aux->id == idCliente)
        {
            if (aux->saldo >= valorSaque)
            {
                aux->saldo -= valorSaque;
                printf("O saque foi realizado com sucesso!");
                return 1; // Saque realizado com sucesso
            }
            else
            {
                printf("O valor de saldo é insuficiente para realizar o saque!");
                return 0; // Saldo insuficiente
            }
        }
        aux = aux->prox;
    }

    return -1; // Cliente não encontrado
}

int realizarDeposito(Lista *lista, int idCliente, double valorDeposito)
{
    Cliente *aux = lista->inicio;

    while (aux != NULL)
    {
        if (aux->id == idCliente)
        {
            aux->saldo += valorDeposito;
            printf("O depósito foi realizado com sucesso!");
            return 1;
        }
        aux = aux->prox;
    }

    return -1; // Cliente não encontrado
}
