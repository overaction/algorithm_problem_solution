#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int cache[30][30];
int bino(int n, int r) {
    // 기저 사례
    if(r == 0 || n == r) return 1;
    // -1이 아니라면 한 번 계산했던 값이니 곧장 반환
    if(cache[n][r] != -1)
        return cache[n][r];
    // 계산한 값을 캐시에 저장
    return cache[n][r] = bino(n-1,r-1) + bino(n-1,r);
}
int main()
{
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++)
            cache[i][j] = -1;
    int re = bino(8,4);
    printf("%d",re);
}
