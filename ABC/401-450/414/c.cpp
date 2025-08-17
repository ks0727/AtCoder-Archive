#include <iostream>
#include<vector>
using namespace std;

int pow(int a,int b){
  long long res = 1;
  for(int i=0;i<b;i++) res *= a;
  return res;
}

bool isp(long long x, int a){
  string y = "";
  while(x){
    y += char(x%a+'0');
    x /= a;
  }
  string z = y;
  reverse(y.begin(),y.end());
  return z==y;
}

int main(){
  int a;
  cin >> a;
  long long n;
  cin >> n;
  vector<string> ps;
  for(int i=1;i<=12;i++){ //12桁までの回文(10進数)を全て求める
    if(i%2 == 1){//奇数の時は真ん中はなんでもいい
      if(i == 1){
        for(int j=1;j<=9;j++) ps.push_back(to_string(j));
      }else{
        int n_side = (i-1)/2;
        for(int j=pow(10,n_side-1);j<pow(10,n_side);j++){
          string a = to_string(j);
          string b = a; reverse(b.begin(),b.end());
          for(int k=0;k<=9;k++){
            string now = a + to_string(k) + b;
            ps.push_back(now);
          }
        }
      }
    }else{
      for(int j=pow(10,i/2-1);j<pow(10,i/2);j++){
        string a = to_string(j);
        string b = a; reverse(b.begin(),b.end());
        ps.push_back(a+b);
      }
    }
  }
  vector<long long> x;
  for(int i=0;i<ps.size();i++) x.push_back(stoll(ps[i]));
  long long ans = 0;
  for(int i=0;i<x.size();i++){
    if(x[i] > n) continue;
    if(isp(x[i],a)) ans += x[i];
  }
  cout << ans << endl;
  return 0;
}

