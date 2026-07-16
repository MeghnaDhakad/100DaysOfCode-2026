class Solution {
  public:
    stack<int> cloneStack(stack<int>& st) {
    if (st.empty()) {
        stack<int> emptyClone;
        return emptyClone;
    }

    int x = st.top();
    st.pop();
    stack<int> clone = cloneStack(st);

    st.push(x);
    clone.push(x);
    return clone;
}
};