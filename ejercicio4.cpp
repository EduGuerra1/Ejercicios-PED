#include <iostream>

using namespace std;

// Estructura de las libros
struct Libro
{
  string titulo;
  string autor;
  int fecha_publicacion;
  bool estado = true;
  // estado true = disponible, false = prestado
};
// Variable para detectar el total de libros
int total_libros = 0;
// Constante del numero de libros maximo
const int libros_max = 10;
// Arreglo donde se guardarán las libros
Libro libros[libros_max];

// Funcion para mostrar las libros disponibles
void mostrarLibro(Libro libro[], int n)
{
 
  // Se valida si no hay ninguna libro registrada
  if (n == 0)
  {
    // Mensaje a mostrar cuando no hay libros registrados
    cout << "No hay libros registradas" << endl;
    return;
  }
   cout << "Lista de libros\n";
  // Ciclo for para recorrer y mostrar todos los registros del array
  for (int i = 0; i < n; i++)
  {
    cout << "Libro #" << i << endl;
    cout << "Titulo: " << libro[i].titulo << endl;
    cout << "Autor: " << libro[i].autor << endl;
    cout << "Fecha de publicacion: " << libro[i].fecha_publicacion << endl;
    // se valida si el estado es true o false para mostrar el mensaje correspondiente
    cout << "Estado: " << (libro[i].estado ? "Disponible" : "Prestado") << endl
         << endl;
  }
}

// Funcion para registrar un libro nuevo
int agregarLibro(Libro libro[], int n)
{
  // Se valida que el numero maximo de libros no sobrepase el limite
  if (n >= libros_max)
  {
    cout << "Biblioteca de libros llena \n";
    return n;
  }

  // Variable tipo "libro" para guardar el nuevo registro
  Libro nuevo_libro;
  // Se solicita la informacion del libro al usuario
  cout << "Ingrese el titulo: ";
  getline(cin >> ws, nuevo_libro.titulo);
  cout << "Ingrese el autor: ";
  getline(cin, nuevo_libro.autor);
ingresarFecha:
  cout << "Ingrese el año de publicacion: ";
  cin >> nuevo_libro.fecha_publicacion;
  // Se valida si la fecha ingresada es correcta
  if (nuevo_libro.fecha_publicacion > 0)
  {
    nuevo_libro.fecha_publicacion = nuevo_libro.fecha_publicacion;
  }
  else
  {
    cout << "Fecha incorrecta, intente nuevamente." << endl;
    goto ingresarFecha;
  }

  // Se agrega el nuevo registro al array
  libro[n] = nuevo_libro;
  cout << "Libro registrado exitosamente." << endl;
  return n + 1;
}

// Funcion para prestar un libro
void prestarLibro(Libro libro[], int n)
{
  // Se valida si no hay ninguna libro registrada
  if (n == 0)
  {
    // Mensaje a mostrar cuando no hay libros registradas
    cout << "No hay libros registradas";
    return;
  }
  // Se muestran las libros disponibles
  mostrarLibro(libro, n);
  prestarLibro:
  // Variable para guardar el nombre de la libro
  string libro_prestado = "";

  // Se solicita al usuario el titulo del libro
  cout << "Ingrese el titulo del libro a prestar: ";
  getline(cin >> ws, libro_prestado);
  int index_libro = -1;
  bool encontrar_libro = false;
  // Se recorre el array de libros para buscar el elemento que coincida
  for (int i = 0; i < libros_max; i++)
  {
    if (libro[i].titulo == libro_prestado)
    {
      index_libro = i;
      encontrar_libro = true;
    }
  }

  // se valida si hay stock del libro seleccionado
  if (libro[index_libro].estado && encontrar_libro)
  {
    cout << "Libro prestado exitosamente." << endl;
    libro[index_libro].estado = false;
  }
  else if (!libro[index_libro].estado && encontrar_libro)
  {
    cout << "El libro no está disponible en este momento." << endl;
  }
  else
  {
    cout << "No se encontró el libro, intente nuevamente. " << endl;
    goto prestarLibro;
  }

}

void mostrarMenu()
{
  cout << "\nSeleccione una opcion" << endl;
  cout << "1. Mostrar libros" << endl;
  cout << "2. Registrar un libro" << endl;
  cout << "3. Prestar un libro" << endl;
  cout << "4. Salir" << endl;
}

void ejecutarMenu()
{
  int opcion;

  do
  {
    mostrarMenu();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      mostrarLibro(libros, total_libros);
      break;
    case 2:
      total_libros = agregarLibro(libros, total_libros);
      break;
    case 3:
      prestarLibro(libros, total_libros);
      break;
    case 4:
      cout << "Saliendo..." << endl;
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    }
  } while (opcion != 4);
}

int main()
{
  ejecutarMenu();
  return 0;
}