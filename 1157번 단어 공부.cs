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
            int[] arr = new int[26];
            string A = Console.ReadLine();
            int max = 0;
            char t = '?';
            for(int i = 0; i < A.Length; i++)
            {
                int a = A[i] > 'Z' ? (A[i] - 'a') : (A[i] - 'A');
                arr[a]++;
                if (max < arr[a])
                {
                    max = arr[a];
                    t = (char)('A' + a);
                }
                else if (max == arr[a]) t = '?';
            }
            Console.WriteLine(t);
        }
    }
}
