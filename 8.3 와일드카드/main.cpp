#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int C,N;
string W,S;
// ���ϰ� ���ڿ� �ϳ��ϳ� ������ ���踦 ����
int cache[101][101];

int solution(int w, int s) {
    // �޸������̼�
    int &ret = cache[w][s];
    if(ret != -1) return ret;

    // ���� �� ���ڿ��� ��ġ�Ѵٸ�
    if(W.size() == w && S.size() == s)
        return ret = 1;
    // ���� �����ȴٸ� �ϳ��� �����ؼ� ���ȣ��
    if(w < W.size() && s < S.size() && (W[w] == '?' || S[s] == W[w]))
        return ret = solution(w+1,s+1);
    // *�� �����ٸ�,
    // 1. *�� ������Ű�� ���� ���
    // 2. *�� �ϳ� �� ������ų ���
    if(W[w] == '*') {
        if(solution(w+1,s) || (s < S.size() && solution(w,s+1)))
            return ret = 1;
    }

    // �̿��� ���� false
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
