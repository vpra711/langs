#include <iostream>
#include <chrono>
#define M 1024
#define N 1024

void multiplymatrix(long long **, long long **);

int main()
{
    long long k {100};
    long long **mat = new long long *[M];
    long long **mat2 = new long long *[M];

    for(int i = 0; i < M; i++)
    {
        mat[i] = new long long[N];
        mat2[i] = new long long[N];
    }

    std::cout << "Created";

    for (long long i = 0; i < M; i++)
        for(long long j = 0; j < N; j++)
            mat[i][j] = ++k;

    for (long long i = 0; i < M; i++)
        for(long long j = 0; j < N; j++)
            mat2[i][j] = ++k;

    multiplymatrix(mat, mat2);
}

void multiplymatrix(long long **matrix1, long long **matrix2)
{
    long long **matrix3 = new long long*[M];

    for(int i = 0; i < M; i++)
        matrix3[i] = new long long[N];

    auto t1 = std::chrono::high_resolution_clock::now();

    for (long long i = 0; i < M; i++)
        for(long long j = 0; j < N; j++)
            for(long long k = 0; k < M; k++)
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];


    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = t2 - t1;
    float ms = duration.count() * 1000.0f;
    float s = ms/1000;

    // for (long long i = 0; i < M; i++)
    // {
    //     for(long long j = 0; j < N; j++)
    //         std::cout << "\t" << matrix3[i][j];
    //     std::cout << std::endl;
    // }

    std::cout << "\n" << ms <<"ms\t" << s  << "s"<< std::endl;
}