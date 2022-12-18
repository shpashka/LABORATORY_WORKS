#include <stdio.h>
#include <assert.h>
#include <windows.h>

int isdigit(char c){
    return((c>='0') && (c<='9'));
}

int decimal_found(char buf[]){
    //logical formula telling whether there is a "0110" situation when using isdigit() to buf[]
    return( (!isdigit(buf[0])&&!isdigit(buf[3])) && (isdigit(buf[1])&&isdigit(buf[2])) );
}

void write_num(char prev, char current){
    //printf("%d",(prev<='9')&&(prev>='1')&&(current>='0')&&(current<=9));
    if((prev<='9')&&(prev>='1')&&(current>='0')&&(current<='9')){
        //printf("  %c%c  ",prev,current);
        if(prev=='1'){
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
                break;*/
            case '7':
                printf("Семнадцать\t");
                break;
            case '8':
                printf("Восемнадцать\t");
                break;
            case '9':
                printf("Девятнадцать\t");
                break;
            }
        }

        else{
            switch(prev){
            case '2':
                printf("Двадцать ");
                break;
            case '3':
                printf("Тридцать ");
                break;
            case '4':
                printf("Сорок ");
                break;
            case '5':
                printf("Пятьдесят ");
                break;
            case '6':
                printf("Шестьдесят ");
                break;
            case '7':
                printf("Семьдесят ");
                break;
            case '8':
                printf("Восемьдесят ");
                break;
            case '9':
                printf("Девяносто ");
                break;
            }
            switch(current){
            case '0':
                printf("\t");
                break;
            case '1':
                printf("один\t");
                break;
            case '2':
                printf("два\t");
                break;
            case '3':
                printf("три\t");
                break;
            case '4':
                printf("четыре\t");
                break;
            case '5':
                printf("пять\t");
                break;
            case '6':
                printf("шесть\t");
                break;
            case '7':
                printf("семь\t");
                break;
            case '8':
                printf("восемь\t");
                break;
            case '9':
                printf("девять\t");
                break;
            }
        }
    }
}



int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char buffer[4] = {' ',' ',' ',' '}; //we are interested in this situation [non-digit,digit,digit,nondigit]

    while((buffer[3] = getchar())!= EOF){
        //we need not the copy but the array itself. Fortunately, it is default in C
        if(decimal_found(buffer)){
            write_num(buffer[1],buffer[2]);
        }
        buffer[0]=buffer[1];
        buffer[1]=buffer[2];
        buffer[2]=buffer[3];
    }

    return 0;
}
