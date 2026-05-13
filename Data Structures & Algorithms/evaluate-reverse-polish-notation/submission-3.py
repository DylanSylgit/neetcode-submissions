class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token in "+-*/":
                # Pop the two operands
                val1 = stack.pop()
                val2 = stack.pop()
                
                if token == "+":
                    stack.append(val2 + val1)
                elif token == "-":
                    stack.append(val2 - val1)
                elif token == "*":
                    stack.append(val2 * val1)
                elif token == "/":
                    stack.append(int(val2 / val1))
            else:
                stack.append(int(token))
                
        return stack[0]