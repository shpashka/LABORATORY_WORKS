#include <stdio.h>
#include <malloc.h>
#include <assert.h>
//using an array of pointers(array of arrays)

int equal(int a[], int b[], int m, int n){
    int flag = 1;
    for(int i=0;i<n;i++){
        if( a[i] != b[i] ){
            flag=0;
            break;
        }
    }
    return flag;
}

void assert_equal(){
    int a[] = {1,2,3,4};
    int b[] = {1,2,3,4};
    assert(equal(a,b,4,4));
}

int main(){
    int n;
    int m;
    int m_const;
    FILE *f;
    f = fopen("arr.txt", "r");

    fscanf(f,"%d %d",&m,&n);
    m_const = m;
    int **a = malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        a[i] = malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            fscanf(f,"%d ",&(a[i][j]));
        }
        //printf("%d",*(a+i));
    }


    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            if(equal(a[i],a[j],m,n)){
                int *temp = a[j];
                for(int k=j;k<m;k++){
                    a[k]=a[k+1];
                }
                temp=NULL;
                //free(temp);
                m-=1;
            }
        }
    }


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //freeing all the memory for array ptrs and then the array itself
    for(int i=0;i<m_const;i++){
        free((a+i));
    }
    free(a);

    assert_equal();
    return 0;
}
