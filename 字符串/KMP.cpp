#include<bits/stdc++.h>

using namespace std;
string s,t;
vector<int> calpre(string s){
	int n=(int)s.length();
	vector<int> nxt(n);
	int i,j;
	for(i=1;i<n;i++){
		while(j>0&&s[j]!=s[i]) j=nxt[j-1];
		if(s[i]==s[j]) j++;
		nxt[i]=j;
	}
	return nxt;
}
int main(){
	cin>>s>>t;
	string now=t+'#'+s;
	int n=(int)s.length();int m=(int)t.length();
	vector<int> nxt=calpre(now);
	for(int i=m+1;i<n+m+1;i++){
		if(nxt[i]==m) printf("%d\n",i-2*m+1);
	}
	printf("%d", nxt[0]);
	for(int i=1;i<m;i++) printf(" %d",nxt[i]);
	return 0;
}
