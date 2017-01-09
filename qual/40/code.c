#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int H,S;
int N[10][3];

int Num[6][20][401];

void preprocess(){
    memset(Num, 0, sizeof(int)*6*20*401);
    int dice[6] = {4, 6, 8,10,12,20};
    int i,j,k,l;
    for(i=0;i<6;i++){
        for(k=1;k<=dice[i];k++)
            Num[i][0][k] = 1;
        for(j=1;j<20;j++){
            for(k = j; k<= dice[i]*(j);k++){
               for(l=1;l<=dice[i];l++) 
                   Num[i][j][k+l] += Num[i][j-1][k];
            }
        }
    }
    for(i=0;i<6;i++){
        for(j=1;j<=20;j++){
            for(k = dice[i]*j - 1; k>= j; k--){
                Num[i][j-1][k] += Num[i][j-1][k+1];
            }
        }
    }
    return;
}

void input(){
    scanf("%d %d", &H, &S);
    memset(N, 0, sizeof(int)*10*3);
    int i;
    for(i=0;i<S;i++){
        scanf("%dd%d",&N[i][0],&N[i][1]);
        char c;
        scanf("%c",&c);
        if(c == ' ' || c == '\n')
            N[i][2] = 0;
        else if(c == '+')
           scanf("%d",&N[i][2]);
        else{
            scanf("%d",&N[i][2]);
            N[i][2] *= -1;
        }
    }
    return;
}

int get_index(int x){
    switch(x){
        case 4:
            return 0;
        case 6:
            return 1;
        case 8:
            return 2;
        case 10:
            return 3;
        case 12:
            return 4;
        case 20:
            return 5;
    }
}

void solve(){
    double max = 0.0;
    int i;
    for(i=0;i<S;i++){
        int km = H - N[i][2];
        double pr; 
        if( km > N[i][0]*N[i][1] )
            pr = 0.0;
        else if( km < N[i][0] )
            pr = 1.0;
        else{
            pr = (1/pow(N[i][1], N[i][0]))*Num[get_index(N[i][1])][N[i][0] - 1][km];
        }
        if( pr > max )
            max = pr;
    }
    printf("%.6f", max);
    return;
}

int main(){
    preprocess();
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        input();
        printf("Case #%d: ",t);
        solve();
        printf("\n");
    }
    return 0;
}
