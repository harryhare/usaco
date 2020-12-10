/*
ID: harryha7
LANG: C++
TASK: numtri
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
// todo: 用答案给的方法，减少内存消耗

int a[500001];
int len;

void level(int i){
    int begin=(i-1)*i/2;
    int end=begin+i;

    for(int i=begin,j=end;i<end;i++,j++){
        a[i]+=max(a[j],a[j+1]);
    }
}
int process(int n) {
    for (int i = n-1;i>=0;i--){
        level(i);
    }
    return a[0];
}

int main() {
    FILE *fin = fopen("numtri.in", "r");
    FILE *fout = fopen("numtri.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    len = n * (n + 1) / 2;
    for (int i = 0; i < len; i++) {
        fscanf(fin, "%d", a + i);
    }
    int r = process(n);
    cout << r << endl;
    fprintf(fout, "%d\n", r);
    return 0;
}