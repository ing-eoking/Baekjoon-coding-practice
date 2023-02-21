using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void dfs(int l, int r, ref List<long> list, long sum, ref long [] w)
        {
            if(l > r) list.Add(sum);
            else
            {
                dfs(l + 1, r, ref list, sum, ref w);
                dfs(l + 1, r, ref list, sum + w[l], ref w);
            }

        }
        static void Main(string[] args)
        {
            String[] buf = Console.ReadLine().Split('\x020');
            long N = Convert.ToInt64(buf[0]), C = Convert.ToInt64(buf[1]);
            buf = Console.ReadLine().Split('\x020');
            long [] w = new long[N];
            for(int i = 0; i < N; i++) w[i] = Convert.ToInt64(buf[i]);
            List<long> p1 = new List<long>(), p2 = new List<long>();
            dfs(0, (int)(N / 2 - 1), ref p1, 0, ref w);
            dfs((int)N / 2, (int)(N - 1), ref p2, 0, ref w);
            p2.Sort();
            int c = 0;
            foreach(long i in p1)
            {
                int idx = p2.FindIndex(e => e > C - i);
                c += idx < 0 ? p2.Count : idx;
            }
            Console.WriteLine($"{c}");
        }
    }
}

