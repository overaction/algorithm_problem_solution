#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int C;
int n,m;
int A[101],B[101];
int cache[101][101];

// A[idxA] 와 B[idxB] 수열 이후에 증가부분수열 최대값을 반환
int jlis(int idxA, int idxB) {
    int &ret = cache[idxA+1][idxB+1];
    if(ret != -1) return ret;

    ret = 2;
    // 두 수열중 최대값
    int maximum = max(A[idxA],B[idxB]);
    for(int next=idxA+1; next < n; next++)
        if(maximum < A[next])
            ret = max(ret,jlis(next,idxB)+1);
    for(int next=idxB+1; next < m; next++)
        if(maximum < B[next])
            ret = max(ret,jlis(idxA,next)+1);
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        int result = 0;
        memset(cache,-1,sizeof(cache));
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%d",&A[i]);
        for(int i=0; i<m; i++)
            scanf("%d",&B[i]);

        result = jlis(-1,-1) - 2;
        printf("%d\n",result);
    }
}
