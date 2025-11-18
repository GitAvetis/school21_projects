Object-Oriented Programming in C# 
=
C# is an object-oriented programming language. The four main principles of object-oriented programming are:
* **Abstraction** – Modeling the required attributes and interactions of entities as classes to define an abstract representation of a system. The details of the internal logic are hidden from the end user. The user does not need to know how specific classes and methods work in order to use them.
* **Encapsulation** – Hiding the internal state and functions of an object and providing access only through a defined set of public functions.
* **Inheritance** – The ability to create new abstractions based on existing ones. Inheritance enables code reuse—if a class already contains some logic and functions, there is no need to rewrite them from scratch when creating a new class; the existing class can be incorporated into the new one entirely.
* **Polymorphism** – The ability to implement inherited properties or methods in different ways across multiple abstractions. It allows the same objects and methods to take different forms.

Class Structure in C# 
-
A complete list of possible elements that can be declared in a class includes:
* Fields,
* Constants,
* Properties,
* Methods,
* Constructors,
* Events,
* Finalizers,
* Indexers,
* Operators,
* Nested Types.

Some methods and properties are specifically designed to be called or accessed from client code, meaning code outside of that class or structure. Other methods and properties can only be used within the class or structure itself. It is important to restrict code accessibility so that only the necessary parts of the code can be accessed from outside. The level of accessibility for types and their members can be specified using the following access modifiers:
* public;
* protected;
* internal;
* protected internal;
* private;
* private protected.

Classes support **inheritance**. A class derived from another class (called a base class) automatically includes all public, protected, and internal members of the base class, except for constructors and finalizers. \
Classes can be declared as **abstract**, meaning that one or more of their members lack implementation. Abstract classes cannot be instantiated directly; they serve as base classes for other classes that provide implementations for the missing members.

How Does OOP in C# Differ from Other Languages?
-
**Java** \
A key difference between C# and Java is that C# supports operator overloading, whereas Java does not. C# includes class properties, whereas Java does not have class properties.

**Python** \
C# allows developers to use pointers in unsafe mode (since pointers can pose security risks). By contrast, Python does not allow the use of pointers at all. Instead, similar results can be achieved by passing objects to functions by reference, as in Java.

**Kotlin** \
C# provides a convenient abstraction in place of traditional get/set methods—namely, properties. (Traditional fields remain available in C#.) \
Kotlin lacks fields entirely. Only properties are available by default. Unlike C#, where “public” must be explicitly defined, in Kotlin “public” is the default visibility modifier, so the keyword is typically omitted. To differentiate between properties with and without setters, Kotlin uses var/val.

Parallel Programming in C# 
=
Parallel programming relies on the principle of decomposition — the process of breaking down a program, algorithm, or data set into sections that can be processed independently.

There are two types of decomposition, both of which can be used within a single algorithm: data decomposition and task decomposition. \
**Data decomposition** is commonly applied to large data processing tasks. It involves breaking down a large data set into multiple smaller groups. \
**Task decomposition** is generally more complex than data decomposition and harder to achieve. In this case, algorithms are divided into smaller tasks that can be executed in parallel.

Challenges in Parallel Code Development
-
**Synchronization** – Ensuring that a task’s result is not used until that task is completed, and preventing interference between parallel tasks.

**Race conditions** occur when parallel tasks depend on shared data. One process may perform operations on shared data that temporarily leave it in an inconsistent state. If another process uses the inconsistent data, unpredictable behavior may occur. Even worse, errors may arise only occasionally, making them difficult to predict or reproduce.

**Solving Synchronization Issues**
To avoid synchronization problems, **locking** must be used. Locking can be requested by one task to prevent another task from entering a particular section of code or accessing a shared state variable. This mechanism is used to synchronize threads and prevent race conditions. When a process requests a lock that has already been granted to another thread, the first process halts execution and waits for the lock to be released. The halted thread is said to be blocked. Usually, a blocked thread will eventually acquire the lock and resume normal operation. However, excessive use of locks can lead to idle processors due to threads being blocked, which impacts performance.

The .NET platform provides several types for parallel programming, including a set of parallel collection classes, simplified synchronization primitives, and types for deferred initialization. These types can be used with any multithreaded application code, including the Task Parallel Library (TPL) and PLINQ.

**The Task Parallel Library** (TPL) is a set of public types and APIs in the System.Threading and System.Threading.Tasks namespaces. The goal of TPL is to increase developer productivity by simplifying the process of adding parallelism to applications. TPL dynamically scales the degree of parallelism to maximize efficient use of all available processors. Additionally, the Task Parallel Library handles task partitioning, thread scheduling in the ThreadPool, cancellation support, state management, and other low-level tasks. By using TPL, developers can enhance code performance by focusing on the work their application is designed to accomplish.
