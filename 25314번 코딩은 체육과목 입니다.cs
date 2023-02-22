using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine())/4;
            while (N-- > 0) Console.Write("long ");
            Console.Write("int");
        }
    }
}

