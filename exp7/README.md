## follow this to run in intel cpu/gpu
[Get Started with Intel® SDK for OpenCL™ Applications 2020 on Windows* OS](https://www.intel.com/content/www/us/en/developer/articles/guide/sdk-for-opencl-2020-gsg-windows-os.html)
## Command to run in college padp server
```console
nvcc exp7.cu -lOpenCL
./a.out

##changes to be made

for changing input size change VECTOR_SIZE MACRO
for changing number of threads change size_t local_size = 64
```
