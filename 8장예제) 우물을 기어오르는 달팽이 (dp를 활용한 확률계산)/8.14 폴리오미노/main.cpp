#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MOD 10000000
using namespace std;

int C,n;
// cache[총 조각 개수][첫 줄 조각 개수]
int cache[101][101];

int poly(int entire, int first) {
    if(entire == first) return 1;
    int &ret = cache[entire][first];
    if(ret != -1) return ret;

    ret = 0;
    for(int second = 1; second <= entire-first; second++) {
        ret += (first+second - 1) * poly(entire-first,second);
        ret %= MOD;
    }
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int c=0; c<C; c++) {
        scanf("%d",&n);
        memset(cache,-1,sizeof(cache));
        int result = 0;
        for(int i=1; i<=n; i++) {
            result += poly(n,i);
            result %= MOD;
        }
        printf("%d\n",result);
    }
}
