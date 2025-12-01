#include "TrianglePerimeter.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, c;

    cout << "Введіть сторону a: ";
    cin >> a;
    cout << "Введіть сторону b: ";
    cin >> b;
    cout << "Введіть сторону c: ";
    cin >> c;

    cout << "\n--- РЕЗУЛЬТАТИ ---\n";

    // 1
    try {
        cout << "perimeterTriangle1: " << perimeterTriangle1(a, b, c) << endl;
    }
    catch (runtime_error& e) {
        cout << "Помилка perimeterTriangle1: " << e.what() << endl;
    }

    // 2
    double result2 = perimeterTriangle2(a, b, c);
    if (result2 >= 0)
        cout << "perimeterTriangle2: " << result2 << endl;
    else
        cout << "perimeterTriangle2: помилка" << endl;

    // 3
    try {
        cout << "perimeterTriangle3: " << perimeterTriangle3(a, b, c) << endl;
    }
    catch (invalid_argument& e) {
        cout << "Помилка perimeterTriangle3: " << e.what() << endl;
    }
    catch (domain_error& e) {
        cout << "Помилка perimeterTriangle3: " << e.what() << endl;
    }

    // 4
    try {
        cout << "perimeterTriangle4: " << perimeterTriangle4(a, b, c) << endl;
    }
    catch (EmptyTriangleException&) {
        cout << "Помилка perimeterTriangle4: EmptyTriangleException" << endl;
    }

    // 5
    try {
        cout << "perimeterTriangle5: " << perimeterTriangle5(a, b, c) << endl;
    }
    catch (TriangleError& e) {
        cout << "Помилка perimeterTriangle5: сторони "
            << e.a << ", " << e.b << ", " << e.c << endl;
    }

    // 6
    try {
        cout << "perimeterTriangle6: " << perimeterTriangle6(a, b, c) << endl;
    }
    catch (TriangleException& e) {
        cout << "Помилка perimeterTriangle6: " << e.what() << endl;
    }

    return 0;
}
