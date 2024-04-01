class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles, empty_bottles = numBottles;
        while (empty_bottles >= numExchange) {
            empty_bottles -= numExchange - 1;
            numExchange++;
            res++;
        }
        return res;
    }
};