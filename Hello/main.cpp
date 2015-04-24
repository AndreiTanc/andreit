#include <iostream>

using namespace std;

int SumaCifre(int p)
{
    int S = 0, c;
    while(p != 0)
    {
        c = p % 10;
        p = p / 10;
        S = S + c;
    }
    return S;
}

void S1(int n)
{
    int i, j, p;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

void SS1(int n)
{
    int i, j, contor = 0;
    for(i = 1; contor < n; i++)
    {
        for(j = 1; j <= i && contor < n; j++)
        {
            cout << j << " ";
            contor++;
        }

        cout << endl;
    }
}


void S2(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
            cout << i << " ";
        cout << endl;
    }
}
void SS2(int n)
{
    int i, j, contor = 0;
    for(i = 1; contor < n; i++)
    {
        for(j = 1; j <= i && contor < n; j++)
        {
            cout << i << " ";
            contor++;
        }

        cout << endl;
    }
}
void S3(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = i; j < 2 * i; j++)
            cout << j << " ";
        cout << endl;
    }
}

void SS3(int n)
{
    int i, j, contor = 0;
    for(i = 1; contor < n; i++)
    {
        for(j = i; j < 2 * i && contor < n; j++)
        {
            cout << j << " ";
            contor++;
        }

        cout << endl;
    }
}


void SSS1(int n)
{
    int i = 1, j = 1, contor = 0;
    while(contor < n)
    {
        cout << j << " ";
        contor++;
        j++;

        if(j > i)
        {
            i++;
            j = 1;
            cout << endl;
        }
    }
    cout << endl;
}

void SSS2(int n)
{
    int i = 1, j = 1, contor = 0;
    while(contor < n)
    {
        cout << i << " ";
        j++;
        contor++;
        if(j > i)
        {
            i++;
            j = 1;
            cout << endl;
        }
    }
    cout << endl;
}
int main()
{
    int n;

    cout << "Introduceti un numar: ";
    cin >> n;

    cout << SumaCifre(n) << endl;

    S1(n);
    S2(n);
    S3(n);

    SS1(n);
    SS2(n);
    SS3(n);

    SSS1(n);
    SSS2(n);
    return 0;
}
