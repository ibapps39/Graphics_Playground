## Regarding y * MAP_LENGTH + x in map[linearIndex]
Here's a simple analogy that might help clarify the concept:

Imagine you have a bookshelf with several shelves (rows) and columns. Each cell on the bookshelf can hold a single book. You can think of the bookshelf as a 2D grid, with each cell having a (row, column) coordinate.

Now, let's say you want to number the books in a single list instead of referring to them by their (row, column) coordinates. To do this, you can start numbering the books from the top-left corner, moving along the columns, and then go to the next row.

This is similar to what we're doing with the 2D map and the 1D array. The map can be thought of as the bookshelf, with each cell having a (row, column) coordinate. By using the formula y * MAP_LENGTH + x, we are converting the (row, column) coordinates to a single index in a list, just like numbering the books on the bookshelf.

Here's a quick recap of the concept:

A 2D grid (map) is represented as a single-dimensional array.
To access a specific cell in the grid, we need to convert the 2D coordinate (y, x) to a 1D index.
The formula y * MAP_LENGTH + x allows us to do this by calculating the row offset (y * MAP_LENGTH) and adding the column offset (x).