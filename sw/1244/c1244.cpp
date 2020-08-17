//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD

#include <stdio.h>
#include <math.h>
#include <algorithm>

int deci[6] ={1,10,100,1000,10000,100000};

int main(){
    int nTest = 0;
    int board = 0;
    int nChange = 0;
    int length = 0;
    int numbers[6];

    scanf("%d", &nTest);
    for(int i=0;i<nTest;i++){
        // input
        scanf("%d %d",&board,&nChange);
        int t=board;
        length = 0;
        while(t){
            numbers[length]=t%10;
            t/=10;
            length++;
        }
        /*
        printf("input : ");
        for(int j=length-1;j>=0;j--)
            printf("%d",numbers[j]);
        printf("\n");
        */

        for(int j=0;j<nChange;j++){
            int target_idx = length-j-1;
            int big_v = numbers[target_idx];
            int big_idx = target_idx;
            bool swaped  =false;

            if(j > length){
                if(j%2==0)
                    break;
                else{
                    int t_v = numbers[1];
                    numbers[1] = numbers[0];
                    numbers[0] = numbers[1];
                    continue;
                }
            }
            for(int k=target_idx-1;k>=0;k--){
                //printf("%d > %d | %d %d\n",numbers[k],big_v,k,big_idx);
                if(numbers[k] >= big_v){
                    big_v = numbers[k];
                    big_idx=k;
                    swaped=true;
                }
            }
            if(swaped){
                //printf("swap %d %d\n",numbers[target_idx],numbers[big_idx]);
                int t_v = numbers[target_idx];
                numbers[target_idx] = big_v;
                numbers[big_idx]  = t_v;
                /*
                printf("swap : ");
                for(int ii=length-1;ii>=0;ii--)
                    printf("%d",numbers[ii]);
                printf("\n");
                */

            }
        }

        printf("#%d ",i+1);
        for(int j=length-1;j>=0;j--)
            printf("%d",numbers[j]);
        printf("\n");
    }   
    return 0;
}