#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    n--;
    for(int digit = 1;;digit++){
        int l = (digit+1)/2; //何個決めることができるか 例)6 -> 3, 5 -> 3
        ll num = 9; //numはその桁に何個あるか
        rep(i,l-1){ //最初は9でそれ以外10だから, 最初以外の分だけループを回す
            num *= 10;
        }
        if(n > num){
            n -= num;
            continue;
        }
        //ループを抜けていたら, それはその桁であるということ
        //nはその桁の何番目かという情報になっている
        // 1 : num/9
        //ただ, 最初は100..0からスタート
        //例えば, n = 1で digit = 6の時, 100になって欲しい, num = 900であるから 1 + 900/9 - 1で100となる, つまりnum/900 -1で下駄を履かせればいい
        n += num/9 -1;
        string s = to_string(n);
        string rs = s;
        reverse(rs.begin(),rs.end());
        if(digit %2 == 1) s.pop_back();
        s += rs;
        cout << s << endl;
        return 0;
    }
    return 0;
}