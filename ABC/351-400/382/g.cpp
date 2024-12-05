#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_X = 5000; // 必要なレアカードの最大値
const double INF = 1e9; // 初期値として大きな値を設定

int main() {
    int N;  // 1パックあたりのカード数
    double X;  // 必要なレアカードの枚数
    cin >> N >> X;
    
    vector<double> p(N); // 各カードがレアである確率
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        p[i]/=100;
    }

    vector<double> dp(MAX_X + 1, INF); // dp配列
    dp[0] = 0.0; // レアカードが0枚必要な場合の期待値は0

    for (int x = 1; x <= X; ++x) {
        double expected = 0.0; // パックを1回開封したときの期待値計算
        for (int i = 0; i < (1 << N); ++i) { // 全てのパックの状態を列挙
            double prob = 1.0;
            int rareCount = 0;
            for (int j = 0; j < N; ++j) {
                if (i & (1 << j)) {
                    prob *= p[j]; // カードjがレアである確率
                    rareCount++;
                } else {
                    prob *= (1 - p[j]); // カードjがレアでない確率
                }
            }
            if (rareCount > 0 && x - rareCount >= 0) {
                expected += prob * dp[x - rareCount];
            }
        }
        dp[x] = expected + 1.0; // 自分の開封分を追加
    }

    cout << fixed << dp[(int)X] << endl; // 必要なレアカード X 枚の期待値を出力
    return 0;
}
