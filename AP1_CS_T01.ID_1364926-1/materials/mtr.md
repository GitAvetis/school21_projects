Description of C# program structure and syntax basics
=
**Program entry point**: Before C# 9, the entry point was a static method named Main that was declared inside a class, usually named Program, that was located inside the namespace. Starting with C# 9, top-level instructions - those instructions that allow you to write code without putting it in a class or method - are used for a program's entry point. 

An example program that outputs: «Hello world».

**Before C# 9**
```C#
using System;
namespace YourNamespace
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello world!");
        }
    }
}
```
**After release of C# 9**
```C#
Console.WriteLine("Hello World!");
```

<b>Program structure</b>: a C# program consists of one or several files. Each file may or may not contain namespaces. A namespace can contain types such as classes, structures, interfaces, enumerations and delegates or other namespaces.

**Code Compilation**: The .NET Framework provides the ICodeCompiler runtime interface. The CSharpCodeProvider class implements this interface and provides access to instances of the C# code generator and code compiler. For example, create an instance of CSharpCodeProvider and use it to get a reference to the ICodeCompiler interface.

Once you have a reference to the ICodeCompiler interface, you can use it to compile the source code. Parameters are passed to the compiler using CompilerParameters class. 

The CompilerParameters object is used to tell the compiler to create an executable file (unlike a DLL library) and to output the resulting build to a disk. CompileAssemblyFromSource call is where the build is compiled. This method accepts a parameter object and source code, which is a string. After compiling the code, you can check for compilation errors. To do this, you must use the return value from CompileAssemblyFromSource, which is a CompilerResults object.

**Control language structures**:

A **sequence** is an algorithmic construct that represents the natural sequential order of actions. Algorithms that use only sequences are called **linear programs**.

```C#
int x = 17;
int y = 5;
int z = x * y;
```
**Branching** is an algorithmic construct in which, depending on the result of the condition check (the answer is "yes" or "no"), one of two options of further actions (branches) is chosen. Algorithms based on branching are called **branching**.

```C#
int year = 1918;
if (year < 2023)
    Console.WriteLine("Past");
elif (year = 2023)
    Console.WriteLine("Present");
else
    Console.WriteLine("Future");
```
**Repetition** is an algorithmic construct that represents a sequence of actions performed repeatedly. Algorithms containing repetition are called **loops**.

```C#
int i = 2;
while (i < 13)
{
    Console.WriteLine(i * 3);
    i++;
}
```
**Composite data types**: structure and union

**Structure** is a union of elements under one name. It occupies a space equal to the sum of sizes of all elements included in it. The structure variable stores all values for each of the elements. The structure fields are stored in the stack.

Operations with structures:

* Membership operation <structure name>.<structure member>;
* Indirect membership operation <pointer to structure> -> <structure member>
* Address fetch operation &;
* Sizeof operation;
* Assignment operatoration =.

**Union** is a type that allows storing data of different types in the same memory location (but not at the same time). It is a way to interpret the same data in different ways. A union occupies memory equal to the largest of its elements. A union variable can only hold the value of one of its elements, so changing the value of one of its elements removes the previous value.

The same operations are allowed as with structures.

**Console class**

Provides standard streams for console applications: input, output, and error message streams.

When you start a console application, the operating system automatically associates three I/O streams with the console: a standard input stream, a standard output stream, and a standard error output stream. The application can read user input data from a standard input stream; writing normal data to the standard output stream; and writing error data to the standard error output stream. These streams are presented to the application as Console.In, Console.Out, and Console.Error properties.

**Memory types**

**Static** - memory allocation before the program execution starts. Such memory is available throughout the entire program execution time.

**Automatic ("placement on the stack")** - automatically allocates arguments and local variables of the function, as well as other metainformation when the function is called and frees memory when the function exits.

The stack operates on the LIFO principle ("last in, first out").

Automatic memory works precisely on the basis of the stack, so that a function called from any part of the program will not erase the automatic memory already in use, but will add its data to the end of the stack. When this function terminates, its data will be removed from the end of the stack.

**Dynamic** - memory allocation from the OS on demand of the application.

Automatic and static memory are allocated once before the program is started. Dynamic memory is used in case of their shortage.

The application can request additional memory from the OS through an allocator or directly through a system call, if necessary. 
After memory allocation, the program receives a pointer to the beginning of the allocated memory, which, in turn, must also be stored somewhere: in static, automatic or dynamic memory. To return the memory back to the allocator, only the pointer itself is needed.

**Garbage collector**

The garbage collector optimization mechanism determines the best time to perform the collection based on the performed memory allocations. When the garbage collector performs a cleanup, it releases the memory allocated for objects that are no longer used by the application. It determines which objects are no longer used by analyzing the roots of the application. An application's roots include static fields, local variables on a thread's stack, CPU registers, GC handles, and the finalize queue. Each root either refers to an object on the managed heap or is set to NULL.  The garbage collector can ask the rest of the runtime for these roots. The garbage collector uses this list to create a graph that contains all the objects that are reachable from the roots.

Objects that aren't in the graph are unreachable from the application's roots. The garbage collector considers unreachable objects garbage and releases the memory allocated for them. During a collection, the garbage collector examines the managed heap, looking for the blocks of address space occupied by unreachable objects. As it discovers each unreachable object, it uses a memory-copying function to compact the reachable objects in memory, freeing up the blocks of address spaces allocated to unreachable objects. Once the memory for the reachable objects has been compacted, the garbage collector makes the necessary pointer corrections so that the application's roots point to the objects in their new locations. It also positions the managed heap's pointer after the last reachable object.

Memory is compacted only if a collection discovers a significant number of unreachable objects.

**Generic templates**

Universal templates allow you to configure a method, class, structure, or interface precisely according to the type of data being processed.

Universal templates are classes, structures, interfaces and methods that have prototypes (type parameters) for one or more types that they store or use.

When you create an instance of a generic class, you must specify the actual types to replace the type parameters. This creates a new generic class, called a constructed generic class, with the selected types replacing all type parameters. The result is a type-safe class.

**Determination of a simple generic class:**

```C#
public class Generic<T>
{
    public T Field;
}
```
