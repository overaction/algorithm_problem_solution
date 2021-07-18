#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int n;
// choices[i] = i 이후에 가장 긴 수열을 갖는 첫 인덱스를 저장
int cache[101], S[100], choices[101];
int maxSize = 0;

int listing(int start) {
    int &ret = cache[start];
    if (ret != -1)
        return ret;
    ret = 1;
    // 초기값 : 이후에 더 큰 숫자 인덱스가 없는 경우 -1 저장ㅣ
    int bestNext = -1;
    for (int next = start + 1; next < n; next++) {
        if (S[start] < S[next]) {
            int cand = listing(next) + 1;
            if(cand > ret) {
                ret = cand;
                bestNext = next;
            }
        }
    }
    choices[start] = bestNext;
    return ret;
}

void reconstruct(int start, vector < int > &seq) {
    vector < int > tseq;
    tseq.push_back(S[start]);
    while(1) {
        int next = choices[start];
        if(next != -1) tseq.push_back(S[next]);
        else break;
        start = next;
    }
    if(maxSize < tseq.size()) {
        maxSize = tseq.size();
        seq.clear();
        for(int i=0; i<tseq.size(); i++)
            seq.push_back(tseq[i]);
    }
}

int main()
{
    memset(cache,-1,sizeof(cache));
    memset(choices,-1,sizeof(choices));
    int maximum = 0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&S[i]);
    for(int i=0; i<n; i++)
        maximum = max(maximum,listing(i));
    printf("%d\n",maximum);

    vector < int > seq;
    for(int i=0; i<n; i++)
        reconstruct(i,seq);
    for(int i=0; i<seq.size(); i++)
        printf("%d ",seq[i]);
    printf("\n%d\n",maxSize);
    for(int i=0; i<n; i++)
        printf("%d ",choices[i]);
}
