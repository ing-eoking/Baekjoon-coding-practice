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
            int[] A = Enumerable.Repeat<int>(-1, 26).ToArray<int>();
            string s = Console.ReadLine();
            for (int i = 0; i < s.Length; i++)
                if (A[s[i] - 'a'] < 0) A[s[i] - 'a'] = i;
            for (int i = 0; i < A.Length; i++) Console.Write("{0} ", A[i]);
        }
    }
}
