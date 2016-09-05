/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: k
 *
 * Created on 6 September 2016, 12:40 AM
 */
#define _USE_MATH_DEFINES

#include <cstdlib>
#include <math.h>
#include <iostream>

using namespace std;
class Shape;
void report(const Shape& s);

class Shape {
protected:
    int sides_;
    double area_;

public:

    Shape(int a, double b) {
        sides_ = a;
        area_ = b;
    }

    int sides() const {
        return sides_;
    }

    double area() const {
        return area_;
    }
};

class Circle : public Shape {
protected:
    double diameter_;

public:

    Circle(double a) : Shape(0, a*M_PI) {
        diameter_ = a;
    }

    double radius() {
        return diameter_ / 2;
    }

    double diameter() {
        return diameter_;
    }
};

class Rectangle : public Shape {
protected:
    double length_;
    double width_;

public:

    Rectangle(double a, double b) : Shape(4, a*b) {
        length_ = a;
        width_ = b;
    }

    double length() {
        return length_;
    }

    double width() {
        return width_;
    }
};

class Triangle : public Shape {
protected:
    double a_;
    double b_;
    double c_;

public:

    Triangle(double a, double b, double c) : Shape(3, 0) {
        a_ = a;
        b_ = b;
        c_ = c;
        double s = (a + b + c) / 2.0; // Heron's method 
        area_ = sqrt(s * (s - a_) * (s - b_) * (s - c_));

    }
};

void report(const Shape& s) {

    cout << "side count: " << s.sides() << ", ";
    cout << "area: " << s.area() << endl;
}

int main(int argc, char** argv) {
    report(Circle(1.0)); // side count: 0, area: 3.14159 
    report(Rectangle(2.0, 2.0)); // side count: 4, area: 4.0 
    report(Triangle(3.0, 4.0, 5.0)); // side count: 3, area: 6
    return 0;
}

