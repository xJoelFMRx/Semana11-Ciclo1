#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int ValidarN() {
    int N;
    do {
        cout << "Ingrese N: ";
        cin >> N;
    } while (N < 10 || N > 30);
    return N;
}

int ValidarR() {
    int R;
    do {
        cout << endl << "Ingrese R: ";
        cin >> R;
    } while (R < 2 || R > 5);
    return R;
}

void GenerarArreglo(int* arreglo, int N)
{
    for (int i = 0; i < N; i++) {
        arreglo[i] = randInt(1, 50);
    }
}

void ImprimirValores(int* arreglo, int N)
{
    for (int i = 0; i < N; i++) {
        cout << "Indice " << i << ": " << arreglo[i] << endl;
    }
}

void OrdenarMenorAMayor(int* arreglo, int N)
{
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arreglo[i] > arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}

int contarDiferentes(int* arreglo, int N) {
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (arreglo[i] != arreglo[i - 1]) {
            cnt++;
        }
    }
    return cnt;
}

int* ModificarArregloUsandoAuxiliar(int* arreglo, int& N, int R) {
    int numDiferentes = contarDiferentes(arreglo, N);
    int NTemp = numDiferentes * R;
    int* temporal = new int[NTemp];

    int k = 0;
    for (int j = 0; j < R; ++j) {
        temporal[k++] = arreglo[0];
    }
    for (int i = 1; i < N; ++i) {
        if (arreglo[i] != arreglo[i - 1]) {
            for (int j = 0; j < R; ++j) {
                temporal[k++] = arreglo[i];
            }
        }
    }

    N = NTemp;
    delete[] arreglo;
    arreglo = nullptr;
    return temporal;
}

int main() {
    srand(time(nullptr));
    int N = ValidarN();
    int* arreglo = new int[N];
    GenerarArreglo(arreglo, N);
    ImprimirValores(arreglo, N);
    OrdenarMenorAMayor(arreglo, N);
    cout << "\nArreglo luego de ordenarlo de menor a mayor\n";
    ImprimirValores(arreglo, N);
    int R = ValidarR();
    arreglo = ModificarArregloUsandoAuxiliar(arreglo, N, R);
    cout << "\nArreglo luego de copiar R veces\n";
    ImprimirValores(arreglo, N);

    delete[] arreglo;

    system("pause>0");
    return 0;
}