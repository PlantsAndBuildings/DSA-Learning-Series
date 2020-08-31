#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;


class mystack {
  private:
    ll sz;
    vi st;

  public:
    mystack() {
      sz = 0;
    }

    void push(ll elem) {
      st.push_back(elem);
      sz++;
    }

    ll top() {
      if (sz == 0) return NULL;
      return st.back();
    }

    ll pop() {
      if (sz == 0) return NULL;
      ll back = st.back();
      st.pop_back();
      sz --;
      return back;
    }

    bool empty() {
      return sz == 0;
    }

    void print() {
      for (ll i=0; i<sz; i++) {
        cout << st[i] << "-> ";
      }
      cout << endl;
    }
};

int main() {
  // test mystack implementation
  mystack s;
  ll n;
  cin >> n;
  ll max_depth = -1;
  ll max_match_len = -1;
  ll max_depth_idx = 0;
  ll max_match_len_idx = 0;
  vi seq;
  ll cur_depth = 0;
  ll cur_match_len = 0;
  for (ll i = 0; i<n; i++) {
    ll elem;
    cin >> elem;
    seq.push_back(elem);
    if (elem == 1) {
      cur_depth++;
      cur_match_len++;
      s.push(elem);
      if (cur_depth > max_depth) {
        max_depth = cur_depth;
        max_depth_idx = i;
      }
      if (cur_match_len > max_match_len) {
        max_match_len = cur_match_len;
        max_match_len_idx = i;
      }
    } else if (elem == 2) {
      if (s.empty()) {
        cout << "something went wrong. exiting" << endl;
        return -1;
      }
      s.pop();
      cur_match_len++;
      cur_depth--;
      if (cur_depth > max_depth) {
        max_depth = cur_depth;
        max_depth_idx = i;
      }
      if (cur_match_len > max_match_len) {
        max_match_len = cur_match_len;
        max_match_len_idx = i;
      }
      if (s.empty()) {
        cur_match_len = 0;
      }
    }
  }
  cout << max_depth << " " << max_depth_idx+1 << " " << max_match_len << " " << max_match_len_idx - max_match_len + 2 << endl;
  return 0;
}
