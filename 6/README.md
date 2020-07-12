# Chapter 6

1.  Arguments are the comma-separated list inside the call operator. Parameters
    are stated in the function definition. Arguments are used to initialize the
    function’s parameters.

2.  (a) Error. The returned value is of type `string` while the function
        definition states the return type to be `int` and no conversion exists
        between the two types. Possible fix is to change the return type in the
        function definition to `string`.

    (b) Error. No return type stated in function definition. Use `void` to
        indicate the lack of a return type.

    (c) Error. Missing opening curly brace.

    (d) Error. Function body must be delimited by curly braces.

3.  …

4.  See [4.cpp](4.cpp).

5.  ```C++
    int abs(int x)
    {
        if (x < 0)
            return -x;
        else
            return x;
    }
    ```

6.  Parameters and ordinary local variables are automatic objects that are
    destroyed once the block terminates. Local `static` objects’ lifetime
    continue across calls to the function and are destroyed when the program
    terminates. Additionally, ordinary local variables are default initialized
    while local `static` objects are value initialized. …

7.  ```C++
    size_t count_calls()
    {
        static size_t count = 0;
        return ++count;
    }
    ```

8.  …

9.  …

10. ```C++
    void swap(int * x, int * y)
    {
        int t = *x;
        *x = *y;
        *y = t;
    }
    ```

11. ```C++
    void reset(int & i)
    {
        i = 0;
    }
    ```

12. ```C++
    void swap(int & x, int & y)
    {
        int t = x;
        x = y;
        y = t;
    }
    ```

    ↑ No need for dereferences.

13. The function declared as `void f(T)` is called by value; that is, the
    parameter and the argument are separate objects and anything done to the
    parameter will not have any effect on the argument. The function declared as
    `void f(T&)` is called by reference, meaning that the parameter is an alias
    to the argument. A parameter passed by reference can change the value of the
    argument to which it is bonded.

14. …

15. …

16. Use reference to `const` when possible:
    `bool is_empty(const string & s) { return s.empty(); }`

17. A function to determine whether a `string` contains any capital letters:

    ```C++
    bool has_upper(const std::string & str)
    {
        for (char ch : str)
            if (isupper(ch))
                return true;
        return false;
    }
    ```

    A function to change a `string` to all lowercase:

    ```C++
    void to_lower(std::string & str)
    {
        for (char & ch : str)
            tolower(ch);
    }
    ```

    The parameters used do not have the same type. The first function used a
    reference to `const` because it does not need to change the argument while
    the second function used a plain reference because it does need to change
    the argument.

18. (a) `bool compare(const matrix & mtx1, const matrix & mtx2);`

    (b) `vector<int>::iterator change_val(int i, vector<int>::iterator iter);`

19. (a) Illegal: too many arguments.

    (b) Legal.

    (c) Legal.

    (d) Legal.

20. Reference parameters should be reference to `const` if the function does not
    need to change the value of the corresponding argument. If we make a
    parameter a plain reference when it could be a reference to `const`, first,
    we couldn’t call the function by passing literals, and second, we couldn’t
    use the plainly referencing function from other functions that correctly
    use reference to `const`.

21. You should use `const int *` for the pointer because there is no need to
    change its value.

    ```C++
    int larger(int i, const int * p)
    {
        if (i > *p)
        {
            return i;
        }
        return *p;
    }
    ```

22. ```C++
    void swap(int * x, int * y)
    {
        int * t = x;
        x = y;
        y = t;
    }
    ```

23. …

24. The function takes a pointer to `int` and prints the first 10 elements of
    the array to which it points (assuming the pointer is valid and points to an
    array with at least 10 elements or else the behavior is undefined). The
    compiler will ignore the `[10]` in the parameter; the type of the parameter
    will be `const int *`. So this approach does not guarantee the size of the
    array to be 10. But there are other approaches, though, you can use
    `void print(const int * ia, size_t it)`, in which you pass the size of the
    array explicitly, or `void print(const int * beg, const int * end)`, in
    which `beg` is the pointer to the first element of the array and `end` is
    the pointer to one past the last element of the array.

25. See [25.cpp](25.cpp).

26. …

27. ```C++
    int sum(initializer_list<int> il)
    {
        int val = 0;
        for (int i : il)
        {
            val += i;
        }
        return val;
    }
    ```

28. `const string &`

29. …

30. …

31. When the reference is bond to an object that still exists after the function
    terminates.

32. Legal. Sets the elements of `ia` to their indexes.

33. ```C++
    void print (std::vector<int>::iterator beg, std::vector<int>::iterator end)
    {
        if (beg != end)
        {
            std::cout << *beg << " ";
            print_vector(++beg, end);
        }
    }
    ```

34. The result returned would still be correct.

35. We have to use `val` in the same expression (unsequenced modification has
    undefined behavior).

36. `string (& func())[10];`

37. `typedef string (& t)[10]; t func();` (or
    `using t = stirng (&)[10]; t func();`),
    `auto func() -> string (&)[10];`, and
    `decltype(string (& t)[10]) func();`.

38. ```C++
    decltype(odd) & arrPtr(int i)
    {
        return (i % 2) ? odd : even;
    }
    ```

39. (a) Illegal. Redefinition. A parameter that has a top-level `const` is
        indistinguishable from one without.

    (b) Illegal. Functions that differ only in their return type cannot be
        overloaded.

    (c) Legal.

40. (a) No error.

    (b) Error. Missing default arguments on `wd` and `bckgrnd`.

41. (a) Illegal. …

    (b) Legal. …

    (c) Legal but unlikely to match the programmer’s intent. …

42. …

43. (a) Put in a header. Definition of an `inline` function.

    (b) Put in a header. Declaration of a function.

44. ```C++
    inline bool isShorter(const string & s1, const string & s2)
    {
        return s1.size() < s2.size();
    }
    ```

45. …

46. Succedded.

47. ```C++
    void print (std::vector<int>::iterator beg, std::vector<int>::iterator end)
    {
        #ifndef NDEBUG
        std::cout << "Vector size is " << end - beg << std::endl;
        #endif

        if (beg != end)
        {
            std::cout << *beg << " ";
            print_vector(++beg, end);
        }
    }
    ```

48. The loop executes until a specific word is entered or the stream hits
    end-of-file. …

49. A candidate function is one that has a matching name and a declaration that
    is visible at the point of the call. A viable function is a candidate
    function that can be called with the arguments in the given call.

50. (a) Ambiguous.

    (b) Best match: `void f(int)`.

    (c) Best match: `void f(int, int)`.

    (d) Best match: `void f(double, double)`.

51. …

52. (a) Match through promotions.

    (b) Match through arithmetic conversions.

53. (a) Overloads.

    (b) Overloads.

    (c) Illegal: redefinition. Top-level `const`s and non`const`s are
        indistinguishable when matching argument and parameter types.

54. ```C++
    int f(int, int);
    std::vector<int (*)(int, int)> fvec;
    ```

55. ```C++
    int add(int x, int y) { return x + y; }
    int subtract(int x, int y) { return x - y; }
    int multiply(int x, int y) { return x * y; }
    int divide(int x, int y) { return x / y; }

    fvec.push_back(&add);
    fvec.push_back(&subtract);
    fvec.push_back(&multiply);
    fvec.push_back(&divide);
    ```

56. ```C++
    for (auto f : fvec)
    {
        std::cout << f(5, 2) << std::endl;
    }
    ```
