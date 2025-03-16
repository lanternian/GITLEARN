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
    for (int t = 0; t < T; t++)
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
                    A[i * n + j]
                = (A[(i - 1) * n + j - 1] + A[(i - 1) * n + j] + A[(i - 1) * n + j + 1]
                         + A[      i * n + j - 1] + A[      i * n + j] + A[      i * n + j + 1]
                         + A[(i + 1) * n + j - 1] + A[(i + 1) * n + j] + A[(i + 1) * n + j + 1])
                 / 9.0;
}