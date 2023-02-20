using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            int size = N, idx = 1, sum = 0;
            bool[] pri = new bool[N + 1];
            for (int i = 2; i <= Math.Sqrt(N); i++)
                for (int j = i + i; j <= N; j += i)
                {
                    if (!pri[j]) size--;
                    pri[j] = true;
                }
            int[] nums = new int[size];
            for (int i = 2; i <= N; i++) if (!pri[i]) nums[idx] = nums[idx++ - 1] + i;
            int l = 0, r = 0, answer = 0;
            while(l <= r && r < size)
            {
                if (nums[r] - nums[l] > N) l++;
                else if (nums[r] - nums[l] < N) r++;
                else
                {
                    answer++;
                    r++;
                }
            }

            Console.WriteLine($"{answer}");
        }
    }
}

