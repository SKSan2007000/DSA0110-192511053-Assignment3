
# ASSIGNMENT 3 – CO3
## CONSTRUCTORS, DESTRUCTORS AND OPERATOR OVERLOADING IN C++

**Course Code:** DSA0110  
**Course Name:** Object-Oriented Programming with C++  
**Submitted by:** B. Santhosh Kumar  
**Register Number:** 192511053  
**GitHub Repository:** https://github.com/SKSan2007000/DSA01-192511053-Assignment3  
**Compiler:** g++ 13, C++17  
**Submission Date:** 11 November 2026

---

# Q1 – Constructors and Constructor Overloading

### Design
`Book` stores `title` and `copies` as private data. The default constructor delegates to the two-argument constructor. The title-only constructor also delegates, so validation is written in one place. A negative copy count throws `std::invalid_argument`.

### Output
```text
Untitled : 0
C++ Basics : 1
Data Structures : 5
Error: copies cannot be negative
```

### Constructor rules
A compiler-generated default constructor is supplied only when no constructor has been declared. Once a parameterised constructor is declared, the compiler does not automatically add a no-argument constructor. Member initializer lists initialise members directly and are required for const members and references. Members are initialised in their declaration order, not the order written in the list.

### Explicit
The title-only constructor is `explicit` to prevent an accidental conversion from a string to a `Book`, such as `Book b = std::string("C++")`.

### Alternative and complexity
One constructor with default arguments would also create an object in O(1) time and O(1) extra space. Overloaded constructors make the supported creation cases clearer. Delegation centralises the negative-copy check; default arguments can also centralise it if all paths call the same constructor body.

---

# Q2 – Copy Constructors: Shallow and Deep Copies

### Design
The `Prescription` class owns a dynamic array of medicine names. Its copy constructor allocates a new array and copies each string. Copy assignment first creates and fills a replacement array, then releases the old array. The `this != &other` check handles self-assignment. The destructor uses `delete[]`.

### Output
```text
Ibuprofen ORS | Paracetamol Cetirizine | Paracetamol ORS
```

### Explanation
A compiler-generated copy of a raw pointer copies only the address. Both objects then point to the same array; changing one changes the data seen by the other, and both destructors may try to delete the same allocation. This is a shallow copy. The implemented copy constructor makes an independent array, which is a deep copy.

The copy constructor is used when an object is initialised from another object, passed by value, or returned by value when copy elision does not remove the copy. The Rule of Three says that a class managing a resource with a destructor will commonly need its own copy constructor and copy-assignment operator as well.

### Alternative and complexity
Using `std::vector<std::string>` gives independent copies automatically. Copying n medicines takes O(n) time and O(n) additional storage. A shallow pointer copy is O(1), but it is unsafe for shared ownership unless ownership is designed separately. `vector` is preferable here because it follows the Rule of Zero.

---

# Q3 – Dynamic Constructors and Destructors

### Design
The seat map is a dynamically allocated two-dimensional `char**` array. The constructor allocates the row pointers and each row, and the destructor uses matching `delete[]` calls. Each seat starts as `O`; a booked seat becomes `X`. `book` checks bounds and refuses to book an already occupied seat. `cancel` changes a valid seat back to `O`. A zero-row event is also created.

### Output
```text
Event opened: 2 x 3
Book (0,1): 1
Book same seat: 0
O X O
O O O
After cancel:
O O O
O O O
Event closed: 6 seats checked
Event opened: 0 x 4
Event closed: 0 seats checked
Event opened: 1 x 2
Event closed: 2 seats checked
```

### Lifetime and resource handling
A local object is destroyed when its block ends. A dynamically created object is destroyed when `delete` is called. If `delete` is forgotten, the object and its owned resources leak. `delete[]` must match `new[]`; using scalar `delete` for an array is undefined behaviour. A destructor has no return type, takes no parameters and cannot be overloaded.

### Alternative and complexity
A flat array uses one allocation for rows × columns and accesses element `(r,c)` at `r * columns + c`. A vector of vectors is easier to read and each row can have a different length. Both give O(1) access. A flat allocation uses one main allocation; a vector-of-vectors may use one allocation per row plus vector metadata.

---

# Q4 – Overloading Arithmetic and Stream Operators

### Design
`Money` stores the amount as integer paise, avoiding floating-point rounding for rupee arithmetic. `+` returns a new object, `+=` updates the current object and returns `Money&`, and `==` compares the stored paise. The stream insertion operator is a friend non-member so the left operand can be `std::ostream`.

