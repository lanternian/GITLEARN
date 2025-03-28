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
    double inv = 1.0 / 9.0;

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
                        double uprow = dst[(i - 1) * n] + dst[(i - 1) * n + 1] + dst[(i - 1) * n + 2];
                        double downrow = src[(i + 1) * n] + src[(i + 1) * n + 1] + src[(i + 1) * n + 2];
                        for (int j = 1; j < n - 1; j++) {
                            dst[i * n + j]
                                = (uprow
                                + dst[      i * n + j - 1] + src[      i * n + j] + src[      i * n + j + 1]
                                + downrow)
                                * inv;
                            uprow += (dst[(i - 1) * n + j + 2]-dst[(i - 1) * n + j - 1]);
                            downrow += (src[(i + 1) * n + j + 2]-src[(i + 1) * n + j - 1]);
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