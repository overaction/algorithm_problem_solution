#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int C,N;
string W,S;

// -1 : �̰�� 0 : ��������� match ���� 1 : ����߰� match ����
int cache[101][101];
bool solution(int w, int s) {
    // �޸������̼�
    int &ret = cache[w][s];
    if(ret != -1) return ret;
    // ���� ������
    if(w == W.size() && s == S.size())
        return ret = 1;

    // ������ ���� ���� ��
    if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = solution(w+1,s+1);
    }

    // *�� ��� *�� �� ���ڸ� �����ؾ� ���� Ž���Ѵ�
    // *�� �ƹ��� ���ڵ� �������� �ʰ� �Ѿ�� ��� �Ǵ� �� ���� �� ������Ű�� ��� �ΰ����� ������
    if(W[w] == '*')
        if(solution(w+1,s) || (s < S.size() && solution(w,s+1)))
            return ret = 1;

    // �� ���� ���� ����
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
