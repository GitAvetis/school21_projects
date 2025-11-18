namespace exercise6
{
    internal class Program
    {
        static void Main()
        {
            int[] parent = null;
            string nodes = "";
            while (!MainCycle(ref parent, ref nodes))
            { }
            Console.ReadKey();
        }

        static bool MainCycle(ref int[] parent, ref string nodes)
        {
            int err_code = 0;

            Input(ref parent, ref nodes, ref err_code);
            if (err_code > 0)
            {
                Console.WriteLine("Couldn't parse a words. Please, try again");
                return false;
            }
            else
            {
                List<int> pathSoFar = new List<int>();
                Console.WriteLine("\n Result:\n");
                Console.WriteLine(Max_path_length(MakingTree(parent, nodes), ref pathSoFar));
                foreach (int node in pathSoFar)
                {
                    if (node == pathSoFar[pathSoFar.Count - 1])
                        Console.Write(node);
                    else Console.Write(node + ", ");
                }
                return true;
            }
        }
        static void Input(ref int[] parent, ref string nodes, ref int err_code)
        {
            try
            {
                Console.WriteLine(" Enter parents nodes:");
                string[] first_line = Console.ReadLine().Split(',', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries);
                parent = new int[first_line.Length];

                for (int i = 0; i < first_line.Length; i++)
                {
                    parent[i] = int.Parse(first_line[i]);
                }
            }
            catch
            {
                err_code++;
            }
            Console.WriteLine(" Enter nodes values:");
            nodes = Console.ReadLine();
            if (nodes.Length != parent.Length)
                err_code++;
        }

        struct Node
        {
            public int id;
            public char value;
            public List<int> Neighbours;
        }

        static List<Node> MakingTree(int[] parent, string nodes)
        {
            List<Node> nodes_list = new List<Node>();// сначала создаём список из структур узлов с пустыми полями для детей 

            for (int i = 0; i < parent.Length; i++)
            {
                nodes_list.Add(new Node
                {
                    id = i,
                    value = nodes[i],
                    Neighbours = new List<int>()
                });
            }

            for (int i = 1; i < parent.Length; i++)// т.к. мы начинаем с -1, то нулевой элемент мы пропустим 
            {
                int p = parent[i];// id узла 
                nodes_list[p].Neighbours.Add(i);
                nodes_list[i].Neighbours.Add(p);
            }

            return nodes_list;
        }

        static int Max_path_length(List<Node> nodes_list, ref List<int> resultPath)
        {
            int max_path_length = 0;
            for (int i = 0; i < nodes_list.Count; i++)
            {
                List<int> pathSoFar = new List<int>();
                Node_path_check(nodes_list, nodes_list[i], -1, ref max_path_length, pathSoFar, ref resultPath);
            }

            return max_path_length;
        }

        static void Node_path_check(List<Node> nodes_list, Node current, int parent_id, ref int max_path_length, List<int> pathSoFar, ref List<int> resultPath)
        {
            pathSoFar.Add(current.id);

            if (pathSoFar.Count > max_path_length)
            {
                max_path_length = pathSoFar.Count;
                resultPath = new List<int>(pathSoFar);
            }

            foreach (int neighbours_id in current.Neighbours)
            {
                Node neighbour = nodes_list[neighbours_id];
                if (neighbour.value != current.value && neighbour.id != parent_id)
                {
                    Node_path_check(nodes_list, neighbour, current.id, ref max_path_length, pathSoFar, ref resultPath);
                }
            }
            pathSoFar.RemoveAt(pathSoFar.Count - 1);
        }

    }
}
