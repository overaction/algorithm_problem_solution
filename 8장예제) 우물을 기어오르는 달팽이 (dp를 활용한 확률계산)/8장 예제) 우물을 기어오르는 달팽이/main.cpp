#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 987654321
using namespace std;
int C,n,m;
double cache[2002][1001];

double climbing(int climbed, int days) {
    if(days <= m && climbed >= n) return 1;
    if(days == m && climbed < n) return 0;
    double &ret = cache[climbed][days];
    if(ret != -1.0) return ret;
    ret = 0.25*climbing(climbed+1,days+1) + 0.75*climbing(climbed+2,days+1);
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int i=0; i<C; i++) {
        for(int j=0; j<2002; j++)
            for(int k=0; k<1001; k++)
                cache[j][k] = -1;
        scanf("%d %d",&n,&m);
        printf("%lf\n",climbing(0,0));
    }
}
