#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 定义状态结构体，用于表示NFA的状态
struct State {
    char symbol;
    State* out1;
    State* out2;
};

// 定义NFA结构体，包含起始状态和接受状态
struct NFA {
    State* start;
    State* accept;
};

// 定义状态转换表的结构
struct TransitionTable {
    map<int, map<char, set<int>>> table;
};

int stateCounter = 0; // 用于生成状态编号

// 创建一个新的状态
State* newState(char symbol = 0, State* out1 = nullptr, State* out2 = nullptr) {
    State* state = new State{ symbol, out1, out2 };
    return state;
}

// 创建一个状态转换表
TransitionTable createTransitionTable(NFA nfa) {
    TransitionTable table;
    stack<State*> stateStack;
    map<State*, int> stateMapping;

    stateStack.push(nfa.start);
    stateMapping[nfa.start] = stateCounter++;
    while (!stateStack.empty()) {
        State* current = stateStack.top();
        stateStack.pop();

        // 查找当前状态的转移边
        map<char, set<int>> transitions;

        if (current->out1) {
            stateStack.push(current->out1);
            stateMapping[current->out1] = stateCounter++;
            transitions[current->symbol].insert(stateMapping[current->out1]);
        }

        if (current->out2) {
            stateStack.push(current->out2);
            stateMapping[current->out2] = stateCounter++;
            transitions[current->symbol].insert(stateMapping[current->out2]);
        }

        table.table[stateMapping[current]] = transitions;
    }

    return table;
}

// 将正则表达式转换为NFA
NFA regexToNFA(string regex) {
    stack<NFA> nfaStack;

    for (char c : regex) {
        if (c == '.') {
            NFA nfa2 = nfaStack.top();
            nfaStack.pop();
            NFA nfa1 = nfaStack.top();
            nfaStack.pop();
            nfaStack.push({ nfa1.start, nfa2.accept });
        }
        else if (c == '|') {
            NFA nfa2 = nfaStack.top();
            nfaStack.pop();
            NFA nfa1 = nfaStack.top();
            nfaStack.pop();
            State* start = newState();
            start->out1 = nfa1.start;
            start->out2 = nfa2.start;
            State* accept = newState();
            nfa1.accept->out1 = accept;
            nfa2.accept->out1 = accept;
            nfaStack.push({ start, accept });
        }
        else if (c == '*') {
            NFA nfa1 = nfaStack.top();
            nfaStack.pop();
            State* start = newState();
            start->out1 = nfa1.start;
            State* accept = newState();
            start->out2 = accept;
            nfa1.accept->out1 = nfa1.start;
            nfa1.accept->out2 = accept;
            nfaStack.push({ start, accept });
        }
        else {
            State* start = newState(c);
            State* accept = newState();
            start->out1 = accept;
            nfaStack.push({ start, accept });
        }
    }

    return nfaStack.top();
}

// 打印状态转换表
void printTransitionTable(TransitionTable table) {
    for (auto entry : table.table) {
        cout << "State " << entry.first << ":\n";
        for (auto transition : entry.second) {
            cout << "  On symbol '" << transition.first << "', transition to states: ";
            for (int state : transition.second) {
                cout << state << " ";
            }
            cout << endl;
        }
    }
}

//int main() {
//    string regex = "a.b|c*";
//    NFA nfa = regexToNFA(regex);
//
//    TransitionTable table = createTransitionTable(nfa);
//
//    // 打印状态转换表
//    printTransitionTable(table);
//
//    return 0;
//}



