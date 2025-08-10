#include <iostream>   // Biblioteca para entrada y salida de datos (cout, cin)
#include <limits>     // Biblioteca para manejo de límites y limpieza de buffer
#include <string>     // Biblioteca para manejo de cadenas de texto
using namespace std;

// Función para verificar si la cadena ingresada es un número entero válido
bool esNumeroEntero(const string &str) {
    if (str.empty()) return false; // Si la cadena está vacía, no es válida
    for (char c : str) {           // Recorremos cada carácter de la cadena
        if (!isdigit(c)) return false; // Si algún carácter no es dígito, retorna falso
    }
    return true; // Si todos son dígitos, retorna verdadero
}

int main() {
    string entrada; // Variable para guardar la entrada del usuario como texto
    int edad;       // Variable para guardar la edad convertida a número

    // Bucle que se repite hasta obtener una edad válida
    while (true) {
        cout << "Ingrese su edad: "; // Mensaje al usuario
        getline(cin, entrada);       // Leer toda la línea escrita por el usuario

        // Validar si la entrada es numérica
        if (esNumeroEntero(entrada)) {
            edad = stoi(entrada); // Convertir la cadena a número entero

            // Validar si está dentro del rango lógico
            if (edad >= 0 && edad <= 120) {
                break; // Salir del bucle si la edad es válida
            } else {
                cout << "Edad fuera de rango (0 a 120 años). Intente de nuevo.\n";
            }
        } else {
            cout << "Entrada no válida. Por favor, ingrese solo números.\n";
        }
    }

    // Determinar si es mayor o menor de edad
    if (edad >= 18) {
        cout << "Usted es mayor de edad.\n";
    } else {
        cout << "Usted es menor de edad.\n";
    }

    return 0; // Fin del programa
}
