## Command to execute exp1a.c
```console
gcc -fopenmp exp1a.c 
./a.out
```
## Command to execute exp1b.c
```console
mpicc exp1b.c
mpirun -np 4 a.out

or 

mpicc exp1b.c -o output
mpirun -np 4 output
```
