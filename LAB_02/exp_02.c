#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int r,c,i,j,count=0,sum=0,k;
  int n_threads=1;

while(n_threads<=8){
count=0;
sum=0;

printf("\nenter number of rows : ");
scanf("%d", &r);
printf("\nenter number of coloumns : ");
scanf("%d", &c);

int **arr1 = (int **)malloc(r * sizeof(int *));
for(i=0;i<r;i++)
arr1[i]=(int *)malloc(c * sizeof(int));

int **arr2 = (int **)malloc(r * sizeof(int *));
for(i=0;i<r;i++)
arr2[i]=(int *)malloc(c * sizeof(int));

int **arr3 = (int **)malloc(r * sizeof(int *));
for(i=0;i<r;i++)
arr3[i]=(int *)malloc(c * sizeof(int));

for(i=0;i<r;i++)
  for(j=0;j<c;j++)
      arr1[i][j] = count++;

for(i=0;i<r;i++)
  for(j=0;j<c;j++)
      arr2[i][j] = count++;


double x = omp_get_wtime();
omp_set_num_threads(n_threads);
#pragma omp parallel for private(j,k)

for(i=0;i<r;i++)
  for(j=0;j<c;j++)
    for(k=0;k<r;k++)
       arr3[i][j]+=arr1[i][k]*arr2[k][j];


double y = omp_get_wtime();

printf("Input size = %d\n", r);
printf("number of threads = %d, time=%lf\n", n_threads, y-x);
n_threads=n_threads*2;
}

return 0;


}
