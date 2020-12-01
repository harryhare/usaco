/*
ID: harryha7
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char *go = "GO\n";
char *stay = "STAY\n";

int cal(char *a) {
    int r = 1;
    for (int i = 0; i < 8 && a[i] != 0 && a[i]!='\r'; i++) {
        r = r*(a[i] - 'A'+1)%47;
    }
    return r;
}

int main() {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char a[8];
    char b[8];
    //fgets(a, 8, fin);
    //fgetc(fin);
    //fgets(b, 8, fin);
    //fgetc(fin);
    fscanf(fin,"%s",a);
    fscanf(fin,"%s",b);
    int i = cal(a);
    int j = cal(b);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<i<<endl;
    cout<<j<<endl;
    if ((i - j) % 47 == 0) {
        fputs(go, fout);
    } else {
        fputs(stay, fout);
    }

    return 0;
}