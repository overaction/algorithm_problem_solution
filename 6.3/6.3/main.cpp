#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int friends[10][10];

int checkPair(bool isChecked[10], int N) {
    // 남은 사람들 중 가장 번호가 빠른 학생을 찾는다
    int firstFriend = -1;
    for(int i=0; i<N; i++) {
        if(!isChecked[i]) {
            firstFriend = i;
            break;
        }
    }
    // 기저 사례 : 만약 짝을 지을 남은 사람이 없으면 방법을 찾은것이므로 종료한다
    if(firstFriend == -1) return 1;
    int ret = 0;
    // 짝을 지을 사람을 결정한다
    for(int next = firstFriend + 1; next < N; next++) {
        if(!isChecked[next] && friends[firstFriend][next]) {
            isChecked[next] = isChecked[firstFriend] = 1;
            ret += checkPair(isChecked,N);
            isChecked[next] = isChecked[firstFriend] = 0;
        }
    }
    return ret;
}

int main()
{
    int c,n,m;
    scanf("%d",&c);
    for(int j=0; j<c; j++) {
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            // 한쪽이 친구면 다른쪽도 친구다
            friends[a][b] = 1;
            friends[b][a] = 1;
        }
        bool isChecked[10];
        int result = checkPair(isChecked,n);
        printf("%d\n",result);
        for(int l=0; l<10; l++)
            for(int k=0; k<10; k++)
                friends[l][k] = 0;
    }
}
