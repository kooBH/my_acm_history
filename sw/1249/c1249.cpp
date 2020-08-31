#define MAX_N 100

#include <stdio.h>

int main(){
  int tc;
  int n;

 scanf("%d", &tc);

 int map[MAX_N][MAX_N];
 int path[MAX_N][MAX_N]={0,};
 char temp_char;
 int ans=0;

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
      path[j][k]=0;
    }
  }

  //process



  //print
  for(int j=0;j<n;j++){
    for(int k=0;k<n;k++){
      printf("%d",map[j][k]);
    }
    printf("\n");
  }
  printf("#%d %d",i+1,ans);
  printf("\n");
 }

 return 0;
}
