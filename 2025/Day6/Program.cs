using System.Security.Cryptography;

namespace Day6
{
    internal class Program
    {
        //static int numRows = 3; // sample
        static int numRows = 4; // actual

        static void part1()
        {
            List<List<long>> nums = [];

            for (int i = 0; i < numRows; i++)
            {
                List<long> numRow = [];
                string inp = Console.ReadLine()!;
                long num = 0;
                for (int j = 0; j < inp.Length; j++)
                {
                    if (inp[j] >= '0' && inp[j] <= '9')
                    {
                        num = num * 10 + inp[j] - '0';
                    }
                    else if (num != 0)
                    {
                        numRow.Add(num);
                        num = 0;
                    }
                }
                if (num != 0) numRow.Add(num);
                nums.Add(numRow);
            }

            List<char> ops = Console.ReadLine()!.Where(x => x != ' ').ToList();

            long sum = 0; 

            for (int i = 0; i < nums[0].Count; i++)
            {
                long acc = nums[0][i];
                for (int j = 1; j < numRows; j++)
                {
                    if (ops[i] == '*') acc *= nums[j][i];
                    else acc += nums[j][i];
                }
                sum += acc;
            }

            Console.WriteLine("Part1: " + sum);
        }
        static void part2()
        {
            List<string> numinp = [];
            for (int i = 0; i < numRows; i++) numinp.Add(Console.ReadLine()!);

            List<List<long>> nums = [[]];
            // Detect column breaks
            for (int i = 0; i < numinp[0].Length; i++)
            {
                bool allSpaces = true;
                for (int j = 0; j < numRows; j++)
                {
                    allSpaces &= numinp[j][i] == ' ';
                }

                if (allSpaces)
                {
                    nums.Add([]);
                }
                else
                {
                    int num = 0;
                    for (int j = 0; j < numRows; j++)
                    {
                        if (numinp[j][i] == ' ') continue;
                        else
                        {
                            num = num * 10 + numinp[j][i] - '0';
                        }
                    }
                    nums[^1].Add(num);
                }

            }
            List<char> ops = Console.ReadLine()!.Where(x => x != ' ').ToList();

            long sum = 0;
            for (int i = 0; i < nums.Count; i++)
            {
                long acc = nums[i][0];
                for (int j = 1; j < nums[i].Count; j++)
                {
                    if (ops[i] == '*') acc *= nums[i][j];
                    else acc += nums[i][j];
                }
                sum += acc;
            }

            Console.WriteLine("Part 2: " + sum);
        }

        static void Main(string[] args)
        {
            //part1();
            part2();
        }
    }
}

//123 328  51 64
// 45 64  387 23
//  6 98  215 314
//* +*+ 