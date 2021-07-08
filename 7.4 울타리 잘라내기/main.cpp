#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define INF 1000000001
using namespace std;

int C,N;

int solution(vector < int > &h, int left, int right) {
    // ���ڰ� �ϳ��ۿ� ���°�� ������ ���߰� ����
    if(left == right) return h[left];
    // �� �������� ����
    int mid = (left + right) / 2;
    // [left, mid], [mid+1, right] �� ������ �����Ѵ�
    int ret = max(solution(h,left,mid), solution(h,mid+1,right));
    // ���ҵ� �κ��� �߾����� ������ ����,������ ������ ���� �ʱⰪ���� ���Ѵ�
    int low = mid, high = mid+1;
    int height = min(h[low],h[high]);
    ret = max(ret, height*2);

    // �߰� �� �簢������ �����Ѵ�
    while(left < low || high < right) {
        // �׻� ���̰� �� ���������� Ȯ���س�����

        // ������ ������ ���̰� �� ���ų�, ������ ���ٸ� ���̸� �������� �����ִٸ�
        if((h[low-1] < h[high+1] || low == left) && high < right) {
            high++;
            height = min(height,h[high]);
        }
        // �ݴ��� ���
        else {
            low--;
            height = min(height,h[low]);
        }
        // Ȯ��� �� �簢���� �ִ� ����
        ret = max(ret, height*(high-low + 1));
    }
    // ����� ��ȯ
    return ret;
}

int main()
{
    int num;
    scanf("%d",&C);
    for(int i=0; i<C; i++) {
        scanf("%d",&N);
        vector < int > h;
        for(int j=0; j<N; j++) {
            scanf("%d",&num);
            h.push_back(num);
        }
        int result = solution(h,0,N-1);
        printf("%d\n",result);
    }
}
