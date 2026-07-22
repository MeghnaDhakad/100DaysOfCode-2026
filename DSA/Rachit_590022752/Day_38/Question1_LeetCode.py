class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """
        count0 = students.count(0)
        count1 = students.count(1)

        for sandwich in sandwiches:
            if sandwich == 0:
                if count0 == 0:
                    return count1
                count0 -= 1
            else:
                if count1 == 0:
                    return count0
                count1 -= 1
        return 0
