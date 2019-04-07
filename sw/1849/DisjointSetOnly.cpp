#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using std::cin;
using std::cout;

/*********************
 * DFS *
 *********************/

/* 
 * Unknown 은 disjoint set에서 결정나므로
 * DFS에서 found는 빼야함.
 *
 */

/*** Disjoint Set ***/
// idx of set which that node belongs to.
int * find;
int * weight;

// number of  union set
int num_set;

  int main() {

  int nTest, nSample, nQuery;
  int i, j,k,temp,temp2;
  int src, dest, diff;
  char type;

  std::ios::sync_with_stdio(false);
  cin.tie(0);

  /* Init */
  find = new int[100001];
  weight = new int[100001];
  num_set = 0;

  cin>>nTest;
  for (i = 0; i < nTest; i++)
  {
    cout<<"#"<<i+1<<" ";
    cin >> nSample>>nQuery;

    /* Initialization */
    for (j = 1; j <= nSample; j++) {
      find[j]=0;
    }
    num_set = 0;

    for (j = 0; j < nQuery; j++) {
      cin >> type;

      /* Insertion */
      if (type == '!') {
        cin>>src>>dest>>diff;

        /* 1. dest,src 가 둘 다 0이 아니거나
         * 2. 둘 중 하나면 0이거나
         * 3. 둘 다 0일 경우
         * */

        /*  1. 기존의 노드들의 추가 또는 서로 다른 set의 연결*/
        if(find[dest]!=0 && find[src]!=0){
          /* 이미 추가된 친구들  */
          if(find[dest]==find[src]){
          
          }
          /*  서로 다른 set의 연결 */
          else{
              temp = find[dest];
           //   temp2 = weight[dest] - diff - weight[src];
              temp2 = diff + weight[src] - weight[dest];
              //cout<<"temp2 "<<temp2<<"\n";
            for(k=1;k<=nSample;k++){
              if(find[k]==temp){
                find[k]=find[src];
                cout<<"weight["<<k<<"] : "<<weight[k];
                weight[k] +=temp2;
                cout<<"-> weight["<<k<<"] : "<<weight[k]<<"\n";
              }
            }
          }
        }
        /* 2. 새로운 노드가 기존 set에*/
        else if((find[dest]!=0 && find[src]==0)
               ||(find[src]!=0  && find[dest]==0)){
          /* src 가 새로운 노드*/
          if(find[src]==0){
            find[src]=find[dest];          
            weight[src] = weight[dest]-diff;
          }
          /* dest 가 새로운 노드*/
          else{
            find[dest]=find[src];          
            weight[dest] = weight[src] + diff;
          }
        }
        /* 3. 새로운 set*/
        else{
          num_set++;
          find[dest]=num_set;
          find[src]=num_set;
          weight[src]=0;
          weight[dest] = diff;
        }
     }
      /* Finding */
      else{
        cin>>src>>dest;
        /* find */
        /* 두 sample 이 같은 set에 속해 있는가 */
        if(find[src] == find[dest] && find[src]!=0 && find[dest]!= 0){
          //cout<<"weight["<<dest<<"] "<<weight[dest]<<"\n";
          cout<<weight[dest]-weight[src]<<" ";
        }
        /* 서로  Disjoint */
        else cout<<"UNKNOWN ";

      }
    }
    cout<<"\n";

  }
  return 0;
}
