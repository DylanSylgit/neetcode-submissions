class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = collections.defaultdict(set)
        cols = collections.defaultdict(set)
        squares = collections.defaultdict(set)

        for r in range(9):
            for c in range(9):
                num = board[r][c]
                if num == ".":
                    continue
                squareIndex = (r//3)*3 + (c//3)
                if num in rows[r]:
                    return False
                if num in cols[c]:
                    return False
                if num in squares[squareIndex]:
                    return False
                rows[r].add(num)
                cols[c].add(num)
                squares[squareIndex].add(num)
        return True
                