### Output
```text
Rs 200.00
true
Rs 1.25
Negative subtraction: -Rs 1.00
```

### Explanation
For `a + b`, the compiler calls `a.operator+(b)` in this member-function design. `+` should not unexpectedly modify its left operand, so it returns a new value. `+=` modifies the left operand and returns a reference so chained updates are possible. `<<` must be a non-member because the left operand is the stream.

### Alternative and complexity
Member and friend implementations both take O(1) time and O(1) extra space for this fixed-size value. Named functions such as `add(a,b)` and `equals(a,b)` also work but are less natural to read. A non-member `operator+` can support implicit conversion on either side, such as `100 + money`, if the conversion rules allow it.

---

# Q5 – Increment, Comparison and Subscript Operators

### Design
`Time` stores elapsed seconds. Prefix increment changes the object and returns a reference. Postfix increment saves the old value, increments the object and returns the saved copy. `Playlist` has const and non-const subscript overloads; both check the index and throw `std::out_of_range`.

### Predicted and observed output
```text
5 7 7
1:00:00
Song A
Error: track index
Error: track index
```
The observed output matched the prediction. In `a = t++`, `a` receives the old value 5 and `t` becomes 6. In `b = ++t`, `t` becomes 7 and `b` receives 7.

### Explanation
The dummy `int` parameter distinguishes postfix `operator++(int)` from prefix `operator++()`. Postfix normally makes a copy, so prefix is preferred for class types when the old value is not needed. The const subscript returns a read-only reference; the non-const version allows an element to be changed.

### Alternative and complexity
An `at(i)` method can perform the same range check and throw `std::out_of_range`. An unchecked `operator[]` is O(1) but an invalid index causes undefined behaviour. Checked and unchecked access are both O(1); checked access adds a comparison and branch.

---

# Q6 – Rules of Operator Overloading

### Design
`Text` owns a null-terminated character array. The constructor allocates enough space, the copy constructor makes a deep copy, copy assignment handles self-assignment, and the destructor releases the array. `+`, `==`, `!=` and `<<` provide concatenation, comparison and output.

### Output
```text
Hello C++ World
true
```

### Rules
Operator overloading cannot change precedence, associativity or the number of operands. At least one operand must be a user-defined type. Operators such as `::`, `.`, `.*`, `?:` and `sizeof` cannot be overloaded. Assignment must be a member function. A friend is useful when a non-member operator needs access to private data, as with stream insertion.

### Alternative and complexity
`std::string` is safer and simpler for ordinary text because it manages memory itself. Concatenating strings of lengths n1, n2 and n3 copies characters proportional to the final lengths; temporary objects may add further copying. A `+=`-based implementation on a local copy can reduce repeated allocation in some cases. For production code, `std::string` should normally be selected over a hand-written owning character array.

---

# Q7 – Complex Number Class for AC Impedance

### Design and formulas
`Complex` stores real and imaginary parts. It provides default, real-only and real-plus-imaginary constructors. The operators use:
- Addition: `(a+bi) + (c+di) = (a+c) + (b+d)i`
- Subtraction: `(a+bi) - (c+di) = (a-c) + (b-d)i`
- Multiplication: `(ac-bd) + (ad+bc)i`
- Division: `((ac+bd) + (bc-ad)i) / (c²+d²)`

Division checks whether the denominator magnitude is zero and throws a `runtime_error`.

### Output
```text
Series impedance: 10 + 3j (|Z|=10.4403)
Parallel impedance: 2 + 4j (|Z|=4.47214)
Error: division by zero impedance
```

### Verification
The series example adds 10 Ω, +5j Ω and -2j Ω, giving 10+3j Ω. The parallel example combines 10 Ω and 5j Ω using `(Z1*Z2)/(Z1+Z2)`. The zero-impedance test is rejected.

### Comparison with std::complex
`std::complex<double>` already implements complex arithmetic and is preferred for normal applications. Both designs store two double values and perform arithmetic in O(1) time. The custom class is useful for learning formulas and defining assignment-specific error behaviour. Floating-point comparison is approximate; the example uses a small tolerance.

---

## Overall conclusion
The tasks show how constructors establish valid objects, copy operations control ownership, destructors release resources, and overloaded operators make value types easier to use. Standard library types such as `std::vector`, `std::string` and `std::complex` reduce manual memory-management errors and should be preferred when their behaviour meets the requirement.
