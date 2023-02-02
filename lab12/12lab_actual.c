#include <stdio.h>

int get_last(int num){
    return(num%10);
}

int get_sum(int *num){
    if(*num>=10 && get_last(*num)+get_last(*num/10)<10)
        return(get_last(*num)+get_last(*num/10));
    else
        return 0;
}

void sum(int num){
    if(num>0){
        sum(num/10);
    }
    if(num>0){
        printf("%d", get_last(num));
        if(get_sum(&num))
            printf("%d", get_sum(&num));
    }

}

int main(){
    int number;
    assert(scanf("%d", &number)!=0);
    sum(number);
return 0;
}
