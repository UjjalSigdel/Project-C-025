# DFS
Depth-First Search (DFS) is a fundamental algorithm used for traversing and searching through data structures like trees and graphs. It starts at a given node, explores as deep as possible along each branch, and then backtracks when it reaches a dead end. In maze solving, DFS systematically explores paths until it finds the exit, making it a practical approach for navigating complex structures.

If we take this sample of 10 X 10 maze
<pre>
0S00000111 
1111010111 
1001010001 
1011010111 
1010010001 
1010110111 
1010000001 
1110110111 
000000000E 
1111111111 
</pre>

The output will be different for each order 

If the order is Right, Down, Left, Up

<pre>
0 S * * * * * 1 1 1 
1 1 1 1 0 1 * 1 1 1 
1 0 0 1 0 1 * 0 0 1 
1 0 1 1 0 1 * 1 1 1 
1 0 1 0 0 1 * 0 0 1 
1 0 1 0 1 1 * 1 1 1 
1 0 1 0 0 0 * 0 0 1 
1 1 1 0 1 1 * 1 1 1 
0 0 0 0 0 0 * * * E 
1 1 1 1 1 1 1 1 1 1 
</pre>

If the order is Down, Right, Up, Left

<pre>
0 S * * * 0 0 1 1 1 
1 1 1 1 * 1 0 1 1 1 
1 0 0 1 * 1 0 0 0 1 
1 0 1 1 * 1 0 1 1 1 
1 0 1 * * 1 0 0 0 1
1 0 1 * 1 1 0 1 1 1 
1 0 1 * 0 0 0 0 0 1 
1 1 1 * 1 1 0 1 1 1 
0 0 0 * * * * * * E 
1 1 1 1 1 1 1 1 1 1 
</pre>

If the order is Right, Left, Down, Up

<pre>
0 S * * * * * 1 1 1 
1 1 1 1 0 1 * 1 1 1 
1 0 0 1 0 1 * 0 0 1 
1 0 1 1 0 1 * 1 1 1 
1 0 1 0 0 1 * 0 0 1 
1 0 1 0 1 1 * 1 1 1 
1 0 1 * * * * 0 0 1 
1 1 1 * 1 1 0 1 1 1 
0 0 0 * * * * * * E 
1 1 1 1 1 1 1 1 1 1 
</pre>