namespace Day4
{
    internal class Program
    {
        static void part1(List<List<char>> map)
        {
            List<(int dx, int dy)> dirs = [
                (1, 0), 
                (1, -1), 
                (1, 1), 
                (-1, -1), 
                (-1, 1), 
                (-1, 0), 
                (0, 1), 
                (0, -1),
            ];

            int cnt = 0;
            for (int y = 0; y < map.Count; y++)
            {
                for (int x = 0; x < map[y].Count; x++)
                {
                    if (map[x][y] != '@') continue;
                    int lcnt = 0;
                    foreach ((int dx, int dy) in dirs)
                    {
                        if (x + dx >= map[y].Count || x + dx < 0 || y + dy >= map.Count || y + dy < 0) continue;
                        if (map[x + dx][y + dy] == '@') lcnt++;
                    }

                    if (lcnt < 4) cnt++;
                }
            }

            Console.WriteLine("part1: " + cnt);
        }

        static void part2(List<List<char>> map)
        {
            List<(int dx, int dy)> dirs = [
                (1, 0),
                (1, -1),
                (1, 1),
                (-1, -1),
                (-1, 1),
                (-1, 0),
                (0, 1),
                (0, -1),
            ];

            List<(int, int)> changeLater = [];
            int cnt = 0;
            do
            {
                changeLater.Clear();

                for (int y = 0; y < map.Count; y++)
                {
                    for (int x = 0; x < map[y].Count; x++)
                    {
                        if (map[x][y] != '@') continue;

                        int lcnt = 0;
                        foreach ((int dx, int dy) in dirs)
                        {
                            if (x + dx >= map[y].Count || x + dx < 0 || y + dy >= map.Count || y + dy < 0) continue;
                            if (map[x + dx][y + dy] == '@') lcnt++;
                        }

                        if (lcnt < 4)
                        {
                            cnt++;
                            changeLater.Add((x, y));
                        }
                    }
                }

                foreach ((int x, int y) in changeLater) map[x][y] = '.';
            } while (changeLater.Count > 0);

            Console.WriteLine("part2: " + cnt);
        }

        static void Main(string[] args)
        {
            List<List<char>> map = [];
            string inp = "start";

            while (true)
            {
                inp = Console.ReadLine()!;
                if (inp == "") break;
                map.Add(inp.Select(x => x).ToList());
            }

            part1(map);
            part2(map);
        }
    }
}
