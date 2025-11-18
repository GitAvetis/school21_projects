namespace exercise3

{

    internal class Program
    {
        static void Main()
        {

            while (!MainCycle()) { }
            Console.WriteLine("\npress any key...");
            Console.ReadKey();
        }

        static bool MainCycle()
        {

            Console.WriteLine("Enter cards values:");
            string? input_line = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(input_line))
                return false;

            bool success_input = true;
            int[] deck = Input(ref success_input, input_line);

            if (!success_input)
                return false;

            if (!All_values_unique(deck))
                return false;

            Array.Sort(deck);
            Print_queue(RestoredQueue(deck));

            return true;

        }

        static int[] Input(ref bool success_input, string input_line)
        {
            string[] input_mass = input_line.Split(',');
            int[] deck = new int[input_mass.Length];
            for (int i = 0; i < input_mass.Length; i++)
            {
                try
                {
                    deck[i] = int.Parse(input_mass[i]);

                }
                catch
                {
                    Console.WriteLine("Couldn't parse a number. Please, try again");
                    success_input = false;
                    break;
                }
            }
            return deck;
        }

        static bool All_values_unique(int[] deck)
        {
            bool result = true;

            for (int i = 0; i < deck.Length; i++)
            {
                int counter_of_deplicates = 0;
                foreach (var item in deck)
                {
                    if (item == deck[i])
                        counter_of_deplicates++;
                }

                if (counter_of_deplicates > 1)
                {
                    result = false;
                    Console.WriteLine("Values are not unique, try again");
                    break;
                }
            }

            return result;
        }

        static Queue<int> RestoredQueue(int[] sortedDeck)
        {
            Queue<int> resultRestoredQueue = new();

            for (int i = sortedDeck.Length - 1; i >= 0; i--)
            {
                Queue<int> tmpRestoredQueue = new();

                int c = resultRestoredQueue.Count;

                if (c > 0)
                {
                    for (int j = 0; j < c - 1; j++)
                    {
                        tmpRestoredQueue.Enqueue(resultRestoredQueue.Dequeue()); //все элементы выдёргиваем
                    }

                    foreach (var item in tmpRestoredQueue)
                        resultRestoredQueue.Enqueue(item);//к последнему элементу добавили те, что только что выдернули 
                }

                Queue<int> newQueue = new();
                newQueue.Enqueue(sortedDeck[i]);//в конец добавили новый элемент

                while (resultRestoredQueue.Count > 0)
                    newQueue.Enqueue(resultRestoredQueue.Dequeue());//добавить то, что уже там было 
                resultRestoredQueue = newQueue;

            }
            return resultRestoredQueue;

        }
        static void Print_queue(Queue<int> result)
        {
            while (result.Count > 0)
            {
                int actual_card = result.Dequeue();
                if (result.Count == 0)
                {
                    Console.Write(actual_card);
                }
                else
                {
                    Console.Write(actual_card + ",");
                }
            }
        }
    }
}
