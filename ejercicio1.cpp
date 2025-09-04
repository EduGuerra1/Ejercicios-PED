#include <iostream>

using namespace std;
// Estructura de los productos
struct Producto
{
    int codigo;
    string nombre;
    double precio;
    int stock;
};

// Variable para detectar el total de productos
int total_producto = 0;
// Constante del numero de productos maximo
const int producto_max = 50;
// Arreglo donde se guardarán las productos
Producto productos[producto_max];

// Funcion para registrar un producto nuevo
int agregarProducto(Producto producto[], int n)
{
    // Se valida que el numero maximo de productos no sobrepase el limite
    if (n >= producto_max)
    {
        cout << "Lista de productos llena \n";
        return n;
    }

    // Variable tipo "producto" para guardar el nuevo registro
    Producto nuevo_producto;

    // Se solicita la informacion del producto al usuario
    cout << "Ingrese el codigo: ";
    cin >> nuevo_producto.codigo;
    cout << "Ingrese el nombre: ";
    getline(cin >> ws, nuevo_producto.nombre);

    double precio = 0.0;
ingresarPrecio:
    cout << "Ingrese el precio: ";
    cin >> precio;
    if (precio > 0.0)
    {
        nuevo_producto.precio = precio;
    }
    else
    {
        cout << "Precio invalido, ingreselo nuevamente." << endl;
        goto ingresarPrecio;
    }
    int cantidad = 0;
stockproducto:
    cout << "Ingrese la cantidad en stock: ";
    cin >> cantidad;

    if (cantidad > 0)
    {
        nuevo_producto.stock = cantidad;
    }
    else
    {
        cout << "Cantidad invalida, ingresela nuevamente." << endl;
        goto stockproducto;
    }

    // Se guarda el producto creado en el array global
    producto[n] = nuevo_producto;

    cout << "Producto creado correctamente\n";
    return n + 1;
};

// Funcion para buscar un producto
void buscarProducto(Producto producto[], int n) {
  // Se valida si no hay ningun producto registrado
  if (n == 0) {
    // Mensaje a mostrar cuando no hay productos registrados
    cout << "No hay productos registrados" << endl;
    return;
  }

  int search = 0;
  cout << "Ingrese el codigo del producto a buscar: ";
  cin >> search;
  // Se recorre el array de productos para buscar el elemento que coincida
  for (int i = 0; i < n; i++) {
    if (producto[i].codigo == search) {
        cout << "Producto encontrado:\n";
        cout << "Codigo: " << producto[i].codigo << endl;
        cout << "Nombre: " << producto[i].nombre << endl;
        cout << "Precio: " << producto[i].precio << endl;
        cout << "Cantidades disponibles: " << producto[i].stock << endl << endl;
        return;
    } 
  }

  cout << "No se ha encontrado el producto.\n";
  return;
}
//Funcion para calcular el valor total del inventario
void calcularInventario(Producto producto[], int n) {
    double total_inventario = 0.0;

    // Se valida si no hay ningun producto registrado
    if (n == 0) {
        // Mensaje a mostrar cuando no hay productos registrados
        cout << "No hay productos registrados" << endl;
        return;
    }

    // Se recorre el array de productos para calcular el valor total del inventario
    for (int i = 0; i < n; i++) {
        total_inventario += producto[i].precio * producto[i].stock;
    }

    cout << "El valor total del inventario es: $" << total_inventario << endl;
}

void mostrarMenu() {
  cout << "\nSeleccione una opcion" << endl;
  cout << "1. Registrar producto" << endl;
  cout << "2. Buscar producto" << endl;
  cout << "3. Calcular valor total del inventario" << endl;
  cout << "4. Salir" << endl;
}

void ejecutarMenu() {
  int opcion;

  do {
    mostrarMenu();
    cin >> opcion;
    switch (opcion) {
      case 1:
        total_producto = agregarProducto(productos, total_producto);
        break;
      case 2:
        buscarProducto(productos, total_producto);
        break;
      case 3:
        calcularInventario(productos, total_producto);
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