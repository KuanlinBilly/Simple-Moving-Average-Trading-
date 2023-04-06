# Simple Moving Average Crossover Trading Strategy with C++

This C++ project demonstrates a simple moving average crossover trading strategy using historical price data.

The strategy compares a short-term moving average (e.g., 5-day moving average) to a longer-term moving average (e.g., 10-day moving average) to determine buy and sell signals. When the short-term moving average crosses above the long-term moving average, a buy signal is generated. Conversely, when the short-term moving average crosses below the long-term moving average, a sell signal is generated.

## Project Structure

This project consists of a single C++ file containing the `MovingAverage` class and a `main()` function.

### MovingAverage Class

The `MovingAverage` class is responsible for computing the moving average for a given period and updating its internal state when new values are provided. The class has the following methods:

- `MovingAverage(size_t period)`: Constructor that takes a period as an argument.
- `double calculate(double newValue)`: Computes the moving average for the given value and updates the internal state.

### main() Function

The `main()` function demonstrates how to use the `MovingAverage` class with example price data. The function initializes two `MovingAverage` instances with different periods (short-term and long-term). Then, it iterates through the price data and calculates the moving averages for each day. Buy and sell signals are generated based on the crossover of the short-term and long-term moving averages.

## Usage

1. Compile the C++ file using a C++ compiler (e.g., g++, clang++):
g++ -o moving_average_crossover moving_average_crossover.cpp


2. The program will output buy and sell signals based on the example price data.

## Example Output
* Buy at 100 (day 6)
* Sell at 97 (day 8)
* Buy at 96 (day 12)
#### This output demonstrates that the program generated a buy signal on day 6, a sell signal on day 8, and another buy signal on day 12, based on the moving average crossover strategy.


