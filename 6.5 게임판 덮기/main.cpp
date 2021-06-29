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

bool canCover(vector < vector < int > > &vboard, int y, int x, int type, int delta) {
    bool ok = true;
    for(int i=0; i<3; i++) {
        int ny = y + blockType[type][i][0];
        int nx = x + blockType[type][i][1];
        if(ny >= H || ny < 0 || nx >= W || nx < 0) ok = false;
        else if((vboard[ny][nx] += delta) > 1) ok = false;
    }
    return ok;
}

int coverBoard(vector < vector < int > > &vboard) {
    int y = -1, x = -1;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(vboard[i][j] == 0) {
                y = i, x = j;
                break;
            }
        }
        if(x != -1) break;
    }
    // 모두 채웠음
    if(x == -1) return 1;

    int ret = 0;
    for(int type = 0; type < 4; type++) {
        if(canCover(vboard,y,x,type,1))
            ret += coverBoard(vboard);
        canCover(vboard,y,x,type,-1);
    }
    return ret;
}

int main() {
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        scanf("%d %d",&H,&W);
        vector < vector < int > > vboard(H, vector<int>(W,0));
        int zeroCnt = 0;
        for(int i=0; i<H; i++) {
            string s;
            cin >> s;
            for(int j=0; j<W; j++) {
                if(s[j] == '#') vboard[i][j] = 1;
                else zeroCnt++;
            }
        }
        if(zeroCnt % 3 == 0) {
            int result = coverBoard(vboard);
            printf("%d\n",result);
        }
        else printf("0\n");
    }
}
