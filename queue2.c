/*Fala Bruno beleza? Então, eu tenho a mania de sempre escrever os códigos em inglês,
mas não as mensagens, só para não achar estranho kkkkkkk. E outra, em cada função eu coloquei
uma mini explicação para eu não ir esquecendo que tinha que fazer kkkkkkk*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

void queue(int);
void deQueue();
void display();

// Opcionais
int sizeQueue();
void positionQueue();

int queueVector[MAX_SIZE], front = -1, back = -1;

int main()
{
    queue(1);
    queue(2);
    queue(3);
    queue(4);
    queue(5);
    queue(6); // nao vai adicionar
    display();
    deQueue();
    display();
    sizeQueue();
    positionQueue(2);
}

void queue(int item)
{
    // Adiciona itens a fila, e reseta o front, e sempre adiciona + 1 no back, respeitando o valor do SIZE
    if (back == MAX_SIZE - 1)
        printf("CPU: Overflow Aritmetico! Nao foi possivel adicionar o item %d a fila.\n", item);
    else
    {
        if (front == -1)
            front = 0;
        // scanf("%d", &item);
        back = back + 1;
        queueVector[back] = item;
        printf("\nItem %d foi adicionado a fila!\n", item);
    }
}

void deQueue()
{
    // Remove itens da fila, começando com o primeiro que foi adicionado.
    if (front == -1 || front > back)
    {
        printf("CPU: Underflow Aritmetico! Nao eh possivel remover nada do nada.\n");
        return;
    }
    printf("Item %d foi removido da fila!\n", queueVector[front]);
    front++;
}

void display()
{
    // Lista todos os itens da fila.
    if (front == -1 || front > back)
        printf("A fila esta vazia.\n");
    else
    {
        printf("Fila: \n");
        for (int i = front; i <= back; i++)
            printf("%d ", queueVector[i]);
        printf("\n");
    }
}

int sizeQueue()
{
    // Faz uma contagem de quantos itens tem na fila, tipo um length
    int c = 0, i;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (queueVector[i] != 0)
            c++;
    }
    printf("\nTotal de itens na fila: %d\n", c);
    return c;
}

void positionQueue(int item)
{
    // Utiliza um looping para pegar todos os itens da fila, então verifica se o
    // número existe, é igual ao inserito e/ou retorna.
    int index = 0, indexFind = -1;

    if (front == -1 || front > back)
    {
        printf("A fila esta vazia.\n");
        return;
    }

    for (int i = front; i <= back; i++)
    {
        if (queueVector[i] == item)
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
        printf("O item %d foi encontrado na posicao: %d\n", item, indexFind - front);
    }
    return;
}