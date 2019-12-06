# My coding dojos.

My place for coding dojos.
Problems from https://cyber-dojo.org/


## Preparation 


### Setup
1. Create a build directory (ex. $ mkdir ../build)
2. Move to this directory ($ cd ../build)
3. Run cmake with path to this repository ($ cmake ../workshop231118)
4. Run make ($ make)

GTest and GMock libraries will be downloaded and compiled during the first build.
In case of timeouts during gtest downloads, please check git proxy settings.

### Adding new files
To add a new file to compilation of main application,
for example foo.cpp, add it to add_library(binary_name ...) clause
in CMakeLists.txt.
```
add_library(binary_name
    ...
    foo.cpp)
```
To add a new test file, add it to add_executable(tests_binary_name ...) clause
in CMakeLists.txt.

## Problems

### Maze

Alice found herself very tiny and wandering around Wonderland.
Even the grass around her seemed like a maze.

This is a tiny maze solver.

A maze is represented by a matrix

[[:S 0 1]
 [1  0 1]
 [1  0 :E]]

S : start of the maze
E : end of the maze
1 : This is a wall that you cannot pass through
0 : A free space that you can move through.

The goal is the get to the end of the maze.
A solved maze will have a :x in the start, the path,
and the end of the maze, like this.

[[:x :x 1]
 [1  :x 1]
 [1  :x :x]]

Source: https://github.com/gigasquid/wonderland-clojure-katas



## Saddle points

Write a program to search for the "saddle points" in
a 5 by 5 array of integers. A saddle point is a cell
whose value is greater than or equal to any in its
row, and less than or equal to any in its column.
There may be more than one saddle point in the array.
Print out the coordinates of any saddle points your
program finds. Print out "No saddle points" if there
are none.

[source: http://users.csc.calpoly.edu/~jdalbey/103/Projects/ProgrammingPractice.html]


## Lcd

Your task is to create an LCD string representation of an
integer value using a 3x3 grid of space, underscore, and
pipe characters for each digit. Each digit is shown below
(using a dot instead of a space)

._.   ...   ._.   ._.   ...   ._.   ._.   ._.   ._.   ._.
|.|   ..|   ._|   ._|   |_|   |_.   |_.   ..|   |_|   |_|
|_|   ..|   |_.   ._|   ..|   ._|   |_|   ..|   |_|   ..|


Example: 910

._. ... ._.
|_| ..| |.|
..| ..| |_|

[source: https://cyber-dojo.org]

## Is Balanced

Write a program to determine if the the parentheses (),
the brackets [], and the braces {}, in a string are balanced.

For example:

{{)(}} is not balanced because ) comes before (

({)} is not balanced because ) is not balanced between {}
     and similarly the { is not balanced between ()

[({})] is balanced

{}([]) is balanced

{()}[[{}]] is balanced


[source: https://cyber-dojo.org]


