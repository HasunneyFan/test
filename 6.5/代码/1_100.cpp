#include<bits/stdc++.h>

using namespace std;

int n, m;
long long v1[1005], v2[1005], w[1005];
long long dp[1005];//数据吓人。。。但好像没那么大

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> v2[i] >> v1[i] >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 0; j--){
			if(j < w[i]) dp[j] = dp[j] + v2[i];
			else dp[j] = max(dp[j] + v2[i], dp[j - w[i]] + v1[i]);
		}
	}
	
	cout << dp[m] * 5ll;
	
	return 0;
}
/*
6 8
21 52 1
21 70 5
21 48 2
14 38 3
14 36 1
14 36 2
*/
