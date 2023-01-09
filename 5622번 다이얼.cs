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
            int[] arr = new int[] { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
            string st = Console.ReadLine();
            int sum = 0;
            for (int i = 0; i < st.Length; i++)
                sum += arr[st[i] - 'A'];
            Console.WriteLine($"{sum}");
        }
    }
}

