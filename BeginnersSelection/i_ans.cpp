#include<bits/stdc++.h>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string S;
    cin >> S;
    queue<int> BFS;
    bool can = false;
    BFS.push(0);
    while(!BFS.empty()){//キューが空になるまで続ける
        int t = BFS.front(); //tにはテェックした後の最初の文字の位置を入れる
        BFS.pop();//テェック済みの最初の文字の位置を削除
        if(t == S.size()){ // 最後まで切れたら成功
            can = true;
            break;
        }
        for(string s : divide){
            if(S.substr(t, s.size()) == s){ //切れたらとりあえず切ったことにしてみる
                BFS.push(t + s.size());
            }
        }
    }
    cout << (can ? "YES" : "NO") << endl;
    return 0;
}
