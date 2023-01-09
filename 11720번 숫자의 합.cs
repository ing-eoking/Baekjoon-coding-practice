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
            int n = Convert.ToInt32(Console.ReadLine());
            string s = Console.ReadLine();
            int sum = 0;
            for(int i = 0; i < n; i++)
                sum += (s[i] - '0');
            Console.WriteLine("{0}", sum);
        }
    }
}
