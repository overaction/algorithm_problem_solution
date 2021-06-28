#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int C,H,W;

// 4가지 블록 type마다 (dy,dx)
int blockType[4][3][2] = {
    { {0,0}, {1,0}, {0,1} },
    { {0,0}, {0,1}, {1,1} },
    { {0,0}, {1,0}, {1,1} },
    { {0,0}, {1,0}, {1,-1} }
};

// board의 (y,x)를 type방법으로 덮거나, 덮었던 블록을 없앤다.
// 1. delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
// 2. 만약 블록이 제대로 덮이지 않은 경우 (범위 초과 / 겹침 / 검은 칸 차지) false 반환
bool setPossible(vector<vector<int> >&vboard, int y, int x, int type, int delta) {
    bool ok = true;
    for(int i=0; i<3; i++) {
        int ny = y + blockType[type][i][0];
        int nx = x + blockType[type][i][1];
        // false 반환하는 경우
        if(ny >=H || ny < 0 || nx >= W || nx < 0)
            ok = false;
        else if((vboard[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector <vector <int> > &vboard) {
    //아직 채우지 못한 칸 중 가장 왼쪽 위 칸을 찾는다
    int y = -1, x = -1;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(vboard[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }
    // 기저사례 : 남은 칸이 없다면 1 반환
    if(y == -1) {
        printf("complete\n");
        return 1;
    }
    int ret = 0;
    for(int type = 0; type<4; type++) {
        // type 형태의 블록으로 채울 수 있다면 재귀호출
        if(setPossible(vboard,y,x,type,1)) {
            ret += cover(vboard);
            printf("%d\n",ret);
        }
        // 채운 블록을 지움
        setPossible(vboard,y,x,type,-1);
    }
    // 방법이없으면 0 반환
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int i=0; i<C; i++) {
        int whiteCnt = 0;
        scanf("%d %d",&H,&W);
        vector < vector <int> > vboard(H, vector<int>(W,0));
        for(int j=0; j<H; j++) {
            string a;
            cin >> a;
            for(int k=0; k<W; k++) {
                if(a[k] == '#') vboard[j][k] = 1;
                else {
                    vboard[j][k] = 0;
                    whiteCnt++;
                }
            }
        }
        // 흰 칸의 개수가 3의배수라면 실행가능
        if(whiteCnt % 3 == 0) {
            int result = cover(vboard);
            printf("%d\n",result);
        }
        else {
            printf("0\n");
        }
    }
}
