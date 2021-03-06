#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

typedef vector <int> Cycle;

int n, p[N];
bool vis[N];
Cycle c;
vector <Cycle> cycles[N];

int ans[N];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--;
	
	for(int i = 0; i < n; i++) if(!vis[i])
	{
		c.clear();
		for(int j = i; !vis[j]; j = p[j])
		{
			vis[j] = 1;
			c.push_back(j);
		}
		
		if(c.size() & 1)
		{
			int d = (c.size() + 1) / 2;
			for(int j = 0; j < (int) c.size(); j++)
			{
				ans[c[j]] = c[(j + d) % c.size()];
			}
		}
		else
		{
			cycles[c.size()].push_back(c);
		}
	}
	
	for(int i = 2; i <= n; i += 2) if(cycles[i].size() > 0)
	{
		if(cycles[i].size() & 1)
		{
			puts("-1");
			return 0;
		}
		for(int j = 0; j < (int) cycles[i].size(); j += 2)
		{
			Cycle &c1 = cycles[i][j], c2 = cycles[i][j + 1];
			int sz = (int) cycles[i][j].size();
			for(int k = 0; k < sz; k++)
			{
				ans[c1[k]] = c2[k];
				ans[c2[k]] = c1[(k + 1) % sz];
			}
		}
	}
	
	for(int i = 0; i < n; i++) printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
	
	return 0;
}
