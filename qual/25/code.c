#include<stdio.h>
#include<math.h>

int P,X,Y;

void input(){
    scanf("%d %d %d",&P,&X,&Y);
    return;
}

void solve(){
    if( ((X-50)*(X-50) + (Y-50)*(Y-50)) > 50*50 ){
        printf("white");
        return;
    }
    int x,y;
    double ang;
    if( X >= 50 && Y >= 50){
        x = 0;
        y = 1;
        ang = 0;
    }
    else if( X >= 50 && Y < 50){
        x = 1;
        y = 0;
        ang = M_PI/2;
    }
    else if( X <= 50 && Y <= 50){
        x = 0;
        y = -1;
        ang = M_PI;
    }
    else{
        x = -1;
        y = 0;
        ang = 3*M_PI/2;
    }
    double angle1 = ang + acos( (x*(X-50) + y*(Y-50))/sqrt((X-50)*(X-50) + (Y-50)*(Y-50)));
    double angle = (P/100.0)*(2*M_PI);
    if( angle1 > angle ){
        printf("white");
        return;
    }
    printf("black");
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
