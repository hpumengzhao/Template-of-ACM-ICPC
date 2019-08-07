#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
vector<int> G[N];
long long bit[30];
int f[N][30];
int depth[N];
void init(){
	bit[0]=1;
	for(int i=1;i<=29;i++) bit[i]=(bit[i-1]<<1);
}
void dfs(int u,int par){
	depth[u]=depth[par]+1;
	f[u][0]=par;
	for(int i=1;bit[i]<=depth[u];i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(v!=par) dfs(v,u);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	for(int i=29;i>=0;i--){
		if(depth[x]-depth[y]>=bit[i]){
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i=29;i>=0;i--){
		if(depth[x]>=(1<<i)&&f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
