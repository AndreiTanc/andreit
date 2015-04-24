#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

inline void reverse(int c[], int n)
{
    //rasturnare
    int i, j, aux;
    i = 0;
    j = 2 * n - 1;

    while(i < j)
    {
        aux = c[i];
        c[i] = c[j];
        c[j] = aux;
        i++;
        j--;
    }


    //reasejare
    for(i = 2 * n - 2; i >= 2; i = i - 2)
    {
       c[i] = c[i - 1];
       c[i - 1] = 0; // !!! aici trebuie facuta aceasta operatie pentru ca altfel valoarea ramane 1
    }
}


inline void reverse_fara_reasezare(int c[], int n)
{
    //rasturnare
    int i, j, aux;
    i = 0;
    j = 2 * n - 1;

    while(i < j)
    {
        aux = c[i];
        c[i] = c[j];
        c[j] = aux;
        i++;
        j--;
    }
}

int Suma(int c[], int n)
{
    int s = 0;
    for(int i = 0; i < 2 * n; i++)
        s += c[i];
    return s;
}

inline int Min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}
int main()
{
    int n; // nr clepsidre max 1000
    int b; // nr boabe de nisip max 1.000.000.000
    int k; // nr de stari max 1000
    int s; // nr de secunde max 1000
    int p, pp; //pozitia 1 sau 2
    int i, aux, h, j;
    static int c[2000] = {0};
    ifstream in("24-clepsidru.in");
    ofstream out("clepsidru.out");

    in >> n >> b >> k;
    c[0] = b;
    out << n - 1 + b << endl;
    pp = 1;
    for(i = 1; i <= k; i++)
    {
        in >> s >> p;
        if(p != pp)
        {
            reverse(c, n);
            assert(Suma(c, n) == b);
        }
        pp = p;
        // procesarea boabelor


        // cad bilele de pe pozitiile intermediare (procesate de jos in sus)
        for(j = 2 * n - 2; j >= 2; j = j - 2)
        {
            if (c[j] > 0)
            {
                c[j]--;
                c[Min(2 * n - 1, j + 2 * s)]++;
            }
        }

        assert(Suma(c, n) == b);

        // daca mai sunt bile pe pozitia 0 atunci le punem pe pozitiile pe care ajung dupa j secunde (ordinea de procesare e importanta)
        for (j = s; c[0] > 0 && j >= 1; j--)
        {
            c[Min(2 * n - 1, 2 * j)]++;
            c[0]--;
        }

        assert(Suma(c, n) == b);
    }

    if(p == 2)
        reverse_fara_reasezare(c, n); // daca ultima operatie a fost cu p = 2 nu mai trebuie facuta reasezare
        // doar reverse

    for(i = 0; i < 2 * n; i = i + 2)
    {
        out << c[i] << " " << c[i + 1] << endl;
    }


    in.close();
    out.close();
    return 0;
}
