#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    using namespace std;
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(),S.end()); // S をソートしておく
    cout << S << endl;
    long max_value = pow(10, N);
    int ans = 0;
    for (long i = 0; i * i < max_value; ++i) {
        string T = to_string(i * i);
        T.resize(N, '0'); // 桁数を揃える
        sort(T.begin(),T.end()); // ソートして
        if (S == T)
            ++ans; // 一致するか判定
    }
    cout << ans << endl;

    return 0;
}
