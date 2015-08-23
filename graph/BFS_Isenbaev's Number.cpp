// 1837. Isenbaev's Number
// bug : if no Isen in sample
// 以Isenbaev为根，建立树，从上而下建立，一旦赋值，则不可以再更改。
// 层次遍历，queue BFS
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

int n;
string team[100][3];
map<string,int> num;   // ans
queue<string> q;

int main()
{
	cin >> n;
	for(int i=0;i<n;++i){
		for(int j=0;j<3;++j){
			cin >> team[i][j];
			num[ team[i][j] ] = -1;
		}
	}
//  root
	if(num.find("Isenbaev")!=num.end()) {
		q.push("Isenbaev");
		num["Isenbaev"] = 0;
	}
	while(!q.empty()){
		string s = q.front();
	//	cout << num[s] <<"----" << s << endl;
		q.pop();
		// find teamate
		for(int i=0;i<n;++i){
			for(int j=0;j<3;++j){
				if(team[i][j]==s){
					// update i's teamate
					for(int k=0;k<3;++k){
						if(k!=j&&num[team[i][k]]==-1){
							num[team[i][k]] = num[s]+1;
							q.push(team[i][k]);
						}
					}
					break;
				}
			}
		}
	}
	for(map<string,int>::iterator it=num.begin(); it!=num.end();it++){
		cout << it->first  << " ";
		if(it->second != -1) cout << it->second << endl;
		else cout << "undefined" << endl;
	}
	return 0;
}     
