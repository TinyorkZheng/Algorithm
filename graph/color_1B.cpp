//  Two Teams
// 一群人分成两个组，要求每一组的每个成员和另一个组有关系。输出第一个组的人。
// 分类，用染色
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> v[110];
int ans=0; // people in group 1 

int main()
{
	cin >> n;
	for(int i=1;i<=n;++i){
		int j;
		while(cin>>j && j) v[i].push_back(j);
		if(v[i].size()==0) {cout << 0 << endl; return 0;}
	}
	queue<int> q;
	vector<int> group(n+1,-1); 
	// -1 no visit,1 in group1, 2 group 2
	for(int i=1;i<=n;++i){
		if(group[i]!=-1) continue;
		group[i]=1;
		q.push(i);
		while(!q.empty()){
			ans++ ;
			int cur = q.front();
			q.pop();
			for(int f=0;f<v[i].size();++f){ // find friend
				if(group[v[i][f]]==-1) group[v[i][f] ]=3-group[cur]; 	
			}
		}
	}
	cout << ans << endl;
	for(int i=1;i<=n;++i){
		if(group[i]==1){
			ans--;
			cout << i ;
			if(ans) cout<< " ";
		}
	}	
	cout << endl;
	return 0;
}

