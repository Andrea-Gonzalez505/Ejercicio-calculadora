#include <iostream>// Biblioteca estándar para entrada y salida
using namespace std;

// Callback functions for different operations
double add(double a, double b)//Realiza la operación suma
{
    return a + b;
}

double multiply(double a, double b)//Realiza la operación multiplicación 
{
    return a * b;
}

double subtract(double a, double b)//Realiza la operación resta
{
    return a - b;
}
double divide(double a, double b)//Realiza la operación divición
{
    return a / b;
}

// Function that performs an operation using a callback
void performOperation(double (*callback)(double, double), double x, double y)//
{
    cout << "El resultado de la operación es: " << callback(x, y) << endl;
}

int main(int argc, char *argv[])
 // Verifica que la cantidad de argumentos ingresados sea correcta
{
    if (argc != 4){
        std::cerr<<"Operación inválida. Número de argumentos incorrecto "<<endl;// En caso de agregar un caracter incorrecto
    }

    double num1 = std::stod(argv[1]);
    double num2 = std::stod(argv[3]);
    char operacion = argv[2][0];//se toma la posicion 2 para posteriormente identificar que operación es

    
//Se reconocen los caracteres para determinar las operaciones a realizar
    if( operacion == '+' ){
        performOperation(add, num1, num2);// Llama a la función de suma
    }
    else if( operacion == '-' ){
        performOperation(subtract, num1, num2); // Llama a la función de resta
    }
    else if( operacion == 'x' ){
        performOperation(multiply, num1, num2);// Llama a la función de multiplicación
    }
    else if( operacion == '/' ){
        // En caso de no poder realizar la operación
        if (num2 == 0){
            std::cerr<<"Operación inválida, no es posible hacer una división por cero. "<<endl;
        }
        else{
            performOperation(divide, num1, num2);
        }
        
    }
    // En caso de agregar un caracter incorrecto
    else{
        std:cerr<<"Operación ingresada incorrecta. Las operaciones admitidas son '+', '-' y 'x'. "<<endl;
        
    
    }

    return 0;
}