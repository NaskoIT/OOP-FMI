1. What is Object Oriented Programming? 
Object Oriented Programming (OOP) is a programming paradigm where the complete software operates as a bunch of objects talking to each other. An object is a collection of data and methods that operate on its data. 

2. What are main features of OOP? 
- Encapsulation 
- Polymorphism 
- Inheritance 
- Abstraction

3. What is encapsulation? 
Encapsulation is referred to one of the following two notions. 
1) Data hiding: A language feature to restrict access to members of an object. For example, private and protected members in C++. 
2) Bundling of data and methods together: Data and methods that operate on that data are bundled together.

4. What is Constructor?
Constructor is a block of code that initializes the newly created object.

5. What is destructor?
A destructor is a method which is automatically called when the object is made of scope or destroyed. Destructor name is also same as class name but with the tilde symbol before the name.

6. What is an object?
An object is a real-world entity which is the basic unit of OOPs for example chair, cat, dog, etc. Different objects have different states or attributes, and behaviors.

7. What is a class?
User-defined blueprint from which objects are created. It consists of methods or set of instructions that are to be performed on the objects.

8. What is method overloading?
Method overloading is a feature of OOPs which makes it possible to give the same name to more than one methods within a class if the arguments passed differ.

9. What is operator overloading?
Operator overloading refers to implementing operators like (<, >, ==, !=, <<, >>) on user-defined types

10. What is a copy constructor?
A copy constructor creates objects by copying variables from another object of the same class. The main aim of a copy constructor is to create a new object from an existing one.

11. Define namespace in C++.
- The namespace is a logical division of the code which is designed to stop the naming conflict.
- The namespace defines the scope where the identifiers such as variables, class, functions are declared.
- The main purpose of using namespace in C++ is to remove the ambiguity. Ambiguity occurs when the different task occurs with the same name.
For example: if there are two functions exist with the same name such as add(). In order to prevent this ambiguity, the namespace is used. Functions are declared in different namespaces.
C++ consists of a standard namespace, i.e., std which contains inbuilt classes and functions. So, by using the statement "using namespace std;" includes the namespace "std" in our program.

12. What are the C++ access specifiers?
The access specifiers are used to define how to functions and variables can be accessed outside the class.
There are three types of access specifiers:
- **Private**: Functions and variables declared as private can be accessed only within the same class, and they cannot be accessed outside the class they are declared.
- **Public**: Functions and variables declared under public can be accessed from anywhere.
- **Protected**: Functions and variables declared as protected cannot be accessed outside the class except a child class. This specifier is generally used in inheritance.

13. What is a friend function?
Friend function acts as a friend of the class. It can access the private and protected members of the class. The friend function is not a member of the class, but it must be listed in the class definition. The non-member function cannot access the private data of the class. Sometimes, it is necessary for the non-member function to access the data. The friend function is a non-member function and has the ability to access the private data of the class.

14. What is the purpose of the "delete" operator?
The "delete" operator is used to release the dynamic memory created by "new" operator.

15. Explain this pointer?
This pointer holds the address of the current object.

16. What does Scope Resolution operator do?
A scope resolution operator(::) is used to define the member function outside the class.

17. What is the difference between delete and delete[]?
Delete [] is used to release the array of allocated memory which was allocated using new[] whereas delete is used to release one chunk of memory which was allocated using new.

18. What is exception handling?
An exception is an event that occurs during the execution of a program. Exceptions can be of any type – Runtime exception, Error exceptions. Those exceptions are adequately handled through exception handling mechanism like try, catch, and throw keywords.

19. What is the default access modifier in a class?
private

20. What is the default access modifier in a structure?
public

21. What are all the operators that cannot be overloaded?
- Scope Resolution (::)
- Member Selection (.)
- Member selection through a pointer to function (.*)

22. Do we require a parameter for constructors?
No, we do not require a parameter for constructors.

23. What is the default constructor?
The compiler provides a constructor to every class in case the provider does not offer the same. This is when the programmer provides the constructor with no specific parameters than it is called a default constructor.

24. Can we overload a destructor?
No, a destructor cannot be overloaded, and it has the only form without the parameters.

25. What does a Static member in C++ mean?
Denoted by the static keyword, a static member is allocated storage, in the static storage area, only once during the program lifetime. 
Static members belongs to the class, not to the object, static member functions don’t have ‘this’ pointer