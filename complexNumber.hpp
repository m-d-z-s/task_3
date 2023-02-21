//
// Created by brusi on 2/20/2023.
//
#ifndef TASK_3_COMPLEXNUMBER_HPP
#define TASK_3_COMPLEXNUMBER_HPP

#include <ostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;
    //x - real

public:
    ComplexNumber(double real = 0, double imaginary = 0) {
        this->real = real;
        this->imaginary = imaginary;
    }

    double Real() const {
        return real;
    }

    double Imaginary() const {
        return imaginary;
    }

    ComplexNumber operator+(const ComplexNumber &number) const {
        return ComplexNumber(real + number.real, imaginary + number.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber &number) const {
        return ComplexNumber(real - number.real, imaginary - number.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber &number) const {
        return ComplexNumber(real * number.Real() - imaginary * number.Imaginary(),
                             number.Imaginary() * number.Imaginary() + number.Real() * number.Real());
    }

    ComplexNumber operator/(const ComplexNumber &number) const {
        return ComplexNumber((real * number.Real() + imaginary * number.Imaginary()) /
                             (number.Real() * number.Real() + number.Imaginary() * number.Imaginary()),
                             (-real * number.Imaginary() + number.Real() * imaginary) /
                             (number.Real() * number.Real() + number.Imaginary() * number.Imaginary()));
    }

    ComplexNumber conjugate() const {
        return ComplexNumber(real, -imaginary);
    }

    double abs() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    double argument() const {
        if (real < 0 && imaginary >= 0) {
            return M_PI + atan(imaginary / real);
        }
        if (real < 0 && imaginary < 0) {
            return -M_PI - atan(imaginary / real);
        }
        if (real > 0) {
            return atan(imaginary / real);
        }
        if (imaginary > 0)
            return M_PI_2;
        return -M_PI_2;
    }

};

inline ostream &operator<<(ostream &operator_, const ComplexNumber &number) {
    return operator_ << '(' << number.Real() << ", " << number.Imaginary() << ')';
}

#endif //TASK_3_COMPLEXNUMBER_HPP
