#include <stdio.h>

#define ull unsigned long long
#define f(_i,_n) for(_i=0;_i<_n;_i++)

#pragma warning(disable:4996)

/* 
   check procedure 를 줄일 수 있는 Data struct
   check의 종류는 3개
   1. 가로
   2. 세로
   3. 블럭

   array of possibilty
   initial values are zero
   so if one's value is set by zero
   it means you can write that databer
*/
bool col[9][9];
bool row[9][9];
bool block[9][9];

bool track(int p);
int map[81];

int main() {
  int i, j;
  int t;
  f(i, 81) {
    scanf("%d", &t);
    /* set check array by initial map state */
    if (t != 0) {
      t--;
      col[i % 9][t] = true;
      row[i / 9][t] = true;
      block[i%9/3 + (i / 27)*3][t] = true;
      t++;
    }
    map[i] = t;
  }

  /* 스도쿠 분류 : 백트레킹 */

  f(i, 9) {
    f(j, 9) printf("%d ", map[9*i + j]); 
    printf("\n");
  }

  printf("col\n");
  f(i, 9) {
    f(j, 9) printf("%d ", col[i][j]); 
    printf("\n");
  }
  printf("row\n");
  f(i, 9) {
    f(j, 9) printf("%d ", row[i][j]); 
    printf("\n");
  }
  printf("block\n");
  f(i, 9) {
    f(j, 9) printf("%d ", block[i][j]); 
    printf("\n");
  }

  track(0);
  f(i, 9) {
    f(j, 9) printf("%d ", map[9*i + j]); 
    printf("\n");
  }


  return 0;
}

/*
   현재 state에서 가능한 action을 greedy하게 취하다가 
   condtion fail이 뜨면 최근의 action을 취소하고 이전 state로 돌아가서
   그 다음으로 가능한 action을 취한다. 이러한 계층의 관리는 재귀적 함수호출을
   사용한 시스템 스텍으로 수행한다.

   이것을 어떻게 구현할 것인가 ? 
 */
bool track(int p) {
  int i, j;
  int r,c,b;
  //printf("t[%d][%d]\n", p / 9, p % 9);
  if ( p == 81)
    return true;
  if (map[p] != 0) return track(p + 1);
  else {
    /* 현재 위치에 둘 수 있는 것을 두고
       다음 위치로 분기한다
       현재 위치에 둬서 막힌다면 분기를 타고
       원래 위치로
    */
    r = p / 9;
    c = p % 9;
    b = (r / 3)*3 + c / 3;
    f(i,9){
      if (!row[r][i] && !col[c][i] && !block[b][i]) {
        map[p] = i+1;
        row[r][i] = 1;
        col[c][i] = 1;
        block[b][i] = 1;
        printf("put  %d at %d, %d\n",i+1,r,c);
        if (!track(p + 1)) {
          printf("fail %d at %d, %d\n",i+1,r,c);
          map[p] = 0;
          row[r][i] = 0;
          col[c][i] = 0;
          block[b][i] = 0;
        }
        else return true; 

      }
    }
  }
  return false;
}
