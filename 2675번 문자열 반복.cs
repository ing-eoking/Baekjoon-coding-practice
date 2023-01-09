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
            int T = Convert.ToInt32(Console.ReadLine());
            for(int t = 0; t < T; t++)
            {
                string[] TC = Console.ReadLine().Split('\x020');
                for (int i = 0; i < TC[1].Length; i++)
                    Console.Write(String.Concat(Enumerable.Repeat(TC[1][i], Convert.ToInt32(TC[0]))));
                Console.Write("\n");
            }
        }
    }
}
