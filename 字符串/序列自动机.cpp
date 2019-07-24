#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+100;
const int INF = 0x3f3f3f3f;
char s[N];
char t[N];
struct sub_AM{
	int nxt[N][27];
	void init(char *s){
		int l=strlen(s);
		for(int i=0;i<26;i++) nxt[l][i]=INF;
		for(int i=l-1;i>=0;i--){
			for(int j=0;j<26;j++){
				nxt[i][j]=nxt[i+1][j];
			}
			nxt[i][s[i]-'a']=i;
		}
	}
	bool find(char *t){
		int pos=-1;
		int l=strlen(t);
		for(int i=0;i<l;i++){
			pos=nxt[pos+1][t[i]-'a'];
			if(pos==INF) return 0;
		}
		return 1;
	}
}solve;
int main(){
	scanf("%s",s);
	solve.init(s);
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",t);
		if(solve.find(t)){
			puts("Yes");
		}
		else puts("No");
	}		
	return 0;
}
