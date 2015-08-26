/* tree : undirected
	connected -> DFS
	no cycle -> delete
vector<> add //need to add Edge(first,v[i]); 
for i in (0,n) :
	if(not col[i])  add.push_back(i); -> in output,check this
	dfs(i){ if(!visit[i]) : //stack implement
		for(u,v) : if(visit[v]) //back edge
			push(delete<edge>) or mark ans[i][j]='a'? 
	}		
}
bug in use stack ,try DFS....
DFS , topo?

*/

// just need to find d and a edges 
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

const int add_e = 2;
const int delete_e = 3;
const int ok_e = 4;

int n,d,a;
long long cost;
int m[110][110],go[110];

void printgo()
{
	cout << "   go : ";for(int i=0;i<n;++i)cout << go[i]<<" "; cout << endl;
}

void print()
{
	cout << "----------------print" << endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j) cout << m[i][j]  ;cout << endl;}
	cout << endl;
}

void DFS(int u,int c)
{
	for(int v=0;v<n;++v){
		if(m[u][v]==1){
//print();
			if(go[v]==0){
cout << "u v : " << u << " " << v << endl;
print();

				go[v]=c;
				m[u][v]=m[v][u]= ok_e;
				DFS(v,c);
			}
			else{
//cout << u << " "<< v <<endl;print();
				cost += d;
				m[u][v]=m[v][u]= delete_e;
			}
		}
	}
}

int main()
{
	cin >> n >> d >> a;	
	// init 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j) m[i][j]=0;
		go[i]=0;
	}
	// input
	for(int i=0;i<n;++i)  {
		string s;
		cin >> s;
		for(int j=0;j<n;++j) m[i][j]=(int)s[j]-'0';
// 0,1 --ans : 2 , 3 , 4
	}
	// find delete/back edge 
	int comp = 0; // conected component
	for(int i=0;i<n;++i){
		if(go[i]==0){
			comp++;
			go[i]=comp;
			DFS(i,comp); //get a component
		}
	}

	// find add edge,connect non-connect compont
	vector<bool> block(comp+1,false);
	block[go[0]]=true;
 
	for( int i=1;i<n;++i){
		if(go[i]!=go[0] && block[go[i]]==false ){ 
			m[i][0]=m[0][i]=add_e;
			cost += a;
			block[go[i]] = true;
		}
	}
	
	// print 
	cout << cost << endl;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(m[i][j]==add_e) cout << 'a';
			else if(m[i][j]==delete_e) cout << 'd';
			else cout << '0';
		}
		cout << endl;
	}
	return 0;
}
