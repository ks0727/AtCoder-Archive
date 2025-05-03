#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000000;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    int init = min(k, n+1);
    for (int i = 0;i<init;i++) a[i] = 1;
    
    if(n <k) {
        cout << 1 << "\n";
        return 0;
    }
    int window = 0;
    for (int i = 0; i < k; i++){
        window = (window + a[i]) % MOD;
    }
    for (int i = k; i <= n; i++){
        a[i] = window;
        window = ( (window + a[i]) % MOD - a[i-k] + MOD ) % MOD;
    }
    cout << a[n] << "\n";
    return 0;
}

