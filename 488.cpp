#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> handCount;
        for (char ball : hand) {
            handCount[ball]++;
        }
        
        int result = backtrack(board, handCount);
        return result == INT_MAX ? -1 : result;
    }
    
private:
    int backtrack(string board, unordered_map<char, int>& handCount) {
        if (board.empty()) {
            return 0;  // Board is already empty
        }
        
        int minSteps = INT_MAX;
        for (int i = 0; i < board.size(); i++) {
            int j = i;
            while (j < board.size() && board[j] == board[i]) {
                j++;
            }
            
            int needed = 3 - (j - i);  // Number of additional balls needed to form a group of 3
            if (handCount[board[i]] >= needed) {
                string newBoard = removeConsecutive(board.substr(0, i) + board.substr(j));
                handCount[board[i]] -= needed;
                int steps = backtrack(newBoard, handCount);
                if (steps != INT_MAX) {
                    minSteps = min(minSteps, needed + steps);
                }
                handCount[board[i]] += needed;  // Undo the changes for backtracking
            }
            
            i = j - 1;  // Skip to the next different ball
        }
        
        return minSteps;
    }
    
    string removeConsecutive(string board) {
        bool found = true;
        while (found) {
            found = false;
            int i = 0;
            while (i < board.size()) {
                int j = i;
                while (j < board.size() && board[j] == board[i]) {
                    j++;
                }
                
                if (j - i >= 3) {
                    board = board.substr(0, i) + board.substr(j);
                    found = true;
                    break;
                }
                
                i = j;
            }
        }
        
        return board;
    }
};
