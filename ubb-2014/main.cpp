#include <iostream>
#include <fstream>
#define MAX 500
using namespace std;


int Citire(int x[], char filename[])
{
    int n, i;
    ifstream in(filename);

    in >> n;
    if(n > MAX)
        n = MAX;

    for(i = 0; i < n; i++)
        in >> x[i];
    in.close();
    return n;
}

int Cmmdc(int a, int b)
{
    int aux;

    while(b != 0)
    {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int Cmmmc(int x[], int n)
{
    int c;
    c = x[0];
    for(int i = 1; i <= n; i++)
    {
        c = c * x[i] / Cmmdc(c, x[i]);
    }
    return c;
}

int main()
{
    int n, x[MAX];
    int cmm = 0;


    n = Citire(x, "input.in");


    cmm = Cmmmc(x, n);

    cout << "Cel mai mic multiplu comun este: " << cmm;
    return 0;
}
