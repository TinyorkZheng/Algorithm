
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;;
const int inf = 0x3f;

int n,a[110];
int dp[110][110];
int main() 
{  
    cin >> n;
    for(int i=0;i<n;++i)
	    scanf("%d",&a[i]);
	// dp
	memset(dp,inf,sizeof(dp));
    for (int i=0;i<n-1;++i)
        dp[i][i + 1] = 0;
	for(int len=3;len<=n;++len){
		for(int i=0;i<n;++i){
		    int j=i+len-1;
		    if(j>n) break;
			// find a minimal state for dp[i][j]
			for(int k=i+1;k<j;++k)
				dp[i][j] =	min(dp[i][j], dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
		}	
	}
	
	cout << dp[0][n-1] << endl;
 //while(1);
   	return 0;
}
