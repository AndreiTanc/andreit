#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

 int Generare(int n, int &max)
 {
     int i = 1;
     cout << n << " = ";
     max = n;
     while(n != 1)
     {
         if(n % 2 == 0)
            n = n / 2;
         else
            n = 3 * n + 1;
         cout << n << " ";
         i++;
         if(max < n)
            max = n;
     }
     cout << endl;
     return i;
 }

void Swap(int &a, int &b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int main()
{
    int n, a, b;
    ifstream in("input.in");

    in >> n >> a >> b;

    in.close();


    int lungime;
    int max;
    lungime = Generare(n, max);
    cout << "Lungimea secventei e: " << lungime << endl;
    cout << "Cel mai mare nr din secventa este: "<< max << endl;

    if(a > b)
        Swap(a, b);

    int lmax = 0, imax;
    for(int i = a; i <= b; i++)
    {
        lungime = Generare(i, max);
        if(lungime > lmax)
        {
            lmax = lungime;
            imax = i;
        }


    }
    cout << "Lungimea maxima a unei secvente pt intervalul [a, b] este: " << lmax << " si se obtine pt valoarea: " << imax << endl;
    //cout << (1 << 31) << endl;
    //cout << ~(1 << 31) << endl;
    return 0;
}
