
namespace exercise8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Student> students = null;
            while (!MainCycle(ref students))
            { }

            Console.ReadKey();
        }
        static bool MainCycle(ref List<Student> students)
        {
            students?.Clear();
            int group = 0;
            int err_code = GetUserInput(ref students, ref group);
            bool result = true;

            if (err_code == 1)
            {
                Console.WriteLine("Couldn't parse a words. Please, try again");
                result = false;
            }
            else if (err_code == 2)
            {
                Console.WriteLine("Incorrect input. Group  <= 0");
            }

            if (Classmates(students, group))
            {
                if (students != null && students.Count > 0)
                    PrintStudents(students);
            }
            else
            {
                Console.WriteLine("There are no students from such a group");
                result = false;

            }

            return result;
        }

        static int GetUserInput(ref List<Student> students, ref int group)
        {
            Console.WriteLine("Enter your data:");
            int error_code = 0;
            try
            {
                string? input = (Console.ReadLine());
                if (input == null)
                    return 1;
                if (!int.TryParse(input, out int num_of_lines) || num_of_lines <= 0)//перове значение - количество строк
                    return 1;
                students = new List<Student>();
                for (int i = 0; i < num_of_lines; i++)
                {
                    string? tmp_line = Console.ReadLine();
                    if (string.IsNullOrWhiteSpace(tmp_line))
                        return 1;
                    string[] tmp_line_split = tmp_line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    if (tmp_line_split.Length != 2)
                        return 1;

                    string student_name = tmp_line_split[0];

                    if (!int.TryParse(tmp_line_split[1], out int students_group))
                        return 1;
                    if (students_group <= 0)
                    {
                        error_code = 2;
                        continue; // пропускаем этот ввод, не добавляем, не выходим из цикла
                    }
                    Student student = new Student(student_name, students_group);
                    students.Add(student);

                }
                string? input_group = (Console.ReadLine());
                if (!int.TryParse(input_group, out group) || group <= 0)//перове значение - количество строк
                    return 2;

            }
            catch
            {
                return 1;
            }

            return error_code;

        }

        static bool Classmates(List<Student> students, int group)
        {
            if (students.Any(student => student.group == group))
            {
                students.RemoveAll(student => student.group != group);
                return true;

            }
            else return false;

        }

        static void PrintStudents(List<Student> students)
        {
            foreach (var student in students)
            {
                if (students[students.Count - 1] != student)
                    Console.Write(student.name + ", ");
                else
                    Console.WriteLine(student.name);
            }
        }
    }
}
