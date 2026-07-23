#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int>cardTrick(int n){
    deque<int>dq;

    for(int card = n;card>=1;card--){
        if(!dq.empty()){
            int last = dq.back();
            dq.pop_back();
            dq.push_front(last);
        }
        dq.push_front(card);
    }
    return vector<int>(dq.begin(),dq.end());
}

int main(){
    int n = 4;

    vector<int>ans = cardTrick(n);
    for(int i = 0 ; i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size() - 1){
            cout<<",";
        }
    }
    return 0;
}