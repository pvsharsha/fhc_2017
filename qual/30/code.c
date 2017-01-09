#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int N;
int W[101];

void input(){
    memset(W, 0 , sizeof(int)*101);
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d", &j);
        W[j]++;
    }
}

void solve(){
    int i = 1,j = 100,k = 0;
    while( (i <=j) && (N > 0) ){
        if(W[j] == 0)
            j--;
        else if(W[i] == 0)
            i++;
        else{
            int qty = (int)ceil(50.0/j);
            if( qty <= N ){
                k++;
                N -= qty;
                W[j]--;
                qty--;
                while(qty>0){
                    if(W[i] == 0){
                        i++;
                    }
                    else{
                        W[i]--;
                        qty--;
                    }
                }
            }
            else{
                N = 0; 
            }
        }
    }
    printf("%d", k);
    return;
}

int main(){
    int T,t;
    scanf("%d",&T);
    for(t = 1; t <= T; t++){
        input();
        printf("Case #%d: ",t);
        solve();
        printf("\n");
    } 
    return 0;
}
