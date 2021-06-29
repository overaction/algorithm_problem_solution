#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 98765432
int C;
char connection[10][17] = {
    "oooxxxxxxxxxxxxx",
    "xxxoxxxoxoxoxxxx",
    "xxxxoxxxxxoxxxoo",
    "oxxxooooxxxxxxxx",
    "xxxxxxoooxoxoxxx",
    "oxoxxxxxxxxxxxoo",
    "xxxoxxxxxxxxxxoo",
    "xxxxooxoxxxxxxoo",
    "xoooooxxxxxxxxxx",
    "xxxoooxxxoxxxoxx"
};

bool allClear(vector < int > &clocks) {
    bool ok = true;
    for(int i=0; i<16; i++) {
        if(clocks[i] != 12) {
            ok = false;
            break;
        }
    }
    return ok;
}

void clickSwtch(vector < int > &clocks, int swtch) {
    for(int i=0; i<16; i++) {
        if(connection[swtch][i] == 'o') {
            if((clocks[i] += 3) > 12) clocks[i] = 3;
        }
    }
}

int solution(vector < int > &clocks, int swtch) {
    // ������ ����ġ���� �������� ��
    if(swtch == 10) return allClear(clocks) ? 0 : INF;

    int ret = INF;
    // ����ġ�� 0�� ������ ��� ~ 3�� ������ ��츦 �����غ���.
    // �������� 4��°�� ������ ������ �ʱ�ȭ�ȴ�.
    for(int i=0; i<4; i++) {
        int tmp = i + solution(clocks,swtch+1);
        ret = min(ret,tmp);
        clickSwtch(clocks,swtch);
    }
    return ret;
}

int main() {
    scanf("%d",&C);
    int num;
    for(int tc=0; tc<C; tc++) {
        vector <int> clocks;
        for(int i=0; i<16; i++) {
            scanf("%d",&num);
            clocks.push_back(num);
        }
        int result = solution(clocks,0);
        (result == INF) ? printf("-1\n") : printf("%d\n",result);
    }
}

