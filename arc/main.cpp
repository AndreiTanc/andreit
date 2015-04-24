#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int C1(int c[], int n)
{
    int contor = 0, i = 0, j;

    while(i < n)
    {
        j = i;
        while(j + 1 < n && c[j + 1] == c[i])
            j++;
        //if(j - i + 1 >= 3)
            contor++;
        i = j + 1;
    }
    return contor;
}


void SecvMax(int c[], int n, int &lo, int &hi)
{
    int maxim = 0, i = 0, j;

    while(i < n)
    {
        j = i;
        while(j + 1 < n && c[j + 1] == c[i])
            j++;
        if(j - i + 1 >= 3)
        {
            if(j - i + 1 > maxim)
            {
                maxim = j - i + 1;
                lo = i;
                hi = j;
            }
        }
        i = j + 1;
    }
}

void Crush(int c[], int &n, int lo, int hi)
{
    int i, j = 0;

    for(i = hi + 1; i < n; i++)
    {
        c[lo + j] = c[i];
        j++;
    }
    n = n - (hi - lo + 1);
}

int main()
{
    int c[10000], V, n, i;
    int lo, hi, left, right;

    ifstream in("19-arc.in");
    ofstream out("arc.out");

    in >> V >> n;

    for(i = 0; i < n; i++)
        in >> c[i];

    if(V == 1)
    {
        out << C1(c, n);
    }
    else
    {
        do // rezolvam cerinta 2
        {
            lo = hi = -1;

            SecvMax(c, n, lo, hi);
            if(lo != -1)
            {
                Crush(c, n, lo, hi);
                do{
                    if(lo > 0 && c[lo] == c[lo - 1])
                    {
                        left = lo - 1; right = lo;
                        while(left - 1 >= 0 && c[left - 1] == c[lo])
                            left--;
                        while(right + 1 < n && c[right + 1] == c[lo])
                            right++;
                        if(right - left + 1 >= 3)
                        {
                            Crush(c, n, left, right);
                            lo = left;
                        }

                        else
                            break;
                    }
                    else
                        break;
                }while(1);
            }
        }while(n > 0 && lo != -1);
        out << n << endl;
        for(i = 0; i < n; i++)
            out << c[i] << endl;
    }

    out.close();
    in.close();
    return 0;
}
