# Project 01 — С#_Bootcamp  

Summary: In this project, you will learn about the main functions of the C# language .  

## Contents
 1. [Chapter I](#chapter-i)   
     - [Rules](#rules)   
 2. [Chapter II](#chapter-ii)  
     - [General Information](#general-information)  
 3. [Chapter III](#chapter-iii)      
     - [Task 0. Creating a Project](#task-0-creating-a-project)  
     - [Task 1. Finding the area of a convex quadrilateral](#task-1-finding-the-area-of-a-convex-quadrilateral)  
     - [Task 2. System of linear equations](#task-2-system-of-linear-equations)  
     - [Task 3. A deck of cards with numbers](#task-3-a-deck-of-cards-with-numbers)  
     - [Task 4. Changing the order in the list](#task-4-changing-the-order-in-the-list)  
     - [Task 5. Word frequency](#task-5-word-frequency)  
     - [Task 6. The longest path in a tree](#task-6-the-longest-path-in-a-tree)  
     - [Task 7. A dictionary](#task-7-a-dictionary)  
     - [Task 8. Students](#task-8-students)  
     - [Task 9. MyList](#task-9-mylist)  

         

## Chapter I
# Rules

1. All along the way you may feel a sense of uncertainty and a severe lack of information: that's okay. Don't forget that the information in the repository and Google is always with you. So are your peers and Rocket.Chat. Communicate. Search. Rely on common sense. Don't be afraid to make mistakes.
2. Be careful about the sources of information. Check. Think. Analyze. Compare. 
3. Read the tasks thoroughly. Reread it several times.  
4. Read the examples carefully. There may be something in them that is not explicitly stated in the task itself.
5. You may find inconsistencies, when something new in the terms of the task or examples conflicts with something you already know. If you come across such an inconsistency, try to figure it out. If you can’t, write the question in open questions and find out in the process of work. Do not leave open questions unresolved.  
6. If a task seems confusing or impossible to complete — it only seems that way. Try to decompose it. Most likely, some parts will become clear.  
7. There will be various tasks. Those marked with an c (\*) are for the more meticulous students. These tasks are more difficult and are not mandatory. But if you do them, you will gain additional experience and knowledge.
8. Don't try to fool the system and those around you. You will be fooling yourself first.
9. You got a question? Ask your neighbor on the right.  If that doesn't help, ask your neighbor on the left.
10. If you use help, you should always understand why and how.  Otherwise, the help will not make sense.
11. Always push only to the develop branch! The master branch will be ignored. Work in the src directory.
12. There should be no files in your directory other than those specified in the tasks.

## Chapter II
# General information

C# (C-Sharp) is an object-oriented programming language developed by Microsoft in 2001. Thanks to its long history and large community, the language has found use in a variety of fields: game development, mobile, desktop and web applications, artificial intelligence and machine learning applications.

So why did this language appear in the first place?

C# is a higher-level language that makes it easier to develop software for Windows. Also this language provides many useful things like type safety, multitasking and event support. 

C# was developed to create applications on the .NET platform. **The .Net Framework** was developed to work with Microsoft Windows operating systems.

.Net allows you to avoid installing separate environments for each programming language. Thus, installation time is reduced and much less memory is needed. You can also use .Net to develop one environment and use it for other languages.

There are 3 concepts you need to learn to understand the principles of .Net: **CLI, CIL and CLR**.

**CLI** — <i>Common Language Infrastructure</i>. With such an infrastructure, each language has its own compiler, but programs are not compiled into native code, but into intermediate bytecode — **CIL** — <i>Common Intermediate Language</i>. After the program is run, the intermediate code is passed to **CLR** — <i>Common Language Runtime </i> — an executable environment that turns the intermediate into native code, which starts executing.

**Main advantages of C#:**
1.	Cross-platform support: capable of running on multiple hardware platforms or operating systems due to .NET Core.
2.	Multipurpose: you can write everything from desktop applications to mobile applications, from web development to game development in C#.
3.	Helpful: the C# language is part of the C family, so after learning C# it is easier to understand languages like C, C++ and Java. 
4.	Friendship with Microsoft: C# was developed by Microsoft and is the primary language for the .NET platform. Therefore, you can access various Microsoft tools such as Visual Studio and Visual Studio Code.
5.	LINQ access: LINQ allows you to run queries on data from different sources (e.g. databases, XML files or collections in memory) using the same commands, i.e. you don't have to learn much.
6.	Security (prevention from errors): C# is a strictly typed language, which means that the compiler checks for type consistency before it is executed. This eliminates redundant debugging and increases program reliability.
7.	Garbage сollector: C# has a built-in garbage collector that automatically frees memory from variables that will no longer be used. So you don't have to worry about memory leaks and clearing it manually.

### Topics to study:
* Program entry point, program structure;
* Program compilation;
* Control structures (sequential, branching, repetition);
* Simple data types (purpose, size, in-memory representation, operations);
* Composite data types (purpose, size, in-memory representation, operations);
* Input/Output (stdin-stdout);
* Automatic, static and dynamic memory, garbage collector;
* Complex data structures (templates and generics).

## Chapter III

**Pay attention!** Each task must be prepared as an individual project. For example, `T01/src/exercise0`, `T01/src/exercise1`, ... , `T01/src/exerciseN-1`, where *N* is a number of tasks. If you need the previous task for the next one, simply copy the previous project to the directory of the next one and continue development in it.

## Task 0. Creating a Project
Create a new project in Visual Studio:

* Select Create Project in the start window.
* In the Create Project window, select All Languages, and then select C# from the drop-down list. 
* Select Windows from the All Platforms list. 
* Then, in the All project types list, select Console.
* Select Console Application.

## Task 1. Finding the area of a convex quadrilateral

Develop a math module that finds the area of a convex quadrilateral as the sum of the areas of the two triangles that form the quadrilateral.

* The program reads the coordinates of the vertices of the quadrilateral. 
* The program works with real numbers.
* The program calculates and outputs the area of a quadrilateral.
* The program does not terminate with an error if the input data is incorrect. The output: «Couldn't parse a number. Please, try again».
* Use only simple types.
<br>(Hint: use Heron's formula.)

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>hfjkj<br>-1.0<br>-1.0<br>1.0<br>4.0<br>3.0<br>0.0<br>1.0<br>-1.0</td>
        <td>Couldn't parse a number. Please, try again
Square = 10</td>
    </tr>
 <tr>
        <td>-4.0<br>-3.0<br>-2.0<br>6.0<br>5.0<br>3.0<br>7.0<br>-3.0	</td>
        <td>Square = 67.5</td>
    </tr>
</table>

## Task 2. System of linear equations

Develop a math module that solves linear equations using the Gaussian method.

* The program reads the path to the file. 
* The program reads the extended system matrix into an array.
* The program works with integers.
* The program outputs the found solution of the linear equation.
* If the equation does not have solutions, the program prints: “The system of linear algebraic equations has no solutions”.
* The program does not terminate with an error if the input data is incorrect. The output: «Couldn't parse a number. Please, try again».
* If the file does not exist, the output: «Input error. File isn't exist».

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>2 1 1 2<br>
        1 -1 0 -2<br>
        3 -1 2 2</td>
        <td>x1 = -1 <br> x2 = 1<br>x3 = 3</td>
    </tr>
 <tr>
        <td>fdfhjk<br>7 -2 -1 2<br>
        6 -4 -5 3<br>
        1 2 4 5</td>
        <td>Couldn't parse a number. Please, try again<br>The system of linear algebraic equations has no solutions
        </td>
    </tr>
</table>

## Task 3. A deck of cards with numbers

Develop a logic module that reveals a deck of cards in a specific order.

* The numbers are read into the deck array.
* The program works with integers. The numbers must be unique.
* deck[i] is the number on the i-th card.
* Initially, all cards in the deck (array) are considered unrevealed.
* After a card is revealed, it is removed from the array.
* The initial order of the cards in the array does not matter.
* The program itself changes the order of the cards so that the cards are revealed in ascending order, and outputs the deck array in the resulting correct order.
* The program repeats the following steps until all cards are revealed:
    1. Take the top card of the deck, reveal it, and remove it from the deck.
    2. If there are still cards in the deck, put the next top card of the deck into the bottom of the deck.
    3. If there are still unrevealed cards, go back to step 1. Otherwise, stop.
* Note that the first entry in the answer is considered the top entry in the deck.
* The program does not terminate with an error if the input data is incorrect. The output: «Couldn't parse a number. Please, try again».
* Implement a queue in this program.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>17,13,11,2,3,5,7
</td>
        <td>2,13,3,11,5,17,7</td>
    </tr>
 <tr>
        <td>1, 1000</td>
        <td>1, 1000</td>
    </tr>
</table>

## Task 4. Changing the order in the list

Develop a logic module that changes the order of nodes in a list.

* It is necessary to create a class of a single linked list as follows:<br>
```c#
 public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int val=0, ListNode next=null) {
            this.val = val;
            this.next = next;
        }
}
```
* The program reads the values of the list nodes and creates a list based on them.
* The list can be presented as follows: L0 → L1 → ... → Ln - 1 → Ln.
* The program should change the order of the list in this way: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
* You cannot change values in list nodes. You can only change the nodes.
* Use stack to implement this program.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>1, 2, 3, 4</td>
        <td>1, 4, 2, 3</td>
    </tr>
 <tr>
        <td>1, 2, 3, 4, 5</td>
        <td>1, 5, 2, 4, 3</td>
    </tr>
</table>

## Task 5. Word frequency

Develop a logic module that counts how many times a certain word occurs in an array of strings.

* The program reads the path to the file. 
* The program reads the number of lines.
* The program reads each new line from the file into an array until it reaches the end of the file.
* After reading all lines, the program receives the word whose frequency needs to be calculated.
* The program works with strings. 
* If a negative number of numbers or zero is entered, it should output: «Input error. Size <= 0».
* If fewer elements were counted than the number + 1, it should output: «Input error. Insufficient number of elements».
* The program outputs to the console the read lines and the word whose frequency should be calculated.
* The program saves to the file "result.txt" and outputs to the console how many times the given word occurred.
* Use only simple types.

<table>
    <tr>
        <th>file1.txt</th>
    </tr>
    <tr>
        <td>2<br>I love learning different programming languages<br>But all languages are so different that I can't say for sure which one is better<br>languages</td>
    </tr>
</table>
<table>
    <tr>
        <th>file2.txt</th>
    </tr>
    <tr>
        <td>2<br>There are a lot books in this world<br>Their number is so huge that it would take a lifetime to read them them<br>life</td>
    </tr>
</table>

<table>
    <tr>
        <th>Input</th>
        <th>Output to the console</th>
	<th>Output to the result.txt</th>
    </tr>
    <tr>
        <td>file1.txt</td>
        <td>I love learning different programming languages<br>But all languages are so different that I can't say for sure which one is better<br>languages<br>2</td>
 <td>2</td>
    </tr>
 <tr>
        <td>file2.txt</td>
        <td>There are a lot books in this world<br>Their number is so huge that it would take a lifetime to read them them<br>life<br>0</td>
 <td>0</td>
    </tr>
  <tr>
        <td>fileIsNotExist.txt</td>
        <td>Input error. File doesn't exist</td>
 <td></td>
    </tr>
</table>

## Task 6. The longest path in a tree

Develop a module that searches for the longest path in a tree with different neighboring characters.

* It is necessary to create a tree in the program (i.e. a connected, undirected graph with no cycles) with the root at node 0, consisting of n nodes numbered from 0 to n - 1. 
* The tree is represented by an array parent of size n, where parent element[i] is the parent element of node i. Since node 0 is the root node, parent element[0] == -1.
* Values of nodes in the tree are letters of the English alphabet.
* The program reads the parent array. 
* The parent array contains only integers.
* The program reads the string s, where s[i] is the character assigned to node i.
* The program outputs the length of the longest path in the tree in a way that no pair of adjacent nodes on the path is assigned the same character.
* The program outputs the path itself (we will call the path the order of nodes)
* The program does not terminate with an error if the input data is incorrect. The output: «Couldn't parse a word. Please, try again».
* You can use structures in this program.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>-1, 0, 0, 1, 1, 2<br>abacbe</td>
        <td>3<br>0, 1, 3</td>
    </tr>
 <tr>
        <td>-1, 0, 0, 0<br>aabc</td>
        <td>3<br> 2, 0, 3</td>
    </tr>
</table>

## Task 7. A dictionary

Develop a module that after receiving a pair of Product - Price values as input, creates a dictionary from them and then finds the arithmetic mean of all the prices received.

* The program reads the number of pairs. 
* The program reads each pair of Product - Price values into a dictionary, where Product is the key, Price is the value.
* The program works with reference data types.
* The first value entered in the pair must be a string, the second – a real number. 
* If a negative or zero price is entered, the program outputs: «Incorrect input. price <= 0» and moves on to the next input. 
* The program outputs the arithmetic mean of all entered prices. Precision: 3 decimal places.
* The program does not terminate with an error if the input data is incorrect. The output: «Couldn't parse a word. Please, try again».

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>4<br>Milk 99.0<br>Meat 375.78<br>Eggs 78.99<br>Bread 39.99</td>
        <td>148.44</td>
    </tr>
 <tr>
        <td>2<br>Cucumbers 180.99<br>Tomatoes 147.96</td>
        <td>164.475</td>
    </tr>
 <tr>
        <td>3<br>Yogurt 78.57<br>Kefir -750.45<br>Tea 299.99</td>
        <td>Incorrect input. price <= 0<br>	189.28</td>
    </tr>
</table>

## Task 8. Students 

Develop a module that searches for all students from the same group.

* Create a Student class with two fields: String name, Integer group. 
* The Student class must be in a separate file. 
* The program reads the number of students.
* Each read user is added to the list. 
* If a negative or zero group is entered, the program outputs: «Incorrect input. Group <= 0» and moves on to the next input. 
* After the students the number of the group is read.
* The program does not terminate with an error if the input data is incorrect. The output: «Couldn't parse a word or number. Please, try again». 
* The program should output the names of students from a given group.
* If there are no students from such a group, the program prints a message: «There are no students from such a group». 
* The program works with reference data types.

<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>5<br>Ivan 111
<br>Harry 254
<br>Olga 111
<br>Irina 344
<br>Yoongi 458
<br>111</td>
        <td>Ivan, Olga</td>
    </tr>
 <tr>
        <td>3<br>
Carry 547
<br>Ben 124
<br>Tom 423
<br>249</td>
        <td>There are no students from such a group</td>
    </tr>
 <tr>
        <td>5
<br>Peter 145
<br>Maria 362
<br>John -457
<br>Edward 375
<br>Taehyung 362
<br>362</td>
        <td>Incorrect input. Group <= 0
	Maria, Taehyung</td>
    </tr>
</table>

## Task 9. MyList 

Develop a MyList class that implements the primitive actions of the List<T> class.

* You need to create your own MyList<T> class that adopts a small number of actions from the List class.
* Actions such as Add, Count and Remove need to be implemented.
* The Add function adds an item to the list and returns nothing.
* The Count function returns the number of items in the list.
* The Remove function removes the specified item and returns nothing.
* Use only generic templates.
<table>
    <tr>
        <th>Input</th>
        <th>Output</th>
    </tr>
    <tr>
        <td>Action <b>Add</b>:<br>
        Initial list: 37, 45, 78, 99 <br>
        Add: 119
        </td>
        <td>Changed list: 37, 45, 78, 99, 119</td>
    </tr>
 <tr>
        <td>Action <b>Count</b>:<br>
        A list: 37, 45, 78, 99, 578
        </td>
        <td>Number of items in the list: 5</td>
    </tr>
   <tr>
        <td>Action <b>Remove</b>:<br>
        Initial list: 37, 45, 135, 999, 0 
        <br>Delete: 999
        </td>
        <td>Changed list: 37, 45, 135, 0</td>
    </tr>
</table>

💡 [Press here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624), **to give us feedback on this project**. It's anonymous and will help our team make your learning process better.
