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
            long A = Convert.ToInt64(buf[0]);
            long B = Convert.ToInt64(buf[1]);
            long C = Convert.ToInt64(buf[2]);
            Console.WriteLine($"{A + B + C}");
        }
    }
}

