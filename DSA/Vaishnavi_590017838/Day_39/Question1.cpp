class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> people;
        for(int i = 0; i < tickets.size(); i++)
            people.push(i);
        int seconds = 0;
        while(!people.empty()) {
            int current = people.front();
            people.pop();
            tickets[current]--;
            seconds++;
            if(tickets[current] > 0)
                people.push(current);
            if(current == k && tickets[current] == 0)
                break;
        }
        return seconds;
    }
};
