using System;

namespace matrix
{
    class matrix
    {
        static void Main(String[] args)
        {
            int M = 1024, N = 1024;
            int[,] mat = new int[M, N];
            int[,] mat2 = new int[M, N];
            int[,] mat3 = new int[M, N];
            int k = 100;

            for(int i = 0; i < M; i++)
                for(int j = 0; j < N; j++)
                {
                    mat[i,j] = ++k;
                    mat2[i,j] = ++k;
                }

            var watch = new System.Diagnostics.Stopwatch();
            Console.WriteLine("Begin");
            watch.Start();

            for(int i = 0; i < M; i++)
                for(int j = 0; j < N; j++)
                    for(int l = 0; l < M; l++)
                        mat3[i,j] += mat[i,l] * mat2[l,j];

            watch.Stop();
            long ms = watch.ElapsedMilliseconds;
            long s = ms / 1000;
            Console.WriteLine($"{ms}ms, {s}s");
        }
    }
}