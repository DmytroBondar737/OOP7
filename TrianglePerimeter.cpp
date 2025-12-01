#include "TrianglePerimeter.h"

// 1. Без специфікації
double perimeterTriangle1(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw runtime_error("Сторони мають бути додатними");

    if (a + b <= c || a + c <= b || b + c <= a)
        throw runtime_error("Не виконується нерівність трикутника");

    return a + b + c;
}

// 2. З throw()
double perimeterTriangle2(double a, double b, double c) throw() {
    if (a <= 0 || b <= 0 || c <= 0)
        return -1;

    if (a + b <= c || a + c <= b || b + c <= a)
        return -1;

    return a + b + c;
}

// 3. З стандартними виключеннями
double perimeterTriangle3(double a, double b, double c) throw(invalid_argument, domain_error) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw invalid_argument("Сторони мають бути додатними");

    if (a + b <= c || a + c <= b || b + c <= a)
        throw domain_error("Не виконується нерівність трикутника");

    return a + b + c;
}

// 4. З порожнім класом
double perimeterTriangle4(double a, double b, double c) throw(EmptyTriangleException) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw EmptyTriangleException();

    if (a + b <= c || a + c <= b || b + c <= a)
        throw EmptyTriangleException();

    return a + b + c;
}

// 5. З незалежним класом
double perimeterTriangle5(double a, double b, double c) throw(TriangleError) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw TriangleError(a, b, c);

    if (a + b <= c || a + c <= b || b + c <= a)
        throw TriangleError(a, b, c);

    return a + b + c;
}

// 6. З спадкоємцем
double perimeterTriangle6(double a, double b, double c) throw(TriangleException) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw TriangleException(a, b, c);

    if (a + b <= c || a + c <= b || b + c <= a)
        throw TriangleException(a, b, c);

    return a + b + c;
}
