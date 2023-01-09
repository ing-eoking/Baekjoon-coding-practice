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
            string[] croa = new string[] { "dz=","z=","c=","c-","d-","lj","nj","s="};
            string st = Console.ReadLine();
            for (int i = 0; i < croa.Length; i++)
                st = st.Replace(croa[i], "*");
            Console.WriteLine($"{st.Length}");
        }
    }
}

