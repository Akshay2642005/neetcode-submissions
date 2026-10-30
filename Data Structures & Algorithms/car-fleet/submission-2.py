class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)
        stack = []
        for p, s in cars:
            d = target - p
            if stack:
                fd, fs = stack[-1]
                if d * fs <= fd * s:
                    continue
            stack.append((d,s))
        return len(stack)