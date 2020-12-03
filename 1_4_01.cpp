/*
ID: harryha7
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;


struct Farmer {
    int p;
    int a;

    static bool cmp(const Farmer &f1, const Farmer &f2) {
        return f1.p < f2.p;
    }
};


struct Farmers {
    Farmer farmers[50000];
    int n = 0;

    void push(int p, int a) {
        farmers[n].p = p;
        farmers[n].a = a;
        n++;
    }

    void sort() {
        std::sort(farmers, farmers + n, Farmer::cmp);
    }

    int cal(int wanted) {
        sort();
        int brought = 0;
        int money = 0;
        for (int i = 0; i < n; i++) {
            if (farmers[i].a >= wanted) {
                money+=wanted*farmers[i].p;
                break;

            } else {
                brought += farmers[i].a;
                money += farmers[i].a * farmers[i].p;
                wanted -= farmers[i].a;
            }
        }
        return money;
    }
};

Farmers farmers;

int main() {
    FILE *fin = fopen("milk.in", "r");
    FILE *fout = fopen("milk.out", "w");
    int n, m;
    fscanf(fin, "%d%d", &n, &m);
    int p, a;
    for (int i = 0; i < m; i++) {
        fscanf(fin, "%d%d", &p, &a);
        farmers.push(p, a);
    }
    int r = farmers.cal(n);
    cout<<r<<endl;
    fprintf(fout, "%d\n", r);
    return 0;
}