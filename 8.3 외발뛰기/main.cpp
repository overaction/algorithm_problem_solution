#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int cache[100][100];
int C,N;
int board[100][100];

void prin() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ",cache[i][j]);
        }
        printf("\n");
    }
}

int solution(int y, int x) {
    // 판을 벗어난 경우
    if(y >= N || x >= N) return 0;
    // 도착했을경우
    if(y == N-1 && x == N-1) return 1;
    // 메모이제이션
    int &result = cache[y][x];
    if(result != -1) return result;
    return result = (solution(y + board[y][x],x) || solution(y,x+board[y][x]));
}

int main()
{
    scanf("%d",&C);
    for(int i=0;i<C;i++) {
        scanf("%d",&N);
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                scanf("%d",&board[j][k]);
                cache[j][k] = -1;
            }
        }
        printf("%d\n",solution(0,0));
        printf("\n");
        prin();
    }
}
