/*
ID: harryha7
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct Farmer {
    int begin;
    int end;
};

bool cmp(const Farmer &x, const Farmer &y) {

    if (x.begin != y.begin) {
        return x.begin < y.begin;
    }
    return x.end < y.end;
}

struct Farmers {
    Farmer farmers[5000];
    int counter = 0;

    int longest_idle = 0;
    int longest_milk = 0;

    void push(int begin, int end) {
        farmers[counter].begin = begin;
        farmers[counter].end = end;
        counter++;
    };

    void sort() {
        std::sort(farmers, farmers + counter, cmp);
    }

//    void longestIdle() {
//        std::sort(farmers, farmers + counter, cmp);
//        int b = farmers[0].begin;
//        int e = farmers[0].end;
//        longest_idle = 0;
//        longest_milk=e-b;
//        for (int i = 1; i < counter; i++) {
//            if (farmers[i].begin <= e) {
//                e = farmers[i].end;
//            } else {
//                longest_milk = max(longest_milk, e - b);
//                longest_idle = max(longest_idle, farmers[i].begin - e);
//                b = farmers[i].begin;
//                e = farmers[i].end;
//            }
//        }
//        cout<<longest_milk<<endl;
//        cout<<longest_idle<<endl;
//    }
    void longestIdle2() {
        std::sort(farmers, farmers + counter, cmp);
        int b = farmers[0].begin;
        int e = farmers[0].end;
        longest_idle = 0;
        longest_milk=e-b;
        for (int i = 1; i < counter; i++) {
            if (farmers[i].begin <= e) {
                e = max(e,farmers[i].end);
            } else {
                longest_milk = max(longest_milk, e - b);
                longest_idle = max(longest_idle, farmers[i].begin - e);
                b = farmers[i].begin;
                e = farmers[i].end;
            }
        }

        longest_milk = max(longest_milk, e - b);

        cout<<longest_milk<<endl;
        cout<<longest_idle<<endl;
    }
};

Farmers farmers;

int main() {
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++) {
        int b, e;
        fscanf(fin, "%d%d", &b, &e);
        farmers.push(b, e);
    }
    farmers.longestIdle2();
    fprintf(fout, "%d %d\n", farmers.longest_milk, farmers.longest_idle);
    return 0;
}