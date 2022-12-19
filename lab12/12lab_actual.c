#include <stdio.h>

int get_last(int *num){
    return(*num%10);
}


void sum(int num, int *k, int *s){
    if(num>0){
        sum(num/10,k,s);
    }
    if(num>0){
        *k+=1;
        printf("%d",get_last(&num));
        *s+=get_last(&num);
        if((*k%2==0) && (*s<=9)){
            printf("_%d_",*s);
            *s=0;
        }
    }

}

int main(){
    int number;
    int COUNTER=0;
    int SUM=0;
    scanf("%d", &number);
    sum(number,&COUNTER,&SUM);

}
