#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
const int N = 1000;
struct edge{
	int v,w,nxt;
}e[N<<1];
int head[N];
bool vis[N];
int cnt;
void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w){
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}
struct node{
	int v;
	int id;
}pre[N];
bool bfs(int s,int t){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	q.push(s);vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i+1;i=e[i].nxt){
			int v=e[i].v;
			int w=e[i].w;
			if(!vis[v]&&w){
				vis[v]=1;
				pre[v].id=i;
				pre[v].v=u;
				if(v==t) return 1;//存在增广路
				q.push(v); 
			}
		}
	}
	return false;
}
int EK(int s,int t){
	int ans=0;
	while(bfs(s,t)){
		int minn=0x7f7f7f7f;
		for(int i=t;i!=s;i=pre[i].v){
			minn=min(minn,e[pre[i].id].w);
		}
		for(int i=t;i!=s;i=pre[i].v){
			e[pre[i].id].w-=minn;
			e[pre[i].id^1].w+=minn;
		}
		ans+=minn;
	}
	return ans;
}
int main(){
	int n,m;
	while(cin>>m>>n){
		init();
		int a,b,c;
		for(int i=1;i<=m;i++){
			cin>>a>>b>>c;
			addedge(a,b,c);
			addedge(b,a,0);
		}
		cout<<EK(1,n)<<endl;
	}
	return 0;
}