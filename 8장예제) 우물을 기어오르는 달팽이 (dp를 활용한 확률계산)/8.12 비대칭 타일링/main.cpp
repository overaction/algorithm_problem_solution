#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MOD 1000000007
using namespace std;

/*
    (��ü ����� �� - ��Ī Ÿ�ϸ��� ����� ��) �� ���� �ȴ�.
*/
int C,n;
int cache[101];
// tiling(n) = �ʺ� n�� �簢���� ä��� ����� �� ��ȯ
// ��ü Ÿ�ϸ� ����� ���� ��ȯ�Ѵ�.
int tiling(int width) {
    if(width <= 1) return 1;
    int &ret = cache[width];
    if(ret != -1) return ret;

    ret = (tiling(width-1) + tiling(width-2))% MOD;
    return ret;
}

// sameTiling(n) = �ʺ� n�� �簢������ ���Ī���� ä��� ����� ��
// ������� ������ ���� ���ɼ��� �ֱ� ������, �̸� MOD�� �����ְ� MOD ������ ���� �������� ����Ѵ�
int sameTiling(int width) {
    // width = Ȧ���� ���
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
