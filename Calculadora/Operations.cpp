#include <iostream>
using namespace std;

// Callback functions for different operations
double add(double a, double b)
{
    return a + b;
}

double multiply(double a, double b)
{
    return a * b;
}

double subtract(double a, double b)
{
    return a - b;
}
double divide(double a, double b)
{
    return a / b;
}

// Function that performs an operation using a callback
void performOperation(double (*callback)(double, double), double x, double y)
{
    cout << "El resultado de la operación es: " << callback(x, y) << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4){
        std::cerr<<"Operación inválida. Número de argumentos incorrecto "<<endl;
    }

    double num1 = std::stod(argv[1]);
    double num2 = std::stod(argv[3]);
    char operacion = argv[2][0];

    

    if( operacion == '+' ){
        performOperation(add, num1, num2);
    }
    else if( operacion == '-' ){
        performOperation(subtract, num1, num2);
    }
    else if( operacion == 'x' ){
        performOperation(multiply, num1, num2);
    }
    else if( operacion == '/' ){
        if (num2 == 0){
            std::cerr<<"Operación inválida, no es posible hacer una división por cero. "<<endl;
        }
        else{
            performOperation(divide, num1, num2);
        }
        
    }
    else{
        std:cerr<<"Operación ingresada incorrecta. Las operaciones admitidas son '+', '-' y 'x'. "<<endl;
    }

    return 0;
}