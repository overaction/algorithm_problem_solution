#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int C,N,W;
int cache[101][1001];
vector <string> bag;
typedef struct info {
    int cap;
    int wish;
}info;
vector < info > vinfo;
vector < int > result;

// index 전 까지 골랐고, capacity만큼 용량이 차 있을 때 최대 절박도를 리턴
int solution(int index, int capacity) {
    // 기저사례 : 끝에 도달
    if(index == N) {
        return 0;
    }
    int &ret = cache[index][capacity];
    if(ret != -1) return ret;

    ret = 0;
    // 물건을 고르지 않았을 경우
    ret = max(ret, solution(index+1,capacity));
    // 물건을 골랐을 경우
    if(capacity + vinfo[index].cap <= W) {
        ret = max(ret, solution(index+1,capacity+vinfo[index].cap)+vinfo[index].wish);
    }
    return ret;
}

void choosing(int index, int capacity) {
    if(index == N) return;
    if(solution(index,capacity) == solution(index+1,capacity))
        choosing(index+1, capacity);
    else {
        result.push_back(index);
        choosing(index+1,capacity+vinfo[index].cap);
    }
}

int main()
{
    int a,b;
    string s;
    scanf("%d",&C);
    info ifo;
    for(int c=0; c<C; c++) {
        memset(cache,-1,sizeof(cache));
        scanf("%d %d",&N,&W);
        for(int i=0; i<N; i++) {
            cin >> s >> a >> b;
            bag.push_back(s);
            ifo.cap = a;
            ifo.wish = b;
            vinfo.push_back(ifo);
        }
        // 절박도 출력
        printf("%d ",solution(0,0));
        // 가져가는 물건의 개수 출력
        choosing(0,0);
        printf("%d\n",result.size());
        // 가져가는 물건 출력
        for(int i=0; i<result.size(); i++)
            cout << bag[result[i]] << endl;
        // 초기화
        bag.clear();
        result.clear();
        vinfo.clear();
    }
}
