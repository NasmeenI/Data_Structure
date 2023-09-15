#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

int get_second_min(stack<int> &s) {
    //write only in this function, do not declare static
    stack<int> temp = s, temp1;

    int min = temp.top();
    temp.pop();
    while(temp.size()) {
        if(min > temp.top()) {
            min = temp.top();
        }
        temp.pop();
    }
    
    temp = s;
    while(temp.size()) {
        if(temp.top() == min) {
            temp.pop();
            continue;
        }
        temp1.push(temp.top());
        temp.pop();
    }

    min = temp1.top();
    temp1.pop();
    while(temp1.size()) {
        if(min > temp1.top()) {
            min = temp1.top();
        }
        temp1.pop();
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }

    //repeat n-1 times
    for (int last = 1;last < n;last+=1) {
        stack<int> s;
        //build s;
        bool distinct = false;
        for (int i = last;i >= 0;i--) {
            s.push(v[i]);
            if (v[i] != v[0]) distinct = true;
        }
        cout << "--use v[" << last << "] to v[0] --" << "\n"; 
        if (distinct) {
            //call get_second_min if we have at least 2 distinct value
            int answer = get_second_min(s);
            //print result and s
            cout << "result is " << answer << "\n";
            cout << "size of s is " << s.size() << "\n" << "member of s are "; 
            while(s.size() > 0) {
               cout << s.top() << " ";
                s.pop(); 
            }

            cout << "\n";
        } 
        else {
            cout << "skip because s has only one value\n\n\n";
        }
    }
    return 0; 
}