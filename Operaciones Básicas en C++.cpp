#include <iostream>
#include <iomanip>  // Para controlar la cantidad de decimales en la salida
using namespace std;

// Función para sumar dos números
double suma(double a, double b) {
    return a + b;
}

// Función para restar dos números
double resta(double a, double b) {
    return a - b;
}

// Función para multiplicar dos números
double multiplicacion(double a, double b) {
    return a * b;
}

// Función para dividir dos números
// Retorna true si la división es válida, false si hay división por cero
bool division(double a, double b, double &resultado) {
    if (b == 0) {
        return false;  // División por cero no permitida
    }
    resultado = a / b;
    return true;
}

// Función para leer un número y validar la entrada
bool leerNumero(double &num) {
    cin >> num;
    if (cin.fail()) {            // Si la entrada no es un número válido
        cin.clear();             // Limpia el estado de error de cin
        cin.ignore(1000, '\n');  // Descarta la entrada incorrecta del buffer
        return false;            // Indica que la lectura falló
    }
    return true;                 // Lectura exitosa
}

int main() {
    double num1, num2;  // Variables para los números ingresados

    cout << fixed << setprecision(2);  // Mostrar números con 2 decimales

    // Solicitar y validar primer número
    cout << "Escribe el primer número: ";
    while (!leerNumero(num1)) {
        cout << "Entrada inválida, escribe un número válido: ";
    }

    // Solicitar y validar segundo número
    cout << "Escribe el segundo número: ";
    while (!leerNumero(num2)) {
        cout << "Entrada inválida, escribe un número válido: ";
    }

    // Mostrar resultados de las operaciones
    cout << "La suma es: " << suma(num1, num2) << endl;
    cout << "La resta es: " << resta(num1, num2) << endl;
    cout << "La multiplicación es: " << multiplicacion(num1, num2) << endl;

    double resultadoDiv;  // Variable para guardar resultado de división

    // Intentar división y verificar si es válida
    if (division(num1, num2, resultadoDiv)) {
        cout << "La división es: " << resultadoDiv << endl;
    } else {
        cout << "La división es: Error, división por cero no permitida." << endl;
    }

    return 0;  // Fin del programa
}
