class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(st.empty()==false && operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int x=(st.top());
                st.push(x*2);
            }
            else if(operations[i]=="+"){
                int z=(st.top());
                st.pop();
                int v=(st.top())+z;
                st.push(z);
                st.push(v);
            }
            else{
                string x=operations[i];
                st.push(stoi(x));
            }
        }
        int sum=0;
        while(st.empty()==false){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};