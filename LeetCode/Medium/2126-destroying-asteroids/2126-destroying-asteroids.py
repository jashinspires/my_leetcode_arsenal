from typing import List

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        current_mass = mass
        for rock in sorted(asteroids):
            if current_mass < rock:
                return False
            current_mass += rock
        return True