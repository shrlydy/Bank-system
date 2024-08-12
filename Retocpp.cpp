#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Cuentahabiente
class Cuentahabiente {
public:
    string nombre;
    int edad;
    int anosEnBanco;

    // Constructor
    Cuentahabiente() {
        nombre = "  ";
        edad = 0;
        anosEnBanco = 0;
    }

    // Función para ingresar datos del Cuentahabiente
    void ingresarDatos() {
        cout << "**DATOS DEL CUENTAHABIENTE**\n";
        cout << "Ingresa tu nombre: ";
        getline(cin, nombre);
        cout << "Ingresa tu edad: ";
        cin >> edad;
        cout << "Ingresa tus años en el banco: ";
        cin >> anosEnBanco;
        cin.ignore(); // Limpiar el buffer de entrada
    }
};

// Clase Cuenta
class Cuenta {
public:
    int numeroCuenta;
    int cantidadEfectivo;
    bool estadoCuenta;

    // Constructor
    Cuenta() {
        numeroCuenta = 0;
        cantidadEfectivo = 0;
        estadoCuenta = false;
    }

    // Función para ingresar datos de la Cuenta
    void ingresarDatos() {
        cout << "**DATOS DE LA CUENTA**\n";
        cout << "Ingresa el número de cuenta: ";
        cin >> numeroCuenta;
        cout << "Ingresa la cantidad total de efectivo: ";
        cin >> cantidadEfectivo;

        // Verificar estado de cuenta
        if (cantidadEfectivo >= 3000) {
            cout << "Su cuenta está activa\n";
            estadoCuenta = true;
        } else {
            cout << "Su cuenta no posee el capital mínimo para registro\n";
            exit(0);
        }
    }
};

// Clase Transaccion
class Transaccion {
public:
    int numeroTransaccion;
    char tipoTransaccion;  // 'R' para retiro, 'D' para depósito
    string operacionTransaccion;
    int cantidadTransaccion;

    // Constructor
    Transaccion() {
        numeroTransaccion = 0;
        tipoTransaccion = ' ';
        cantidadTransaccion = 0;
    }

    // Función para ingresar datos de la Transacción
    void ingresarDatos() {
        cout << "\n**TRANSACCIÓN**\n";
        cout << "Ingresa el número de transacción: ";
        cin >> numeroTransaccion;
        cout << "Ingresa el tipo de transacción (R para retiro, D para depósito): ";
        cin >> tipoTransaccion;
        cout << "Ingresa el concepto: ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, operacionTransaccion);
        cout << "Ingresa la cantidad de la transacción: ";
        cin >> cantidadTransaccion;
    }
};

int main() {
    // Crear objeto Cuentahabiente
    Cuentahabiente cuentahabiente;

    // Ingresar datos del Cuentahabiente
    cuentahabiente.ingresarDatos();

    cout << endl;

    // Crear objeto Cuenta
    Cuenta cuenta;

    // Ingresar datos de la Cuenta
    cuenta.ingresarDatos();

    cout << endl;

    // Almacenar el monto inicial para mostrar como saldo anterior
    int montoInicial = cuenta.cantidadEfectivo;

    // Crear vector de Transacciones
    vector<Transaccion> transacciones(3);

    // Ingresar datos de las Transacciones y actualizar saldo
    for (int i = 0; i < 3; ++i) {
        transacciones[i].ingresarDatos();

        // Actualizar saldo de la cuenta según el tipo de transacción
        if (transacciones[i].tipoTransaccion == 'D') {
            cuenta.cantidadEfectivo += transacciones[i].cantidadTransaccion;
        } else if (transacciones[i].tipoTransaccion == 'R') {
            cuenta.cantidadEfectivo -= transacciones[i].cantidadTransaccion;
        }
    }

    cout << endl;

    // Mostrar el balance de la cuenta
    cout << "**EL BALANCE DE SU CUENTA " << cuentahabiente.nombre << " ES EL SIGUIENTE**\n";
    cout << "Cuenta: " << cuenta.numeroCuenta << "\n";
    cout << "Saldo anterior: " << montoInicial << "\n";
    cout << "Saldo actual: " << cuenta.cantidadEfectivo << "\n";

    return 0;
}