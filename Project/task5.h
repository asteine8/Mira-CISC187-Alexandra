#include <vector>


class Task5 {
    public:
        static std::vector<double> sortBodyTemperatures(std::vector<double> temps) {
            std::vector<double> sortedTemps;

            // Checks a finite number of cases that do not scale with N
            for (double t = 97.05; t <= 99.1; t += 0.1) {
                for (double temp : temps) { // Iterate through temperatures
                    if (temp < t && temp > (t-0.1)) {
                        sortedTemps.push_back(temp);
                    }
                }
            }

            return sortedTemps;
        }
};