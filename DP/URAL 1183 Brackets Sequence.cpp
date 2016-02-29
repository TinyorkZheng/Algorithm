#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;;
const int inf = 0xffff;
string s;
int dp[110][110],pos[110][110];

void DFSprint(int l,int r)
{
//cout << "print : " << l << " " << r << endl;
     if(l>r) return ;
     if(l==r){  
     // cout << "---> l==r:\n"; 
         if(s[l]=='('||s[l]==')') cout << "()" ;
         else cout << "[]" ;       
     }
     else if(pos[l][r]==-1){
	// cout << "---> pos[l]r]==-1\n";
         // l and r matched
         cout << s[l];
         DFSprint(l+1,r-1);
         cout << s[r];    
     }
     else{
	// cout << "--> inset k \n";
          //no print, only insert pos[l][r] 
          DFSprint(l,pos[l][r]);
          DFSprint(pos[l][r]+1,r);    
     }
}

int main() {  
    cin >> s ;
    memset(dp,inf,sizeof(dp));
    memset(pos,-1,sizeof(pos));
    int len = s.size();
    for(int i=0;i<len;++i)
        dp[i][i]=1,dp[i+1][i]=0;
    // dp
    /*
		for(int length=1; length<len; ++lenght)
			for(int start=0; start+length<len; ++start)
    */

    for(int i=len-2;i>=0;--i){
        for(int j=i+1;j<len;++j){
            dp[i][j]=len+1; // max
            if( (s[i]=='('&&s[j]==')') || (s[i]=='['&&s[j]==']'))
                dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
            // find a minimal state for dp[i][j],and k is the position
            for(int k=i;k<j;++k){
                if(dp[i][j] > dp[i][k]+dp[k+1][j]){
                    dp[i][j] =  dp[i][k]+dp[k+1][j];
                    pos[i][j] = k; 
                }   
            }
        }           
    }
    DFSprint(0,len-1);
    cout << endl;
     
    return 0;
}
