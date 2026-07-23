class Solution {
public:
    vector<int> cardTrick(int n) {

        deque<int> dq;

        for (int i = n; i >= 1; i--) {

            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            dq.push_front(i);
        }

        return vector<int>(dq.begin(), dq.end());
    }
};