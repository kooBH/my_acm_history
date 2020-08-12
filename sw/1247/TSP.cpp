/*
 *https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD&categoryId=AV15OZ4qAPICFAYD&categoryType=CODE
 * */

//https://hsp1116.tistory.com/40

#include <algorithm>
#include <stdio.h>
#include <vector>


int num_node;
int dist[12][12];
std::vector<int>anses;

int TSP(std::vector<int>path,std::vector<bool>visited,int len){
  /*
  for(auto item : path){
    printf("%d ",item);
  }
  printf("%d\n",len);
*/
  if(path.size() == num_node-1){
    anses.push_back(len+dist[path.back()][num_node-1]);
    return len+dist[path.back()][num_node-1];
  }
  int ret = 10000;

  for(int next = 1;next<num_node-1;next++){
    if(visited[next]==true)continue;

    int cur = path.back();
    path.push_back(next);
    visited[next] = true;
    ret = std::min(ret,TSP(path,visited,len+dist[cur][next]));
    visited[next] = false;
    path.pop_back();
  }
  return ret;

}

int main(){
  int num_test_case = 0;
  int i,j,k,l;

  int x[12];
  int y[12];
  int ans;

  scanf("%d",&num_test_case);

  for(i=0;i<num_test_case;i++){
    scanf("%d",&num_node);
    num_node+=2;
    scanf("%d %d",&x[0],&y[0]);
    scanf("%d %d",&x[num_node-1],&y[num_node-1]);
    for(j=1;j<num_node-1;j++){
      scanf("%d %d,",&x[j],&y[j]);
    }

    /* Create Distance map */
    for(j=0;j<num_node;j++){
      for(k=0;k<num_node;k++){
          dist[j][k] = abs(x[j]-x[k])+abs(y[j]-y[k]);
//          printf("%d ",dist[j][k]);
      }
 //     printf("\n");
   }

    // start at 0
    std::vector<int>path(1,0);
    std::vector<bool> visited(num_node,false);
    visited[0]=true;

    int ans = TSP(path,visited,0);
    /*
    for(auto item : anses){
      printf("%d ",item);
    }
    printf("\n");
    */
    printf("#%d %d\n",i+1,ans);
  }
  return 0;
}
