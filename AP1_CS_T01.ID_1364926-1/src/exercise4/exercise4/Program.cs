namespace exercise4
{
    internal class Program
    {
        static void Main()
        {
            Console.WriteLine("Enter values:");
            string? input_line = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(input_line))
            {
                bool success_input = true;
                
                int[] list_input = Input(ref success_input, input_line);
                if (success_input)
                {
                    ListNode head = Create_List(list_input);
                    int node_lenth = list_input.Length;

                    ListNode new_node = Lists_positions_switch(head);

                    for (int i = 0; i < node_lenth; i++)
                    {
                        Console.Write(new_node.val + " ");
                        new_node = new_node.next;

                    }
                }
                Console.ReadKey();
            }

        }

        static ListNode Lists_positions_switch(ListNode head)
        {
            Stack<ListNode> stack = new();
            ListNode current = head;
            while (current != null)
            {
                stack.Push(current);
                current = current.next;
            }
            
            current =  head;
            ListNode result = current;
            int counter = stack.Count / 2;

            for (int i = 0; i < counter; i++){
                ListNode last = stack.Pop();
                ListNode tmp = current.next;
                current.next = last;
                last.next = tmp;
                current = tmp;
            }

            current.next = null;

            return result;
        }

        static ListNode Create_List(int[] list_input)
        {
            ListNode head = new(list_input[0]);
            ListNode current = head;

            for (int i = 1; i < list_input.Length; i++)
            {
                current.next = new ListNode(list_input[i]);
                current = current.next;
            }
            return head;
        }

        static int[] Input(ref bool success_input, string input_line)
        {
            string[] input_mass = input_line.Split(',');
            int[] list_input = new int[input_mass.Length];
            for (int i = 0; i < input_mass.Length; i++)
            {
                try
                {
                    list_input[i] = int.Parse(input_mass[i]);
                }
                catch
                {
                    Console.WriteLine("Couldn't parse a number. Please, try again");
                    success_input = false;
                    break;
                }
            }
            return list_input;
        }
    }

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

}
