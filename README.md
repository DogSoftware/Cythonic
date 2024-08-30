# Cythonic
Easy and neat (for now basic) programming language!
<hr>
<h3>Cythonic is an extremely easy to use programming language designed with simplicity and readability in mind. It's syntax is designed to be as close to natural language as possible, making it accessible for beginners and convenient for experienced developers. Cythonic supports a <i>variety</i> of "commands" (basic for now) for file manipulation, mathematical operations, string processing and more.</h3>
![image](https://github.com/user-attachments/assets/6fe71beb-26c3-4fae-869b-0e5406897a5c)

## Features

- **Simple Syntax:** Commands are written in an easy to understand English like syntax.
- **File Operations:** Create, read, append, delete and copy files.
- **String Manipulation:** Reverse, sort, convert case, find length and repeat strings.
- **Mathematical Operations:** Basic arithmetic operations such as addition, subtraction, multiplication and division.

## Setting up
### Linux
### Prerequisites
Before you begin, ensure that you have the following installed on your system:
- A C compiler (like `gcc`)
- "make" utility
- "git"

  ### Debian/Ubuntu

1. **Update Your System:**
   sudo apt-get update && sudo apt-get upgrade

2. **Install the Required Packages:**
   sudo apt-get install build-essential git

3. **Clone the Cythonic Repository:**
   git clone https://github.com/DogSoftware/Cythonic.git

4. **Navigate to the Cythonic Directory:**
   cd cythonic

5. **Build the Program:**
   make

6. **Try out one of the sample Cythonic script**
   ./cythonic examples/hello-world.cy

### Fedora

1. **Update Your System:**
   sudo dnf update

2. **Install the Required Packages:**
   sudo dnf install gcc git make

3. **Clone the Cythonic Repository:**
   git clone https://github.com/DogSoftware/Cythonic.git

4. **Navigate to the Cythonic Directory:**
   cd cythonic

5. **Build the Program:**
   make

6. **Try out one of the sample Cythonic script**
   ./cythonic examples/hello-world.cy

### Arch

1. **Update Your System:**
   sudo pacman -Syu

2. **Install the Required Packages:**
   sudo pacman -S base-devel git

3. **Clone the Cythonic Repository:**
   git clone https://github.com/DogSoftware/Cythonic.git

4. **Navigate to the Cythonic Directory:**
   cd cythonic

5. **Build the Program:**
   make

6. **Try out one of the sample Cythonic script**
   ./cythonic examples/hello-world.cy

*Note: Cythonic works fine on Windows Subsystem for Linux*

## Learning what you are working with

### "print (TMP is such a cool game!);"
Prints the given text to the "console".

### "wait numberofsecondshere;"
Pauses execution for the specified number of seconds.

### "version"
Displays the current version of Cythonic.

### "create_file example.txt"  Note the semicolon ain't required in create_file!
Creates a new file with the specified name and extension.

### "read_file example.txt" Note the semicolon ain't required in read_file!
Reads and displays the contents of the specified file.

### "append_file example.txt {Text to append}" Note the semicolon ain't required in append_file!
Appends the given text to the specified file. The text to append should be enclosed within curly braces {}.

### "delete_file example.txt" Note the semicolon ain't required in delete_file!
Deletes the specified file.

### "open_url www.example.com" Note the semicolon ain't required in open_url!
*Simulates* opening the specified URL.

### "current_time"
Displays the current system time in YYYY-MM-DD HH:MM:SS format.

### "math_add 5 10;"
Adds the two provided numbers and displays the result.

### "math_subtract 10 5;"
Subtracts the second number from the first and displays the result.

### "math_multiply 4 7;"
Multiplies the two provided numbers and displays the result.

### "math_divide 20 4;"
Divides the first number by the second and displays the result. If the second number is zero an error message is displayed.

### "reverse This is a test;"
Reverses the given string and displays it.

### "length Calculate this string length;"
Calculates and displays the length of the given string.

### "to_upper make this uppercase;"
Converts the given string to uppercase and displays it.

### "to_lower MAKE THIS LOWERCASE;"

Converts the given string to lowercase and displays it.

### "sort unsortedstring;"
Sorts the characters in the given string alphabetically and displays the sorted string.

### "repeat 3 Cythonic is kind of cool!;"
Repeats the given string the specified number of times.

### "copy_file source.txt destination.txt" Note the semicolon ain't required in copy_file!
Copies the contents of the source file to the destination file.

### "hasta la vista baby;"
Hasta la vista baby and terminate that bloody program. The ultimate exit command!

## License
Copyright (c) DogSoftware All rights reserved.

Licensed under the MIT license:

Copyright 2024 DogSoftware

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
