using System;

namespace Day2
{
    internal class Program
    {
        static List<long> repeatsp1(long lo, long hi)
        {
            List<long> rps = [];

            // Split up longo groups of length 2k 
            long minlen = lo.ToString().Length;
            long maxlen = hi.ToString().Length;

            if (minlen % 2 == 1) minlen++;
            if (maxlen % 2 == 1) maxlen--;
            
            for (long i = minlen; i <= maxlen; i += 2)
            {
                long half = i / 2;
                long start = (long)Math.Pow(10, half - 1);
                long end = (long)Math.Pow(10, half);
                for (long k = start; k < end; k++)
                {
                    long num = k + k * end;
                    if (num >= lo && num <= hi) rps.Add(num);
                }
            }

            return rps;
        }

        static List<long> repeatsp2(long lo, long hi)
        {
            HashSet<long> rps = [];

            // Split up groups of length 2k 
            int minlen = lo.ToString().Length;
            int maxlen = hi.ToString().Length;

            for (int len = minlen; len <= maxlen; len++)
            {
                for (int k = 2; k <= len; k++)
                {
                    if (len % k != 0) continue; // not divisible by k

                    int numlen = len / k;

                    long start = (long)Math.Pow(10, numlen - 1);
                    long end = (long)Math.Pow(10, numlen);

                    for (long i = start; i < end; i++)
                    {
                        long sum = i;
                        for (int j = 1; j < k; j++) sum = sum * end + i;
                        if (sum >= lo && sum <= hi) rps.Add(sum);
                    }
                }
            }

            return rps.ToList();
        }

        static void part1()
        {
            string inp = Console.ReadLine()!;
            List<List<long>> ranges = inp.Split(",").Select(x => x.Split("-").Select(long.Parse).ToList()).ToList();

            long sum = 0;
            foreach (var x in ranges)
            {
                sum += repeatsp1(x[0], x[1]).Sum();
            }
            Console.WriteLine(sum);
        }

        static void part2()
        {
            string inp = Console.ReadLine()!;
            List<List<long>> ranges = inp.Split(",").Select(x => x.Split("-").Select(long.Parse).ToList()).ToList();

            long sum = 0;
            foreach (var x in ranges)
            {
                sum += repeatsp2(x[0], x[1]).Sum();
            }
            Console.WriteLine(sum);
        }


        static void Main(string[] args)
        {
            //part1();
            part2();
        }
    }
}

// 11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124