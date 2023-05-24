class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int states = minutesToTest / minutesToDie + 1;
        while (pow(states, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};
