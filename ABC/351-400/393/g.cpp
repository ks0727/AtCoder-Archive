#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    const int MAXA = 1000000;
    vector<int> A(N);
    vector<int> freq(MAXA+1, 0);
    
    // 入力と各値の出現頻度の記録
    for (int i = 0; i < N; i++){
        cin >> A[i];
        freq[A[i]]++;
    }
    
    // cnt[d] = A の中で d で割り切れる要素の個数
    vector<int> cnt(MAXA+1, 0);
    for (int d = 1; d <= MAXA; d++){
        for (int m = d; m <= MAXA; m += d){
            cnt[d] += freq[m];
        }
    }
    
    // best[x] = x の約数 d の中で、cnt[d] >= K となる最大の d
    vector<int> best(MAXA+1, 0);
    // 降順に d を調べる。最初に更新される d が最大値になる。
    for (int d = MAXA; d >= 1; d--){
        if(cnt[d] >= K){
            for (int m = d; m <= MAXA; m += d){
                if(best[m] == 0)
                    best[m] = d;
            }
        }
    }
    
    // 各 A[i] に対して答えを出力
    for (int i = 0; i < N; i++){
        cout << best[A[i]] << "\n";
    }
    
    return 0;
}
