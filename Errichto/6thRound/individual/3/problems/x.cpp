#include <bits/stdc++.h>

using namespace std;

const int N = 5043;

int p1[N];
int p2[N];
int p3[N];
int n, q;
int l[N], r[N];

int solve(int idx)
{
	memset(p1, 0, sizeof p1);
	for(int i = 0; i < q; i++)
	{
		if(i == idx) continue;
		p1[l[i]]++;
		p1[r[i]]--;
	}
	memset(p2, 0, sizeof p2);
	int c = 0;
	for(int i = 0; i < n; i++)
	{
		c += p1[i];
		p2[i] = c;
	}
	memset(p3, 0, sizeof p3);
	for(int i = 0; i < n; i++) {
		p3[i + 1] = p3[i] + (p2[i] == 1 ? 1 : 0);
        printf("pref[%d] = %d\n", i + 1, p3[i]);
    }
    printf("\n");
	int ans = -int(1e9);
	for(int i = 0; i < q; i++)
	{
		if(i == idx) continue;
		ans = max(ans, p3[l[i]] - p3[r[i]]);
	}
	for(int i = 0; i < n; i++)
		if(p2[i] > 0)
			ans++;
	return ans;
}

int main()
{
	cin >> n >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i];
		l[i]--;
	}
	int ans = 0;
	for(int i = 0; i < q; i++)
		ans = max(ans, solve(i));
	cout << ans << endl;
}
