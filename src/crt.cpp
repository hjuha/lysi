#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll pot(const ll n, const ll k, const ll m) {
	if (!k) return 1;
	if (k & 1) return (n * pot(n, k - 1, m)) % m;
	ll u = pot(n, k / 2, m);
	return (u * u) % m;
}

ll inv(const ll a, const ll n) {
	return pot(a % n, n - 2, n);
}

ll crt(vector<ll> a, vector<ll> m, ll p) {
	int n = a.size();
	ll x = 0;
	ll X = 1;
	for (ll k : m) {
		X *= k;
		X %= p;
	}
	for (int i = 0; i < n; i++) {
		ll t = (a[i] * X / m[i]) % p;
		t *= inv(X / m[i], m[i]);
		x += t;
		x %= p;
	}
	return x;
}

int main() {
	cout<<crt({3, 4, 2}, {5, 7, 3}, 1000000007)<<endl;
}