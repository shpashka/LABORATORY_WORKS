#include <stdio.h>
#include <malloc.h>
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

int main(){
    int n;
    int m;
    FILE *f;
    f = fopen("arr.txt", "r");

    fscanf(f,"%d %d ",&m,&n);

    int **a = malloc(sizeof(int)*(m));
    for(int i=0;i<m;i++){
        a[i] = malloc(sizeof(int)*(n));
        for(int j=0;j<n;j++){
            fscanf(f,"%d ",&a[i][j]);
        }
        //printf("%d",*(a+i));
    }

    //freeing the memory from extra matrix lines
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(equal(a[i],a[j],m,n)){
                int *temp = a[j];
                for(int k=j;k<m;k++){
                    a[k]=a[k+1];
                }
                a[m]=NULL;
                free(temp);
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

    free(a);
    return 0;
}
