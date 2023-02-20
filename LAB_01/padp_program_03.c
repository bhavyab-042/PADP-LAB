#include <omp.h>
#include <stdio.h>

int main(){
    int cnt = 10;
    #pragma omp parallel num_threads(cnt)
    printf("hello\n");
}