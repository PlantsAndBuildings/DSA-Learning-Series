#include <iostream>
#include <cassert>
#include <vector>


using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

int main() {
  lli t;
  cin >> t;
  while (t--) {
    lli n;
    cin >> n;
    vi s(n), p(n), v(n);
    vi pft(n);
    lli max_pft = -1;
    for (int i = 0; i < n; i++) {
      cin >>  s[i] >> p[i] >> v[i];
      pft[i] = (p[i]/(s[i] + 1))*v[i];
      max_pft = std::max(max_pft, pft[i]);
    }
    assert(max_pft != -1);
    cout << max_pft << endl;
  }
}
