#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
// 광학 문자 인식

int m, q, n;
// 단어의 번호는 트릭을 사용해야하기 때문에 1부터 m까지
// 분류기 반환문장R을 단어의 번호로 변환.
int R[101];
double Begin[501];
double T[501][501], M[501][501];
double dp[101][502]; // 1로 초기화 : log(1) == 0
int choice[102][502];
string W[501];
void init() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m + 1; ++j)
			dp[i][j] = 1.0;
}
double dfs(int idx, int pre) {
	// 현재 idx에서 전 단어가 pre였을때 현재 단어를 선택할 때 구할 수 있는 최대 확률.

	// 모든 문장을 다 분석했을 때.
	if (idx == n)return 0;

	double&ret = dp[idx][pre];
	if (ret != 1.0)return ret;

	ret = -1e200; // log(0) == 음의 무한대

	int &choose = choice[idx][pre];

	for (int thisMatch = 1; thisMatch < m + 1; ++thisMatch) {
		// 'log값' 후보자. => 곱을 합으로.
		double cand = T[pre][thisMatch] + M[thisMatch][R[idx]] + dfs(idx + 1, thisMatch);

		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}
void dfs2(int idx, int pre) {
	if (idx == n)return;

	int choose = choice[idx][pre];

	cout << W[choose] << ' ';
	dfs2(idx + 1, choose);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> q;

	for (int i = 1; i < m + 1; ++i)
		cin >> W[i];

	for (int i = 1; i < m + 1; ++i) {
		cin >> Begin[i];

		Begin[i] = log(Begin[i]);
	}
	for (int i = 0; i < m + 1; ++i)
		for (int j = 1; j < m + 1; ++j) {
			if (i == 0)
				T[i][j] = Begin[j];

			else {
				cin >> T[i][j];

				T[i][j] = log(T[i][j]);
			}
		}
	for (int i = 1; i < m + 1; ++i)
		for (int j = 1; j < m + 1; ++j) {
			cin >> M[i][j];

			M[i][j] = log(M[i][j]);
		}
	while (q--) {
		cin >> n;
		init();
		for (int i = 0; i < n; ++i) {
			string tmp;
			cin >> tmp;
			// 단어 번호찾기
			for (int j = 1; j < m + 1; ++j)
				if (tmp == W[j]) {
					R[i] = j;
					break;
				}
		}
		dfs(0, 0);
		dfs2(0, 0);
		cout << '\n';
	}
	return 0;
}
