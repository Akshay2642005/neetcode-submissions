class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), reverse=True)
        fleets, slowest = 0, 0
        for p, s in cars:
            time = (target - p) / s
            if time > slowest:
                fleets += 1
                slowest = time
        return fleets
        