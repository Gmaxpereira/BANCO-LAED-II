#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct
{
    int dia, mes, ano;
} Date;

typedef struct
{
    char siglaEstado[3], cidade[100], bairro[100], rua[100];
    int numero;
} Adress;

typedef struct Cliente
{
    int id;
    char nome[255];
    Date dataNascimento;
    Adress endereco;
    double saldo;
    double limite;
    struct Cliente *prox;
} Cliente;

typedef struct
{
    Cliente *inicio;
    Cliente *fim;
    int tam;
} Lista;

void cria(Lista *l);
int insereOrdenado(Lista *l, int id, char nome[], int dia, int mes, int ano, char siglaEstado[], char cidade[], char bairro[], char rua[], int numero, double saldo, double limite);
int retira(Lista *l, int id);

int estaVazia(Lista l);
int getInicio(Lista l);
int getFim(Lista l);
int getTamanho(Lista l);
void exibe(Lista l);

void buscaCliente(Lista *l, char nome[]);
int comparePorSaldo(const void *cliente1, const void *cliente2);
int comparePorID(const void *cliente1, const void *cliente2);
void ordena(Lista *l, int sortOption);
void exibeClientesPorEstado(Lista l, char siglaEstado[]);
double getSaldo(Lista l, int id, int tam);
int realizarSaque(Lista *lista, int id, double valorSaque);
int realizarDeposito(Lista *lista, int id, double valorDeposito);

#endif /* CLIENTE_H */