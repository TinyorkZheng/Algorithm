#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;;
// strcpy,strcmp,strcat
const int MAX_LENGTH = 110;
const int INF = 0x0fffffff;
 
struct Sequence{
    char str[MAX_LENGTH];
    int len, rep;
    
	void set(const char *istr, int ilen, int irep) 
	{
    	 strcpy(str, istr);
    	 len = ilen;
    	 rep = irep;
    }
     
    void build(Sequence ori) 
	{
        char strRep[MAX_LENGTH];
    	sprintf(strRep, "%d", ori.rep);
    	int strRepLen = strlen(strRep);
 
    	int foldLen = ori.len + strRepLen + 2, notFoldLen = ori.len * ori.rep;
    	bool needFold = foldLen < notFoldLen;
 
    	char strBuild[MAX_LENGTH] = { '\0' };
    	if (needFold) {
            sprintf(strBuild, "%d(%s)", ori.rep, ori.str);
        	set(strBuild, foldLen, 1);
	    } 
		else {
	        for (int i = 1; i <= ori.rep; ++i) 
                strcat(strBuild, ori.str);
        	set(strBuild, notFoldLen, 1);
    	}
	}
	
	void combine(Sequence a, Sequence b) 
	{
 	    if (strcmp(a.str, b.str) == 0)
           set(a.str, a.len, a.rep + b.rep);
    	else {
   	 	    Sequence l, r;
   	 		l.build(a);
     	 	r.build(b);
        	char str[MAX_LENGTH];
        	strcpy(str, l.str);
        	strcat(str, r.str);
        	set(str, l.len + r.len, 1);
   		}
	}  
};

Sequence seq[MAX_LENGTH][MAX_LENGTH];
 
int main() { 
    string ts; 
    cin >> ts;
    int len = ts.size();
    for (int i = 0; i < len; ++i) {
        char str[2] = {ts[i], '\0'};
        seq[i][i].set(str, 1, 1);
    }
 
    for (int subSeqLen = 1; subSeqLen < len; ++subSeqLen) {
        for (int start = 0; start < len - subSeqLen; ++start) {
            int end = start + subSeqLen;
            Sequence saveq;
            saveq.combine(seq[start][start], seq[start + 1][end]);
            for (int mid = start + 1; mid < end; ++mid) {
                Sequence tmp;
                tmp.combine(seq[start][mid], seq[mid + 1][end]);
                if (tmp.len < saveq.len || ((tmp.len == saveq.len) && (tmp.rep > saveq.rep))) {
                    saveq = tmp;
                }
            }
            seq[start][end] = saveq;
        }
    }
 
    Sequence res;
    res.build(seq[0][len - 1]);
    printf("%s\n", res.str);
   	return 0;
}
