// Christos Kokkalis 2020
// Fraction calculator driver program

#include <fractionCalc.h>
#include <iostream>

// Main program
int main() {

    int operand = 0;
    Fraction num, div;
    while (operand != 5) {
        std::cout << "How would you like to calculate the two fractions? \n";
        std::cout << "(1) Addition\n";
        std::cout << "(2) Subtraction\n";
        std::cout << "(3) Multiplication\n";
        std::cout << "(4) Division\n";
        std::cout << "(5) Exit program\n";
        std::cout << "Please select an option (1-5): ";
        std::cin >> operand;
        switch (operand) {
        case 1: {
            input(num, div);
            Fraction object = num + div;
            std::cout << "The calculated fraction is " << object.convertToString() << std::endl;
            std::cout << std::endl;
        }
              break;
        case 2: {
            input(num, div);
            Fraction object = num - div;
            std::cout << "The calculated fraction is " << object.convertToString() << std::endl;
            std::cout << std::endl;
        }
              break;
        case 3: {
            input(num, div);
            Fraction object = num * div;
            std::cout << "The calculated fraction is " << object.convertToString() << std::endl;
            std::cout << std::endl;
        }
              break;
        case 4: {
            input(num, div);
            Fraction object = num / div;
            std::cout << "The calculated fraction is " << object.convertToString() << std::endl;
            std::cout << std::endl;
        }
              break;
        case 5: {
            std::cout << "Exiting...\n";
        }
              break;
        default:
            std::cout << "Please select a valid option! (1-5)\n";
            std::cout << std::endl;
        }
    }
    return 0;
}