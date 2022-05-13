#include<bits/stdc++.h>

using namespace std;

int n, m;
int dp[2005];
int ans;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int a, b, c, d;
		cin >> a;
		if(a == 1){
			cin >> b >> c;
			for(int j = m; j >= 1; j--){
				for(int k = 1; k <= j; k++){
					dp[j] = max(dp[j], dp[j - k] + b * k * k - c * k);
				}
			}
		}
		else if(a == 2){
			cin >> b >> c >> d;
			for(int j = m; j >= 1; j--){
				for(int k = 1; k <= d && k * c <= j; k++){
					dp[j] = max(dp[j], dp[j - k * c] + b * k);
				}
			}
		}
		else if(a == 3){
			cin >> b >> c;
			for(int j = c; j <= m; j++){
//				for(int k = 1; k * c <= j; k *= 2){
//					dp[j] = max(dp[j], dp[j - k * c] + b * k);
//				} 废掉的代码不要删，万一什么时候有用呢？（
				dp[j] = max(dp[j], dp[j - c] + b);
			}
		}
	}
	
	for(int i = 1; i <= m; i++)
		ans = max(ans, dp[i]);
	cout << ans;
	
	return 0;
}
