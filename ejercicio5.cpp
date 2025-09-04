#include <iostream>
#include <cstring>

using namespace std;

// Estructura de las prendas
struct Prenda {
  string nombre;
  string talla;
  double precio;
  int stock;
};
// Variable para detectar el total de prendas
int total_prendas = 0;
// Constante del numero de prendas maximo
const int prendas_max = 50;
// Arreglo donde se guardarán las prendas
Prenda prenda[prendas_max];

// Funcion para mostrar las prendas disponibles
void mostrarPrenda(Prenda prenda[], int n) {
  cout << "Lista de prendas\n";
  // Se valida si no hay ninguna prenda registrada
  if (n == 0) {
    // Mensaje a mostrar cuando no hay prendas registrados
    cout << "No hay prendas registradas" << endl;
    return;
  }
  // Ciclo for para recorrer y mostrar todos los registros del array
  for (int i = 0; i < n; i++) {
    cout << "Prenda #" << i << endl;
    cout << "Nombre: " << prenda[i].nombre << endl;
    cout << "Talla: " << prenda[i].talla << endl;
    cout << "Precio: " << prenda[i].precio << endl;
    cout << "Cantidades disponibles: " << prenda[i].stock << endl;
  }
}

// Funcion para registrar una prenda nueva
int agregarPrenda(Prenda prenda[], int n) {
  // Se valida que el numero maximo de prendas no sobrepase el limite
  if (n >= prendas_max) {
    cout << "Lista de prendas llena \n";
    return n;
  }

  // Variable tipo "prenda" para guardar el nuevo registro
  Prenda nueva_prenda;

  // Se solicita la informacion de la prenda al usuario
  cout << "Ingrese el nombre: ";
  getline(cin >> ws, nueva_prenda.nombre);
ingresarTalla:
  string talla;
  cout << "Ingrese la talla(S, M, L, XL): ";
  cin >> talla;
  // Se valida si la talla ingresada es correcta
  if (talla == "S" || talla == "M" || talla == "L" || talla == "XL") {
    
    nueva_prenda.talla = talla;
    
  } else {
    // Si no es correcta, regresa al usuario a ingresar otra talla
    cout << "Talla incorrecta, intente nuevamente." << endl;
    goto ingresarTalla;
  }

  cout << "Ingrese el precio: ";
  cin >> nueva_prenda.precio;

  int cantidad = 0;
  stockPrenda:
  cout << "Ingrese la cantidad: ";
  cin >> cantidad;

  if (cantidad > 0)
  {
    nueva_prenda.stock = cantidad;
  }else{
    cout << "Cantidad invalida, ingresela nuevamente." << endl;
    goto stockPrenda;
  }
  
  // Se guarda el prenda creado en el array global
  prenda[n] = nueva_prenda;

  cout << "Prenda creada correctamente\n";
  return n + 1;
};

// Funcion para vender una prenda
void venderPrenda(Prenda prenda[], int n) {
  // Se valida si no hay ninguna prenda registrada
  if (n == 0) {
    // Mensaje a mostrar cuando no hay prendas registradas
    cout << "No hay prendas registradas";
    return;
  }
  // Se muestran las prendas disponibles
  mostrarPrenda(prenda, n);
comprarPrenda:
  // Variable para guardar el nombre de la prenda
  string prenda_compra = "";

  // Se solicita al usuario el nombre de la prenda
  cout << "Ingrese el nombre de la prenda a vender: ";
  getline(cin >> ws, prenda_compra);
  int index_prenda = -1;
  bool encontrar_prenda = false;
  // Se recorre el array de prendas para buscar el elemento que coincida
  for (int i = 0; i < prendas_max; i++) {
    if (prenda[i].nombre == prenda_compra) {
      index_prenda = i;
      encontrar_prenda = true;
    }
  }
  
  // se valida si hay stock de la prenda seleccionada
  if (prenda[index_prenda].stock > 0 && encontrar_prenda) {
    cout << "Prenda comprada exitosamente.";
    prenda[index_prenda].stock = prenda[index_prenda].stock - 1;
  }else{
    cout << "No se encontró la prenda, intente nuevamente. ";
    goto comprarPrenda;
  }
}

void mostrarMenu() {
  cout << "\nSeleccione una opcion" << endl;
  cout << "1. Mostrar prendas" << endl;
  cout << "2. Registrar una prenda" << endl;
  cout << "3. Vender una prenda" << endl;
  cout << "4. Salir" << endl;
}

void ejecutarMenu() {
  int opcion;

  do {
    mostrarMenu();
    cin >> opcion;
    switch (opcion) {
      case 1:
        mostrarPrenda(prenda, total_prendas);
        break;
      case 2:
        total_prendas = agregarPrenda(prenda, total_prendas);
        break;
      case 3:
        venderPrenda(prenda, total_prendas);
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

int main() {
  ejecutarMenu();
  return 0;
}