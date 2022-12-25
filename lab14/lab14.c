#include <stdio.h>
#include <malloc.h>

int main(){
    int n;
    int *x;
    FILE *f;
    f = fopen("arr.txt", "r");
    fscanf(f,"%d",&n);


    x = (int*)malloc(sizeof(int)*n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // working with x[i][j]
            fscanf(f,"%d",(x + i*n + j));
            printf(" %d ",*(x + i*n + j));

        }
        printf("\n");
    }

    int i,j,p,ring;
    i=0;
    j=0;
    p=0;
    ring=0;
    while(p<n*n){

        while(j<n-1-ring && p<n*n){
            printf("%d ",*(x + i*n +j));
            j++;
            p++;
        }
        while(i<n-1-ring && p<n*n){
            printf("%d ",*(x + i*n +j));
            i++;
            p++;
        }
        while(j>ring && p<n*n){
            printf("%d ",*(x + i*n +j));
            j--;


            p++;
        }
        ring++;

        while(i>ring && p<n*n){
            printf("%d ",*(x + i*n +j));
            i--;

            p++;
        }
    }



    free(x);
}





