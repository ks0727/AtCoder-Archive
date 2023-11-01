#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
    }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
    vector<vector<char>  > chart(N,vector<char>(N));
    //表の初期化を行う(値を-にする)
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            chart.at(i).at(j) = '-';
        }
    }
    //勝敗の結果を代入する(添え字で-1をしているのは、A,Bは1以上の数が入るため)
    for(int i=0;i<M;i++){
        chart.at(A.at(i)-1).at(B.at(i)-1) = 'o';
        chart.at(B.at(i)-1).at(A.at(i)-1) = 'x';
    }
    //表を表示
    for(int i = 0;i<N;i++){
        for(int j =0;j<N;j++){
            cout << chart.at(i).at(j);
            if(j == N-1) cout << endl;
            else cout << " ";
        }
    }
}
