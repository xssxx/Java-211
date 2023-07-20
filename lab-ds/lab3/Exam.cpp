#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    double score1[N], score2[N], score3[N];
    double sumScore1 = 0, sumScore2 = 0, sumScore3 = 0;

    for (int i = 0; i < N; i++) {
        cin >> score1[i] >> score2[i] >> score3[i];
        sumScore1 += score1[i];
        sumScore2 += score2[i];
        sumScore3 += score3[i];
    }

    double totalMean = (sumScore1 + sumScore2 + sumScore3) / N;

    double meanScore1 = sumScore1 / N;
    double meanScore2 = sumScore2 / N;
    double meanScore3 = sumScore3 / N;


    for (int i = 0; i < N; i++) {
        int count = 0;
        bool meanPass = false, totalMeanPass = false, zeroPass = false;

        if (score1[i] >= meanScore1) count++;
        if (score2[i] >= meanScore2) count++;
        if (score3[i] >= meanScore3) count++;

        if (count >= 2) meanPass = true;
        if (score1 > 0 && score2 > 0 && score3 > 0) zeroPass = true;
        if (score1[i] + score2[i] + score3[i] >= totalMean) totalMeanPass = true;

        if (meanPass && totalMeanPass && zeroPass)
            cout << i + 1 << " ";
    }

    return 0;
}