#include<stdio.h>
#include<string.h>
#include<math.h>

int H,S;
int N[9][3];

void input(){
    scanf("%d %d", &H, &S);
    memset(N, 0, sizeof(int)*9*2);
    int i;
    for(i=0;i<S;i++)
        scanf("%dd%d%d",&N[i][0],&N[i][1],&N[i][2]);
    return;
}

double C(int a, int b){
    double num = 1.0;
    int i;
    for(i = 1; i<=b; i++){
        num *= (( a - i + 1)/i);
    }
    return num;
}

void solve(){
    double max = 0.0;
    int i;
    for(i=0;i<S;i++){
        int km = (H - N[i][2] - N[i][0])/N[i][1];
        double pr = 0.0;
        int j;
        double dn = pow(N[i][1], N[i][0]);
        for(j=0;j<=km;j++){
            pr += (1/dn)*pow(-1, j)*C(N[i][0],j)*C(H - N[i][2] - N[i][1]*j - 1, H - N[i][2] - N[i][1]*j - N[i][0]);
        }
        if( pr > max )
            max = pr;
    }
    printf("%.6f", max);
    return;
}


int main(){
    int T,t;
    scanf("%d", &T);
    for(t=1;t<=T;t++){
        input();
        printf("Case #%d: ",t);
        solve();
        printf("\n");
    }
    return 0;
}
