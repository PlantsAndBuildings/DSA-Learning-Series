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
    string shots;
    cin >> shots;
    assert(shots.length() == 2*n);

    lli a_rem = n;
    lli b_rem = n;
    lli a = 0;
    lli b = 0;
    lli known = -1;
    for (int i = 0; i < 2*n; i++) {
      if (i % 2 == 0) {
        a_rem--;
        if (shots[i] == '1') a++;
      }
      if (i%2 == 1) {
        b_rem--;
        if (shots[i] == '1') b++;
      }

      if (a > b_rem + b) {
        known = i+1;
        break;
      }

      if (b > a_rem + a) {
        known = i+1;
        break;
      }
    }
    if (known != -1) cout << known << endl;
    else cout << 2*n << endl;
  }
}
