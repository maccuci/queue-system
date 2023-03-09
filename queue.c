/*Fala Bruno beleza? Então, eu tenho a mania de sempre escrever os códigos em inglês,
mas não as mensagens, só para não achar estranho kkkkkkk. E outra, em cada função eu coloquei
uma mini explicação para eu não ir esquecendo que tinha que fazer kkkkkkk*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void queue();
void deQueue();
void display();

// Opcionais
int countQueue();
void positionQueue();

int queueVector[SIZE], front = -1, back = -1;

int main()
{
    int choice, n;
    while (1)
    {
        printf("Escolha uma opcao: \n");
        printf("1. Adicionar na fila\n");
        printf("2. Remover da fila\n");
        printf("3. Listar a fila\n");
        printf("4. Contar itens na fila\n");
        printf("5. Encontrar a posicao na fila\n");
        printf("6. Sair\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            queue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            countQueue();
            break;
        case 5:
            positionQueue();
            break;
        case 6:
            exit(0);
            break;
        default:
            main();
        }
    }
    return 0;
}

void queue()
{
    // Adiciona itens a fila, e reseta o front, e sempre adiciona + 1 no back, respeitando o valor do SIZE
    int item;
    if (back == SIZE - 1)
        printf("CPU: Overflow Aritmetico\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Insira o item para adicionar na fila: \n");
        scanf("%d", &item);
        back = back + 1;
        queueVector[back] = item;
    }
}

void deQueue()
{
    // Remove itens da fila, começando com o primeiro que foi adicionado.
    if (front == -1 || front > back)
    {
        printf("CPU: Underflow Aritmetico \n");
        return;
    }
    else
    {
        printf("Item removido da fila: %d\n", queueVector[front]);
        front = front + 1;
    }
}

void display()
{
    // Lista todos os itens da fila.
    if (front == -1)
        printf("A fila esta vazia.\n");
    else
    {
        printf("Fila: \n");
        for (int i = front; i <= back; i++)
            printf("%d ", queueVector[i]);
        printf("\n");
    }
}

int countQueue()
{
    // Faz uma contagem de quantos itens tem na fila, tipo um length
    int c = 0, i;

    for (i = 0; i < SIZE; i++)
    {
        if (queueVector[i] != 0)
            c++;
    }
    printf("Total de itens na fila: %d\n", c);
    return c;
}

void positionQueue()
{
    // Utiliza um looping para pegar todos os itens da fila, então verifica se o
    // número existe, é igual ao inserito e/ou retorna.
    int index = 0, indexFind = -1, input;

    if (front == -1 || front > back)
    {
        printf("A fila esta vazia.\n");
        return;
    }

    printf("Insira o item para mostrar a posicao: \n");
    scanf("%d", &input);

    for (int i = front; i <= back; i++)
    {
        if (queueVector[i] == input)
        {
            indexFind = i;
            break;
        }
    }
    if (indexFind == -1)
    {
        printf("O item nao foi encontrado na fila.\n");
    }
    else
    {
        printf("O item %d foi encontrado na posicao: %d\n", input, indexFind - front);
    }
    return;
}