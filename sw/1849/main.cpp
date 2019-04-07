#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using std::cin;
using std::cout;

/*********************
 * DisjointSet + DFS *
 *********************/

/* 
 * Unknown 은 disjoint set에서 결정나므로
 * DFS에서 found는 빼야함.
 *
 */

/*** Disjoint Set ***/
// idx of set which that node belongs to.
int * find;

// number of  union set
int num_set;

/*** DFS ***/
/* Vars */
typedef struct edge {
  int d;
  int w;
  edge(int a, int b) {
    d = a;
    w = b;
  }
}edge;

typedef struct vertex {
  std::vector<edge*> e;
  bool visit;
}vertex;

vertex* vtxs;
int dw;
bool found;

/* Funcs */
void dfs(int src, int dest) {
  vtxs[src].visit = true;
  //	printf("dfs %d %d\n",src,dest);
  edge *temp;
  int tw;
  if (found)return;

  if (src == dest) {
    found = true;
    return;
  }

  std::vector<edge*>::iterator iter;
  for (iter = vtxs[src].e.begin(); iter != vtxs[src].e.end(); ++iter) {
    temp = *iter;
    if (vtxs[temp->d].visit)continue;
    //	printf("dfs from %d to %d %d += %d\n",src,temp->d,dw,temp->w);		
    tw = dw;
    dw += temp->w;
    dfs(temp->d, dest);
    if (!found)
      dw = tw;
  }
}

  int main() {

  int nTest, nSample, nQuery;
  int i, j,k,temp;
  int src, dest, diff;
  char type;
  edge * e1, *e2;

  std::ios::sync_with_stdio(false);
  cin.tie(0);

  /* Init */
  vtxs = new vertex[100001];
  find = new int[100001];
  num_set = 0;

  cin>>nTest;
  for (i = 0; i < nTest; i++)
  {
    cout<<"#"<<i+1<<" ";
    cin >> nSample>>nQuery;

    /* Initialization */
    for (j = 1; j <= nSample; j++) {
      vtxs[j].visit = false;
      std::vector<edge*>::iterator iter;
      for(iter = vtxs[j].e.begin(); iter != vtxs[j].e.end(); ++iter)
        delete(*iter);
      vtxs[j].e.clear();
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
          /* 서로 같은 set */
          if(find[dest]==find[src]){
          
          }
          /*  서로 다른 set의 연결 */
          /* 하나로 통일 하면 돰. 통일 당하는 set의 기준은?*/
          else{
            for(k=1;k<=nSample;k++)
              temp = find[dest];
              if(find[k]==temp){
                find[k]=find[src];
              }
          }
        }
        /* 2. 새로운 노드가 기존 set에*/
        else if((find[dest]!=0 && find[src]==0)
               ||(find[src]!=0  && find[dest]==0)){
          /* src 가 새로운 노드*/
          if(find[src]==0){
            find[src]=find[dest];          
          }
          /* dest 가 새로운 노드*/
          else{
            find[dest]=find[src];          
          }
        }
        /* 3. 새로운 set*/
        else{
          num_set++;
          find[dest]=num_set;
          find[src]=num_set;
        }
        e1 = new edge(dest, diff);
        e2 = new edge(src, -diff);
        vtxs[src].e.push_back(e1);
        vtxs[dest].e.push_back(e2);
      }
      /* Finding */
      else{
        cin>>src>>dest;
        /* Reset temp vars */
        dw = 0;
        found = false;
        /* find */
        /* 두 sample 이 같은 set에 속해 있는가 */
        if(find[src] == find[dest] && find[src]!=0 && find[dest]!= 0){
           dfs(src, dest);
           cout<<dw<<" ";
        }
        /* 서로  Disjoint */
        else cout<<"UNKNOWN ";

        for (k = 1; k <= nSample; k++) {
          vtxs[k].visit = false;
        }

      }
    }
    cout<<"\n";

  }
  return 0;
}
