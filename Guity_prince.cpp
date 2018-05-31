#include<bits/stdc++.h>
using namespace std;
int w,h,x,y,res;
char grid[21][21];
void dfs(int p,int q)
{
    res++;
    if(grid[p][q]=='#') return;
    if(p<0 || p>w || q<0 || q>h) return;
    grid[p][q]='#';
    dfs(p,q-1);
    dfs(p-1,q);
    dfs(p,q+1);
    dfs(p+1,q);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
       cin>>w>>h;
       for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> grid[i][j];
				if(grid[i][j] == '@') {
					x = i;
					y = j;
				}
			}
       }
       dfs(x,y);
       cout<<"Case "<<++cnt<<": "<<res<<endl;
       res=0;
    }
    return 0;
}
