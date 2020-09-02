#define MAX_N 100

#include <stdio.h>

#include <queue>
#include <utility>

#define BIG 99999

using std::queue;
using std::pair;
using std::make_pair;

int main(){
  int tc;
  int n;
  int x,y;

 scanf("%d", &tc);

 int map[MAX_N][MAX_N];
 int path[MAX_N][MAX_N]={BIG,};
 char temp_char;
 int ans=0;

 queue<pair<int,int>> q;

 for(int i=0;i<tc;i++){
  //input
  scanf("%d",&n);
  scanf("%c",&temp_char);
  for(int j=0;j<n;j++){
    for(int k=0;k<n;k++){
      scanf("%c",&temp_char);
      map[j][k]=int(temp_char)-48;
    }
      scanf("%c",&temp_char);
  }

  //init
  for(int j=0;j<n;j++){
    for(int k=0;k<n;k++){
      path[j][k]=BIG;
    }
  }
  // start
  x=0;
  y=0;
  path[x][y]=0;
  q.push(make_pair(x,y+1));
  path[x][y+1]=map[x][y+1];
  q.push(make_pair(x+1,y));
  path[x+1][y]=map[x+1][y];
  
  //process
  while(!q.empty()){
     pair<int,int> t = q.front();
     q.pop();
     x = t.first;
     y = t.second;

     //up
     if(y!=0){
       if(path[x][y-1]>path[x][y]+map[x][y-1]){
         path[x][y-1] = path[x][y]+map[x][y-1];
         q.push(make_pair(x,y-1));
       }
     }
     //down
     if(y!=n-1){
       if(path[x][y+1]>path[x][y]+map[x][y+1]){
         path[x][y+1] = path[x][y]+map[x][y+1];
         q.push(make_pair(x,y+1));
         }
     }
     //left
     if(x!=0){
       if(path[x-1][y]>path[x][y]+map[x-1][y]){
         path[x-1][y] = path[x][y]+map[x-1][y];
         q.push(make_pair(x-1,y));
       }
     }
     //right
     if(x!=n-1){
       if(path[x+1][y]>path[x][y]+map[x+1][y]){
         path[x+1][y] = path[x][y]+map[x+1][y];
         q.push(make_pair(x+1,y));
     }
   }
  }

  //print
  for(int j=0;j<n;j++){
    for(int k=0;k<n;k++){
   //   printf("%d ",path[j][k]);
    }
//    printf("\n");
  }
  ans = path[n-1][n-1];
  printf("#%d %d",i+1,ans);
  printf("\n");
 }
 return 0;
}
