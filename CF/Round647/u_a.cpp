#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL getR(LL a){
	while(a % 2 == 0)
		a /= 2;
	return a;
}

void solve(){
	LL a, b;
	scanf("%lld %lld", &a, &b);
	if(a > b)	swap(a, b);
	
	LL r = getR(a);
	if(getR(b) != r){
		puts("-1");
		return;
	}
	
	int ans = 0;
	b /= a;
	
	while(b >= 8)
		b /= 8, ++ans;
	if(b > 1)	++ans;
	printf("%d\n", ans);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}
