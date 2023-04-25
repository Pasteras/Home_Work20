//Create a template calculator that will work correctly without
//depending on the type of digits that are transmitted to it.
//The calculator must containthe following functions.
//Functions must not use cmath functions.
//1. Additions
//2. Subtraction
//3. Multiplication
//4. Division
//5. Exponentiation(recursive) // !pow()
//6. Finding the factorial(recursively)

#include <iostream>

using namespace std;

int N;
int sel;

int Fact(int N);
int Pow(int f_num, int s_num);
template <typename T1, typename T2>
T2 Sum(T1 f_num, T2 s_num);

int main()
{
    int f_num;
    double s_num;
    while (true)
    {
        cout << "\tCalculator." << endl;
        cout << "Select an action: " << endl <<
            "1 +.\n2 -.\n3 /.\n4 *.\n5 Pow.\n6 Factorial.\n";
        cin >> sel;
        if (sel == 6)
        {
            cout << "Press number: ";
            cin >> N;
            cout << endl << "Result: " << Fact(N) << endl;
            break;
        }
        if (sel == 5)
        {
            cout << "Press number: ";
            cout << "Press first number: ";
            cin >> f_num;
            cout << endl;
            cout << "Press second number: ";
            cin >> s_num;
            cout << endl;
            cout << endl << "Result: " << Pow(f_num, s_num) << endl;
            break;
        }
        cout << "Press first number: ";
        cin >> f_num;
        cout << endl;
        cout << "Press second number: ";
        cin >> s_num;
        cout << endl;
        cout << endl << "Result: " << Sum(f_num, s_num) << endl;
        break;
    }
}

template <typename T1, typename T2> 
T2 Sum(T1 f_num, T2 s_num)
{
    if (sel == 1)
    {
        return f_num + s_num;
    }
    if (sel == 2)
    {
        return f_num - s_num;
    }
    if (sel == 3)
    {
        return f_num / s_num;
    }
    if (sel == 4)
    {
        return f_num * s_num;
    }
    if (sel == 4)
    {
        return f_num * s_num;
    }
    if (sel == 5)
    {
        return f_num * s_num;
    }
}

int Fact(int N)
{
    if (N == 0)
    {
        return 0;
    }
    if (N == 1)
    {
        return 1;
    }
    return N * Fact(N - 1);
}

int Pow(int f_num, int s_num)
{
    if (s_num == 0)
    {
        return 1;
    }
    else if (N < 0)
    {
        return 1 / Pow(f_num, -s_num);
    }
    else
    {
        return f_num * Pow(f_num, s_num - 1);
    }
}
