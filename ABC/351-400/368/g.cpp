#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int compute_grundy_number(int n) {
    if (n == 1) {
        return 0;
    }
    set<int> factors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n / i);
        }
    }
    factors.erase(n);
    
    int mex = 0;
    while (factors.find(mex) != factors.end()) {
        ++mex;
    }
    return mex;
}

string find_winner(int N, vector<int>& A) {
    int xor_sum = 0;
    for (int i = 0; i < N; ++i) {
        xor_sum ^= compute_grundy_number(A[i]);
    }
    return xor_sum != 0 ? "Anna" : "Bruno";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cout << find_winner(n, a) << endl;
    return 0;
}
