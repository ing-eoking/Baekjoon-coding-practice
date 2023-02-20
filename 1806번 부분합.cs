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
            string[] buf;
            buf = Console.ReadLine().Split('\x020');
            int N = Convert.ToInt32(buf[0]), S = Convert.ToInt32(buf[1]);
            buf = Console.ReadLine().Split('\x020');
            int[] nums = new int[N];
            int l = 0, sum = 0, min = 10000000;
            for(int i = 0; i < N; i++)
            {
                nums[i] = Convert.ToInt32(buf[i]);
                sum += nums[i];
                while(sum >= S && l < N)
                {
                    min = Math.Min(min, (i - l) + 1);
                    sum -= nums[l];
                    l++;
                }
            }
            if (min > 9999999) min = 0;
            Console.WriteLine($"{min}");
        }
    }
}

