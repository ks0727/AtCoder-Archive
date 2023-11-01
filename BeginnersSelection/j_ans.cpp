#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int t_0 = 0;
    int x_0 = 0;
    int y_0 = 0;
    int t, x, y = 0;
    rep(i, N){
        int dt, dx, dy = 0;
        cin >> t >> x >> y;
        dt = abs(t - t_0);
        dx = abs(x - x_0);
        dy = abs(y - y_0);

    // 前の値の保持
        t_0 = t;
        x_0 = x;
        y_0 = y;

        // もし経過時間よりも移動距離の方が長かったらダメ
        if (dt < dx + dy){
        cout << "No" << endl;
        return 0;
        }

        // もし経過時間と距離の偶奇が違ったらダメ←これがポイント
        else if (dt % 2 != (dx + dy) % 2){
        cout << "No" << endl;
        return 0;
        }
    }

    // その他はOK
    cout << "Yes" << endl;
    }