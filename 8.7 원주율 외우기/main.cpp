#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;
int C,piSize;
int pi[10001];
int cache[10001];

int calculate(int s, int e) {
    int complete = true;
    // ��� ���ڰ� ������ üũ
    for(int i=s; i<e; i++) {
        if(pi[i] != pi[i+1]) {
            complete = false;
            break;
        }
    }
    if(complete) return 1;
    complete = true;

    // ������������ üũ
    for(int i=s; i<e-1; i++) {
        if(pi[i] - pi[i+1] != pi[i+1] - pi[i+2]) {
            complete = false;
            break;
        }
    }
    if(complete && (pi[s] - pi[s+1] == 1 || pi[s+1] - pi[s] == 1))
        return 2;
    else if(complete)
        return 5;

    complete = true;

    // �����ư��鼭 ��Ÿ������ üũ
    int prev = pi[s];
    int next = pi[s+1];
    for(int i=s; i<=e; i+=2) {
        if(prev != pi[i]) {
            complete = false;
            break;
        }
    }
    if(complete == false) return 10;
    for(int i=s+1; i<=e; i+=2) {
        if(next != pi[i]) {
            complete = false;
            break;
        }
    }
    if(complete == false) return 10;
    return 4;
}

int memorize(int start) {
    // ������� : ���� ����
    if(start == piSize) return 0;

    int &ret = cache[start];
    if(ret != -1) return ret;
    ret = INF;
    for(int L=3; L<=5; L++) {
        if(start+L <= piSize) {
// ��ȭ�� : {start~start+L���� ���̵�} + {start+L ���ĺ����� �ּҳ��̵�}
            ret = min(ret, calculate(start,start+L-1)+memorize(start+L));
        }
    }
    return ret;
}

int main()
{
    string s;
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        memset(cache,-1,sizeof(cache));
        cin >> s;
        piSize = s.size();
        for(int i=0; i<s.size(); i++) {
            pi[i] = s[i]-48;
        }
        printf("%d\n",memorize(0));
    }
}
