#include <stdio.h>

int pow(int a, int b){ //домножаем число на себя пока не получим степень
    int a1=a;
    for(int k=1;k<b;k++)
        a1*=a;
    return a1;
}

int mod(int a, int b){
    return(((a%b)+b)%b);
}

int min(int a, int b){
    return (a<=b)?a:b;
}

int max(int a,int b){
    return (a<=b)?b:a;
}

int abs(int a){
    return (a<0)?-a:a;
}

int sign(int a){
    return (a!=0)?abs(a)/a:0;
}

int main(){
    int i=-29;
    int j=3;
    int l=9;
    char d;
    for(int step=0; step<=50; step++){
        if((float*)(pow(i-20, 2)/pow(10,2) + pow(j,2)/pow(5,2) > 1)){ //гмт точек вне эллипса
            if(step==50){
                printf("No entry");
                break;
            }
            i = mod(i*max(j,l),20) + mod(j*min(i,l),30) + step;
            j = mod((i-j+l-step)*sign(step-10),20);
            l = mod(abs(i-j)*l - abs(j-l)*i + abs(i-l)*j,20) - step;
        }
        else{
            printf("Entry, %d", step);
            break;
        }
    }
    scanf("%c",d);
}
