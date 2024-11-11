class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while (mainTank) {
            if (mainTank >= 5 && additionalTank) {
                res += 50;
                additionalTank--;
                mainTank -= 5;
                mainTank++;
            } else {
                res += mainTank * 10;
                mainTank = 0;
            }
        }
        return res;
    }
};