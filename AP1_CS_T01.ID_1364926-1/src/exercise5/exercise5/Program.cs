using System.Text;

namespace exercise5
{
    internal class Program
    {
        static void Main()
        {
            string key_word = "";
            string output_path = "";
            int lines_counter = 0;
            int error_code = 0;
            string[] result = Input(ref lines_counter, ref key_word, ref error_code);
            Print_output(error_code, result, key_word, output_path);

            Console.ReadKey();
        }

        static void Print_output(int error_code, string[] result, string key_word, string path)
        {
            if (error_code == 0)
            {
                foreach (var item in result)
                {
                    Console.WriteLine(item);
                }
                int matches = Matches_counter(result, key_word);
                File_Exists(ref path, "output");
                File.WriteAllText(path, matches.ToString());
                Console.WriteLine(matches);
            }
            else if (error_code == 1)
            {
                Console.WriteLine("Input error. File doesn't exist");
            }
            else if (error_code == 2)
            {
                Console.WriteLine("Input error. Size <= 0");
            }
            else if (error_code == 3)
            {
                Console.WriteLine("nput error. Insufficient number of elements");
            }

        }
        static bool File_Exists(ref string path, string finding_folder)
        {
            string currentPath = Directory.GetCurrentDirectory();
            path = finding_folder;
            for (int i = 0; i < 10; i++)
            {
                string testsFolderPath = Path.Combine(currentPath, finding_folder);
                if (Directory.Exists(testsFolderPath))
                {
                    path = testsFolderPath;
                    break;
                }

                string parentPath = Path.GetDirectoryName(currentPath);
                if (string.IsNullOrEmpty(parentPath) || parentPath == currentPath)
                    break;

                currentPath = parentPath;
            }
            if (finding_folder == "tests")
            {
                path = Path.Combine(path, Console.ReadLine());
            }
            else if (finding_folder == "output")
            {
                path = Path.Combine(path, "result.txt");

            }
            if (File.Exists(path))
                return true;
            else return false;
        }
        static string[] Input(ref int lines_counter, ref string key_word, ref int error_code)
        {
            string path = "";
            if (File_Exists(ref path, "tests"))
            {
                string[] all_lines = File.ReadAllLines(path, Encoding.UTF8);
                lines_counter = int.Parse(all_lines[0]);
                if (lines_counter <= 0)
                {
                    error_code = 2;
                }
                else if (all_lines.Length < lines_counter + 1)
                {
                    error_code = 3;
                }
                else
                {
                    string[] result = new string[lines_counter];
                    for (int i = 0; i < lines_counter; i++)
                    {
                        result[i] = all_lines[i + 1];
                    }
                    key_word = all_lines[all_lines.Length - 1];
                    return result;
                }
            }
            else
            {
                error_code = 1;
            }
            return null;

        }
        static int Matches_counter(string[] result, string key_word)
        {
            int counter = 0;
            foreach (string line in result)
            {
                string[] words = line.Split(' ');
                char[] punctuation = { '.', ',', '!', '?', ';', ':' };
                foreach (string word in words)
                {
                    if (word.Trim(punctuation) == key_word)
                        counter++;
                }

            }
            return counter;
        }

    }
}
