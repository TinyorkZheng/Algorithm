#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[25];

int main()
{
	int n,k;
	cin >> n >> k;
	memset(dp,sizeof(dp),0);
	
	dp[1] = k-1;     // 1-9
	dp[2] = k*(k-1);  // (1-9)0 (1-9)(1-9)
	dp[3] = (k-1)*(k-1)*(k+1);
	 // (1-9)(0)(1-9) + (1-9)(1-9)(0-9) = 9*9*11
	for (int i=4; i<=n; ++i){
		dp[i] = dp[i-3]*(k-1)*(k-1)+dp[i-2]*(k-1);
	} 
	
	cout << dp[n] << endl; 
//	while(1);
	return 0;
}

