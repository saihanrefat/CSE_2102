#include<bits/stdc++.h>
using namespace std;
const int maxn =100;
int front=0;
int rear =0;
int adj[maxn][maxn];
int queu[maxn];
int visit[maxn];
void bfs(int n,int start)
{
   queu[rear++]=start;
    visit[start]=1;
    while(front<rear)
    {
        int u=queu[front++];
        cout<<u<<" ";
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]==1 & visit[v] !=1)
            {
                queu[rear++]=v;
                visit[v]=1;
            }
        }
    }


}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
    }

    int start;
    cin>>start;
    bfs(n,start);

}
