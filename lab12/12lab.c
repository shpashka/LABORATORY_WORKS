#include <stdio.h>

int get_last(int *num){
    return(*num%10);
}

int get_last_binary(int *num){
    return(*num%2);
}


void digit2bin(int digit,int k){ //the second parameter is the depth of recursion
    if(digit/2>0){
        digit2bin(digit/2,++k);
    }
    //(k+1) in the deepest recursion call means the length of the number.
    //Other k's are a bit wrong(+-1), but they are useless for us, we need the last one
    //so, in the deepest call we have a length of bin num and a first bin digit

    //we have to format binary number by printing zeros and print the number itself
    else{ //just for this deepest call
        const int FORMATTED_LENGTH=4;
        for(int i=0;i<FORMATTED_LENGTH-(k+1);i++){
            printf("0");
        }
    }
    printf("%d",get_last_binary(&digit));

}

void digits(int number){

    if(number/10>0){
        digits(number/10);
    }

    //get_last(&number) - is a digit now. But the digits go from left of the number!
    //we are said not to use arrays so it is convenient to use this recursion
    digit2bin(get_last(&number),0);//we translate a digit to formatted bin
    printf(" ");
}


int main(){
    int number;
    scanf("%d", &number);
    digits(number);

}


