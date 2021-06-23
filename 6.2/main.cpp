#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
/*
n : 전체 원소의 수
picked : 지금까지 고른 원소들의 번호
toPick : 더 고를 원소의 수
*/
int recursum(int n) {
    if(n == 1) return 1;
    return n + recursum(n-1);
}

void printPicked(vector<int>& picked) {
    int vsize = picked.size();
    for(int i=0; i<vsize; i++) {
        printf("%d ",picked[i]);
    }
    printf("\n");
}

void pick(int n, vector<int>& picked, int toPick) {
    // 더 고를 원소가 없을 때 고른 원소들을 출력한다
    if(toPick == 0) {
        printPicked(picked);
        return;
    }
    // 고를 수 있는 가장 작은 번호를 계산한다
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    // 원소 하나를 고른다
    for(int next = smallest; next < n; next++) {
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
}

int main()
{
    vector < int > myvect;
    pick(7,myvect,4);
}

