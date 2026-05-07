class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = collections.defaultdict(set)
        cols = collections.defaultdict(set)
        squares = collections.defaultdict(set)
        for r in range(9):
            for c in range(9):
                value = board[r][c]

                if value == ".":
                    continue

                s = (r//3)*3 + (c//3)
                
                if value in rows[r] or value in cols[c] or value in squares[s]:
                    return False
                
                rows[r].add(value)
                cols[c].add(value)
                squares[s].add(value)
        return True
