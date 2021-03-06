/* Don’t Ask Woman about Her Age */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
string s;
vector<int> a;
int bit_max=0; // if k exit , then k-base is impoosible 

int main()
{
    cin >> s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]>='A'&&s[i]<='Z') a.push_back(10+s[i]-'A');                    
    	else a.push_back(s[i]-'0');    
        if(a[i]>bit_max) bit_max=a[i];
    } 
    if(bit_max<=1){
        cout << 2 << endl; // no 1-base solution
        return 0;
    } 
    for(int mod=bit_max; mod<=35; ++mod){            
    	int sum = a[0]%mod; // if b[0]>mod
    	int power=mod+1;
    	for(int b=1; b<a.size(); ++b){
    		sum = (sum+( (a[b]%mod)*(power%mod) )%mod) %mod;
    		power = power*power%mod;
    	} 
    	if(sum==0) {cout << mod+1 << endl; return 0;}
    }

	cout << "No solution." << endl;
         
	return 0;
}
