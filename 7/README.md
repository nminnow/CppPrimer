# Chapter 7

1.  …

2.  …

3.  …

4.  ```C++
    struct Person
    {
        std::string name;
        std::string address;
    };
    ```

5.  ```C++
    struct Person
    {
        // ...

        std::string get_name() const
        {
            return name;
        }

        std::string get_address() const
        {
            return address;
        }
    };
    ```

    These functions should be `const` because they do not change the object on
    which they are operated.

6.  …

7.  …

8.  Because `read` needs to change the object while `print` doesn’t.

9.  ```C++
    std::istream & read(std::istream & is, Person & prsn)
    {
        is >> prsn.name >> prsn.address;
        return is;
    }

    std::ostream & print(std::ostream & os, const Person & prsn)
    {
        os << prsn.name << " " << prsn.address;
        return os;
    }
    ```

10. Reads `cin` into `data1` then `data2`. If the both reads succeeded, then
    the condition evaluates to `true`.

11. …

12. …

13. …

14. …

15. ```C++
    struct Person
    {
        // ...

        Person() = default;

        Person(const std::string & n)
            : name(n) { }

        Person(const std::string & n, const std::string & a)
            : name(n), address(a) { }
        
        Person(std::istream & is)
        {
            read(is, *this);
        }
    };
    ```

16. The interface of the class should be defined after the `public` specifier
    while the implementation should be defined after the `private` specifier.
    There are no restrictions on how often an access specifier may appear.

17. The only difference between using a `struct` or a `class` is the default
    access level; for `struct`, it’s `public`, and for `class`, it’s `private`.

18. Encapsulation is the restricting of direct access to some of an object’s
    components.<sup>[1]</sup> It forces the user to use the interface provided.

19. ```C++
    class Person
    {
    private:
        std::string name;
        std::string address;
    
    public:
        // the rest
    };
    ```

20. …

21. …

22. ```C++
    class Person
    {
        friend std::istream & read(std::istream & is, Person & prsn);
        friend std::istream & print(std::istream & is, const Person & prsn);

    private:
        std::string name;
        std::string address;
    
    public:
        std::string get_name() const { return name; }
        std::string get_address() const { return address; }

        Person() = default;
        Person(const std::string & n): name(n) { }
        Person(const std::string & n, const std::string & a)
            : name(n), address(a) { }
        Person(std::istream & is) { read(is, *this); }
    };
    ```

23. ```C++
    class Screen
    {
    public:
        typedef std::string::size_type pos;

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
    
    public:
        char get() const { return contents[cursor]; }
        char get(pos ht, pos wd) const;
        Screen & move(pos r, pos c);

        Screen() = default;
        Screen(pos ht, pos wd): height(ht), width(wd) { }
        Screen(pos ht, pos wd, char c)
            : height(ht), width(wd), contents(ht * wd, c) { }
    };

    inline char Screen::get(pos ht, pos wd) const
    {
        pos row = r * width;
        cursor = row + c;
        return *this;
    }

    inline Screen & Screen::move(pos r, pos c)
    {
        pos row = r * width;
        return contents[row + c];
    }
    ```

24. See #23 above.

25. Yes. `Screen` only uses built-in types and `string`s.

26. …

27. ```C++
    class Screen
    {
        // ...

    private:
        // ...

        void do_display(std::ostream & os) { os << contents; }

    public:
        // ...

        inline Screen & Screen::move(pos r, pos c)
        {
            pos row = r * width;
            return contents[row + c];
        }

        Screen & set(char c)
        {
            contents = cursor[c];
            return *this;
        }
        Screen & set(pos row, pos col, char ch)
        {
            contents[row * width + ch] = ch;
            return *this;
        }

        Screen & display(std::ostream & os)
        {
            do_display(os);
            return *this;
        }
        const Screen & display(std::ostream & os) const
        {
            do_display(os);
            return *this;
        }

        // ...
    };
    ```

28. …

29. …

30. …

31. ```C++
    class Y;

    class X
    {
        Y * ptr = nullptr;
    };

    class Y
    {
        X obj;
    };
    ```

32. …

33. ```C++
    Screen::pos Screen::size() const
    {
        return height * width;
    }
    ```

34. Then `pos` would not be recognized as a valid type name.

35. ```C++
    typedef string Type;
    Type initVal(); // Type = string

    class Exercise
    {
    public:
        typedef double Type;
        Type setVal(Type); // Type = double
        Type initVal(); // Type = double
    private:
        int val;
    };

    // Type Exercise::setVal(Type parm) // 1st Type = string, 2nd Type = double
    Exercise::Type Exercise::setVal(Type parm) // fixed: both Type = double
    {
        val = parm + initVal(); // calls Exercise::initVal()
        return val;
    }
    ```

36. Fixed:

    ```C++
    struct X
    {
        X(int i, int j): base(i), rem(i % j) { }
        int base, rem;
    };
    ```

37. ```C++
    Sales_data first_item(cin); // Sales_data(std::istream & is)
    int main()
    {
        Sales_data next; // Sales_data(std::string s = "")
        Sales_data last("9-999-99999-9"); // Sales_data(std::string s = "")
    }
    ```

38. ```C++
    Sales_data(std::istream & is = std::cin) { read(is, *this); }
    ```

39. No. `Sales_data()` would be an ambiguous call.

40. ```C++
    class Book
    {
    private:
        std::string title;
        std::string author;
        double price = 0;
        unsigned long sales = 0;
        unsigned long revenue = 0;

        unsigned long calc_revenue(double p, unsigned long s) { return p * s; }

    public:
        Book() = default;
        Book(std::string t, std::string a): title(t), author(a) { }
        Book(std::string t, std::string a, double p, unsigned long s):
            title(t), author(a), price(p), sales(s),
            revenue(calc_revenue(p, s)) { }
    };
    ```

    …

41. ...

42. ```C++
    class Book
    {
    private:
        std::string title;
        std::string author;
        double price;
        unsigned long sales;
        unsigned long revenue;

        unsigned long calc_revenue(double p, unsigned long s) { return p * s; }

    public:
        Book(std::string t, std::string a, double p, unsigned long s):
            title(t), author(a), price(p), sales(s),
            revenue(calc_revenue(p, s)) { }
        Book(): Book("", "", 0, 0) { }
        Book(std::string t): Book(t, "", 0, 0) { }
        Book(std::string t, std::string a): Book(t, a, 0, 0) { }
        Book(std::string t, std::string a, double p): Book(t, a, p, 0) { }
    };
    ```

43. ```C++
    class NoDefault
    {
    private:
        int num;

    public:
        NoDefault(int i): num(i) { }
    };

    class C
    {
    private:
        NoDefault nd;

    public:
        C(): nd(0) { }; // need to initialize nd explicitly
    };
    ```

44. No. Ten elements need to be default initialized but there is no default 
    initializer for `NoDefault`.

45. Yes.

46. (a) Untrue. In most cases when there is no constructor defined, the
        compiler can synthesize one.

    (b) Untrue. The default constructor can be the one that supplies default
        arguments for all of its parameters.

    (c) Untrue. “In practice, it is almost always right to provide a default
        constructor if other constructors are being defined.”

    (d) Untrue. The compiler only generates a synthesized default constructor
        is no constructor is defined at all.

47. …

48. …

49. …

50. …

51. …

52. …

53. …

54. …

55. …

56. A `static` class member is associated with the class itself and not
    instances of the class. If you use `static` members, there is no need to
    store the same value in every instance of the class. Unlike ordinary
    members, `static` members can have incomplete type and can be used as
    default arguments.

57. …

58. …

[1]: https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)
