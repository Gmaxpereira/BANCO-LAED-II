#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "../include/cliente.h"

/*
Autores: Gabriel Maximino, João Henrique,
         Luiz Roberto e Vinícius Martins
*/

int main()
{
    Lista l;
    int sucesso, sortOption, opcao = 0;

    int id;
    char nome[255], siglaEstado[3];
    double valorSaque, saldo, valorDeposito;

    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    cria(&l);

    sucesso = insereOrdenado(&l, 1, "Lionel Messi", 24, 06, 1987, "SP", "Sao Paulo", "Alphaville", "Rua Boca Junior", rand() % 1000, 9874.32, 20000);
    sucesso = insereOrdenado(&l, 2, "Cristiano Ronaldo", 05, 02, 1985, "RJ", "Rio de Janeiro", "Bangu", "Rua Sou o Milior", rand() % 1000, 7614.13, 15000);
    sucesso = insereOrdenado(&l, 3, "Neymar", 05, 02, 1992, "SP", "Santos", "Sapo", "Rua Bruna Marquezine", rand() % 1000, 1342.91, 5600.50);
    sucesso = insereOrdenado(&l, 4, "Karim Benzema", 19, 12, 1987, "RS", "Porto Alegre", "Chimarrao", "Rua das Araucarias", rand() % 1000, 8431.93, 10000);
    sucesso = insereOrdenado(&l, 5, "Erling Haaland", 21, 07, 2000, "MT", "Tangara da Serra", "Homem do Campo", "Sitio Cambui", rand() % 1000, 5183.00, 7500.30);
    sucesso = insereOrdenado(&l, 6, "Aragorn Elessar", 1, 03, 1915, "AM", "Gondolin", "Anduril", "Rua Guardiao do Norte", rand() % 1000, 732.41, 2500.00);
    sucesso = insereOrdenado(&l, 7, "Eddard Stark", 26, 03, 1960, "RS", "Gramado", "Winterfell", "Rua Whitewalker", rand() % 1000, 8613.91, 13000);
    sucesso = insereOrdenado(&l, 8, "Sirius Black", 03, 11, 1959, "MG", "Pocos de Caldas", "Animago", "Rua Ordem da Fenix", rand() % 1000, 12278, 30000);
    sucesso = insereOrdenado(&l, 9, "Paul Atreides", 17, 10, 2001, "TO", "Arrakis", "Fremen", "Rua Dagacris", rand() % 1000, 92761.99, 200000);
    sucesso = insereOrdenado(&l, 10, "Roronoa Zoro", 11, 11, 2002, "MG", "Laugh Tale", "Santoryuu", "Rua Shishi Sonson", rand() % 1000, 7.51, 600);

    if (!estaVazia(l))
    {
        exibe(l);
    }

    while (opcao != 9)
    {
        printf("\n-------------------------------------------------\n");
        printf("Qual operacao deseja realizar?\n1 - Exibir os dados de um cliente\n2 - Ordenar os clientes por saldo\n3 - Ordenar os clientes por ID\n4 - Exibir todos os clientes que moram em um estado\n5 - Excluir um cliente\n6 - Exibir todos os clientes\n7 - Saque\n8 - Deposito\n9 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", nome);
            buscaCliente(&l, nome);
            break;
        case 2:
            ordena(&l, 1);
            exibe(l);
            break;
        case 3:
            ordena(&l, 2);
            exibe(l);
            break;
        case 4:
            printf("Digite a sigla do estado: ");
            scanf(" %[^\n]", siglaEstado);
            exibeClientesPorEstado(l, siglaEstado);
            break;
        case 5:
            printf("Deseja remover o cliente com qual ID? ");
            scanf("%d", &id);
            sucesso = retira(&l, id);
            if (!sucesso)
                printf("FALHA EM REMOVER O ID: %d\n\n", id);
            exibe(l);
            break;
        case 6:
            exibe(l);
            break;
        case 7:
            printf("Digite o ID do cliente: ");
            scanf("%d", &id);
            printf("Digite o valor do saque: ");
            scanf("%lf", &valorSaque);

            saldo = getSaldo(l, id, l.tam);
            printf("O saldo atual do cliente com id %d eh R$ %.2f\n", id, saldo);

            int resultadoSaque = realizarSaque(&l, id, valorSaque);

            if (resultadoSaque == -1)
            {
                printf("O cliente com esse ID nao foi encontrado");
            }
            else
            {
                saldo = getSaldo(l, id, l.tam);
                printf(" O saldo atual do cliente com id %d eh R$ %.2f", id, saldo);
            }
            break;
        case 8:
            printf("Digite o ID do cliente: ");
            scanf("%d", &id);
            printf("Digite o valor do depósito: ");
            scanf("%lf", &valorDeposito);

            saldo = getSaldo(l, id, l.tam);
            printf("O saldo atual do cliente com id %d eh R$ %.2f\n", id, saldo);

            int resultadoDeposito = realizarDeposito(&l, id, valorDeposito);

            if (resultadoDeposito == -1)
            {
                printf("O cliente com esse ID nao foi encontrado");
            }
            else
            {
                saldo = getSaldo(l, id, l.tam);
                printf(" O saldo atual do cliente com id %d eh R$ %.2f", id, saldo);
            }
            break;
        case 9:
            break;
        default:
            printf("Escolha uma opcao valida!");
            break;
        }
    }

    while (!estaVazia(l))
    {
        sucesso = retira(&l, getInicio(l));
    }

    return 0;
}
