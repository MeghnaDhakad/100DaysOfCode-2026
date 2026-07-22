from collections import deque

class Solution:
    def countStudents(self, students, sandwiches):
        q = deque(students)
        i = 0
        rotations = 0

        while q and rotations < len(q):
            if q[0] == sandwiches[i]:
                q.popleft()
                i += 1
                rotations = 0
            else:
                q.append(q.popleft())
                rotations += 1

        return len(q)