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
            string[] arr = Console.ReadLine().Split('\x020');
            int A = Convert.ToInt32(new string(arr[0].Reverse().ToArray()));
            int B = Convert.ToInt32(new string(arr[1].Reverse().ToArray()));
            Console.WriteLine($"{(A > B ? A : B)}");
        }
    }
}

