#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MOD 1000000007
using namespace std;

/*
    (전체 경우의 수 - 대칭 타일링의 경우의 수) 가 답이 된다.
*/
int C,n;
int cache[101];
// tiling(n) = 너비가 n인 사각형을 채우는 경우의 수 반환
// 전체 타일링 경우의 수를 반환한다.
int tiling(int width) {
    if(width <= 1) return 1;
    int &ret = cache[width];
    if(ret != -1) return ret;

    ret = (tiling(width-1) + tiling(width-2))% MOD;
    return ret;
}

// sameTiling(n) = 너비가 n인 사각형에서 비대칭으로 채우는 경우의 수
// 결과값이 음수가 나올 가능성도 있기 때문에, 미리 MOD를 더해주고 MOD 값으로 나눈 나머지를 출력한다
int sameTiling(int width) {
    // width = 홀수일 경우
    if(width % 2 == 1) {
        return (tiling(width) - tiling(width/2) + MOD) % MOD;
    }
    int ret = tiling(width);
    ret = (ret - tiling(width/2) + MOD) % MOD;
    ret = (ret - tiling(width/2 - 1) + MOD) % MOD;
    return ret;
}
int main()
{
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        memset(cache,-1,sizeof(cache));
        scanf("%d",&n);
        printf("%d\n",sameTiling(n));
    }
}
