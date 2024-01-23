# proj_1
34 project 1

Student 1: Akash Seelam (921183255)

## Project Status
This the current status of the project: Completed

## Known Issues
The project fails to function properly maybe with the MakeFile, because I had a lot of issues with Docker and getting WSL to work. 

## Code References
* [Levenstein Difference Calculator](https://planetcalc.com/1721/)
* [String Library](https://cplusplus.com/reference/string/string/)
* [Edit Distance GeeksForGeeks](https://www.geeksforgeeks.org/edit-distance-dp-5/)
* [Trimming std-string](https://syntaxfix.com/question/59883/what-s-the-best-way-to-trim-std-string)
* [Right-Trim std-string](https://stackoverflow.com/questions/216823/how-to-trim-a-stdstring)
* [Expand_tabs help](https://stackoverflow.com/questions/58295089/c-equivalent-of-pythons-expandtabs-function)
* [Potential Google Test-Cases](https://google.github.io/googletest/)





## Generative AI Use
I used ChatGPT for Prompts 1-11. 

### Prompt 1
What is the issue with my code? It's not giving me a very good explanation. 
std::string Upper(const std::string &str) noexcept{
    for (int i = 0; i < str.length(); i++){
        str[i] = std:toupper(str[i]);
    }
    return "";
} 

### Response 1
The function you provided in C++ attempts to convert a given string to uppercase by iterating through each character and using `std::toupper` on each character. However, there are a couple of issues with the provided code:

1. The function returns an empty string (`return "";`). If you want to return the modified string, you should return `str` instead.

2. The loop should use `std::toupper` instead of `std:toupper`.

Here's a corrected version of your function:

```cpp
#include <cctype>  // Include the necessary header for std::toupper
#include <string>

std::string Upper(const std::string &str) noexcept {
    std::string result = str;  // Create a copy of the input string

    for (int i = 0; i < result.length(); i++) {
        result[i] = std::toupper(result[i]);
    }

    return result;
}
```

Now, this function should correctly convert each character in the input string to its uppercase equivalent, and it returns the modified string. However, keep in mind that the Python `.upper()` method is more concise and directly operates on the original string without the need for explicit iteration.

### Chagnes 1
I was just confused on the error message, and realized I forgot to add a colon and forgot to actually return anything. I quickly fixed both issues. 

### Prompt 2
what is ssize_t

### Response 2
`ssize_t` is a signed integer type used in C and C++ programming to represent the sizes of objects or memory regions. It is typically used to indicate sizes or offsets, and it is capable of representing the size of the largest possible object on the system.

The `ssize_t` type is commonly found in functions that deal with I/O operations and system calls. For example, functions like `read()` and `write()` that are used for reading and writing data often use `ssize_t` to indicate the number of bytes read or written. The use of a signed type allows these functions to use negative values to indicate errors.

Here's an example of how `ssize_t` might be used:

```c
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytesRead;

    // Read up to 1024 bytes into the buffer
    bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));

    // Check for errors
    if (bytesRead == -1) {
        // Handle error
    } else {
        // Process the data read
    }

    return 0;
}
```

In this example, `ssize_t` is used to store the number of bytes read by the `read()` function. The negative value `-1` is often used to indicate an error condition.

### Changes 2
I didn't make any changes, but I was just curious what exactly this integer type is, and I utilized it for a later function which required this specific integer type. 

### Prompt 3
So in C++, would this work: std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    str = str[start:end]
    return "";
} 

### Response 3
The syntax `str[start:end]` you've used in your C++ code snippet is not valid in C++. This is more reminiscent of Python's slicing syntax rather than C++.

To achieve a similar effect in C++, you can use the `.substr()` method along with the start index and the length of the substring. Here's how you can modify your function:

```cpp
#include <string>

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {
    if (start < 0 || start >= str.length() || end < start) {
        // Handle invalid indices or range
        return ""; // You might want to return an error message or handle it differently
    }

    // Calculate the length of the substring
    size_t length = static_cast<size_t>(end - start);

    // Extract substring using .substr()
    return str.substr(static_cast<size_t>(start), length);
}
```

In this modified function:

- It checks for invalid indices or range to ensure it won't result in undefined behavior.
- It calculates the length of the substring.
- It uses `.substr()` to extract the substring.

Remember that in C++, indices are typically zero-based, and `end` is the index just after the last character you want in the substring. If you want to include the character at index `end`, you might need to adjust the calculation accordingly.

### Changes 3
I utilized the if statement because it seemed to be an efficient and effective way of handling all indices or incorrect ranges. 

### Prompt 4
what do i do now: std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string new_str = str;
    int string_length = new_str.length();
    
    int spacing = width - string_length;
    int left_spacing = spacing / 2;
    int right_spacing = spacing - left_spacing;
    return ;


### Response 4
It looks like you've started the implementation of a `Center` function in C++. You need to construct the resulting string with the appropriate left and right padding. Here's how you can complete your function:

```cpp
#include <iostream>
#include <string>

std::string Center(const std::string &str, int width, char fill) noexcept {
    std::string new_str = str;
    int string_length = new_str.length();

    int spacing = width - string_length;
    int left_spacing = spacing / 2;
    int right_spacing = spacing - left_spacing;

    // Construct the resulting string with left padding, the original string, and right padding.
    return std::string(left_spacing, fill) + new_str + std::string(right_spacing, fill);
}

int main() {
    std::string original = "C++";
    int width = 10;
    char fillchar = ' ';

    // Call the Center function
    std::string centered = Center(original, width, fillchar);

    // Print the result
    std::cout << centered << std::endl;

    return 0;
}
```

In this example, the `Center` function constructs the centered string using the provided parameters (original string, width, and fill character). The `main` function demonstrates how to use the `Center` function and prints the centered string.

### Changes 4
I was a little confused previously on what exactly I was returning, but this cleared up everything and I realized I was returning left spacing + the string + the right spacing

### Prompt 5
std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string new_str = str;
    std::string old_str = old;
    std::string rep_str = rep;

    position = new_str.find(old_str)

    if (position != std::string::npos){
        new_str.replace(position, old_str.length(), rep_str)
    }
    return new_str;
} Will this code return the string str with all instances of old replaced with rep?
### Response 5
Yes, the code you provided is a function designed to replace all instances of the substring `old` with the substring `rep` in the input string `str`. The `find` method is used to locate the first occurrence of the substring `old`, and if it is found (`position != std::string::npos`), the `replace` method is used to replace that occurrence with the substring `rep`. This process is repeated until no more occurrences of `old` are found.

So, the corrected code should indeed return a new string where all instances of `old` in the input string `str` are replaced with `rep`.
### Changes 5
Didn't actually change anything, but wanted some insight into my program, which I recieved. 

### Prompt 6
what do i do next: std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string new_str = str;
    std::vector <std::string> new_vect = vect;
    for (int i = 0; i < new_vect.size(); i++) {
        new_str = new_str + vect[i];

        if(i < new_vect.size() - 1) {
            new_str =
        }
    }
    return "";
}
### Response 6
It looks like you're on the right track in your attempt to modify the `Join` function. However, there seems to be a mistake in your code. Instead of appending the separator string to `new_str` after each element, you should append it before each element, except for the first one. Here's the corrected code:

```cpp
std::string Join(const std::string &str, const std::vector<std::string> &vect) noexcept {
    std::string new_str = "";
    std::vector<std::string> new_vect = vect;

    for (int i = 0; i < new_vect.size(); i++) {
        new_str += (i == 0) ? "" : str;  // Add separator before each element, except the first one
        new_str += new_vect[i];
    }

    return new_str;
}
```

Explanation of changes:
- Initialized `new_str` to an empty string (`""`) instead of `str`.
- Changed the loop to append the separator before each element (except for the first one).
- Removed the unnecessary line that copied `vect` to `new_vect`.

Now, this modified function should correctly join the elements of the vector into a single string with the specified separator. You can use it in a manner similar to the previous example:

```cpp
std::vector<std::string> myVector = {"apple", "banana", "orange"};
std::string separator = ", ";
std::string result = Join(separator, myVector);
std::cout << result << std::endl;
```

Output:
```
apple, banana, orange
```
### Changes 6
I went over the changes recommended and decided that some parts were a better implementation of the Join function, and so integrated those parts into my code. Mainly initialized new_str to an empty string and changed the loop like CHatGPT suggested. 

### Prompt 7
When writing test cases, you care about code coverage. You want to make sure that:

Coverage of all input classes (allowing defaults, specifying non-defaults, any special cases, etc.)
Coverage of all you code paths, all of your code paths in your code should be exercised by at least one test
### Response 7
Absolutely, achieving good code coverage is crucial when writing test cases. It ensures that your tests exercise various parts of your code, helping to identify potential issues and verify the correctness of your implementation. Here are some considerations for improving code coverage:

1. **Default Values:**
   - Test with default values for function parameters.
   - Ensure that the function behaves as expected when no additional parameters are specified.

2. **Non-Default Values:**
   - Test with non-default values for parameters.
   - Cover a variety of input values to check how the function behaves with different inputs.

3. **Edge Cases:**
   - Identify edge cases relevant to your function.
   - Test with extreme values, boundary values, and scenarios that might be considered unusual.

4. **Error Handling:**
   - Test how the function handles error conditions, invalid inputs, or unexpected situations.
   - Ensure that appropriate error messages or responses are provided.

5. **Branches and Conditionals:**
   - Design tests that cover different branches in your code, especially if there are conditionals or switch statements.
   - Test both true and false conditions.

6. **Loops:**
   - If your code contains loops, ensure that tests cover various loop scenarios, including different loop counts or iterations.

7. **Combination of Features:**
   - Test combinations of features or parameters to ensure that your function behaves correctly when multiple factors are involved.

8. **Boundary Testing:**
   - Test values at the boundaries of expected ranges.
   - Check how the function behaves when inputs are at the upper or lower limits of acceptable values.

9. **Integration Tests:**
   - Consider integration tests that cover interactions between multiple functions or components.
   - Ensure that different parts of your code work well together.

10. **Code Paths:**
    - Identify different code paths within your functions.
    - Make sure that each code path is exercised by at least one test.

By systematically considering these aspects, you can create a comprehensive set of test cases that provides good code coverage. Regularly reassess and update your test suite as your code evolves to maintain thorough coverage. Additionally, leveraging code coverage tools can help you visualize which parts of your code are covered by tests and which may need additional attention.
### Changes 7
Used these thoughts as inspiration when I actually began writing my test cases to make sure I had a variable and proper amount of test cases. 

### Prompt 8
Recieved an error: why? got an error: g++ StringUtils.cpp -o MyStringUtilsTest
C:\Users\14087\AppData\Local\Temp\ccOxUJgl.o:StringUtils.cpp:(.text+0x119a): undefined reference to `StringUtils::EditDistance(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
C:\Users\14087\AppData\Local\Temp\ccOxUJgl.o:StringUtils.cpp:(.text+0x12b2): undefined reference to `StringUtils::EditDistance(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
C:\Users\14087\AppData\Local\Temp\ccOxUJgl.o:StringUtils.cpp:(.text+0x13ca): undefined reference to `StringUtils::EditDistance(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
C:\Users\14087\AppData\Local\Temp\ccOxUJgl.o:StringUtils.cpp:(.text+0x14e2): undefined reference to `StringUtils::EditDistance(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
C:\Users\14087\AppData\Local\Temp\ccOxUJgl.o:StringUtils.cpp:(.text+0x15fa): undefined reference to `StringUtils::EditDistance(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
C:\Users\14087\AppData\Local\Temp\ccOxUJgl.o:StringUtils.cpp:(.text+0x1712): more undefined references to `StringUtils::EditDistance(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)' follow

### Response 8
The error indicates that the linker is unable to find the implementation of the `StringUtils::EditDistance` function. Make sure that you have the implementation of `StringUtils::EditDistance` in the `StringUtils.cpp` file. Here's an example of how it might look:

```cpp
// StringUtils.cpp

#include "StringUtils.h" // Include the header file where StringUtils class is declared

int StringUtils::EditDistance(const std::string& str1, const std::string& str2, bool caseSensitive) {
    // Implement the EditDistance function here
    // ...
    return result; // Replace with the actual result
}
```

Ensure that the `StringUtils.cpp` file is part of your project build and that it's being compiled and linked along with the other source files.

If the implementation is already present, double-check for typos or mistakes in the function signature and make sure that the `StringUtils.cpp` file is indeed included in your build system. If the issue persists, you may need to provide more details about your project structure and build system for further assistance.

### Changes 8
Realized one of my curly braces was in an incorrect area, fixed this issue. 

### Prompt 9
You know the edit distance in Python? I made on in C++, and this is the code: int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    int x = left.size();
    int y = right.size();

    std::vector<int> prev(x+1, 0), curr(x+1, 0);

    for (int j = 0; j <= x; j++) {
        prev[j] = j;
    }
    for (int i = 1; i <= y; i++) {
        curr[0] = i;
        for (int j = 1; j <= x; j++) {
            if (ignorecase) {
                if (std::tolower(left[i - 1]) == std::tolower(right[j - 1])) {
                    curr[j] = prev[j - 1];
                } else {
                    int yx = std::min(1 + prev[j], 1 + curr[j - 1]);
                    curr[j] = std::min(yx, 1 + prev[j - 1]);
                }
            } else {
                if (left[i - 1] == right[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int yx = std::min(1 + prev[j], 1 + curr[j - 1]);
                    curr[j] = std::min(yx, 1 + prev[j - 1]);
                }
            }
        }
        prev = curr;
    }

    return prev[x];
}
However, this isn't being totally correct, and my test cases are failing because of an issue. What could be the issue here?

### Response 9
It looks like there might be an issue with the implementation of your edit distance function. Let's go through the code and identify potential areas for improvement.

I noticed that in your nested loops, when checking for character equality, you have duplicated code. You can simplify it by removing the redundant conditions. Also, it seems there might be an indexing issue when accessing characters from the strings.

Here's an updated version of your code:

```cpp
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    int x = left.size();
    int y = right.size();

    std::vector<int> prev(x + 1, 0), curr(x + 1, 0);

    for (int j = 0; j <= x; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= y; i++) {
        curr[0] = i;

        for (int j = 1; j <= x; j++) {
            int cost = (left[j - 1] == right[i - 1]) ? 0 : 1;

            if (ignorecase) {
                cost = (std::tolower(left[j - 1]) == std::tolower(right[i - 1])) ? 0 : 1;
            }

            int yx = std::min(1 + prev[j], 1 + curr[j - 1]);
            curr[j] = std::min(yx, cost + prev[j - 1]);
        }

        prev = curr;
    }

    return prev[x];
}
```

This modification removes the redundant conditions for character comparison and uses a single cost variable to simplify the logic. Please try this updated version with your test cases and see if it resolves the issues you're facing.

### Changes 9
I realized that my code was duplicated, and removed the redundant conditions as ChatGPT said. 

### Prompt 10
What are some other test cases I can potentially use? 
TEST(StringUtilsTest, Join){
    EXPECT_EQ(StringUtils::Join(",", {"apple", "orange", "banana"}), "apple,orange,banana");

    EXPECT_EQ(StringUtils::Join(" ", {"Hello", "World"}), "Hello World");

    EXPECT_EQ(StringUtils::Join("-", {"one", "two", "three"}), "one-two-three");

    EXPECT_EQ(StringUtils::Join("", {"a", "b", "c"}), "abc");

    EXPECT_EQ(StringUtils::Join(",", {}), "");
### Response 10
It looks like you've provided a set of test cases for a `StringUtils::Join` function. To come up with additional test cases, you can consider testing various scenarios to ensure the robustness of your implementation. Here are some suggestions:

1. **Empty Separator with Non-Empty Strings:**
   ```cpp
   EXPECT_EQ(StringUtils::Join("", {"apple", "orange", "banana"}), "appleorangebanana");
   ```

2. **Empty Input Strings:**
   ```cpp
   EXPECT_EQ(StringUtils::Join(",", {}), "");
   ```

3. **Strings with Whitespace Characters:**
   ```cpp
   EXPECT_EQ(StringUtils::Join(" ", {"  apple", "orange  ", " banana  "}), "  apple orange   banana  ");
   ```

4. **Mix of Empty and Non-Empty Strings:**
   ```cpp
   EXPECT_EQ(StringUtils::Join(",", {"", "apple", "", "orange", "banana", ""}), ",apple,,orange,banana,");
   ```

5. **Custom Separator:**
   ```cpp
   EXPECT_EQ(StringUtils::Join(" | ", {"apple", "orange", "banana"}), "apple | orange | banana");
   ```

6. **Special Characters in Strings:**
   ```cpp
   EXPECT_EQ(StringUtils::Join("-", {"apple!", "@orange", "b@n@n@@"}), "apple!-@orange-b@n@n@@");
   ```

7. **Repeated Strings:**
   ```cpp
   EXPECT_EQ(StringUtils::Join(",", {"apple", "apple", "apple"}), "apple,apple,apple");
   ```

8. **Mixed Data Types (if applicable):**
   If your `StringUtils::Join` supports different data types, test a mix of them.

Make sure to consider edge cases and scenarios that your function might encounter in real-world usage. Additionally, handle cases where unexpected input might be passed to the function.
### Changes 10
Changed some of my test cases to mirror these because of their apparent robustness as I can potentially find more scenarios where my code fails and therefore fix it. 

### Prompt 11
What are some other google test cases I can use? TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("Hello World", "World", "Universe"), "Hello Universe");

    EXPECT_EQ(StringUtils::Replace("apple apple apple", "apple", "orange"), "orange orange orange");

    EXPECT_EQ(StringUtils::Replace("The quick brown fox", "The", "A"), "A quick brown fox");

    EXPECT_EQ(StringUtils::Replace("This is a test", "test", "challenge"), "This is a challenge");

### Response 11
For the `StringUtils::Replace` function, you can create additional test cases to cover various scenarios. Here are some suggestions:

1. **Empty Input String:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("", "find", "replace"), "");
   ```

2. **Empty Find String:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("Hello World", "", "Universe"), "Hello World");
   ```

3. **Empty Replace String:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("Hello World", "World", ""), "Hello ");
   ```

4. **Multiple Occurrences:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("apple apple apple", "apple", "orange"), "orange orange orange");
   ```

5. **Case Sensitivity:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("apple Apple APPLe", "apple", "orange"), "orange Apple APPLe");
   ```

6. **Special Characters:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("The quick brown fox", "fox", "@#$%"), "The quick brown @#$%");
   ```

7. **Overlapping Occurrences:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("aaaaa", "aa", "b"), "ba");
   ```

8. **Replace Entire String:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("This is a test", "This is a test", "Success"), "Success");
   ```

9. **Replace with Longer String:**
   ```cpp
   EXPECT_EQ(StringUtils::Replace("The quick brown fox", "brown", "big brown"), "The quick big brown fox");
   ```

10. **Escape Characters:**
   If your function supports escape characters, test cases involving them.

Make sure to cover edge cases and handle scenarios where unexpected input might be passed to the function. These additional test cases will help ensure the correctness and robustness of your `StringUtils::Replace` implementation.

### Changes 11 
Revamped some of my test cases to look similar in order to better my understanding of the code and also make sure it works for multiple edge cases. 
