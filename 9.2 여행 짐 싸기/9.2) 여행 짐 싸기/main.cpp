#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int C,N,W;
int cache[101][1001];
vector <string> bag;
typedef struct info {
    int cap;
    int wish;
}info;
vector < info > vinfo;
vector < int > result;

// index �� ���� �����, capacity��ŭ �뷮�� �� ���� �� �ִ� ���ڵ��� ����
int solution(int index, int capacity) {
    // ������� : ���� ����
    if(index == N) {
        return 0;
    }
    int &ret = cache[index][capacity];
    if(ret != -1) return ret;

    ret = 0;
    // ������ ���� �ʾ��� ���
    ret = max(ret, solution(index+1,capacity));
    // ������ ����� ���
    if(capacity + vinfo[index].cap <= W) {
        ret = max(ret, solution(index+1,capacity+vinfo[index].cap)+vinfo[index].wish);
    }
    return ret;
}

void choosing(int index, int capacity) {
    if(index == N) return;
    if(solution(index,capacity) == solution(index+1,capacity))
        choosing(index+1, capacity);
    else {
        result.push_back(index);
        choosing(index+1,capacity+vinfo[index].cap);
    }
}

int main()
{
    int a,b;
    string s;
    scanf("%d",&C);
    info ifo;
    for(int c=0; c<C; c++) {
        memset(cache,-1,sizeof(cache));
        scanf("%d %d",&N,&W);
        for(int i=0; i<N; i++) {
            cin >> s >> a >> b;
            bag.push_back(s);
            ifo.cap = a;
            ifo.wish = b;
            vinfo.push_back(ifo);
        }
        // ���ڵ� ���
        printf("%d ",solution(0,0));
        // �������� ������ ���� ���
        choosing(0,0);
        printf("%d\n",result.size());
        // �������� ���� ���
        for(int i=0; i<result.size(); i++)
            cout << bag[result[i]] << endl;
        // �ʱ�ȭ
        bag.clear();
        result.clear();
        vinfo.clear();
    }
}
