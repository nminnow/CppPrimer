# Chapter 5

1. A null statement is a single semicolon, useful when the language requires a
   statement but the program’s logic does not.

2. A block (a.k.a. compound statement) is a sequence of statements surrounded by
   a pair of curly braces, useful when the language requires a single statement
   but the program’s logic needs more than one.

3. See [3.cpp](3.cpp). …

4. (a) Illegal syntax. Possible fix:

       ```C++
       string::iterator iter = s.begin();
       while (iter != s.end()) { /* ... */ }
       ```

   (b) The condition of the `if` statement is illegal because it no longer have
       access to `status`. Possible fix is to define `status` before the while
       loop:

       ```C++
       bool status;
       while (bool = find(word)){ /* ... */ }
       if (!status) { /* ... */ }
       ```

5. …

6. ```C++
   string lettergrade = (grade >= 90) ? "A" :
                        (grade >= 80) ? "B" :
                        (grade >= 70) ? "C" :
                        (grade >= 60) ? "D" : "F";
   ```

7. (a) Missing semicolon at the end of line 2.

   (b) Missing curly braces.

   (c) Second `if` statement does not have access to `ival`.

   (d) Probably confused the equality operator with the assignment operator.

8. Dangling else can occur when there are more `if` branches than `else`
   branches. The dangling else behaves contrary to the programmer’s intent by
   matching with the closest preceding unmatched `if` and not the indentation of
   the source text. Can be resolved by using curly braces to enclose the inner
   `if` to a block.

9. See [9.cpp](9.cpp).

10. See [10.cpp](10.cpp).

11. See [11.cpp](11.cpp).

12. See [12.cpp](12.cpp).

13. (a) Forgot `break`.

    (b) Control bypasses explicitly initialized variable `ix`. Also good idea to
        add `break` for `default`. 

    (c) No commas allowed in case labels; use separate case labels for each
        number.
    
    (d) Case labels must be a constant expression.

14. See [14.cpp](14.cpp)

15. …

16. ```C++
    // idiomatic for loop
    for (int i = 0; i < 10; ++i)
    {
       /* ... */
    }

    // using a while loop to achieve the same thing
    int i = 0;
    while (i < 10)
    {
       /* .. */
       ++i;
    }

    // idiomatic while loop
    int i;
    while (std::cin >> i)
    {
       /* ... */
    }

    // using a for loop to achieve the same thing
    for (int i; std::cin >> i;)
    {
       /* ... */
    }
    ```

17. See [17.cpp](17.cpp).

18. (a) Forgot curly brace. …

    (b) No variable definitions inside the condition of a `do while` loop. …
   
    (c) Calls `get_response()` until it returns `0`.

19. See [19.cpp](19.cpp).

20. See [20.cpp](20.cpp).

21. See [21.cpp](21.cpp).

22. ```C++
    while (true)
    {
        int sz = get_size();
        if (sz > 0)
        {
            break;
        }
    }
    ```

23. See [23.cpp](23.cpp).

24. See [24.cpp](24.cpp).

25. See [25.cpp](25.cpp).
