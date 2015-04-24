#include <iostream>
#include <cstring>

using namespace std;

int main()
{
//    float f = 0.0f;
//    int i;
//    for(i = 1; i <= 1000000; i++)
//    {
//        f = f + 0.001f;
//        if(i % 1000 == 0)
//            cout << i << " " << f << endl;
//    }
//
//    cout << int(f);

    char s[256] ="bine*albine*foarte*bine*";
    char dest[256] = "";
    int i;
    cin.get(s,255);

    char v[256];
    char * p;
    p = strchr(s, '*');

    int n;
    n = p - s;
    strncpy(v, s, n);
    v[n] = '\0';

    p = strtok(s, "*");
    while(p != NULL)
    {
        if(strcmp(p, v) != 0)
            strcat(dest, p);
        strcat(dest, "*");
        p =  strtok(NULL, "*");
    }
    cout << dest << endl;

    return 0;
}
