#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingrese numero: "; cin >> N;
    } while (N < 40 || N > 50);
    return N;
}

void GenerarArreglo(int* Arreglo, int N)
{
    for (int i = 0; i < N; i++)
    {
        Arreglo[i] = randInt(1, 50);
    }
}

void MostrarValores(int* Arreglo, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Indice " << i << ": " << Arreglo[i] << endl;
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

int* EliminarMultiplos3(int*& Arreglo, int& N)
{
    for (int i = 0; i < N; i++)
    {
        if (Arreglo[i] % 3 == 0)
        {
            Arreglo = EliminarEnPosicion(Arreglo, N, i);
            i--;
        }
    }
    return Arreglo;
}

void OrdenarMayorAMenor(int* Arreglo, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (Arreglo[i] < Arreglo[j])
            {
                int temp = Arreglo[i];
                Arreglo[i] = Arreglo[j];
                Arreglo[j] = temp;
            }
        }
    }
}

int* InsertarEnPosicion(int* Arreglo, int& N, int nuevoValor, int pos)
{
    //Crear un arreglo temporal del mismo tipo y de Tamaño N + 1
    int* temp = new int[N + 1];
    //Copiar elementos del arreglo original hasta la posicion deseada
    for (int i = 0; i < N; i++)
    {
        temp[i] = Arreglo[i];
    }
    //Insertar el nuevo elemento en la posicion deseada
    temp[pos] = nuevoValor;
    //Copiar elementos del arreglo original despues la posicion deseada
    for (int i = pos; i < N; i++)
    {
        temp[i + 1] = Arreglo[i];
    }
    //Actualizar el tamaño del arreglo
    N += 1;
    //Liberar la memoria del arreglo original
    delete[] Arreglo;
    Arreglo = nullptr;
    //Retornamos el arreglo temporal
    return temp;
}

void InsertarNuevoValor(int*& Arreglo, int& N, int nuevoValor)
{
    bool insertado = false;
    for (int i = 0; i < N; i++)
    {
        if (nuevoValor >= Arreglo[i])
        {
            insertado = true;
            Arreglo = InsertarEnPosicion(Arreglo, N, nuevoValor, i);
            break;
        }
    }
    if (!insertado)
    {
        //Insertar al final
        Arreglo = InsertarEnPosicion(Arreglo, N, nuevoValor, N);
    }
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    int* Arreglo = new int[N];
    int nuevoValor;

    GenerarArreglo(Arreglo, N);
    MostrarValores(Arreglo, N);
    EliminarMultiplos3(Arreglo, N);
    cout << "\nArreglo luego de eliminar multiplos de 3\n";
    MostrarValores(Arreglo, N);
    OrdenarMayorAMenor(Arreglo, N);
    cout << "\nArreglo luego de ser ordenado de mayor a menor\n";
    MostrarValores(Arreglo, N);
    cout << "\nIngrese un numero para que sea insertado en el arreglo: "; cin >> nuevoValor;
    InsertarNuevoValor(Arreglo, N, nuevoValor);
    MostrarValores(Arreglo, N);

    delete[] Arreglo;

    system("pause>0");
    return 0;
}