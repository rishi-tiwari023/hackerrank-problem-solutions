long largestRectangle(vector<int> h) {
    stack < int> st;
    int area=0;
    int i=0;
    h.insert(h.begin(), INT_MIN);
    h.insert(h.end(), INT_MIN);
    
    while (i  <  h.size()){
        if (!st.empty() && h[i] < h[st.top()]){
            int R=i;
            int heightIndex=st.top();
            st.pop();
            int L=st.top();
            int width = R - L - 1;
            area=max(area, h[heightIndex]*width);
        } else {
            st.push(i);
            i++;
        }
    }
    return area;
}


