#include <iostream>

using namespace std;

void calcularNum(int vector[], int n)
{
    int mayor = vector[0];
    int menor = vector[0];

    for (int i = 0; i < n; i++)
    {
        if (vector[i] > mayor)
        {
            mayor = vector[i];
        }
        if (vector[i] < menor)
        {
            menor = vector[i];
        }
    }

    cout << "El numero mayor es: " << mayor << endl;
    cout << "El numero menor es: " << menor << endl;
}

int main()
{
    int n;
    cout << "Ingrese la cantidad de elementos" << endl;
    cin >> n;

    int *vector = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento #" << i << endl;
        cin >> vector[i];
    }

    calcularNum(vector, n);
    cout << endl;
    // Delete: se librera la memoria
    delete[] vector;

    return 0;
}