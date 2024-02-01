#!/usr/bin/python3
"""module."""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
    grid (List[List[int]]): A list of lists representing the grid.

    Returns:
    int: The perimeter of the island.
    """
    if not grid:
        return 0

    rows, cols = len(grid), len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4  # Initialize with 4 sides

                # Check left neighbor
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

                # Check upper neighbor
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

    return perimeter
