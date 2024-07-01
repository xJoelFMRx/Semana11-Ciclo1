#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GenerarArreglo(int* Arreglo, int N)
{
    for (int i = 0; i < N; i++)
    {
        Arreglo[i] = randInt(1, 100);
    }
}

void OrdenarDeMenorAMayor(int* Arreglo, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (Arreglo[i] > Arreglo[j])
            {
                int temp = Arreglo[i];
                Arreglo[i] = Arreglo[j];
                Arreglo[j] = temp;
            }
        }
    }
}

void MostrarArreglo(int* Arreglo, int N)
{
    cout << "Arreglo: ";
    for (int i = 0; i < N; i++)
    {
        cout << Arreglo[i] << " ";
    }
    cout << endl;
}

void VecesRepetido(int* Arreglo, int N)
{
    int ContRepe = 1;
    for (int i = 0; i < N; i++)
    {
        if (Arreglo[i] == Arreglo[i + 1])
        {
            ContRepe++;
        }
        else
        {
            cout << Arreglo[i] << " se repite " << ContRepe << " veces" << endl;
            ContRepe = 1;
        }
    }
}

int* EliminarEnPosicion(int* arreglo, int& N, int pos) {
    int* temporal = nullptr;
    if (N > 1) {
        temporal = new int[N - 1];
        for (int i = 0, k = 0; i < N; i++)
        {
            if (i != pos)
            {
                temporal[k++] = arreglo[i];
            }
        }
    }
    N--;
    delete[] arreglo;
    arreglo = nullptr;
    return temporal;
}

int* BorrarValoresRepetido(int* Arreglo, int& N)
{
    for (int i = 0; i < N; i++)
    {
        if (Arreglo[i] == Arreglo[i + 1])
        {
            Arreglo = EliminarEnPosicion(Arreglo, N, i);
            i--;
        }
    }
    return Arreglo;
}

int main()
{
    srand(time(nullptr));
    int N = 30;
    int* Arreglo = new int[N];

    GenerarArreglo(Arreglo, N);
    MostrarArreglo(Arreglo, N);
    OrdenarDeMenorAMayor(Arreglo, N);
    MostrarArreglo(Arreglo, N);
    VecesRepetido(Arreglo, N);
    Arreglo = BorrarValoresRepetido(Arreglo, N);
    MostrarArreglo(Arreglo, N);

    delete[] Arreglo;

    system("pause>0");
    return 0;
}