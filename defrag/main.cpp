#include <iostream>
#include <fstream>

using namespace std;



int F1(int a[][361], int P, int S)
{
    int contor = 0, i, j;
    int z;
    for(i = 1; i <= P; i++)
    {
        z = 0;
        for(j = 1; j <= S; j++)
            if(a[i][j] == 1)
                z++;
        if(z == 0)
            contor++;
    }

    return contor;
}

void F2(ofstream out, int a[][361], int P, int S)
{
    int i, j, mutari, hi, lo;

    for(i = 1; i <= P; i++)
    {
        mutari = 0;

        lo = 1;hi = S;

        while(lo <= hi && a[i][lo] == 0)
            lo++;

        if(lo == hi + 1)
        {
            out << "0 ";
            continue;
        }

        while(hi >= lo && a[i][hi] == 0)
            hi--;

        if(hi == lo || hi == lo + 1)
        {
            out << "0 ";
            continue;
        }

        //TODO


    }
}

int main()
{
    int a[101][361], V, S, P, C, i, j, x, y;

    ifstream in("4-defrag.in");
    ofstream out("defrag.out");

    in >> V >> P >> S >> C;

    for(i = 0; i <= 100; i++)
        for(j = 0; j <= 360; j++)
            a[i][j] = 0;

    for(i = 1; i <= C; i++)
    {
        in >> x >> y;
        a[x][y] = 1;
    }

    if(V == 1)
    {
        out << F1(a, P, S) << endl;
    }
    else
    {
        F2(out, a, P, S);
    }



    in.close();
    out.close();
    return 0;
}
