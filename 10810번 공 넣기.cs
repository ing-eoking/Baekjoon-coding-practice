using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            String[] buf = Console.ReadLine().Split('\x020');
            int N = Convert.ToInt32(buf[0]), M = Convert.ToInt32(buf[1]),i,j,k;
            int [] h = new int [N+1];
            for(int a = 0; a < M; a++)
            {
                buf = Console.ReadLine().Split('\x020');
                i = Convert.ToInt32(buf[0]);
                j = Convert.ToInt32(buf[1]);
                k = Convert.ToInt32(buf[2]);
                for(int b = i; b <= j; b++)
                {
                    h[b] = k;
                }
            }
            for (int idx = 1; idx <= N; idx++)
                Console.Write($"{h[idx]} ");
        }
    }
}

