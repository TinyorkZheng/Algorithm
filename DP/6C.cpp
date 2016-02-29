/*
1=red,2=white,3=blue
--12=[i-1]
--21 
--32=[i-2]=-1-- 
--31      =-2--
*/
#include <cstdio>
const int MAX_N = 46;

long long int cnt[MAX_N];

int main() 
{ 
    int n;
    scanf("%d", &n);
    
    cnt[1] = cnt[2] = 2;
    for (int i = 3; i <= n; ++i)
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    
    printf("%lld\n", cnt[n]);
    return 0;
}
