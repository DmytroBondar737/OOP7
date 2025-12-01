#pragma once
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

// 1. Порожній клас
class EmptyTriangleException {};

// 2. Незалежний клас з полями
class TriangleError {
public:
    double a, b, c;
    TriangleError(double a, double b, double c) : a(a), b(b), c(c) {}
};

// 3. Спадкоємець від exception
class TriangleException : public exception {
    double a, b, c;
    string msg;
public:
    TriangleException(double a, double b, double c) : a(a), b(b), c(c) {
        stringstream ss;
        ss << "Неправильний трикутник: " << a << ", " << b << ", " << c;
        msg = ss.str();
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

// Функції
double perimeterTriangle1(double a, double b, double c);
double perimeterTriangle2(double a, double b, double c) throw();
double perimeterTriangle3(double a, double b, double c) throw(invalid_argument, domain_error);
double perimeterTriangle4(double a, double b, double c) throw(EmptyTriangleException);
double perimeterTriangle5(double a, double b, double c) throw(TriangleError);
double perimeterTriangle6(double a, double b, double c) throw(TriangleException);
