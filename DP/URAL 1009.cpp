#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[20][11];

int main()
{
	int n,k;
	cin >> n >> k;
	memset(dp,sizeof(dp),0);
	
	dp[0][0]=0;
	for (int i=1; i<=k; ++i)
		dp[0][i] = 1;
	
	for (int bit=1; bit<=n; ++bit){
		for (int base=0;base<k; ++base){
			for (int low_base=0; low_base<k; ++low_base){
				if(base==0&&low_base==0) continue;
				dp[bit][base] += dp[bit-1][low_base];
			}
		}
	} 
	
	int ans = 0;
	for(int i=0;i<=k;++i)
		ans += dp[n-1][i];
	cout << ans << endl; 
	while(1);
	return 0;
}

