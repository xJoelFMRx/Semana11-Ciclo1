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
    cout << "\t================================================\n";
    cout << "\t1.GENERAR NOTAS\n";
    cout << "\t2.LISTAR NOTAS\n";
    cout << "\t3.MOSTRAR MAYOR NOTA\n";
    cout << "\t4.MOSTRAR MENOR NOTA\n";
    cout << "\t5.MOSTRAR NOTA PROMEDIO\n";
    cout << "\t6.MOSTRAR PORCENTAJE APROBADOS Y DESAPROBADOS\n";
    cout << "\t7.ORDENAR LISTA DESCENDENTEMENTE\n";
    cout << "\t9.SALIR\n";
}

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingrese la cantidad de notas: "; cin >> N;
    } while (N < 1);
    return N;
}

void GenerarNotas(int* Notas, int N)
{
    for (int i = 0; i < N; i++)
    {
        Notas[i] = randInt(0, 20);
    }
    cout << endl << "\t\tLAS NOTAS HAN SIDO GENERADAS";
}

void ListarNotas(int* Notas, int N)
{
    cout << endl << "\t\t\tLISTADO DE NOTAS\n";
    cout << "\t\t=================================\n";
    for (int i = 0; i < N; i++)
    {
        cout << "\t\tNota " << i + 1 << ": " << Notas[i] << endl;
    }
}

void MostrarNotaMayor(int* Notas, int N)
{
    cout << endl << "\t\tOBTENER MAYOR NOTA\n";
    int mx = Notas[0];
    for (int i = 0; i < N; i++)
    {
        mx = max(mx, Notas[i]);
    }
    cout << endl << "\t\tLa mayor nota es: " << mx;
}

void MostrarNotaMenor(int* Notas, int N)
{
    cout << endl << "\t\tOBTENER MENOR NOTA\n";
    int mn = Notas[0];
    for (int i = 0; i < N; i++)
    {
        mn = min(mn, Notas[i]);
    }
    cout << endl << "\t\tLa menor nota es: " << mn;
}

void MostrarNotaPromedio(int* Notas, int N)
{
    cout << endl << "\t\tNOTA PROMEDIO\n";
    double S = 0;
    double Promedio = 0;
    for (int i = 0; i < N; i++)
    {
        S += Notas[i];
    }
    if (N > 0)
    {
        Promedio = (S * 1.0) / N;
    }
    cout << endl << "\t\tLa nota promedio es: " << Promedio;
}

void MostrarPorcentajeAproYDesapro(int* Notas, int N)
{
    cout << endl << "\t\tPORCENTAJE DE APROBADOS Y DESAPROBADOS\n";
    int CantApro = 0;
    int CantDesapro = 0;
    double porcentajeApro = 0;
    double porcentajeDesapro = 0;
    for (int i = 0; i < N; i++)
    {
        if (Notas[i] >= 13)
        {
            CantApro++;
        }
    }
    CantDesapro = N - CantApro;
    if (N > 0)
    {
        porcentajeApro = (CantApro * 100.0) / N;
    }
    if (N > 0)
    {
        porcentajeDesapro = (CantDesapro * 100.0) / N;
    }
    cout << endl << "\t\tEl porcentaje de Aprobados es: " << porcentajeApro << "%";
    cout << endl << "\t\tEl porcentaje de Desaprobados es: " << porcentajeDesapro << "%";
}

void OrdenarDescendentemente(int* Notas, int N)
{
    cout << endl << "\t\t\tLISTADO DE NOTAS DESCENDENTEMENTE\n";
    cout << "\t\t===================================================\n";
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (Notas[i] < Notas[j])
            {
                int temp = Notas[i];
                Notas[i] = Notas[j];
                Notas[j] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "\t\tNota " << i + 1 << ": " << Notas[i] << endl;
    }
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    system("cls");
    int* Notas = new int[N];
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
            GenerarNotas(Notas, N);
            system("pause>0");
            break;
        case 2:
            system("cls");
            ListarNotas(Notas, N);
            system("pause>0");
            break;
        case 3:
            system("cls");
            MostrarNotaMayor(Notas, N);
            system("pause>0");
            break;
        case 4:
            system("cls");
            MostrarNotaMenor(Notas, N);
            system("pause>0");
            break;
        case 5:
            system("cls");
            MostrarNotaPromedio(Notas, N);
            system("pause>0");
            break;
        case 6:
            system("cls");
            MostrarPorcentajeAproYDesapro(Notas, N);
            system("pause>0");
            break;
        case 7:
            system("cls");
            OrdenarDescendentemente(Notas, N);
            system("pause>0");
            break;
        case 9:
            break;
        }
        system("cls");
    } while (*opc != 9);

    delete[] Notas;
    delete opc;

    Notas = nullptr;
    opc = nullptr;

    system("pause>0");
    return 0;
}