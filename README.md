# C Piscine Rush01 - Skycraper Puzzle

## Pseudocode

- Get user input
  - Validation
    - check the argument delimiters if not spaces, reject the user input if any of the odd index is not a space
    - check if the even index are valid character numbers, only valid character numbers are allowed
    - checks if the total count of arguments (spaces and numbers) is divisible by 8, else, reject the user input
  - Parse the input
    - allocate memory for array to store user input.
    - convert number from its char form to int form
    - load int value to the input array
- Create the grid (This grid is the board of the game, with the user input placed on the edges and the solution in the middle.)
  -
