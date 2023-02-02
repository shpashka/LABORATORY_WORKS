#include <stdio.h>
#include <assert.h>
#include <windows.h>


typedef enum{
    s0,
    s1,
    s2,
    s3,
    s4
}State;




void write_num(int prev, int current){
    assert((prev<=9)&&(prev>=1)&&(current>=0)&&(current<=9));
    if(prev==1){
        switch(current){
        /*case '1':
            printf("Одиннадцать\t");
            break;
        case '2':
            printf("Двенадцать\t");
            break;
        case '3':
            printf("Тринадцать\t");
            break;
        case '4':
            printf("Четырнадцать\t");
            break;
        case '5':
            printf("Пятнадцать\t");
            break;
        case '6':
            printf("Шестнадцать\t");
            beak;*/
        case 7:
            printf("Семнадцать\t");
            break;
        case 8:
            printf("Восемнадцать\t");
            break;
        case 9:
            printf("Девятнадцать\t");
            break;
        }
    }

    else{
        switch(prev){
        case 2:
            printf("Двадцать ");
            break;
        case 3:
            printf("Тридцать ");
            break;
        case 4:
            printf("Сорок ");
            break;
        case 5:
            printf("Пятьдесят ");
            break;
        case 6:
            printf("Шестьдесят ");
            break;
        case 7:
            printf("Семьдесят ");
            break;
        case 8:
            printf("Восемьдесят ");
            break;
        case 9:
            printf("Девяносто ");
            break;
        }
        switch(current){
        case 0:
            printf("\t");
            break;
        case 1:
            printf("один\t");
            break;
        case 2:
            printf("два\t");
            break;
        case 3:
            printf("три\t");
            break;
        case 4:
            printf("четыре\t");
            break;
        case 5:
            printf("пять\t");
            break;
        case 6:
            printf("шесть\t");
            break;
        case 7:
            printf("семь\t");
            break;
        case 8:
            printf("восемь\t");
            break;
        case 9:
            printf("девять\t");
            break;
        }
    }

}



int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char symbol;
    int digit1;
    int digit2;

    State state = s0;
    while((symbol = getchar())!= EOF){
        int digit = symbol-'0'; // it is an integer made from char if it is a digit(else it is a meaningless number)
        switch(state){
        case(s0): // s0,s1,s2,s3,s4 define a DefiniteFiniteAutomaton - see the automaton in repository
            if(digit==1){
                state = s1;
                digit1 = digit;
            }
            else if(digit>=2 && digit<=9){
                state = s2;
                digit1 = digit;
            }
            else
                state = s0;
            break;
        case(s1):
            if(digit>=7 && digit<=9){
                state = s3;
                digit2 = digit;
            }
            else if(digit>=0 && digit<=6)
                state = s4;
            else
                state = s0;
            break;
        case(s2):
            if(digit>=0 && digit<=9){
                state = s3;
                digit2 = digit;
            }
            else
                state = s0;
            break;
        case(s4):
            if(digit>=0 && digit<=9)
                state = s4;
            else
                state = s0;
            break;
        case(s3): // final state which means that the number has been found
            if(digit>=0 && digit<=9)
                state = s4;
            else
                write_num(digit1,digit2);
                state = s0;
            break;
        }




    }
    return 0;
}
