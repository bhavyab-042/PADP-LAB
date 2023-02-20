#include <omp.h>
#include <stdio.h>

int main(){
    #pragma omp parallel num_threads(5)
    printf("hello\n");
}