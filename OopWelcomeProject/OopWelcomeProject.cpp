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

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator+(int number, Fraction f);
    friend Fraction operator+(Fraction f, int number);

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);

    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);

    Fraction operator++()
    {
        this->numerator += this->denominator;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction copy = *this;
        ++(*this);
        return copy;
    }

    /*Fraction operator+(int number)
    {
        Fraction fresult;
        fresult.numerator = this->numerator + this->denominator * number;
        fresult.denominator = this->denominator;
        return fresult;
    }*/

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

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    Fraction fresult;
    fresult.numerator = f1.numerator * f2.denominator
        + f1.denominator * f2.numerator;
    fresult.denominator = f1.denominator * f2.denominator;
    return fresult;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction fresult;
    fresult.numerator = f1.numerator * f2.numerator;
    fresult.denominator = f1.denominator * f2.denominator;
    return fresult;
}

Fraction operator+(int number, Fraction f)
{
    Fraction fresult;
    // non friend function
    /*fresult.SetNumerator(f.GetNumerator() + f.GetDenominator() * number);
    fresult.SetDenominator(f.GetDenominator());*/

    fresult.numerator = f.numerator + f.denominator * number;
    fresult.denominator = f.denominator;

    return fresult;
}

Fraction operator+(Fraction f, int number)
{
    return number + f;
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
    return !(f1 < f2);
}

ostream& operator<<(ostream& out, const Fraction& f)
{
    out << "[" << f.numerator << "/" << f.denominator << "]";
    return out;
}

istream& operator>>(istream& in, Fraction& f)
{
    in >> f.numerator;
    in >> f.denominator;
    return in;
}


struct FractionS
{
    int numerator;
    int denominator;
};

int main()
{
    Fraction f1(2, 3);
    //f1.PrintLine();

    Fraction f2(3, 4);
    //f2.PrintLine();

    Fraction f3(4, 5);
    //f3.PrintLine();

    Fraction f4 = f1++;

    cout << f1 << " " << f4;

    //Fraction fres = f1.Plus(f2).Minus(f3).Plus(f1);

    //Fraction f4 = f1 + f2;
    //int n = 10;
    //f4 = n + f1;
    ////f4.PrintLine();
    ////cout << f4;


    //Fraction f5;
    //cin >> f5;
    //cout << f5;


    ////f1.Add(f2);
    ////f1.PrintLine();

    //Color color = Color::White;
    //Fruit fruit = Fruit::Orange;

    //Color color1 = Color::Red;

    //cout << (color == fruit);
    

    //color = Color::Black;
}
