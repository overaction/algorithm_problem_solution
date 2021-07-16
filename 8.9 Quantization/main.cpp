#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 987654321
using namespace std;
int C,n,s;
int A[101];
int Sum[101],sqSum[101];
int cache[101][11];

int minians(int from, int to) {
    int sum = Sum[to] - (from == 0 ? 0 : Sum[from-1]);
    int sqsum = sqSum[to] - (from == 0 ? 0 : sqSum[from-1]);

    int m = round( (sum) / (to-from+1) );
    int result = sqsum - (2*m*sum) + (m*m*(to-from+1));
    return result;
}

void initial() {
    sort(A,A+n);
    memset(cache,-1,sizeof(cache));
    Sum[0] = A[0];
    sqSum[0] = A[0]*A[0];
    for(int i=1; i<n; i++) {
        Sum[i] = A[i] + Sum[i-1];
        sqSum[i] = A[i]*A[i] + sqSum[i-1];
    }
}

// from에서 시작해서 parts개로 양자화 했을 때 최소해를 반환
int quantization(int from ,int parts) {
    // 끝까지 도달했을경우
    if(from == n) return 0;
    // 더이상 양자화할 수 없다면
    if(parts == 0) return INF;

    int &ret = cache[from][parts];
    if(ret != -1) return ret;

    ret = INF;
    for(int step = 1; step+from <= n; step++) {
        ret = min(ret, minians(from,from+step-1)+quantization(from+step,parts-1));
    }
    return ret;
}

int main() {
    scanf("%d",&C);
    for(int i=0; i<C; i++) {
        scanf("%d %d",&n,&s);
        for(int j=0; j<n; j++) scanf("%d",&A[j]);
        initial();
        printf("%d\n",quantization(0,s));
    }
}
