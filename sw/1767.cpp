#include <stdio.h>

int main(){
  int nTestCase;
  int nSize;

  int i,j,k;
  int **d;
  scanf("%d",&nTestCase);
  for(k=0;k<nTestCase;k++){
    scanf("%d",&nSize);
    d = new int*[nSize];
    for(j=0;j<nSize;j++)
      d[j] = new int[nSize];

    for(i=0;i<nSize;i++)
      for(j=0;j<nSize;j++)
        scanf("%d",&d[i][j]);

    for(i=0;i<nSize;i++){
      for(j=0;j<nSize;j++)
        printf("%d ",d[i][j]);
      printf("\n");
    }
  
    for(j=0;j<nSize;j++)
      delete d[j];
    delete d;
      printf("\n");
  }

  return 0;
}
