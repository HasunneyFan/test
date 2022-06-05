//不会写。。。偷分ing（我是蒟蒻
//忘了priority_queue的复杂度，估计偷不了多少分。。。（蒟蒻
#include<bits/stdc++.h>

using namespace std;

int n, a, b, cnt;
priority_queue<int> lst;

int main(){
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		lst.push(num);
	}
	
	while(1){
		int num = lst.top();
		if(cnt * a >= num){
			cout << cnt;
			return 0;
		}
		
		lst.pop();
		num -= b;
		lst.push(num);
		cnt++;
	}
	
	return 0;
}
