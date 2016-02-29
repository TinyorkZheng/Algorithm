#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100000;
const long long mod = 1000000007;
int sum[(N+10)<<2];
int m[N],ri[N],t[(N+10)<<2];

void push_r(int root){sum[root]=sum[root<<1]+sum[root<<1|1];}

void build(int l,int r,int root){
	if(r==l){ cin>>sum[root]>>m[l]>>ri[l];}
	int mid = (l+r)>>1;
	build(l,mid,root<<1);
	build(mid,r,root<<1|1);
	push_r(root);
}
void recover(int time,int L,int R,int l,int r,int root)
{
	if (l==r && l>=L && l<=R){
		int temp=(time-t[l])*ri[l];
		if (sum[root]+temp>m[l]) sum[root]=m[l];
			else sum[root]+=temp;
		return ;
	}
	int mid=(l+r)>>1;
	if (L<=mid) recover(time,L,R,l,mid,root<<1);
	if (R> mid) recover(time,L,R,mid+1,r,root<<1|1);
	push_r(root);

}
b
long long query(int L,int R,int l,int r,int root)
{
	if(L<=l&&R>=r) return sum[root];
	long long ans=0;
	int mid=(l+r)>>1;
	if(L<=mid) ans=query(L,R,l,mid,root<<1);
	if(R>mid) ans+=query(L,R,mid+1,r,root<<1|1);
	return ans;
}
void clea(int time,int L,int R,int l,int r,int root){
	if (l==r && l<=L && l<=R){

	}
	int mid = (l+r)>>1;
	if(L<=mid) clea(time,L,R,l,mid,root<<1);
	if(R> mid) clea(time,L,R,mid,r,root<<1|1);
	push_r(root);
}

int main()
{
	int n,tm,time,l,r;
	memset(t,0,sizeof(t));
	cin >> n;
	build(1,n,1);
	cin >> tm;
	long long ans=0;
	for(int i=0;i<tm;++i){
		cin >> time >> l >> r;
		recover(time,l,r,1,n,1);
		ans  = (ans+query(1,r,1,n,1))%mod;
		clea(time,l,r,1,n,1);
	}
	cout << ans << endl;
	return 0;
}
