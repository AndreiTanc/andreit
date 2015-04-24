#include <iostream>
#include <fstream>

using namespace std;

int c1(int d)
{
    int s = 0;
    d = d - 1;
    s = s + d;

    d = d - 2;
    while(d >= 1)
    {
        s = s + 2 * d;
        d -= 2;
    }
    return s;
}

// verifica daca bila de pe pozitia a,b se afla in chenarul de diensiune d plasat in pozitia x, y
inline int InChenar(int x,int y,int d,int a, int b)
{
    if(a < x || a > x + d)
        return 0;

    if(a <= x + d / 2)
        if(b >= y - (a - x) && b <= y + (a - x))
            return 1;
        else
            return 0;
    else
        if(b >= y - (x + d - a) && b <= y + (x + d - a))
            return 1;
        else
            return 0;

}
int main()
{
    int p;
    int n, k, d;
    int a[55001] = {0}, b[55001] = {0};
    ifstream in("pseudobil.in");
    ofstream out("pseudobil.out");

    in >> p >> n >> k >> d;

    if(p == 1)
    {
        //rezolvam doar cerinta 1
        out << c1(d);
    }
    else
    {
        //rezolvam doar cerinta 2
        int contor, j, i, m, x, y;
        for(i = 1; i <= k; i++)
        {
            in >> a[i];
            in >> b[i];
        }
        in >> m;
        for(i = 1; i <= m; i++)
        {
            in >> x >> y;
            contor = 0;
            for(j = 1; j <= k; j++)
            {
                if(InChenar(x, y, d, a[j], b[j]))
                    contor++;
            }
            out << contor << endl;
        }

    }

    in.close();
    out.close();
    return 0;
}
