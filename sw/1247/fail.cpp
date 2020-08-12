/*
 *https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD&categoryId=AV15OZ4qAPICFAYD&categoryType=CODE
 * */

/*
 * Failed. Didn't read well. Didn't consider office and home
 */

#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>

using std::vector;
using std::pair;

int main(){
  int num_test_case = 0;
  int num_client = 0;
  int i,j,k,l;

  int x[12];
  int y[12];
  int connect[12];
  int ans;
n
  vector<pair<int,pair<int,int>>> dist;

  scanf("%d",&num_test_case);

  for(i=0;i<num_test_case;i++){
    scanf("%d",&num_client);
    num_client+=2;
    for(j=0;j<num_client;j++){
      scanf("%d %d,",&x[j],&y[j]);
    }

    /* Create Distance map */
    for(j=0;j<num_client;j++){
      for(k=0;k<num_client;k++){
        if(k>j)
          dist.push_back(std::make_pair(abs(x[j]-x[k])+abs(y[j]-y[k]),std::make_pair(j,k) ));
      }
    }
    /* Init Path map*/
    for(j=0;j<num_client;j++){
        connect[j]=0;
    }

    /*
     * Note : almost open field. every vertex has 
     * edges to all other vertexes.
     * is brute force allowed?
     * */
    std::sort(dist.begin(),dist.end());
    
    /* shortest path */
    ans=0;
    for(auto item : dist){
      printf("%d %d %d\n",item.first,item.second.first,item.second.second);
      /* Can't add */
      if(connect[item.second.first]>1 || connect[item.second.second] >1) 
        continue;
      /* Connected */
      if(connect[item.second.first]>0 && connect[item.second.second]>0)
        continue;
      /* Office to home */
      if(item.second.first==0 && item.second.second==1)
        continue;
      connect[item.second.first]++;
      connect[item.second.second]++;
      //printf("connect %d - %d\n",item.second.first,item.second.second);
      ans+=item.first;
    }

    /*
    for(j=0;j<num_client;j++)
      printf("%3d ",connect[j]);
    printf("\n");
    */
    break;
    printf("#%d %d\n",i+1,ans);

    dist.clear();
  }
  return 0;

}
