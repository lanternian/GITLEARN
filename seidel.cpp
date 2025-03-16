#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#include <omp.h>
void* my_malloc(uint64_t size)
{
    return malloc(size);
}

void my_seidel(int n, int T, double *A)
{
    double* B = (double*)malloc(n * n * sizeof(double));
    memcpy(B, A, n * n * sizeof(double));

    int block = 16, numsblock = (n-2 + block - 1) / block;

    #pragma omp parallel num_threads(32)
    {
        for (int step = 0; step < numsblock + 2*(T - 1); step++) {
            // 处理每个分块
            #pragma omp for schedule(static)
            for (int b = (step%2); b < numsblock; b+=2) {
                // 计算第几次迭代
                int t = (step - b) / 2;
                if(t >= 0 && t < T) {
                    int start = 1 + b * block;
                    int end = std::min(start + block,n-1);

                    double* src = (t % 2 == 0) ? A : B;
                    double* dst = (t % 2 == 0) ? B : A;

                    for (int i = start; i < end; i++) {
                        for (int j = 1; j < n - 1; j++) {
                            dst[i * n + j]
                            = (dst[(i - 1) * n + j - 1] + dst[(i - 1) * n + j] + dst[(i - 1) * n + j + 1]
                            + dst[      i * n + j - 1] + src[      i * n + j] + src[      i * n + j + 1]
                            + src[(i + 1) * n + j - 1] + src[(i + 1) * n + j] + src[(i + 1) * n + j + 1])
                            / 9.0;
                        }
                    }
                }
            }
        }
    }
    
    // 确保最终结果在A中
    if(T % 2 == 1) {
        memcpy(A, B, n * n * sizeof(double));
    }
    
    free(B);
}