#ifndef TASK_3_COMPLEXNUMBER_HPP
#define TASK_3_COMPLEXNUMBER_HPP

#include <ostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    double real; //x
    double imaginary; //y

public:
    ComplexNumber(double real = 0, double imaginary = 0) {
        this->real = real;
        this->imaginary = imaginary;
    }

    inline double Real() const {
        return real;
    }

    inline double Imaginary() const {
        return imaginary;
    }

    inline ComplexNumber operator+(const ComplexNumber &number) const {
        return ComplexNumber(real + number.real, imaginary + number.imaginary);
    }

    inline ComplexNumber operator-(const ComplexNumber &number) const {
        return ComplexNumber(real - number.real, imaginary - number.imaginary);
    }

    inline ComplexNumber operator*(const ComplexNumber &number) const {
        return ComplexNumber(real * number.Real() - imaginary * number.Imaginary(),
                             number.Imaginary() * number.Imaginary() + number.Real() * number.Real());
    }

    inline ComplexNumber operator/(const ComplexNumber &number) const {
        return ComplexNumber((real * number.Real() + imaginary * number.Imaginary()) /
                             (number.Real() * number.Real() + number.Imaginary() * number.Imaginary()),
                             (-real * number.Imaginary() + number.Real() * imaginary) /
                             (number.Real() * number.Real() + number.Imaginary() * number.Imaginary()));
    }

    inline ComplexNumber conjugate() const {
        return ComplexNumber(real, -imaginary);
    }

    inline double abs() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    inline double argument() const {
        if (real == 0 && imaginary == 0) return 0;
        if (real < 0 && imaginary >= 0) return M_PI + atan(imaginary / real);
        if (real < 0 && imaginary < 0) return -M_PI - atan(imaginary / real);
        if (real > 0) return atan(imaginary / real);
        if (imaginary > 0) return M_PI_2;
        return -M_PI_2;
    }

};

inline ostream &operator << (ostream &operator_, const ComplexNumber &number) {
    return operator_ << '(' << number.Real() << ", " << number.Imaginary() << ')';
}

#endif
