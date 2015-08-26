// time limit not use cin but scanf ... 
// 30*30=600 - 10^3
// floyd : 10^3 = 10^9 ?? 
// compute at depth
// directed,so (i,k) , in ith level

#include <cstdio>
#include <cstring>
const int  N = 35;
const long long MAX = 1111111;
int n, temp[N], s[N];
int pre, dis, ans;
int main()
{
	char ch;
	scanf("%d",&n); 
	s[0]=1;s[1]=0; 
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d", &k);
		temp[0] = k;
		for(int j=1;j<=k;j++) temp[j] = MAX;
		for(int j=1;j<=k;j++){
			while( scanf("%d",&pre) && pre){
				scanf("%d",&dis);
// printf("j=%d temp=%d pre=%d dist=%d",j,temp[j],s[pre],dis);
				if(temp[j]>s[pre]+dis)
					temp[j]=s[pre]+dis;
			}
		}
		if(i!=n) scanf(" %c",&ch);
		for(int j=0;j<=temp[0];j++)s[j]=temp[j];
	}
	// find min(s[1],...,s[ s[0] ]);
	ans = s[1];
	for(int i=2;i<=s[0];i++){ if(s[i]<ans) ans=s[i];}
	printf("%d\n", ans);
    return 0;
}

