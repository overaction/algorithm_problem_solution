#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int C;
// ���ö��� ��, ����� �ð�, �Դ� �ð�
int n;
int heating[10001];
int eating[10001];

int solution() {
    // ��������� ������� ���Ѵ�
    vector < pair <int,int > > order;
    for(int i=0; i<n; i++)
        order.push_back({-eating[i],i});
    sort(order.begin(),order.end());

    for(int i=0; i<n; i++)
        printf("%d %d\n",order[i].first,order[i].second);

    int ret = 0, beginEat = 0;
    for(int i=0; i<n; i++) {
        int box = order[i].second;
        beginEat += heating[i];
        ret = max(ret, beginEat + eating[box]);
    }
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int i=0; i<C; i++) {
        scanf("%d",&n);
        for(int j=0; j<n; j++)
            scanf("%d",&heating[j]);
        for(int j=0; j<n; j++)
            scanf("%d",&eating[j]);
        printf("%d\n",solution());
    }
}
