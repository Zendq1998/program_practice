/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
  let isValid = function(board, row, col, d) {
      for (let i = 0; i < 9; i += 1) {
          if (board[i][col] !== '.' && board[i][col] == d) return false
          if (board[row][i] !== '.' && board[row][i] == d) return false
          let sub_row = parseInt(row/3) * 3 + parseInt(i/3)
          let sub_col = parseInt(col/3) * 3 + i % 3
          if (board[sub_row][sub_col] !== '.' && board[sub_row][sub_col] == d)                   return false
       }
      return true
  }
  
  let solve = function(board) {
      for (let i = 0; i < 9; i += 1) {
          for (let j = 0; j < 9; j += 1) {
              if (board[i][j] == '.') {
                  for (let c = 1; c <= 9; c += 1) {
                      if (isValid(board, i, j, c)) {
                          board[i][j] = c + ""
                          if (solve(board)) return true
                          else board[i][j] = '.'
                      }
                  }
                  return false
              }
          }
      }
      return true
  }
  
  solve(board)
};