/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  let sub_box = [
      [[], [], []],
      [[], [], []],
      [[], [], []]
  ]
  let row = [], column = []
  for (let i = 0; i < 9; i += 1) {
      row = []
      column = []
      
      for (let j = 0; j < 9; j += 1) {
          
          if (board[j][i] !== '.') {
              
              if (column.indexOf(board[j][i]) !== -1) {
                  return false
              }
              column.push(board[j][i])
          }
          if (board[i][j] !== '.') {
              if (row.indexOf(board[i][j]) !== -1) {
                  return false
              }
              row.push(board[i][j])
              let r = parseInt(i/3)
              let c = parseInt(j/3)
              if (sub_box[r][c].indexOf(board[i][j]) !== -1) {
                  return false
              }
              sub_box[r][c].push(board[i][j])
          }
      }
  }
  return true
};