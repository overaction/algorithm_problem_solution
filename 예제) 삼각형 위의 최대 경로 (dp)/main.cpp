#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int board[10][10];
int cache[10][10];
int result = 0;

int N = 5;

int solution(int y, int x) {
    printf("%d %d\n",y,x);
    for(int i=0; i<5; i++) {
        for(int j=0; j<=i; j++) {
            printf("%d ",cache[i][j]);
        }
        printf("\n");
    }
    // 기저사례 : 끝까지 도달
    if(y == N-1) {
        return board[y][x];
    }
    // 메모이제이션
    int &ret = cache[y][x];
    if(ret != -1) return ret;

    return ret = max(solution(y+1,x+1),solution(y+1,x))+board[y][x];
}

int main()
{
    for(int i=0; i<5; i++) {
        for(int j=0; j<=i; j++) {
            scanf("%d",&board[i][j]);
            cache[i][j] = -1;
        }
    }
    printf("%d\n",solution(0,0));
}
