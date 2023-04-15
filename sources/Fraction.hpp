
#include "math.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;
namespace ariel{

    class Fraction
    {
        private:
        int Numerator ;
        int Denominator;
        
        public:
            Fraction(int , int);
            Fraction(double);
            Fraction();

            Fraction(const Fraction& other);
            ~Fraction();

            int getNumerator() const;
            int getDenominator() const;

            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            
            
            bool operator>(const Fraction& ) const ;
            bool operator<(const Fraction& ) const;
            
            bool operator<=(const Fraction& ) const;
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;

            Fraction& operator++();
            Fraction operator++(int);
            Fraction& operator--();
            Fraction operator--(int);
            
            // Type conversions
            explicit operator double() const;

            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            // std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            friend Fraction operator*(const double& d, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);        
    };
     
}