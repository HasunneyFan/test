#include<bits/stdc++.h>

using namespace std;

struct siz{
	int x;
	int y;
	int cnt;//表示第几步
};

int t, n;
int _map[1005][1005];
bool yes;

int main(){
	cin >> t;
	for(int times = 1; times <= t; times++){
		cin >> n;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				_map[i][j] = 0x3f3f3f3f;
			}
		}
		yes = 0;//初始化
		
		for(int i = 1; i <= 2 * n - 2; i++){
			int x, y;
			cin >> x >> y;
			_map[x][y] = i;
		}//刷新map
		
		queue<siz> que;
		siz first = {1, 1, 0};
		que.push(first);//这也算初始化吧

		int changex[4] = {1, 0, -1, 0};
		int changey[4] = {0, 1, 0, -1};
		while(!que.empty()){//很普通的bfs
			siz sum = que.front();
			que.pop();
			if(sum.x == n && sum.y == n){
				cout << "Yes" << endl;
				yes = 1;
				break;
			}//成立则输出，结束此bfs
			
			for(int i = 0; i < 4; i++){
				sum.x += changex[i];
				sum.y += changey[i];
				sum.cnt += 1;
				if(sum.x >= 1 && sum.x <= n && sum.y >= 1 && sum.y <= n && sum.cnt <= _map[sum.x][sum.y]){
					que.push(sum);
					_map[sum.x][sum.y] = 0;
				}
			}
		}
		if(!yes) cout << "No" << endl;//不成立
	}
	return 0;
}
/*
	2
	
	2
	1 1
	2 2
	
	5
	3 3
	3 2
	3 1
	1 2
	1 3
	1 4
	1 5
	2 2
*/
