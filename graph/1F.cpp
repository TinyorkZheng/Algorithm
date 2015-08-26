#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;  
const int N=110; 
const int INF=21460000;
struct edge{
    int x,y,c;
    bool operator < (const edge& a)const {
        return c<a.c;
    }
}e[N*N];
int n,k;
int Index[N],fa[N],mat[N][N];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main()
{
    int x,y,ans,cnt;
    cin >> n >> k;
    memset(Index,0,sizeof(Index));
    for(int i=0;i<k;i++){
        cin >> x;
        Index[x]=1;
    }
    k=2;
    for(int i=1;i<=n;i++){
        if(Index[i])continue;
        Index[i]=k++;
    }
    memset(mat,INF,sizeof(mat));
    for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             int tcost; cin >> tcost;
             mat[Index[i]][Index[j]]=min(mat[Index[i]][Index[j]],tcost);
         }
    }
    cnt=0;
    for(int i=1;i<k;i++){
        for(int j=i+1;j<k;j++){
            e[cnt].x=i;e[cnt].y=j;e[cnt++].c=mat[i][j];
	}
    }
    sort(e,e+cnt);
// for(int i=0;i<cnt;++i) printf("%d %d %d \n",e[i].u,e[i].v,e[i].val );
// printf("\n");
    ans=0;
    for(int i=1;i<k;i++)fa[i]=i;
    for(int i=0;i<cnt;i++){
	int l,r;
        l=find(e[i].x);r=find(e[i].y);
        if(l!=r){
            fa[r]=l;
            ans+=e[i].c;
        }
    }
    cout << ans << endl;
    return 0;
}
