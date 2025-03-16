#include <cstdint>
#include <cstdlib>
#include <cstring>

#include <omp.h>
void* my_malloc(uint64_t size)
{
    return malloc(size);
}

void my_seidel(int n, int T, double *A)
{
    double* B = (double*)malloc(n * n * sizeof(double));
    memcpy(B, A, n * n * sizeof(double));
    for (int t = 0; t < T; t++){
        double* src = (t % 2 == 0) ? A : B;
        double* dst = (t % 2 == 0) ? B : A;
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
	            dst[i * n + j]
                = (dst[(i - 1) * n + j - 1] + dst[(i - 1) * n + j] + dst[(i - 1) * n + j + 1]
		         + dst[      i * n + j - 1] + src[      i * n + j] + src[      i * n + j + 1]
		         + src[(i + 1) * n + j - 1] + src[(i + 1) * n + j] + src[(i + 1) * n + j + 1])
                 / 9.0;
    }
    // 确保最终结果在A中
    if(T % 2 == 1) {
        memcpy(A, B, n * n * sizeof(double));
    }
}