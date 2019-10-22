# dojo
Coding dojo, assesments from https://cyber-dojo.org/



#maze

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



#saddle points

Write a program to search for the "saddle points" in
a 5 by 5 array of integers. A saddle point is a cell
whose value is greater than or equal to any in its
row, and less than or equal to any in its column.
There may be more than one saddle point in the array.
Print out the coordinates of any saddle points your
program finds. Print out "No saddle points" if there
are none.

[source: http://users.csc.calpoly.edu/~jdalbey/103/Projects/ProgrammingPractice.html]

