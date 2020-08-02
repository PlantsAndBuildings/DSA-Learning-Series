#include <vector>
#include <iostream>

#define DEBUG false

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

template<class T> class stack {
  private:
    vector<T> st;
  public:
    stack() {
    }

    void push(T elem) {
      this->st.push_back(elem);
    }

    void print() {
      for (ll i = 0; i < this->st.size(); i++) {
        cout << this->st[i] << " ";
      }
      cout << endl;
    }

    T pop() {
      if (!this->st.empty()) {
        T top_elem = *(this->st.end() - 1);
        this->st.pop_back();
        return top_elem;
      }
      throw "pop() called on empty stack!";
    }

    T top() {
      if (!this->st.empty()) {
        T top_elem = *(this->st.end() - 1);
        return top_elem;
      }
      throw "top() called on empty stack!";
    }

    ll size() {
      return this->st.size();
    }

    bool empty() {
      return this->st.empty();
    }
};

int main() {
  ll t;
  cin >> t;
  while (t--) {
    string l;
    cin >> l;
    stack<char> st;
    ll max_valid_prefix_len = 0;
    ll cur_valid = 0;
    for (int i = 0; i < l.length(); i++) {
      if (l[i] == '<') {
        st.push(l[i]);
        cur_valid ++;
      }
      else if (l[i] == '>' && !st.empty() && st.top() == '<') {
        cur_valid ++;
        st.pop();
        if (st.empty()) {
          max_valid_prefix_len += cur_valid;
          cur_valid = 0;
        }
      }
      else if (l[i] == '>' && st.empty()) {
        cur_valid = -1;
        break;
      }
      else if (l[i] == '>' && !st.empty() && st.top() == '>') {
        cur_valid = -1;
        break;
      }
#ifdef DEBUG
#if DEBUG
      st.print();
#endif
#endif
    }
    cout << max_valid_prefix_len << endl;
  }
}
