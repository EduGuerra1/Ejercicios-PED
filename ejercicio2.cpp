#include <iostream>

using namespace std;

void ingresarDatos(int notas[4][4], int alumnos, int materias){
    cout << "Ingrese las notas de los alumnos: " << endl;
    for (int i = 0; i < alumnos; i++)
    {
        cout << "Alumno " << i+1 << endl;
        for (int j = 0; j < materias; j++)
        {
            cout << "Ingrese la nota de la materia " << j+1 << ": ";
            cin >> notas[i][j];
        }
        cout << endl;
    }
};

void calcularPromedioAlumno(int notas[4][4], int alumnos, int materias){
    cout << "El promedio de notas de los alumnos es: " << endl;
    for (int i = 0; i < alumnos; i++)
    {
        int suma = 0;
        for (int j = 0; j < materias; j++)
        {
            suma += notas[i][j];
        }
        double media = (double) suma/materias;
        cout << "El alumno " << i+1 << " tiene una media de " << media << endl;
        
    }
};

void calcularPromedioNota(int notas[4][4], int alumnos, int materias){
    cout << " \nEl promedio de notas por materia es: " << endl;
    for (int j = 0; j < materias; j++)
    {
        int suma = 0;
        for (int i = 0; i < alumnos; i++)
        {
            suma += notas[i][j];
        }
        double media = (double) suma/alumnos;
        cout << "La materia " << j+1 << " tiene una media de " << media << endl;

    }
};


int main()
{

    int nota_alumnos = 4;
    int materias = 4;

    int notas[4][4];

    ingresarDatos(notas, nota_alumnos, materias);
    calcularPromedioAlumno(notas, nota_alumnos, materias);
    calcularPromedioNota(notas, nota_alumnos, materias);

    return 0;
}