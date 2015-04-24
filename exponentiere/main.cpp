#include <iostream>

using namespace std;

int exponentiere_recursiv(int a, int k, int n)
{
    if(k == 0)
        return 1;
    else if(k == 1)
        return a % n;
    else if(k % 2 == 0)
    {
        int p;
        p = exponentiere_recursiv(a, k/2, n);
        return ((p % n) * (p % n)) % n;
    }
    else
    {
        int p;
        p = exponentiere_recursiv(a, k - 1, n);
        return ((p % n) * (a % n)) % n;
    }
}

int exponentiere_nerecursiv(int a, int k, int n)
{
    int A, c, rez = 1;
    A = a % n;
    while(k != 0)
    {
        c = k % 2;
        k = k / 2;
        if(c == 1)
        {
            rez = (rez * (A % n)) % n;
        }
        A = (A * A) % n;
    }
    return rez;
}

int main()
{
    int n = 17, k = 100, a = 2;
    cout << exponentiere_recursiv(a, k, n) << endl;
    cout << exponentiere_nerecursiv(a, k, n) << endl;
    return 0;
}
