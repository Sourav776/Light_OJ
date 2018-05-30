#include<bits/stdc++.h>
using namespace std;

int test, edge, N, ret;
int node[20007], arr[20007];
int a, b, st, t, last, vam, lyk;
vector<int> graph[20007], vis;

int color[20007];

void dfs(int u, int c)
{
    color[u] = c;
    for(int j = 0; j < graph[u].size(); j++){
        int v = graph[u][j];
        if(color[v] == -1){
            vis.push_back(v);
            ///cout << u << "->" << v << "->" << (c^1) << endl;
            dfs(v, c^1);
        }
    }
}

int main()
{

    scanf("%d", &test);

    while(test--){
        scanf("%d",&edge);
        N=0;
        for(int i=0; i < edge; i++){
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
            if(!arr[a]) node[N++] = a, arr[a] = 1;
            if(!arr[b]) node[N++] = b, arr[b] = 1;
        }

        ret = 0;
        for(int p = 0; p < N; p++) color[node[p]] = -1;

        for(int k = 0; k < N; k++){
            if(color[node[k]] == -1){
                vam=0, lyk=0;
                vis.push_back(node[k]);
                dfs(node[k], 0);
                for(int l = 0; l < vis.size(); l++){
                    if(color[vis[l]] == 0) vam++;
                    else lyk++;
                }
                ret += max(vam, lyk);
                ///cout << "vam = " << vam << " lyk = " << lyk << endl;
                vis.clear();
            }
        }

        printf("Case %d: %d\n", ++t, ret);

        for(int m = 0; m < N; m++){
            graph[node[m]].clear();
            arr[node[m]] = 0;
        }
    }

    return 0;
}

