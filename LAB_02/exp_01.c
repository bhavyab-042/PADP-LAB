#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#define SEED 35791246

void main(int argc,char **argv)
{
	
 int n=0,i,count=0;
 int n_threads=1;
 double z,pi,x,y;
double st =0.0, end=0.0;

 while(n_threads<=8){
 count=0;
 n=0;
	
 printf("\n Enter number of intervals: ");
 scanf("%d", &n);


/* No. of intervals should be positive integer */
	if (n<= 0) {
		printf("\n\t\t Number of intervals should be positive integer\n");
		exit(1);
	}
 srand(SEED);
 st =0.0;
 end=0.0;
 st = omp_get_wtime();
 omp_set_num_threads(n_threads);
 

 #pragma omp parallel for

 for (i = 1; i <n ;i++) {
  x=(double)rand()/RAND_MAX;
  y=(double)rand()/RAND_MAX;
  z=x*x+y*y;
  if(z<=1) count++;
}
pi=(double)count/n*4;
end = omp_get_wtime();
printf("\nnumber of trails = %d \t pi value=%g\n", n,pi);
printf(" number of threads = %d \t time =%lf\n", n_threads, end-st);
n_threads=n_threads*2;

}
	
}
