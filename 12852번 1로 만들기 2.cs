using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine()), cur, sz;
            int[][] nums = new int[N + 1][];
            nums[1] = new int[0];
            Queue<int> q = new Queue<int>();
            q.Enqueue(1);
            while ((cur = q.Dequeue()) != N)
            {

                sz = nums[cur].Length;
                if (cur * 3 <= N && nums[cur * 3] == null)
                {
                    q.Enqueue(cur * 3);
                    nums[cur * 3] = new int[sz + 1];
                    Array.Copy(nums[cur], nums[cur * 3], sz);
                    nums[cur * 3][sz] = cur;

                }
                if (cur * 2 <= N && nums[cur * 2] == null)
                {
                    q.Enqueue(cur * 2);
                    nums[cur * 2] = new int[sz + 1];
                    Array.Copy(nums[cur], nums[cur * 2], sz);
                    nums[cur * 2][sz] = cur;
                }
                if (cur + 1 <= N && nums[cur + 1] == null)
                {
                    q.Enqueue(cur + 1);
                    nums[cur + 1] = new int[sz + 1];
                    Array.Copy(nums[cur], nums[cur + 1], sz);
                    nums[cur + 1][sz] = cur;
                }
            }
            Console.WriteLine($"{nums[N].Length}");
            Console.Write($"{N}");
            for(int i = nums[N].Length -1; i >=0; i--) Console.Write($" {nums[N][i]}");

        }
    }
}

