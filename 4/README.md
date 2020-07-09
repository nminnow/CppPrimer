# Chapter 4

1. 105

2. (a) `(* (vec.begin()))`

   (b) `((* (vec.begin())) + 1)`

3. …

4. `((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2))`

5. (a) -86

   (b) -18

   (c) 0

   (d) -2

6. `x` is even if `x % 2 == 0` and odd if not.

7. `unsigned i = -42`, `short i = 56539` assuming `short`s are 16 bits, etc.

8. The logical AND and OR operators are left-associative and perform
   short-circuit evaluation. The equality operators does not guarantee that
   operands are evaluated in any order.

9. `cp` is evaluated first and returns `true`, then `*cp` is evaluated and also
   returns `true`. The result of the condition is therefore `true`.

10. `std::cin >> i && i != 42`

11. `a > b && b > c && c > d`

12. If `j` is less than `k`, then the condition is false if and only if `i` is
    `1` and `true` otherwise. If `j` is not less than `k`, then the condition
    is false if and only if `i` is 0 and `true` otherwise.

13. (a) `i = 3`, `d = 3.0`

    (b) `i = 3`, `d = 3.5`

14. The first `if` test will produce an error because `42` is not a modifiable
    lvalue. The second `if` test will evaluate to `true`.

15. The assignment is illegal because `ival` is an int while `pi` is a pointer
    to int and you cannot assign the value of a pointer to an int. You can
    correct it by assigning `0` to the variables individually.

16. (a) `if ((p = getPtr()) != 0)` (assignment has low precedence)

    (b) `if (i == 1024)` (confusing equality and assignment operators)

17. Prefix increments increment the operand and yield the changed value as a
    result. Postfix increments increment the operand and return a copy of the
    unchanged value.

18. The first element would be skipped and `v.end()` could possibly be
    dereferenced.

19. (a) If `ptr` is not a null pointer, then `ptr` will be incremented and the
        unincremented value of `ptr` will be dereferenced. The expression will
        evaluate to `true` if and only if `ptr` is not a null pointer and the
        dereferenced value is nonzero.
    
    (b) The logical AND operator is guaranteed to evaluate the left operand
        first, so the result is `true` if and only if both the unincremented
        copy of `ival` and the incremented `ival` are nonzero.

20. (a) Legal as long as `iter` is valid and not an off-the-end iterator. `iter`
        is incremented and the unchanged copy of `iter` is dereferenced.
    
    (b) Illegal. A `vector<string>` cannot be incremented like that.

    (c) Illegal. The dot operator has a higher precedence than the dereference
        operator, so the `empty()` member function is to be fetched from `iter`.
        However, `iter` is an iterator and does not have such a member.

    (d) Legal. Fetches the `empty()` member function from the resulting object
        from dereferencing `iter`.
    
    (e) Illegal. A `vector<string>` cannot be incremented like that.

    (f) Legal as long as `iter` is valid and not an off-the-end iterator.
        Increments `iter` and fetches the `empty()` member function from the
        resulting object of referencing the incremented `iter`.

21. ```C++
    for (auto & i : ivec)
        i = i % 2 ? 2 * i : i;
    ```

22. ```C++
    // Using only conditional operators
    string finalgrade = (grade < 60) ? "fail" : 
                             (grade <= 75) ? "low pass" :
                             (grade < 90) ? "pass" : "high pass";

    // Using one or more if statements
    string finalgrade;
    if (grade > 90)
        finalgrade = "high pass";
    else if (grade > 75)
        finalgrade = "pass";
    else if (grade >= 60)
        finalgrade = "low pass";
    else
        finalgrade = "fail";
    ```

    …

23. It failed because operator precedence rules grouped the expression like

    ```C++
    string s = "word";
    string pl = ((s + s[s.size() - 1]) == 's') ? "" : "s";
    ```

    but you cannot test equality between a `string` and a `char` using the
    equality operator. You can fix it by adding parentheses to override the
    normal precedence rules:

    ```C++
    string s = "word";
    string pl = s + (s[s.size() - 1] == 's') ? "" : "s";
    ```

24. If the operators are left-associative, the expression will be grouped like
    `((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass"`
    in which case the program will fail to compile because the types of
    `"high pass"` and `grade < 60` are incompatible. Ignoring the type errors,
    either `"high pass"` or `grade < 60` will be used as the conditional of the
    outer loop. A grade greater than `90` or less than `60` will yield a
    `finalgrade` of `"fail"` and a `grade` less than `90` and greater than `60`
    will yield a `finalgrade` of `"pass"`.

25. `11111111111111111110001110000000`

26. If 27 is not strictly less than the size of `int` in bits, then the
    operation is not defined.

27. (a) `00000000000000000000000000000011`

    (b) `00000000000000000000000000000111`

    (c) `true`

    (d) `true`

28. ```C++
    cout << sizeof (bool) << endl;
    cout << sizeof (char) << endl;
    cout << sizeof (signed char) << endl;
    cout << sizeof (unsigned char) << endl;
    cout << sizeof (wchar_t) << endl;
    cout << sizeof (char16_t) << endl;
    cout << sizeof (char32_t) << endl;
    cout << sizeof (short) << endl;
    cout << sizeof (unsigned short) << endl;
    cout << sizeof (int) << endl;
    cout << sizeof (unsigned int) << endl;
    cout << sizeof (long) << endl;
    cout << sizeof (unsigned long) << endl;
    cout << sizeof (long long) << endl;
    cout << sizeof (unsigned long long) << endl;
    cout << sizeof (float) << endl;
    cout << sizeof (double) << endl;
    cout << sizeof (long double) << endl;
    ```

29. …

30. (a) `(sizeof (x + y))`

    (b) `(sizeof (p->mem[i]))`

    (c) `((sizeof a) < b)`

    (d) `(sizeof (f()))`

31. We used prefix not postfix increment and decrement because postfix operators
    do extra work that is unnecessary to this program. No other changes would
    have to be made in the context of this program.

    ```C++
    vector<int>::size_type cnt = ivec.size();
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    ```

32. …

33. If `someValue` evaluates to `true`, then `x` and `y` are both incremented
    and the incremented `y` is returned. If `someValue` evaluates to `false`,
    then `x` and `y` are both decremented and the decremented `y` is returned.

34. (a) `fval` is converted to `bool`

    (b) `ival` is converted to `float`, then `fval + (float) ival` is converted
        to `double`

    (c) `cval` is converted to `int`, then `ival * (int) cval` is converted to
        `double`

35. (a) `'a'` is converted to `int`, then `(int) 'a' + 3` is converted to `char`

    (b) `ival` and `ui` are converted to `double`, then
        `(double) ui - (double) ival * 1.0` is converted to `float`

    (c) `ui` is converted to `float`, then `(float) ui * fval` is converted to
        `double`

    (d) `ival` and `fval` are converted to `double`, then
        `(double) ival + (double) fval + dval` is converted to `char`

36. `i *= static_cast<int>(d)`

37. (a) `pv = const_cast<string *>(ps)`

    (b) `i = static_cast<int>(*pc)`

    (c) `pv = static_cast<double *>(&d)`

    (d) `pc = static_cast<char *>pv`

38. `j / i` is evaluated with integer division, then the result is casted to
    type `double` and assigned to `slope`.
