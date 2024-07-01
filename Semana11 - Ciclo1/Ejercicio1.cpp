#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void MostrarMenu()
{
    cout << "\t\t\tMENU\n";
    cout << "\t===================================\n";
    cout << "\t1. GENERAR DATOS\n";
    cout << "\t2. LISTAR LOS ELEMENTOS\n";
    cout << "\t3. BUSCAR MAYOR Y MOSTRAR UBICACION\n";
    cout << "\t4. BUSCAR MENOR Y MOSTRAR UBICACION\n";
    cout << "\t5. ORDENAR ARREGLO DESCENDENTEMENTE\n";
    cout << "\t9. SALIR\n";
}

void GenerarDatos(int* Arreglo, int N)
{
    for (int i = 0; i < N; i++)
    {
        Arreglo[i] = randInt(1, 250);
    }
    cout << "\n\t\tLOS DATOS HAN SIDO GENERADOS";
}

void ListarArreglo(int* Arreglo, int N)
{
    cout << "\t\tLISTADO DE NUMEROS ALMACENADOS\n";
    cout << "\t\t===============================\n";
    for (int i = 0; i < N; i++)
    {
        cout << "\tElemento " << i + 1 << ": " << Arreglo[i] << endl;
    }
}

void MayorYPosicion(int* Arreglo, int N)
{
    cout << "\t\tMOSTRAR MAYOR NUMERO Y SU POSICION\n";
    cout << "\t\t====================================\n";
    int posmayor = 0;
    for (int i = 1; i < N; i++)
    {
        if (Arreglo[posmayor] < Arreglo[i])
        {
            posmayor = i;
        }
    }
    cout << endl << "\t\tMayor numero: " << Arreglo[posmayor] << endl;
    cout << "\t\tPosicion del mayor numero: " << posmayor + 1;
}

void MenorYPosicion(int* Arreglo, int N)
{
    cout << "\t\tMOSTRAR MENOR NUMERO Y SU POSICION\n";
    cout << "\t\t====================================\n";
    int posmenor = 0;
    for (int i = 1; i < N; i++)
    {
        if (Arreglo[posmenor] > Arreglo[i])
        {
            posmenor = i;
        }
    }
    cout << endl << "\t\tMenor numero: " << Arreglo[posmenor] << endl;
    cout << "\t\tPosicion del menor numero: " << posmenor + 1;
}

void OrdenarDescendentemente(int* Arreglo, int N)
{
    cout << "\t\tLISTADO DE NUMEROS ALMACENADOS DESCENDENTEMENTE\n";
    cout << "\t\t================================================\n";
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
    for (int i = 0; i < N; i++)
    {
        cout << "\tElemento " << i + 1 << ": " << Arreglo[i] << endl;
    }
}

int main()
{
    srand(time(nullptr));
    int N = randInt(10, 100);
    int* Arreglo = new int[N];
    int* opc = new int;
    *opc = 0;

    do
    {
        MostrarMenu();
        cout << "\tIngrese opcion: "; cin >> *opc;
        system("cls");
        switch (*opc)
        {
        case 1:
            system("cls");
            GenerarDatos(Arreglo, N);
            system("pause>0");
            break;
        case 2:
            system("cls");
            ListarArreglo(Arreglo, N);
            system("pause>0");
            break;
        case 3:
            system("cls");
            MayorYPosicion(Arreglo, N);
            system("pause>0");
            break;
        case 4:
            system("cls");
            MenorYPosicion(Arreglo, N);
            system("pause>0");
            break;
        case 5:
            system("cls");
            OrdenarDescendentemente(Arreglo, N);
            system("pause>0");
            break;
        case 9:
            break;
        }
        system("cls");
    } while (*opc != 9);

    delete opc;
    delete[] Arreglo;

    Arreglo = nullptr;
    opc = nullptr;

    system("pause>0");
    return 0;
}
