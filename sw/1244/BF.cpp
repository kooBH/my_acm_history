//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD

#include <stdio.h>
#include <math.h>
#include <algorithm>

int deci[6] ={1,10,100,1000,10000,100000};

int BF(int arr[6], int value,int length,int depth, int limit){
    int ret = value;
    printf("[d]%d [v]%d [l]%d\n",depth,value,length);
    if(depth == limit)
        return ret;

    for(int i=length-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            int t_arr[6]={0,};
            int t_value = 0;
            //printf("swap %d & %d\n",i,j);
            for(int k=0;k<length;k++){
                if(k==i)
                    t_arr[k]=arr[j];
                else if(k==j)
                    t_arr[k]=arr[i];
                else
                    t_arr[k]=arr[k];
                t_value+=t_arr[k]*deci[k];
                /*
                for(int ii=length-1;ii>=0;ii--)
                    printf("%d",t_arr[ii]);
                printf(" =  %d\n",t_value);
                */
            }
//            printf("BF : [v]%d\n",t_value);
            ret = std::max(BF(t_arr,t_value,length,depth+1,limit),ret);
        }
    }
    return ret;
}

int main(){
    int nTest = 0;
    int board = 0;
    int nChange = 0;
    int length = 0;
    int numbers[6];
    int ans;

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
        for(int j=0;j<length;j++)
            printf("%d",numbers[length-j-1]);
        printf(" | %d\n",length);
        */

        ans = BF(numbers,board,length,0,nChange);

        printf("#%d %d\n",i+1,ans);
    }   
    return 0;
}