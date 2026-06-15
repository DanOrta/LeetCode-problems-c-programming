# LeetCode: Problems Solved
I present you, a list of some of the LeetCode problems that I have solved. Trying to give the extra mile, I have implemented a compilation pipeline so you can:

1. Compile and verify that at least the syntax is correct.
2. I have implemented a unitTest module, so you can add your own unit test cases and verify your solutions.

So far, the code organization is not the best, but I'm working on it.

## Prerequisites
In principle, this is a **multi-platform** implementation (although I have only tested it with Linux). So you just need a couple of programs to start coding:

* make
* git
* gcc
* gdb (or another debugger)

## How to compile?
If you already have the required software, just run:
````bash
make
````
or
````bash
make test
````
to compile and execute the test cases.

## How to add more problems?
Like I mentioned before, I'm working on improving the current file organization. The best you can do right now is to:

1. Go to the `problems` folder and create a new one. Use the problem number to name the new folder. Use 4 digits, and use 0s for padding (e.g., 0069).
2. Inside of your new folder, create a new .c file. Choose a name with no spaces. Name it whatever you want, but the header file **must have the same name** just with the .h file extension (e.g., main.c, main.h).
3. Add a README.md file with the problem's description.
4. In the root directory of the project, open the Makefile and add your new file to the `SRCS` variable. Follow the internal convention. It's simple, you'll figure it out ;)
5. Open the unitTest.h header file and create your own data structure. It must contain at the very least your *input data* and the *expected result*. Right now the convention is **expectedResult_problemName**. Finally, add at the end of the file `extern TEST(problemName);`. This will be your function prototype. Also, don't forget to add the header of your problem "XXXX/problemName.h".
6. Open the unitTest.c and once that you have created your own data structure, use any of the previous problems as template.
7. And finally, go to `src/main.c` and add `RUN(problemName);` at the end.

Now you should be ready to compile. The most complicated step is number 5, but I'm sure you can figure it out. In the future, I hope to make it easier.
