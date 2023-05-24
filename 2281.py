class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(strength)
        total_sum = 0
        min_strength = float('inf')
        num_contiguous_groups = 0

        for num in strength:
            min_strength = min(min_strength, num)
            num_contiguous_groups += 1
            total_sum += num * num_contiguous_groups
            total_sum %= MOD

        return total_sum
