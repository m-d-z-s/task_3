#include <iostream>
#include "complexNumber.hpp"

int main() {
    ComplexNumber mas[4]{1,2,5,ComplexNumber(9,-16)};
    cout << mas << endl;
    ComplexNumber *pc;
    ComplexNumber newComplexNumber = *new ComplexNumber(1,2);
    cout << "Real = " << newComplexNumber.Real() << "Imaginary = " << newComplexNumber.Imaginary() << endl;
    new ComplexNumber[3];
    //pc[1].Real();



}
