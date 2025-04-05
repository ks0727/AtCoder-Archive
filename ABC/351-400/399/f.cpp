#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const long long MOD = 998244353;
long long modpow(long long base, int exp) {
    long long res = 1;
    base %= MOD;
    while(exp){
        if(exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<long long> P(N+1, 0);
    for (int i = 0; i < N; i++){
        P[i+1] = (P[i] + A[i]) % MOD;
    }
    
    vector<long long> arr(K+1, 0);
    arr[0] = 1;
    for (int t = 1; t <= K; t++){
        long long num = (K - t + 1);
        long long inv = modpow(t, MOD-2);
        arr[t] = (arr[t-1] * num) % MOD;
        arr[t] = (arr[t] * inv) % MOD;
    }
    vector<vector<long long>> m(K+1, vector<long long>(N+1, 0));
    for (int i = 0; i <= N; i++){
        m[0][i] = (i==0 ? 1 : (m[0][i-1] + 1) % MOD);
    }
    for (int d = 1; d <= K; d++){
        m[d][0] = 0; 
        for (int i = 1; i <= N; i++){
            long long power = modpow(P[i], d);
            m[d][i] = (m[d][i-1] + power) % MOD;
        }
    }
    long long S = 0;
    for (int j = 1; j <= N; j++){
        for (int t = 0; t <= K; t++){
            long long sign = (t % 2 == 0 ? 1 : MOD - 1);
            long long termP = modpow(P[j], K - t);
            long long add = sign;
            add = (add * arr[t]) % MOD;
            add = (add * termP) % MOD;
            add = (add * m[t][j-1]) % MOD;
            S = (S + add) % MOD;
        }
    }
    cout << S % MOD << "\n";
    return 0;
}
