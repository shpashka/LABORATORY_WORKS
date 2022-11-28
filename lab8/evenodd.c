#include <stdio.h>
int max(int num1, int num2)
    {
    return (num1>num2)? num1: num2;
    }

int min(int num1, int num2)
    {
    return (num1>num2)? num2: num1;
    }


struct Pair
    {
    int num1;
    int num2;
    };
struct Pair Pair(int num1, int num2)
    {
    struct Pair output;
    output.num1 = num1;
    output.num2 = num2;
    return output;
    }
struct Pair add_pair(struct Pair source, struct Pair added)
    {
    source.num1 += added.num1;
    source.num2 += added.num2;
    return source;
    }
struct Pair sub_pair(struct Pair source, struct Pair subbed)
    {
    source = add_pair(source,Pair(-subbed.num1,-subbed.num2));
    return source;
    }
int sum(struct Pair numbers)
    {
    return numbers.num1+numbers.num2;
    }
int positive(struct Pair pair)
    {
    return((pair.num1>0) && (pair.num2>0))? 1:0;
    }
struct Pair min_pair(struct Pair pair1, struct Pair pair2)
    {
    return (sum(pair1)<sum(pair2))? pair1: pair2;
    }







int main()
{
    FILE *text;
    int k;
    struct Pair min_evenodd={10001,10001}, min_oddeven={10001,10001}, min_oddodd={10001,10001}, united = {0,0}; // min_evenodd - минимальное четное, максимальное нечетное и т.д. аналогично;
                                                              // иначе говоря, это пара мин/макс
    struct Pair curr_pair; // но в curr_pair элементы просто по порядку идут

    text = fopen("test6.txt","r");
    fscanf(text, "%d", &k); //узнали сколько пар
    //printf("%d\n",k);

    for(int o=0; o<k;o++)
    {

        struct Pair curr_pair;
        fscanf(text, "%d %d", &curr_pair.num1, &curr_pair.num2);//считали пару в поля num1 и num2 пары curr_pair
        //printf("%d %d   ",curr_pair.num1,curr_pair.num2);
        if(curr_pair.num1%2!=0) //пара нужна только если первое нечетное
        {
            //printf("%d %d  %d %d %d\n",united.num1,united.num2,curr_pair.num1,curr_pair.num2,o);
            united = add_pair(united,Pair(min(curr_pair.num1, curr_pair.num2),max(curr_pair.num1, curr_pair.num2)));//суммируем

            switch((curr_pair.num2)%2) // посмотрим на четность второго числа в паре
            {
            case 1: //значит это пара нечет/нечет переприсвоение минимальной по сумме пары нечетное/нечетное
                {
                min_oddodd = min_pair(min_oddodd, curr_pair);
                //printf("\noo%d %d  %d %d\n",min_pair(min_oddodd, curr_pair).num1, min_pair(min_oddodd, curr_pair).num2,o,curr_pair.num2%2);
                break;
                }
            case 0: // это пара четного и нечетного у нее минимальным и максимальным может оказаться как чет/нечет так и нечет/чет
                {
                switch(min(curr_pair.num1, curr_pair.num2)%2)
                {
                case 1:
                    {
                    //printf("\noe%d %d  %d %d\n",min_pair(min_oddeven, curr_pair).num1, min_pair(min_oddeven, curr_pair).num2,o,curr_pair.num2%2);
                    min_oddeven = min_pair(min_oddeven, curr_pair);
                    break;
                    }
                case 0:
                    {
                    //printf("\neo%d %d  %d %d\n",min_pair(min_evenodd, curr_pair).num1, min_pair(min_evenodd, curr_pair).num2,o,curr_pair.num2%2);
                    min_evenodd = min_pair(min_evenodd, curr_pair);
                    break;
                    }
                }
                break;
                }

            }
        }
    }
    //итак, имеем пару из суммы минимальных чисел в парах и суммы максимальных
    //проверим, удовлетворит ли условию задания и вычтем нужную пару в противном случае
    //первое число должно быть четным а второе нечетным

    //printf("%d %d\n%d %d\n%d %d\n%d %d",united.num1,united.num2,min_evenodd.num1,min_evenodd.num2,min_oddeven.num1,min_oddeven.num2,min_oddodd.num1,min_oddodd.num2);

    switch(united.num1%2)
    {
    case 0:
        {
        switch(united.num2%2)
        {
        case 0:
            {
            //printf("ОТВЕТ %d %d",united.num1,united.num2);
            if(positive(sub_pair(united, min_evenodd))>0) //если нет нужного для вычитания минимума
                united = sub_pair(united, min_evenodd);   //то он получается вычитанием двух других(см отчет)
            else
                united = sub_pair(united, add_pair(min_oddodd, min_oddeven));
            if(sum(united)<0)
            {
                printf("NO");
                break;
            }
            printf("1answer %d %d\n%d",united.num1,united.num2, sum(united));
            break;
            }
        case 1:
            {
            if(sum(united)<0)
            {
                printf("NO");
                break;
            }
            printf("2answer %d %d\n%d",united.num1,united.num2, sum(united));  //ответ получен
            break;
            }
        }
        break;
        }
    case 1:
        {
        switch(united.num2%2)
        {
        case 0:
            {
            //printf("ОТВЕТ %d %d",united.num1,united.num2);
            if(positive(sub_pair(united, min_oddodd))>0)
                united = sub_pair(united, min_oddodd);
            else
                united = sub_pair(united, add_pair(min_evenodd, min_oddeven));//см отчет
            if(sum(united)<0)
            {
                printf("NO");
                break;
            }
            printf("3answer %d %d\n%d",united.num1,united.num2, sum(united));
            break;
            }
        case 1:
            {
            //printf("ОТВЕТ %d %d",united.num1,united.num2);
            if(positive(sub_pair(united, min_oddeven))>0)
                united = sub_pair(united, min_oddeven);
            else
                united = sub_pair(united, add_pair(min_oddodd,min_evenodd));
            if(sum(united)<0)
            {
                printf("NO");
                break;
            }
            printf("4answer %d %d\n%d",united.num1,united.num2, sum(united));
            break;
            }
        }
        break;
        }
    }
    //printf("%d %d",united.num1, united.num2);
    fclose(text);
    return 0;
}
