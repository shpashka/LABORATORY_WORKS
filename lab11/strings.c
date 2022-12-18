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
                printf("�����������\t");
                break;
            case '2':
                printf("����������\t");
                break;
            case '3':
                printf("����������\t");
                break;
            case '4':
                printf("������������\t");
                break;
            case '5':
                printf("����������\t");
                break;
            case '6':
                printf("�����������\t");
                break;*/
            case '7':
                printf("����������\t");
                break;
            case '8':
                printf("������������\t");
                break;
            case '9':
                printf("������������\t");
                break;
            }
        }

        else{
            switch(prev){
            case '2':
                printf("�������� ");
                break;
            case '3':
                printf("�������� ");
                break;
            case '4':
                printf("����� ");
                break;
            case '5':
                printf("��������� ");
                break;
            case '6':
                printf("���������� ");
                break;
            case '7':
                printf("��������� ");
                break;
            case '8':
                printf("����������� ");
                break;
            case '9':
                printf("��������� ");
                break;
            }
            switch(current){
            case '0':
                printf("\t");
                break;
            case '1':
                printf("����\t");
                break;
            case '2':
                printf("���\t");
                break;
            case '3':
                printf("���\t");
                break;
            case '4':
                printf("������\t");
                break;
            case '5':
                printf("����\t");
                break;
            case '6':
                printf("�����\t");
                break;
            case '7':
                printf("����\t");
                break;
            case '8':
                printf("������\t");
                break;
            case '9':
                printf("������\t");
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
