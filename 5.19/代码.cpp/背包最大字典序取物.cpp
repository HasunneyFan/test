#include<bits/stdc++.h>

using namespace std;

stack<int> lst;//讲个笑话，我开始debug以前以为queue是栈。。。直到20min过后。。。
int n, m, cnt;
int w[1005], v[1005], dp[1005][1005];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for(int i = 1; i <= n; i++){//逆序の逆序==正序（
		for(int j = 1; j <= m; j++){
			if(j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	int j = m;
	for(int i = n; i >= 1; i--){
		if(j >= w[i] && dp[i - 1][j] <= dp[i - 1][j - w[i]] + v[i]){//不知道为什么我用我“以为”正确的代码运行结果错误但是用我“以为”错误的代码样例就对了（？    此处从">="改成"<="了     依然不李姐         我李姐了（此时又过了10min     我怎么又不李姐了（做完第二题后再来看代码
			lst.push(i);
			j -= w[i];
		}
	}
	while(!lst.empty()){//存入的数再倒序输出
		cout << lst.top() << " ";
		lst.pop();
	}
	return 0;
}
/*
4 7
1 1
2 3
3 4
4 5
*/
