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
            int N = Convert.ToInt32(Console.ReadLine()),sum = 0;
            for(int n  = 0; n < N; n++)
            {
                bool[] alpha = new bool[26];
                bool tf = true;
                string word = Console.ReadLine();
                char cur = ' ';
                for (int i = 0; i < word.Length; i++)
                    if (cur != word[i]) {
                        cur = word[i];
                        if (alpha[cur - 'a']) {
                            tf = false;
                            break; 
                        }
                        alpha[cur - 'a'] = true;
                    }
                if (tf) sum++;
            }
            Console.WriteLine($"{sum}");
        }
    }
}

