#include <iostream> // la entrada y salida estándar (cout, cin)
#include <string>   // Cadenas de texto (string) y sus métodos
#include <cctype>   // Manipular caracteres individuales (toupper, tolower, etc.)
#include <vector>   // Manejar listas dinámicas (vector), aquí usado para palabras prohibidas
using namespace std;

// Clase para manejar la generación del RFC
class RFC {
private:
    // Datos del empleado
    string nombre;
    string apellidoP;
    string apellidoM;
    int dia, mes, anio;

    // Lista de palabras prohibidas por el SAT (no pueden aparecer en las 4 primeras letras del RFC)
    vector<string> palabrasProhibidas = {
        "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO",
        "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "CULO", "FETO",
        "GUEI", "GUEY", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KOGE",
        "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KULO", "MAME", "MAMO",
        "MEAR", "MEAS", "MEON", "MION", "MOCO", "MULA", "PEDA", "PEDO",
        "PENE", "PUTA", "PUTO", "QULO", "RATA", "RUIN"
    };

    // Función que obtiene la primera vocal interna (desde la segunda letra) del apellido paterno
    char obtenerVocalInterna(const string &apellido) {
        for (size_t i = 1; i < apellido.size(); i++) { // Recorre desde la segunda letra
            char c = toupper(apellido[i]); // Convierte a mayúscula para comparar
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                return c; // Devuelve la primera vocal encontrada
            }
        }
        return 'X'; // Si no hay vocal interna, devuelve 'X'
    }

    // Convierte un string a mayúsculas
    string mayusculas(string s) {
        for (char &c : s) c = toupper(c);
        return s;
    }

    // Verifica si las primeras 4 letras forman una palabra prohibida y reemplaza la cuarta por 'X'
    void validarPalabraProhibida(string &rfc) {
        string primeros4 = rfc.substr(0, 4); // Extrae las primeras 4 letras
        for (string prohibida : palabrasProhibidas) {
            if (primeros4 == prohibida) { // Si coincide con palabra prohibida
                rfc[3] = 'X'; // Cambia la cuarta letra a 'X'
                break; // Sale del bucle
            }
        }
    }

public:
    // Constructor: recibe y guarda los datos del empleado en mayúsculas
    RFC(string nom, string apP, string apM, int d, int m, int a) {
        nombre = mayusculas(nom);
        apellidoP = mayusculas(apP);
        apellidoM = mayusculas(apM);
        dia = d;
        mes = m;
        anio = a;
    }

    // Función que genera el RFC siguiendo las reglas indicadas
    string generarRFC() {
        string rfc = "";

        // 1ra letra del apellido paterno
        rfc += apellidoP[0];
        // 2da letra: primera vocal interna del apellido paterno
        rfc += obtenerVocalInterna(apellidoP);

        // 3ra letra: inicial del apellido materno o 'X' si no existe
        if (apellidoM.empty())
            rfc += 'X';
        else
            rfc += apellidoM[0];

        // 4ta letra: inicial del nombre
        rfc += nombre[0];

        // Validar si las primeras 4 letras forman palabra prohibida
        validarPalabraProhibida(rfc);

        // 5 y 6: últimos dos dígitos del año
        rfc += to_string(anio).substr(2, 2);

        // 7 y 8: mes con dos dígitos (agrega 0 si es menor a 10)
        if (mes < 10) rfc += "0";
        rfc += to_string(mes);

        // 9 y 10: día con dos dígitos (agrega 0 si es menor a 10)
        if (dia < 10) rfc += "0";
        rfc += to_string(dia);

        // Homoclave ficticia (XXX)
        rfc += "XXX";

        return rfc; // Devuelve el RFC final
    }
};

int main() {
    // Variables para capturar los datos
    string nombre, apellidoP, apellidoM;
    int dia, mes, anio;

    // Captura de datos
    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    cout << "Ingrese apellido paterno: ";
    getline(cin, apellidoP);

    cout << "Ingrese apellido materno (dejar vacio si no tiene): ";
    getline(cin, apellidoM);

    cout << "Ingrese fecha de nacimiento (DD MM AAAA): ";
    cin >> dia >> mes >> anio;

    // Crear objeto RFC con los datos capturados
    RFC empleado(nombre, apellidoP, apellidoM, dia, mes, anio);

    // Mostrar RFC generado
    cout << "\nRFC generado: " << empleado.generarRFC() << endl;

    return 0;
}
