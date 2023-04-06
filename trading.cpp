#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

class MovingAverage {
public:
    MovingAverage(size_t period) : _period(period) {}

    double calculate(double newValue) {
        if (_values.size() >= _period) {
            _sum -= _values.front();
            _values.pop_front();
        }
        _values.push_back(newValue);
        _sum += newValue;
        return _sum / _values.size();
    }

private:
    size_t _period;
    std::deque<double> _values;
    double _sum = 0.0;
};

int main() {
    // Example price data
    std::vector<double> prices = {100, 102, 101, 103, 99, 100, 98, 97, 95, 94, 96, 98, 100, 102, 104};

    // Initialize moving averages
    MovingAverage shortTermMA(5);
    MovingAverage longTermMA(10);

    bool isPositionOpen = false;

    for (size_t i = 0; i < prices.size(); ++i) {
        double shortTermAvg = shortTermMA.calculate(prices[i]);
        double longTermAvg = longTermMA.calculate(prices[i]);

        if (!isPositionOpen && shortTermAvg > longTermAvg) {
            std::cout << "Buy at " << prices[i] << " (day " << i + 1 << ")\n";
            isPositionOpen = true;
        } else if (isPositionOpen && shortTermAvg < longTermAvg) {
            std::cout << "Sell at " << prices[i] << " (day " << i + 1 << ")\n";
            isPositionOpen = false;
        }
    }

    return 0;
}
