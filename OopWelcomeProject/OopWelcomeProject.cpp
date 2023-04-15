#include <iostream>

enum class Color
{
    Black,
    White,
    Red
};

enum class Fruit
{
    Apple,
    Orange,
    Ananas
};

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

    void Add(Fraction f)
    {
        this->numerator = this->numerator * f.denominator
            + this->denominator * f.numerator;
        this->denominator *= f.denominator;
    }

    Fraction Plus(Fraction f)
    {
        Fraction fresult;
        fresult.numerator = this->numerator * f.denominator
            + this->denominator * f.numerator;
        fresult.denominator = this->denominator * f.denominator;
        return fresult;
    }

    Fraction Minus(Fraction f)
    {
        Fraction fresult;
        fresult.numerator = this->numerator * f.denominator
            - this->denominator * f.numerator;
        fresult.denominator = this->denominator * f.denominator;
        return fresult;
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
    Fraction f1(2, 3);
    f1.PrintLine();

    Fraction f2(3, 4);
    f2.PrintLine();

    Fraction f3(4, 5);
    f3.PrintLine();

    Fraction fres = f1.Plus(f2).Minus(f3).Plus(f1);

    //f1.Add(f2);
    //f1.PrintLine();

    Color color = Color::White;
    Fruit fruit = Fruit::Orange;

    Color color1 = Color::Red;

    //cout << (color == fruit);
    

    color = Color::Black;
}
