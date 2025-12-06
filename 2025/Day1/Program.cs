namespace Day1
{
    internal class Program
    {
        static void part1()
        {
            int curr = 50;
            int cnt = 0;
            while (true)
            {
                string inp = Console.ReadLine();
                if (inp == "stop" || inp == "")
                {
                    break;
                }
                
                int val = int.Parse(inp.Substring(1));
                if (inp[0] == 'L') val = -val;
                curr = (100 + (curr + val)) % 100;
                if (curr == 0) cnt++;
            }
            Console.WriteLine(cnt);
        }

        static void part2()
        {
            int curr = 50;
            int cnt = 0;
            while (true)
            {
                string inp = Console.ReadLine();
                if (inp == "stop" || inp == "")
                {
                    break;
                }

                int val = int.Parse(inp.Substring(1));
                int delta = inp[0] == 'L' ? -1 : 1;
                for (int i = 0; i < val; i++)
                {
                    curr += delta;
                    if (curr == -1)
                    {
                        curr = 99;
                    }
                    if (curr == 100)
                    {
                        curr = 0;
                    }
                    if (curr == 0) cnt++;
                }
            }
            Console.WriteLine(cnt);
        }

        static void Main(string[] args)
        {
            //part1();
            part2();
        }
    }
}
