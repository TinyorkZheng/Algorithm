/*动态规划
    因为是图论作业，所以I最初想到的是最短路，但是图怎么存？图的最短路需要保存可以经过的点(n*m个点10^6)，肯定爆了，不可能只保存交叉点。果断放弃。
考虑用DP
    设当前在(i+1,j+1)表示到达这个点的最短距离。可以到达这里的点有三个。
则(i+1,j+1)=min( (i+1,j)+1，(i,j+1)+1，(i,j)+sqrt(2) ) -> 如果有交叉线。
初始状态是矩阵左边 和下边的边界，即(0,i)=(i,0)=i
    思考，假设从行开始遍历，再求出到达该行的每一列的距离，则这里当i+1行求出来后，i就没用了.
  所以每次只需要维护到达所有列的最短距离就可以了。
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int n,m,k; // n is col and m is row
	cin >> n >> m >> k;

	vector<vector<bool> > has(m+1,vector<bool>(n+1));
	for (int i=0; i<k; ++i){
		int r,c;
		cin >> c >> r; // (x.y)
		has[r][c] = 1;
	}	
	vector<double> d(n+1,0.0);
	for (int i=0; i<=n; ++i) d[i]=(double)i;

	for (int r=1; r<=m; ++r) {// row
// start at [r,0]->[r+1,0]
/*cout << r << " : "; 
for(int i=0;i<=n;++i) cout << d[i] <<" "; 
cout << endl;	*/
		double NOupdate = d[0];
		d[0] += 1.0; 
		for (int c=1; c<=n; ++c){
			double save = d[c];
			if(has[r][c]) d[c]=NOupdate+sqrt(2);
			else d[c]=min(d[c-1],d[c])+1;
			NOupdate = save;
		}
	}
	cout << (int)(d[n]*100+0.5) << endl;
	return 0;
}

