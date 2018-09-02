# UsedToo

This is a program that checks for words that are used too much.

## How to use

In order to run this program, you can clone this repository, build the project as an executable using the provided CMakeLists.txt file, then run the executable. The program will prompt you for an input file. Just enter the absolute path to any textfile and it should run through and spit out your most used uncommon words.

## Building with CMake

(CMake 3.5 or newer is required)
```
mkdir .build
cd .build
cmake ..
make
cd ..
```
Then run the executable `./UsedToo` and follow the prompts
