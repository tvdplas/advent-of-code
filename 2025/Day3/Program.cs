namespace Day3
{
    internal class Program
    {
        static void part1(List<List<int>> joltage)
        {
            int sum = 0;
            foreach (var j in joltage)
            {
                List<List<int>> indexesOf = [];
                for (int i = 0; i < 10; i++) indexesOf.Add([]);
                
                for (int i = 0; i < j.Count; i++)
                {
                    indexesOf[j[i]].Add(i);
                }

                int best = 0;

                for (int startNum = 9; startNum >= 0; startNum--)
                {
                    if (indexesOf[startNum].Count == 0) continue;
                    for (int endNum = 9; endNum >= 0; endNum--)
                    {
                        if (indexesOf[endNum].Count == 0) continue;

                        int startIndex = indexesOf[startNum][0];
                        int endIndex = indexesOf[endNum][^1];
                        if (startIndex < endIndex) best = Math.Max(best, 10 * startNum + endNum);
                    }
                }

                sum += best;
            }
            Console.WriteLine("part1: " + sum);
        }



        static void part2(List<List<int>> joltage)
        {
            long sum = 0;
            foreach (var js in joltage)
            {
                List<List<long>> dp = [];
                for (int i = 0; i <= 12; i++)
                {
                    List<long> n = [];
                    for (int j = 0; j < js.Count; j++)
                    {
                        n.Add(-1);
                    }
                    dp.Add(n);
                }

                for (int j = 0; j < js.Count; j++)
                {
                    dp[0][j] = 0;
                    dp[1][j] = js[j];
                }


                for (int i = 2; i <= 12; i++)
                {
                    for (int j = js.Count - i; j >= 0; j--)
                    {
                        // Select this element; then we add its value and max value below it
                        for (int jp = j + 1; jp < js.Count; jp++)
                            dp[i][j] = Math.Max(dp[i][j], js[j] * (long)Math.Pow(10, i - 1) + dp[i - 1][jp]);
                        // Or not select this element, then we add the max value next to it
                        for (int jp = j + 1; jp < js.Count; jp++)
                            dp[i][j] = Math.Max(dp[i][j], dp[i][jp]);
                    }
                }

                long val = -1;
                for (int j= 0; j < js.Count; j++)
                {
                    val = Math.Max(val, dp[^1][j]);
                }
                sum += val;
            }
            Console.WriteLine("part2: " + sum);
        }

        static void Main(string[] args)
        {
            string inp = "start";
            List<List<int>> joltage = [];
            while (inp != "")
            {
                inp = Console.ReadLine();
                if (inp == "") break;
                List<int> j = [];
                foreach (char c in inp) j.Add(int.Parse(c.ToString()));
                joltage.Add(j);
            }

            part1(joltage);
            part2(joltage);
        }
    }
}
