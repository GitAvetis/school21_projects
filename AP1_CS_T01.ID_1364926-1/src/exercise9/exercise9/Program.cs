namespace exercise9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("First test\n");
            TestMyList1();
            Console.WriteLine();
            Console.WriteLine("Second test\n");
            TestMyList2();
            Console.WriteLine();
            Console.WriteLine("Third test\n");
            TestMyList3();
            Console.ReadKey();
        }

        static void TestMyList1()
        {
            List<int> first_test = [37, 45, 78, 99];
            MyList<int> my_list = new MyList<int>();
            List_to_MyList(first_test, my_list);
            Console.Write("Before add: ");
            PrintMyList(my_list);
            my_list.Add(119);
            Console.Write("After add 119 in List: ");
            PrintMyList(my_list);

        }
        static void TestMyList2()
        {
            List<int> second_test = [37, 45, 78, 99, 578];
            MyList<int> my_list = new MyList<int>();
            List_to_MyList(second_test, my_list);
            Console.Write("List elements: ");
            foreach (var item in second_test)
            {
                if (item != second_test[second_test.Count - 1])
                    Console.Write(item + ", ");
                else
                    Console.WriteLine(item);
            }
            Console.WriteLine("Result of count: " + my_list.Count);
            Console.WriteLine();
        }

        static void TestMyList3()
        {
            List<int> third_test = [37, 45, 135, 999, 0];
            MyList<int> my_list = new MyList<int>();
            List_to_MyList(third_test, my_list);
            Console.Write("Before remove: ");
            PrintMyList(my_list);
            my_list.Remove(999);
            Console.Write("After remove 78 from List: ");
            PrintMyList(my_list);
        }

        static void PrintMyList(MyList<int> test_data)
        {
            for (int i = 0; i < test_data.Count; i++)
            {
                if (i != test_data.Count - 1)
                    Console.Write(test_data[i] + ", ");
                else
                    Console.WriteLine(test_data[i]);
            }

        }

        static void List_to_MyList(List<int> source, MyList<int> destination)
        {
            foreach (var item in source)
            {
                destination.Add(item);
            }
        }
    }
}