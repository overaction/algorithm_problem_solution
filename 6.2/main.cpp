#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
/*
n : ��ü ������ ��
picked : ���ݱ��� �� ���ҵ��� ��ȣ
toPick : �� �� ������ ��
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
    // �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�
    if(toPick == 0) {
        printPicked(picked);
        return;
    }
    // �� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    // ���� �ϳ��� ����
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

