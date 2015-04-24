#include <iostream>
#include <fstream>
#define MAX 100

using namespace std;

int Citire(int X[], int n, char filename[])
{
    ifstream in(filename);

    int i = 0;

    while(i < n && in >> X[i])
        i++;
    return i;
}


void Tiparire(int X[], int n, char mesaj[])
{
    int i;

    if(n == 0)
    {
        cout << mesaj << " este sirul vid";
        return;
    }
    cout << mesaj << " = (";
    for(i = 0; i < n - 1; i++)
    {
        cout << X[i] << ", ";
    }
    cout << X[n - 1] << ")\n";
}

void Cifre(int c[], int n, int x)
{
    while(x != 0)
    {
        c[x % 10] = 1;
        x = x / 10;
    }
}

int VectoriEgali(int c[], int v[], int n)
{
    int ok = 1, i;

    for(i = 0; i < n && ok; i++)
        if(c[i] != v[i])
            ok = 0;

    return ok;
}

void Eliminare(int v[], int &n, int offset, int contor)
{
    int i;
    if(offset < 0 || offset >= n)
        return;
    if(contor <= 0)
        return;
    if(contor >= n - offset)
    {
        n = offset;
        return;
    }

    for(i = 0; offset + contor + i < n; i++)
    {
        v[offset + i] = v[offset + contor + i];
    }

    n = n - contor;

}

void Inserare(int v[], int &n, int x)
{
    int i, gasit = 0;
    for(i = 0; i < n && !gasit; i++)
        if(x == v[i])
            gasit = 1;
    if(!gasit)
    {
        v[n] = x;
        n++;
    }
}

int Asemenea(int x, int y)
{
    int c[10] = {0}, v[10] = {0};

    Cifre(c, 10, x);
    Cifre(v, 10, y);

    return VectoriEgali(c, v, 10);
}

int main()
{
    int R[MAX] = {0}, X[MAX] = {0};
    int dimX = 0, dimR = 0, k, j, i;

    dimX = Citire(X, MAX, "input.in");

    for(i = 0; i < dimX - 1; i++)
    {
        for(j = i; j < dimX - 1 && Asemenea(X[j], X[j + 1]); j++);
        if(j > i)
        {
            for(k = i; k <= j; k++)
                Inserare(R, dimR, X[k]);
            Eliminare(X, dimX, i, j - i + 1);
            i--;
        }
    }

    Tiparire(X, dimX, "X");
    Tiparire(R, dimR, "R");
    return 0;
}
