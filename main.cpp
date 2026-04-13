
#include <iostream>
#include <chrono>
using namespace std;

double calculate(int iteration, int param1, int param2) {
    double result = 1.0;
    for (int i = 1; i < iteration; ++i) {
        double j = static_cast<double>(i * param1) / param2;
        result -= (1.0 / j);
        j = static_cast<double>(i * param1) + param2;
        result += (1.0 / j);
    }
    return result;
}

int main() {
    auto startTime = chrono::high_resolution_clock::now();
    
    double result = calculate(200000000, 4, 1) * 4;
    
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;

    cout << "Result: " << result << endl;
    cout << "Execution Time: " << duration.count() << " seconds" << endl;

    return 0;
}
