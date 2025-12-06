namespace Day5
{
    internal class Program
    {
        static void part1(List<(long, long)> ranges, List<long> queries)
        {
            int cnt = 0;
            foreach (long q in queries)
            {
                foreach ((long lo, long hi) in ranges)
                {
                    if (q >= lo && q <= hi)
                    {
                        cnt++;
                        break;
                    }
                }
            }

            Console.WriteLine("Part1: " + cnt);
        }
        static void part2(List<(long, long)> ranges, List<long> queries)
        {
            bool changed = false;
            do
            {
                changed = false;
                for (int i = 0; i < ranges.Count; i++)
                {
                    for (int j = i + 1; j < ranges.Count; j++)
                    {
                        // Check if we can merge the two ranges; if so, merge into the first, delete the second
                        if (ranges[i].Item1 <= ranges[j].Item2 && ranges[j].Item1 <= ranges[i].Item2)
                        {
                            (long, long) newRange = (Math.Min(ranges[i].Item1, ranges[j].Item1), Math.Max(ranges[i].Item2, ranges[j].Item2));
                            ranges[i] = newRange;
                            changed = true;
                            ranges[j] = ranges[^1];
                            ranges.RemoveAt(ranges.Count - 1);
                            j--;
                        }
                    }
                }
            } while (changed);

            long cnt = 0;
            foreach (var range in ranges)
            {
                cnt += range.Item2 - range.Item1 + 1;
            }

            Console.WriteLine("Part2: " + cnt);
        }

        static void Main(string[] args)
        {
            List<(long, long)> ranges = [];
            List<long> queries = [];

            string inp = "start";
            while (inp != "")
            {
                inp = Console.ReadLine()!;
                if (inp == "") break;
                var x = inp.Split("-");
                ranges.Add((long.Parse(x[0]), long.Parse(x[1])));
            }

            inp = "start2";
            while (inp != "")
            {
                inp = Console.ReadLine()!;
                if (inp == "") break;
                queries.Add(long.Parse(inp));
            }

            part1(ranges, queries);
            part2(ranges, queries);
        }
    }
}

