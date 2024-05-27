# sudoku-game
The provided code is a complete C++ program for a Sudoku game that allows a user to solve a Sudoku puzzle by entering numbers into empty cells. It also includes functionality to solve the Sudoku puzzle automatically if the user is unable to solve it.
Time Complexity: O(9 ^ NxN)
Space Complexity: O(NXN)
In practice, the constraints and heuristics used in the backtracking algorithm (like isSafe checks) make the algorithm run faster than the worst-case scenario in most real-world cases. However, for theoretical analysis, the time complexity remains exponential.
