#include <iostream>
#include <queue>

using std::cin;
using std::cout;

using std::queue;

char table[10][10];
int hx,hy;
int N,M;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct state;

queue<state> bfs;

struct state{
  int rx,ry,bx,by,cnt;
  state(int _rx,int _ry,int _bx,int _by,int _cnt){
    cnt=_cnt;
    rx = _rx;
    ry = _ry;
    bx = _bx;
    by = _by;
  }
  bool move(){
    int tx,ty;
    for (int i = 0; i < 4; i++) {
      /* 빨간공 */
      tx = rx;
      ty = ry;
      while(1){
        tx = tx + dx[i];
        ty = ty + dy[i];
        //안 움직
        if (tx < 1 || tx == N-1 || ty < 1 || ty == M-1)break;
        // 움직
        else{
          if(table[ty][tx]=='#')break;
          else if(table[ty][tx]=='O'){
          
          }if(table[ty][tx]=='B'){
          
          }

        }
      }
      /* 파란공 */
      tx = bx + dx[i];
      ty = by + dy[i];
      //안 움직
      if (tx < 1 || tx == N-1 || ty < 1 || ty == M-1);
      // 움직
      else{
        if(table[ty][tx]=='#');
        else if(table[ty][tx]=='O'){
        
        }if(table[ty][tx]=='R'){
        
        }
      
      }

    }
    cnt++;
    return false;
  }
};

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  int rx,ry,bx,by;

  /* Input */
  cin>>N>>M;
  cout<<N<<" "<<M<<"\n";
  for(int r=0;r<M;r++){
    for(int c=0;c<N;c++){
      cin>>table[c][r];
      switch(table[c][r]){
        case 'R': rx=r,ry=c;
          break;
        case 'B': bx=r,by=c;
          break;
        case 'O' :hx=r,hy=c;
          break;
      }
      cout<<table[c][r];
    }
  }
  /* test */
  for(int r=0;r<M;r++){
    for(int c=0;c<N;c++)
      cout<<table[c][r];
    cout<<"\n";
  }
  cout <<"R " << rx <<" "<<ry <<"\n";
  cout <<"B " << bx <<" "<<by <<"\n";
  cout <<"H " << hx <<" "<<hy <<"\n";

  /* Start State */
  bfs.push(state(rx,ry,bx,by,0));


  return 0;
}
