#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void show_vet(int *vetor, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cout << "{" << vetor[i] << "}";
    }

    cout << "\n";
}

void popular_vetor(int *vetor, int tam)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < tam; i++)
        vetor[i] = rand() % 1000;
}

void ordem_decrescente(int *vetor, int tam)
{
    int i, j, aux;
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (vetor[j] < vetor[i])
            {
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
}

int *alocar_vetor(int *vetor, int tam)
{
    vetor = (int *)malloc(tam * sizeof(int));

    popular_vetor(vetor, tam);

    ordem_decrescente(vetor, tam);

    return vetor;
}

int Selection_sort(int *vetor, int tam)
{
    int menor, aux, i, j;

    for (i = 0; i < tam; i++)
    {

        menor = i;

        for (j = i + 1; j < tam; j++)

        {

            if (vetor[j] < vetor[i])
            {
                menor = j;
            }
        }

        if (menor != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }

        show_vet(vetor, tam);
    }
}

int Insertion_sort(int *vetor, int tam)
{
    int i, j, atual;

    for (i = 1; i < tam; i++)
    {
        atual = vetor[i];

        j = i - 1;

        while ((j >= 0) && (atual < vetor[j]))
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = atual;
        show_vet(vetor, tam);
    }
}

void Quick_Sort(int *vetor, int inicio, int final)
{
    int pivo, esq, dir, meio, aux;

    esq = inicio;
    dir = final;

    meio = (int)((esq + dir) / 2);
    pivo = vetor[meio];

    while (dir > esq)
    {
        while (vetor[esq] < pivo)
        {
            esq = esq + 1;
        }
        while (vetor[dir] > pivo)
        {
            dir = dir - 1;
        }

        if (esq <= dir)
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;

            esq = esq + 1;
            dir = dir - 1;
        }

        show_vet(vetor, 10);
    }

    if (inicio < dir)
    {
        Quick_Sort(vetor, inicio, dir);
    }
    if (esq < final)
    {
        Quick_Sort(vetor, esq, final);
    }
}

int main()
{
    int *vetor, tam = 10;
    vetor = alocar_vetor(vetor, tam);
    Quick_Sort(vetor, 0, tam);
    cout << "==================================================\n";
}