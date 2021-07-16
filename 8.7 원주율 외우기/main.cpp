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
    // 모든 숫자가 같은지 체크
    for(int i=s; i<e; i++) {
        if(pi[i] != pi[i+1]) {
            complete = false;
            break;
        }
    }
    if(complete) return 1;
    complete = true;

    // 등차수열인지 체크
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

    // 번갈아가면서 나타나는지 체크
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
    // 기저사례 : 끝에 도달
    if(start == piSize) return 0;

    int &ret = cache[start];
    if(ret != -1) return ret;
    ret = INF;
    for(int L=3; L<=5; L++) {
        if(start+L <= piSize) {
// 점화식 : {start~start+L까지 난이도} + {start+L 이후부터의 최소난이도}
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
