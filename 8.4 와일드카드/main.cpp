#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int C,N;
string W,S;

// -1 : 미계산 0 : 계산했지만 match 실패 1 : 계산했고 match 성공
int cache[101][101];
bool solution(int w, int s) {
    // 메모이제이션
    int &ret = cache[w][s];
    if(ret != -1) return ret;
    // 전부 같으면
    if(w == W.size() && s == S.size())
        return ret = 1;

    // 같으면 다음 문자 비교
    if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = solution(w+1,s+1);
    }

    // *일 경우 *에 몇 글자를 대응해야 할지 탐색한다
    // *에 아무런 글자도 대입하지 않고 넘어가는 경우 또는 한 글자 더 대응시키는 경우 두가지로 나뉜다
    if(W[w] == '*')
        if(solution(w+1,s) || (s < S.size() && solution(w,s+1)))
            return ret = 1;

    // 이 외의 경우는 실패
    return ret = 0;

}

int main()
{
    scanf("%d",&C);
    for(int i=0; i<C; i++) {
        vector < string > answer;
        cin >> W;
        scanf("%d",&N);
        for(int j=0; j<N; j++) {
            cin >> S;
            memset(cache,-1,sizeof(cache));
            if(solution(0,0) == 1) answer.push_back(S);
        }
        sort(answer.begin(),answer.end());
        for(int i=0; i<answer.size(); i++)
            printf("%s\n",answer[i]);
    }
}
