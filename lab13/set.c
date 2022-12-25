#include <stdio.h>
#include <assert.h>


void remove_one(unsigned int *set){
    *set&=(*set-1);
    //magically this removes the right "1" bit from our int-set(see Kernigan Ritchie book)
}
void t_remove_one(){
    unsigned int set1 = 4;
    remove_one(&set1);
    assert(set1==0);
    unsigned int set2 = 5;
    remove_one(&set2);
    assert(set2==4);
}


int potency(unsigned int set){
    unsigned int size = 0;
    for(;set>0;size++){
        remove_one(&set);
    }
    return(size);
}
void t_potency(){
    unsigned int set1 = 5;
    assert(potency(set1)==2);
    unsigned int set2 = 7;
    assert(potency(set2)==3);
}


void set_append(unsigned int *set, char letter){
    unsigned int add_set = 1u<<(letter-'A'); //getting a set of single char
    *set|=add_set; //adding a char to the set
}
void t_set_append(){
    unsigned int set1 = 8;
    set_append(&set1, 'B');
    assert(set1==10);
}


void print_set(unsigned int set){
    for(char letter='A';letter<='Z';++letter){
        if(set&(1u<<(letter-'A'))){
            printf("%c ",letter);
        }
    }
}


int main(){
    t_potency();
    t_set_append();
    unsigned int lower_set=0;
    int flag =1;
    while(flag){
        char c = getchar();

        if((c=='\n')||(c=='\t')||(c==',')||(c=='.')||(c=='?')){
            if(potency(lower_set)>1){
                printf("Yes, there is, it contains these letters ");
                print_set(lower_set);
                flag=0;
            }
            lower_set&=0;//making empty set
        }
        else{
            if((c<='Z')&&(c>='A')){
                set_append(&lower_set,c);
                }
        }
        if(c==EOF){
            printf("There are no such words");
        }
    }
    return 0;
}
