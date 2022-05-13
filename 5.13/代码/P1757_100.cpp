#include<bits/stdc++.h>

using namespace std;

int n, m, ans;
int w[1005][1005];
int v[1005][1005];
int c[1005];
int dp[1005];
int cnt;

int main(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		w[z][++c[z]] = x;
		v[z][c[z]] = y;
		cnt = max(cnt, z);
	}
	
	for(int i = 1; i <= cnt; i++)
		for(int j = m; j >= 1; j--)
			for(int k = 1; k <= c[i]; k++)
				if(j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
	
	for(int i = 1; i <= m; i++)ans = max(ans, dp[i]);
	cout << ans;
	
	return 0;
}//不打注释の代码.jpg
