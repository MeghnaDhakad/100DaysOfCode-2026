class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five=0
        ten=0
        for i in bills:
            if i==5:
                five=five+1
            elif i==10:
                if five==0:
                    return False
                five=five-1
                ten=ten+1
            else:
                if ten>0 and five>0:
                    ten=ten-1
                    five=five-1
                elif five>=3:
                    five=five-3
                else:
                    return False
        return True
