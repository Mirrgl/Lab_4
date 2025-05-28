#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define EPSILON 0.0001

using namespace std;

float function(float x)
{
    return (x * x - 3 * sin(x));
}

float derivativeFunction(float x)
{
    return (2 * x - 3 * cos(x));
}

float secondDerivativeFunction(float x)
{
    return (2 + 3 * sin(x));
}

void methodHalf(float a, float b)
{
    // if (function(a) * function(b) > 0) {
    //     cout << "На концах отрезка функция имеет одинаковые знаки" << endl;
    //     return;
    // }

    int step = 0;
    float center;

    cout << fixed << setprecision(5);
    cout << left << setw(3) << "N" << setw(9) << "a" << setw(8) << "b" << "b - a" << endl;
    cout << left << setw(3) << step << setw(9) << a << setw(8) << b << abs(b - a) << endl;

    while (abs(b-a) >= EPSILON) {
        center = (a+b)/2;
        if (function(a) * function(center) < 0) {
            b = center;
        }
        if (function(center) * function(b) < 0) {
            a = center;
        }
        step++;
        cout << left << setw(3) << step << setw(9) << a << setw(8) << b << abs(b - a) << endl;
    }
    cout << "Корень = " << a << endl << "Шагов всего: " << step << endl;
}

void methodNewton(float a) {
    // if (function(a) * secondDerivativeFunction(a) <= 0) {
    //     cout << "У функции и второй произвнодной разные знаки" << endl;
    //     return;
    // }

    int k = 0;
    float x_k1 = 0;
    float x_k = a;

    cout << left << setw(3) << "N" << setw(9) << "x_n" << setw(9) << "x_n+1" << "x_n1 - x_n" << endl;
    cout << left << setw(3) << k << setw(9) << x_k << setw(9) << x_k1 << x_k1 - x_k << endl;

    while (true) {
        k++;
        x_k1 = x_k - function(x_k)/derivativeFunction(x_k);
        cout << left << setw(3) << k << setw(9) << x_k << setw(9) << x_k1 << x_k1 - x_k << endl;
        if (abs(x_k1 - x_k) < EPSILON) {
            break;
        }
        x_k = x_k1;
    }
    cout << "Корень = " << x_k1 << endl << "Шагов всего: " << k << endl;
}

float canonFunction(float x) {
    return (sqrt(abs(3*sin(x))));
}

void methodSimpleIterations(float a) {
    int k = 0;
    float x_k1 = 0;
    float x_k = a;

    cout << left << setw(3) << "N" << setw(9) << "x_n" << setw(9) << "x_n+1" << "x_n1 - x_n" << endl;
    cout << left << setw(3) << k << setw(9) << x_k << setw(9) << x_k1 << x_k1 - x_k << endl;

    while (true) {
        k++;
        x_k1 = canonFunction(x_k);
        cout << left << setw(3) << k << setw(9) << x_k << setw(9) << x_k1 << x_k1 - x_k << endl;
        if (abs(x_k1 - x_k) <= EPSILON) {
            break;
        }
        x_k = x_k1;
    }
    cout << "Корень = " << x_k1 << endl << "Шагов всего: " << k << endl;
}

int main()
{
    cout << "Метод половинного деления:" << endl;
    methodHalf(-2,1);
    cout << endl;
    methodHalf(1, 2);
    cout << endl;

    cout << "Метод Ньютона:" << endl;
    methodNewton(-0.5);
    cout << endl;
    methodNewton(1);
    cout << endl;

    cout << "Метод простых итераций:" << endl;
    methodSimpleIterations(-0.5);
    cout << endl;
    methodSimpleIterations(1);
    cout << endl;

    return 0;
}