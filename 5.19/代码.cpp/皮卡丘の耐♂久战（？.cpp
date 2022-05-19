#include<bits/stdc++.h>//看输出前：芭芭（拉）了这么多结果还是二维背包模板？

using namespace std;//看输出后：还要求出剩余体力？？

int n, a, b, p[105][105], h[105][105];
int w[105], v[105];

int main(){//短暂思考后：不还是模板题马
	cin >> a >> b >> n;
	for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for(int i = 1; i <= n; i++){
		for(int j = a; j >= w[i]; j--){
			for(int k = b; k >= v[i]; k--){
				if(p[j][k] < p[j - w[i]][k - v[i]] + 1){
					p[j][k] = p[j - w[i]][k - v[i]] + 1;
					h[j][k] = max(h[j][k], h[j - w[i]][k - v[i]] + v[i]);
				}
			}
		}
	}
	cout << p[a][b] << " ";
	for(int i = 1; i <= b; i++){
		if(p[a][i] == p[a][b]){
			cout << b - h[a][i];
			return 0;
		}
	}
	return 0;
}
/*10 100 5
7 10
2 40
2 50
1 20
4 20*/
