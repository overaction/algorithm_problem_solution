#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int C,H,W;

// 4���� ��� type���� (dy,dx)
int blockType[4][3][2] = {
    { {0,0}, {1,0}, {0,1} },
    { {0,0}, {0,1}, {1,1} },
    { {0,0}, {1,0}, {1,1} },
    { {0,0}, {1,0}, {1,-1} }
};

// board�� (y,x)�� type������� ���ų�, ������ ����� ���ش�.
// 1. delta = 1�̸� ����, -1�̸� ������ ����� ���ش�.
// 2. ���� ����� ����� ������ ���� ��� (���� �ʰ� / ��ħ / ���� ĭ ����) false ��ȯ
bool setPossible(vector<vector<int> >&vboard, int y, int x, int type, int delta) {
    bool ok = true;
    for(int i=0; i<3; i++) {
        int ny = y + blockType[type][i][0];
        int nx = x + blockType[type][i][1];
        // false ��ȯ�ϴ� ���
        if(ny >=H || ny < 0 || nx >= W || nx < 0)
            ok = false;
        else if((vboard[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector <vector <int> > &vboard) {
    //���� ä���� ���� ĭ �� ���� ���� �� ĭ�� ã�´�
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
    // ������� : ���� ĭ�� ���ٸ� 1 ��ȯ
    if(y == -1) {
        printf("complete\n");
        return 1;
    }
    int ret = 0;
    for(int type = 0; type<4; type++) {
        // type ������ ������� ä�� �� �ִٸ� ���ȣ��
        if(setPossible(vboard,y,x,type,1)) {
            ret += cover(vboard);
            printf("%d\n",ret);
        }
        // ä�� ����� ����
        setPossible(vboard,y,x,type,-1);
    }
    // ����̾����� 0 ��ȯ
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
        // �� ĭ�� ������ 3�ǹ����� ���డ��
        if(whiteCnt % 3 == 0) {
            int result = cover(vboard);
            printf("%d\n",result);
        }
        else {
            printf("0\n");
        }
    }
}
