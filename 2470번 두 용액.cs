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
            string[] snum = Console.ReadLine().Split('\x020');
            int[] nums = new int[N];
            for (int i = 0; i < N; i++)
                nums[i] = Convert.ToInt32(snum[i]);
            Array.Sort(nums);
            int l = 0, r = N - 1, min = 2000000000, mr = N - 1, ml = 0;
            while(l < r)
            {
                int s = nums[l] + nums[r];
                if(min > Math.Abs(s))
                {
                    min = Math.Abs(s);
                    ml = nums[l];
                    mr = nums[r];
                    if (s == 0) break;
                }
                if (s < 0) l++;
                else r--;
            }
            Console.WriteLine($"{ml} {mr}");
        }
    }
}

