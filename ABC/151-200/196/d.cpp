#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  int ans = 0;
  set<vector<string> > st;
  auto f = [&](auto f,vector<string> board,int d)->void{
    //for(int i=0;i<h;i++){
      //for(int j=0;j<w;j++) cout << board[i][j];
      //cout << endl;
    //}
    //cout << "----------------" << endl;
    if(d == a){
      st.insert(board);
      return;
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(i!= h-1 && board[i][j] =='.' && board[i+1][j] == '.'){
          vector<string> nb = board;
          nb[i][j] = '0';
          nb[i+1][j] = '0';
          f(f,nb,d+1);
        }
        if(j != w-1 && board[i][j] == '.' && board[i][j+1] == '.'){
          vector<string> nb = board;
          nb[i][j] = '1'; nb[i][j+1] = '1';
          f(f,nb,d+1);
        }
      }
    }
  };
  vector<string> s;
  for(int i=0;i<h;i++) s.push_back(string(w,'.'));
  f(f,s,0);
  
  cout << st.size() << endl;
  return 0;
}

