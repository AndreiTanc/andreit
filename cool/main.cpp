#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    int p, N, K, i;
    int A[5000] = {0};
    int v[1001] = {0};

    ifstream in("cool2.in");
    ofstream out("cool.out");

    in >> p >> N >> K;
    for(i = 0; i < N; i++)
        in >> A[i];


    int i1, i2, cool, n1 = 0;

    if(p == 1)
    {
        // cerinta 1
        for(i = 0; i < K; i++)
            v[A[i]]++;
        cool = 1;
        for(i = 1; i <= 1000; i++)
        {
            if(v[i] > 1)
                cool = 0;
        }

        for(i = 1; i <= 1000; i++)
                if(v[i] == 1)
                    n1++;

        if(cool == 1)
        {
            i1 = 1;
            while(v[i1] == 0)
                i1++;
            i2 = 1000;
            while(v[i2] == 0)
                i2--;


            if(i2 - i1 + 1 != n1)
                cool = 0;
        }
        if(cool == 1)
            out << i2;
        else
            out << n1;
    }
    else
    {
        // cerinta 2
    }

    return 0;
}
