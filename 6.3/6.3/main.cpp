#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int friends[10][10];

int checkPair(bool isChecked[10], int N) {
    // ���� ����� �� ���� ��ȣ�� ���� �л��� ã�´�
    int firstFriend = -1;
    for(int i=0; i<N; i++) {
        if(!isChecked[i]) {
            firstFriend = i;
            break;
        }
    }
    // ���� ��� : ���� ¦�� ���� ���� ����� ������ ����� ã�����̹Ƿ� �����Ѵ�
    if(firstFriend == -1) return 1;
    int ret = 0;
    // ¦�� ���� ����� �����Ѵ�
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
            // ������ ģ���� �ٸ��ʵ� ģ����
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
