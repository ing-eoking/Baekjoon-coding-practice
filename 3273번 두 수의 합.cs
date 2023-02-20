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
            SortedSet<int> h = new SortedSet<int>();
            for(int i = 0; i < N; i++)
                h.Add(Convert.ToInt32(snum[i]));
            int x = Convert.ToInt32(Console.ReadLine()), answer = 0;
            foreach (int v in h)
            {
                if (v >= x / 2 + x % 2) break;
                if (h.Contains(x - v)) answer++;
            }
            Console.WriteLine($"{answer}");
        }
    }
}

