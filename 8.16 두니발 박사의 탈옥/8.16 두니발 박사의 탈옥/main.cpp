#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int C,N,D,P,T,Q;

int village[51][51], counts[51];
// cache[마을 번호][날짜]
double cache[51][101];

/* 완전탐색
double allSearch(vector < int > &path) {
    // 날짜에 도달했다면
    if(path.size() == D+1) {
        // 도착을 제대로 한 경우
        if(path.back() == Q) {
            double result = 1.0;
            for(int i=0; i+1<path.size(); i++) {
                int next = counts[path[i]];
                result /= next;
            }
            return result;
        }
        else return 0;
    }
    double ret = 0;
    for(int i=0; i<N; i++) {
        // 마지막 지점과 연결되어있다면
        if(village[path.back()][i]) {
            path.push_back(i);
            ret += allSearch(path);
            path.pop_back();
        }
    }
    return ret;
}
*/

// 현재 위치에 있고 해당 날짜일 때 마지막날 도달 시 확률 반환
double searching(int now, int day) {
    // 기저사례 : 마지막 날 도달 시
    if(day == D) {
        if(now == Q) return 1;
        else return 0;
    }
    double &ret = cache[now][day];
    if(ret != -1.0) return ret;

    ret = 0.0;
    for(int i=0; i<N; i++) {
        if(village[now][i])
            ret += (searching(i,day+1)/counts[now]);
    }
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        scanf("%d %d %d",&N,&D,&P);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%d",&village[i][j]);
                if(village[i][j]) counts[i]++;
            }
        }
        scanf("%d",&T);
        for(int i=0; i<T; i++) {
            for(int i=0; i<51; i++)
                for(int j=0; j<101; j++)
                    cache[i][j] = -1.0;
            scanf("%d",&Q);
            printf("%lf ",searching(P,0));
        }
        printf("\n");
        memset(counts,0,sizeof(counts));
    }
}
