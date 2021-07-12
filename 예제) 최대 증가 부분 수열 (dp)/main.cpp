#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

/*
 예제 대신 8.5 합친 LIS의 다른 풀이법으로 적습니다
*/

int C,N;
int n,m;
int A[101],B[101];
int cache[101][101];

// solution은 A[a] B[b]로 시작하는 수열 중 가장 긴 수열을 반환
int solution(int prev, int a, int b) {
    int &ret = cache[a][b];
    if(ret != -1) return ret;

    //
    ret = 1;
    for(int next=a; next<n; next++) {
        if(A[next] > prev)
            ret = max(ret,solution(A[next],next+1,b)+1);
    }
    for(int next=b; next<m; next++) {
        if(B[next] > prev)
            ret = max(ret,solution(B[next],a,next+1)+1);
    }
    return ret;
}

int main()
{
    int result = -1;
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        memset(cache,-1,sizeof(cache));
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%d",&A[i]);
        for(int i=0; i<m; i++) scanf("%d",&B[i]);

        // 시작점을 정해주기 때문에 각각 실행
        for(int i=0; i<n; i++)
            result = max(result,solution(A[i],i+1,0));
        for(int i=0; i<m; i++)
            result = max(result,solution(B[i],0,i+1));
        printf("%d\n",result);
    }
}
