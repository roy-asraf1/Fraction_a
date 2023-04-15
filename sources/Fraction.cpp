
#include "Fraction.hpp" 
#include "iostream"
using namespace std;
using namespace ariel;

Fraction :: Fraction (int numa, int numb){
    this->Numerator =numa;
    this->Denominator=numb;
}
Fraction :: Fraction (double numa){
    this->Numerator =numa;
    this->Denominator=1;
}
Fraction ::Fraction (){
    this->Numerator =0;
    this->Denominator =0;
}
Fraction :: Fraction (const Fraction& copy):Numerator(copy.Numerator),Denominator(copy.Denominator){//copy constractor

}
Fraction :: ~Fraction(){

    cout << "Destructor called" <<endl;

}

Fraction Fraction :: operator+(const Fraction& other) const{
    Fraction ans = (other.Numerator+Numerator, other.Denominator+Denominator);
    return ans;
}
Fraction Fraction :: operator-(const Fraction &other) const{
    int numerator = Numerator * other.Denominator - Denominator * other.Numerator;
    int denominator = Denominator * other.Denominator;
    return Fraction(numerator, denominator);
}
Fraction Fraction :: operator/(const Fraction &other) const{
    int numerator = Numerator * other.Denominator;
    int denominator = Denominator * other.Numerator;
    return Fraction(numerator, denominator);


}
Fraction Fraction :: operator*(const Fraction &other) const{
    int numerator = Numerator * other.Numerator;
    int denominator = Denominator * other.Denominator;
    return Fraction(numerator, denominator);

}
Fraction operator*(const double& d, const Fraction& f) {

}
Fraction& Fraction ::operator++(){
    Numerator += Denominator;
    return *this;
    
}
Fraction& Fraction ::operator--(){
    Numerator -= Denominator;
    return *this;
    
}

bool Fraction :: operator>(const Fraction& other)const{
    return Numerator * other.Denominator > other.Numerator * Denominator;
}
bool Fraction :: operator<(const Fraction& other)const{
    return Numerator * other.Denominator < other.Numerator * Denominator;
}

bool Fraction::operator>=(const Fraction& other) const {
    Numerator * other.Denominator >= other.Numerator * Denominator;
}
bool Fraction :: operator<=(const Fraction& other)const{
    return Numerator * other.Denominator <= other.Numerator * Denominator;
}

int Fraction :: getDenominator () const{
    return Denominator;
}
int Fraction :: getNumerator () const{
    return Numerator;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
    os << fraction.getNumerator() << "/" << fraction.getDenominator(); // output the fraction as numerator/denominator
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& fraction)

{

}
