#include <iostream>
#include <vector>

#define INF 1000000000+11

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vi s(n);
    for (ll i = 0; i < n; i++) cin >> s[i];
    vi g(n, INF);
    for (ll i = 0; i < n; i++) {
      if (i == 0) g[i] = s[i];
      else {
        g[i] = min(g[i-1], s[i]);
      }
    }
    ll cur = g[n-1];
    ll ans = n * g[n-1];
    for (ll i = n-2; i >= 0; i--) {
      if (g[i] != cur) {
        ans += (g[i] - g[i+1])*(i+1);
      }
    }
    cout << ans << endl;
  }
}
