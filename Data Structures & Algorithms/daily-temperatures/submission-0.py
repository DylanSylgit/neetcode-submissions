class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)

        for i in range(len(temperatures)):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                popped = stack.pop()
                res[popped] = i - popped
            stack.append(i)
        while len(stack) !=0:
            popped = stack.pop()
            res[popped] = 0
        return res
            