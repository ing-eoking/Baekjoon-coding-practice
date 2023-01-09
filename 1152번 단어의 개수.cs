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
            int c = 0;
            for (int i = 0; i < arr.Length; i++)
                if (String.IsNullOrEmpty(arr[i])) c++;
            Console.WriteLine($"{arr.Length-c}");
        }
    }
}
