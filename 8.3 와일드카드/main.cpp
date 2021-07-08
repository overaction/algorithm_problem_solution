#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int C,N;
string W,S;
// 패턴과 문자열 하나하나 사이의 관계를 저장
int cache[101][101];

int solution(int w, int s) {
    // 메모이제이션
    int &ret = cache[w][s];
    if(ret != -1) return ret;

    // 만약 두 문자열이 일치한다면
    if(W.size() == w && S.size() == s)
        return ret = 1;
    // 서로 대응된다면 하나씩 증가해서 재귀호출
    if(w < W.size() && s < S.size() && (W[w] == '?' || S[s] == W[w]))
        return ret = solution(w+1,s+1);
    // *을 만났다면,
    // 1. *에 대응시키지 않을 경우
    // 2. *에 하나 더 대응시킬 경우
    if(W[w] == '*') {
        if(solution(w+1,s) || (s < S.size() && solution(w,s+1)))
            return ret = 1;
    }

    // 이외의 경우는 false
    return ret = 0;
}

int main()
{
    scanf("%d",&C);
    for(int tc=0; tc<C; tc++) {
        vector <string> v;
        cin >> W;
        scanf("%d",&N);
        for(int i=0; i<N; i++) {
            cin >> S;
            memset(cache,-1,sizeof(cache));
            if(solution(0,0))
                v.push_back(S);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++)
            cout << v[i] << endl;
    }
}
