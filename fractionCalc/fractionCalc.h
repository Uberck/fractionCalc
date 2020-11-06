// Christos Kokkalis 2020
// Fraction calculations class header file

#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
#include<sstream>
#include<string>

class Fraction {
public:
    int numerator;
    int denominator;

    // Initializes the constructor
    Fraction() {
        numerator = denominator = 1;
    }
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // Calculates the greatest common denominator
    int GCD(int X, int Y) {
        if (X == 0)
            return Y;
        return GCD(Y % X, X);
    }

    // Overloading the +, -, *, and / operators
    Fraction& operator + (Fraction Number) {
        Fraction fraction;
        // Calculation for GCD as denominator
        fraction.denominator = GCD(denominator, Number.denominator);
        // Finding the value of the denominator
        fraction.denominator = (denominator * Number.denominator) / fraction.denominator;
        // Calculates the fraction's numerator
        fraction.numerator = (numerator) * (fraction.denominator / denominator) + (Number.numerator) * (fraction.denominator / Number.denominator);
        return fraction;
    }
    Fraction& operator - (Fraction Number) {
        Fraction fraction;
        // Calculation for GCD as denominator
        fraction.denominator = GCD(denominator, Number.denominator);
        // Finding the value of the denominator
        fraction.denominator = (denominator * Number.denominator) / fraction.denominator;
        // Calculate the numerator via subtraction
        fraction.numerator = (numerator) * (fraction.denominator / denominator) - (Number.numerator) * (fraction.denominator / Number.denominator);
        return fraction;
    }
    Fraction& operator * (Fraction Number) {
        Fraction fraction;
        // Multiplies the denominator
        fraction.denominator = denominator * Number.denominator;
        // Multiplies the numerator
        fraction.numerator = numerator * Number.numerator;
        return fraction;
    }
    // Converts the fraction to a number
    Fraction& operator / (Fraction Number) {
        Fraction fraction;
        // Multiply the denominator with stored numerator
        fraction.denominator = denominator * Number.numerator;
        // Multiply the numerator with stored denominator
        fraction.numerator = numerator * Number.denominator;
        return fraction;
    }

    // Convert to string
    std::string convertToString() {
        std::stringstream stream;
        stream << numerator << "/" << denominator;
        std::string store;
        stream >> store;
        return store;
    }

    double toDouble() {
        // Converts the fraction to a double
        return ((double)numerator) / denominator;
    }
};

// Check the fail bit of rdstate
bool cinfailed() {
    return (std::cin.rdstate() & std::istream::failbit) != 0;
}

// Passing by reference, boolean value using to determine numerator or denominator
void readValue1(int & result, bool isDenominator) {
    // Ternary operator to assign label
    std::string label = isDenominator ? "denominator" : "numerator";
    std::cout << "Enter the " << label << " for the first fraction (digits only): ";
    std::string garbage;
    std::cin >> result;
    while (result == 0 || cinfailed()) {
        if (cinfailed()) {
            // Clear the fail bit
            std::cin.clear();
            // Read bad data from cin
            std::cin >> garbage;
            std::cout << "Invalid data entry, please enter digits only: ";
        }
        else {
            if (isDenominator && result == 0){
                std::cout << "The " << label << " cannot be 0, please try again: ";
            }
            else
            {
                break;
            }
        }
        std::cin >> result;
    }
}

// Pass by reference for second fraction
void readValue2(int& result, bool isDenominator) {
    // Ternary operator to assign label
    std::string label = isDenominator ? "denominator" : "numerator";
    std::cout << "Enter the " << label << " for the second fraction (digits only): ";
    std::string garbage;
    std::cin >> result;

    while (result == 0 || cinfailed()) {
        if (cinfailed()) {
            // Clear the fail bit
            std::cin.clear();
            // Read bad data from cin
            std::cin >> garbage;
            std::cout << "Invalid data entry, please enter digits only: ";
        }
        else {
            if (isDenominator && result == 0) {
                std::cout << "The " << label << " cannot be 0, please try again: ";
            }
            else
            {
                break;
            }
        }
        std::cin >> result;
    }
}

// Call readValue 4 time for numerator and denominator values
void input(Fraction& frac1, Fraction& frac2) {
    readValue1(frac1.numerator, false);
    readValue1(frac1.denominator, true);
    readValue2(frac2.numerator, false);
    readValue2(frac2.denominator, true);
}

#endif