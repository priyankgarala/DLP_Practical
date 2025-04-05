/*
Implement DFA as below:
no. of input symbols: 2
input symbol: a b
enter number of states: 1
initial state: 1
number of accepting states: 1
Accepting states: 2
transistion table:
1 to a->2
1 to b->3
2 to a->1
2 to b->4
3 to a->4
3 to b->1
4 to a->3
4 to b->2

input string : abbabab

output : vaild
Other programs:
1. string over 0,1 where every 0 immediately by 11
2. string over a b c start and end with same letter
3. string over lower case alphabet and digits, starts with alphabet only.
*/
#include <bits/stdc++.h>
using namespace std;

// 1: DFA for the string of types "abbabab"
bool testCase1(const string &input) {
    int transition[5][2]={{0, 0}, {2, 3}, {1, 4}, {4, 1}, {3, 2}};
    int currentState=1;

    for (char ch:input) {
        int symbol=(ch == 'a') ? 0 : 1; // 'a' -> 0, 'b' -> 1
        currentState=transition[currentState][symbol];
    }
    return currentState== 2;
}

// 2: DFA for strings where every '0' is followed by '11'
bool testCase2(const string &input) {
    int i = 0;
    while(i < input.length()) {
        if(input[i] == '0') {
            if(i + 2 < input.length() && input[i + 1] == '1' && input[i + 2] == '1') {
                i += 3;
            }
            else{
                return false;
            }
        }
        else{
            i++;
        }
    }
    return true;
}

// 3: DFA for strings over 'a', 'b', 'c' that start and end with the same letter
bool testCase3(const string &input) {
    int n = input.length();
    if(n == 0 || input[0] != input[n - 1]) {
        return false;
    }
    for(char ch : input) {
        if(ch != 'a' && ch != 'b' && ch != 'c') {
            return false;
        }
    }
    return true;
}

// 4: DFA for strings over lowercase alphabets and digits, starting with an alphabet
bool testCase4(const string &input) {
/*    if (!islower(input[0])) {
        return false; // Must start with a lowercase alphabet
    }*/
    for(char ch : input) {
        if(!islower(ch) && !isdigit(ch)) {
            return false; // Only lowercase alphabets and digits are allowed
        }
    }
    return true;
}

int main() {
    int choice;
    string input;

    cout<< "Choose Test Case:\n";
    cout<< "1. DFA for string 'abbabab'\n";
    cout<< "2. DFA for strings where every '0' is followed by '11'\n";
    cout<< "3. DFA for strings over 'a', 'b', 'c' starting and ending with the same letter\n";
    cout<< "4. DFA for strings over lowercase alphabets and digits, starting with an alphabet\n";
    cout<< "Enter your choice (1-4): ";
    cin>> choice;

    cout<< "Enter string: ";
    cin>> input;

    bool isValid = false;
    switch(choice) {
        case 1:
            isValid = testCase1(input);
            break;
        case 2:
            isValid = testCase2(input);
            break;
        case 3:
            isValid = testCase3(input);
            break;
        case 4:
            isValid = testCase4(input);
            break;
        default:
            cout << "Invalid choice\n";
            return 1;
    }

    if(isValid) {
        cout << "Valid\n";
    }
    else{
        cout << "Invalid\n";
    }

    return 0;
}