#include <iostream>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction() : Fraction(0, 1)
    {}

    Fraction(int n, int d) : numerator{ n }
    {
        if (d == 0)
            d = 1;
        denominator = d;
    }

    void SetNumerator(int n)
    {
        numerator = n;
    }
    int GetNumerator()
    {
        return numerator;
    }
    void SetDenominator(int d)
    {
        if (d != 0)
            denominator = d;
    }
    int GetDenominator()
    {
        return denominator;
    }

    void Print()
    {
        cout << "[" << numerator << "/" << denominator << "]";
    }

    void PrintLine()
    {
        Print();
        cout << "\n";
    }
};

struct FractionS
{
    int numerator;
    int denominator;
};

int main()
{
    FractionS f1;
    f1.numerator = 10;
    f1.denominator = 0;

    Fraction f;
    //f.SetNumerator(10);
    //f.SetDenominator(37);
    f.PrintLine();

    
}
