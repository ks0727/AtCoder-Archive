#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
// ダブリングの最大ビット数
const int MAX_LOG = 60;

int main() {
    int N; long long K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--; // 0-indexedに変換
    }

    // ダブリングテーブルの準備
    vector<vector<int>> doubling(MAX_LOG, vector<int>(N));
    for (int i = 0; i < N; i++) {
        doubling[0][i] = P[i];
    }
    // ダブリングテーブルの構築: doubling[k][i] は i 番目の要素を 2^k 回操作した後の位置
    for (int k = 1; k < MAX_LOG; k++) {
        for (int i = 0; i < N; i++) {
            doubling[k][i] = doubling[k - 1][doubling[k - 1][i]];
        }
    }
    for(int s=0;s<60;s++){
        rep(i,N) cout << doubling[s][i] << ' '; cout << endl;
    }
    // 初期の順列 P に対して K 回操作後の位置を計算
    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        int pos = i;
        for (int k = 0; k < MAX_LOG; k++) {
            if (K & (1LL << k)) { // K の k ビット目が 1 のとき
                pos = doubling[k][pos];
            }
        }
        result[i] = pos + 1; // 1-indexedに戻す
    }

    // 結果の出力
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
