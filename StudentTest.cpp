#include "doctest.h"
#include <iostream>
#include "sources/Fraction.hpp"
#include <stdexcept>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;

TEST_CASE("throws") {
    Fraction f1(1, 2);
    Fraction f2(0.5);
    CHECK_NOTHROW(Fraction(1, 2));
    CHECK_NOTHROW(Fraction(0.5));
    CHECK_NOTHROW(Fraction());
    CHECK_NOTHROW(Fraction(f1));
    CHECK_NOTHROW(Fraction(f2));
    CHECK_NOTHROW(f1 + f2);
    CHECK_NOTHROW(f1 - f2);
    CHECK_NOTHROW(f1 * f2);
    CHECK_NOTHROW(f1 / f2);
    CHECK_NOTHROW(f1 > f2);
    CHECK_NOTHROW(f1 < f2);
    CHECK_NOTHROW(f1 >= f2);
    CHECK_NOTHROW(f1 <= f2);
    CHECK_NOTHROW(++f1);
    CHECK_NOTHROW(--f1);
}
TEST_CASE("THE CONSTUCTORS:")
{
    //default 
    Fraction fraction1;
    Fraction fraction2(3, 4);
    Fraction fraction3(0.5);
    Fraction fraction4(fraction2);
    
    CHECK(fraction1.getNumerator() == 0);
    CHECK(fraction1.getDenominator() == 0);

    // two ints
    CHECK(fraction2.getNumerator() == 3);
    CHECK(fraction2.getDenominator() == 4);

    // one argument double
    CHECK(fraction3.getNumerator() == 1);
    CHECK(fraction3.getDenominator() == 2);

    // copy constructor
    CHECK(fraction4.getNumerator() == 3);
    CHECK(fraction4.getDenominator() == 4);
}

TEST_CASE("VALID ANSWERS,OPERATORS AND ALSO THERE IS NO INFINITE LOOP:"){
    clock_t start, end;
    start = clock();
    Fraction fraction0(2,4);
    Fraction fraction1(1, 2);
    Fraction fraction2(3, 4);
    Fraction fraction3 = fraction1 + fraction2;
    Fraction fraction4 = fraction1 - fraction2;
    Fraction fraction5 = fraction1 * fraction2;
    Fraction fraction6 = fraction1 / fraction2;

    CHECK(fraction3.getNumerator() == 5);
    CHECK(fraction3.getDenominator() == 4);
    CHECK(fraction4.getNumerator() == -1);
    CHECK(fraction4.getDenominator() == 4);
    CHECK(fraction5.getNumerator() == 3);
    CHECK(fraction5.getDenominator() == 8);
    CHECK(fraction6.getNumerator() == 2);
    CHECK(fraction6.getDenominator() == 3);

    CHECK(fraction2 > fraction1);
    CHECK(fraction1 < fraction2);
    CHECK(fraction2 >= fraction2);
    CHECK(fraction0 >= fraction2);
    CHECK(fraction1 <= fraction1);
    
    // Check some loop
    end = clock();
    double timeTotal = double(end - start) / CLOCKS_PER_SEC;
    CHECK(timeTotal < 5.0);
}

TEST_CASE("increase and decrese "){
    Fraction fraction1(2, 3);
    fraction1++;
    CHECK(fraction1.getNumerator() == 5);
    CHECK(fraction1.getDenominator() == 3);
    fraction1--;
    CHECK(fraction1.getNumerator() == 2);
    CHECK(fraction1.getDenominator() == 3);
}


TEST_CASE("IO Operators")
{
    Fraction fraction1(3, 4);
    Fraction fraction2;
    std::stringstream ss;
    std::stringstream ss2("1/2");
    ss << fraction1;
    ss2 >> fraction2;
    CHECK(ss.str() == "3/4");
    CHECK_NOTHROW(ss << fraction1);
    CHECK(fraction2.getNumerator() == 1);
    CHECK(fraction2.getDenominator() == 2);

}




