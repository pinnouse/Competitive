class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        num_boats = 0
        people_hash = [0] * (limit + 1)
            
        for p in people:
            people_hash[p] += 1
        
        i, j = 1, limit
        while i <= j:
            if people_hash[i] == 0:
                i += 1
                continue
            elif people_hash[j] == 0:
                j -= 1
                continue
            if i + j <= limit:
                if i != j or people_hash[i] >= 2:
                    people_hash[i] -= 1
            people_hash[j] -= 1
            num_boats += 1
            
        return num_boats