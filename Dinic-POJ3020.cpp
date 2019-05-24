#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;

//Dinic最大流, 节点编号从0开始 
struct MaxFlow{
    const static ll MAX_V = 1005;
    ll V;
    //终点、容量、反向边 
    struct edge{
        ll to, cap, rev;
    };
    vector<edge> G[MAX_V];
    ll level[MAX_V];//顶点到源点的距离标号 
    ll iter[MAX_V];// 当前弧，在其之前的边已经没有用了

    void add_edge(ll from, ll to, ll cap){
        G[from].push_back((edge){to, cap, (ll)G[to].size()});
        G[to].push_back((edge){from, 0, (ll)G[from].size()-1});
    } 

    // 通过BFS计算从源点出发的距离标号 
    void bfs(ll s){
        fill(level, level + V, -1);
        queue<ll> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()){
            ll v = que.front();
            que.pop();
            for (ll i=0; i< G[v].size(); i++){
                edge& e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    //通过DFS寻找增广路 
    ll dfs(ll v, ll t, ll f){
        if (v == t)
            return f;
        for (ll &i = iter[v]; i < G[v].size(); i++){
            edge& e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]){
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    //求解从s到t的最大流 
    ll max_flow(ll s, ll t){
        ll flow = 0;
        for (;;){
            bfs(s);
            if(level[t] < 0)
                return flow;
            fill(iter, iter + V, 0);
            ll f;
            while ((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
    }

    void init(ll n = 0){
        for (ll i = 0; i < V; i++){
            G[i].clear();
        }
        V = n;
    }
}mf;
char maze[100][100];
int id[100][100];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//bool vis[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",(maze[i]+1));
		}
		int num=0;
		int all=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				id[i][j]=++num;
				if(maze[i][j]=='*') all++;
			}
		}
		mf.init();
		mf.V=2*num+2;
		for(int i=1;i<=num;i++){
			mf.add_edge(0,i,1);
			mf.add_edge(i,0,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(maze[i][j]=='*'){
						for(int k=0;k<4;k++){
						int dx=i+dir[k][0];
						int dy=j+dir[k][1];
						if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
							if(maze[dx][dy]=='*'){
								mf.add_edge(id[i][j],id[dx][dy]+num,1);
								mf.add_edge(id[dx][dy]+num,id[i][j],0);
							}
						}
					}	
				}
			}
		}
		for(int i=1;i<=num;i++){
			mf.add_edge(i+num,num*2+1,1);
			mf.add_edge(num*2+1,i+num,0);
		}
		ll ans=mf.max_flow(0,2*num+1);
		printf("%lld\n",all-ans/2);
	}
	return 0;
} 
