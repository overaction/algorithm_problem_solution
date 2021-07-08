#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define INF 1000000001
using namespace std;

int C,N;

int solution(vector < int > &h, int left, int right) {
    // 판자가 하나밖에 없는경우 분할을 멈추고 종료
    if(left == right) return h[left];
    // 두 구간으로 분할
    int mid = (left + right) / 2;
    // [left, mid], [mid+1, right] 두 범위로 분할한다
    int ret = max(solution(h,left,mid), solution(h,mid+1,right));
    // 분할된 부분을 중앙으로 가지는 왼쪽,오른쪽 판자의 합을 초기값으로 정한다
    int low = mid, high = mid+1;
    int height = min(h[low],h[high]);
    ret = max(ret, height*2);

    // 중간 두 사각형부터 진행한다
    while(left < low || high < right) {
        // 항상 높이가 더 높은쪽으로 확장해나간다

        // 오른쪽 판자의 높이가 더 높거나, 왼쪽이 막다른 곳이며 오른쪽이 열려있다면
        if((h[low-1] < h[high+1] || low == left) && high < right) {
            high++;
            height = min(height,h[high]);
        }
        // 반대의 경우
        else {
            low--;
            height = min(height,h[low]);
        }
        // 확장된 후 사각형의 최대 넓이
        ret = max(ret, height*(high-low + 1));
    }
    // 결과값 반환
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
