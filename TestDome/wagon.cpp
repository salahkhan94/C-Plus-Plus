#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
public:
    void attachWagonFromLeft(int wagonId)
    {
        train.push_back(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        train.push_front(wagonId);
    }

    int detachWagonFromLeft()
    {
        int d = train.back();
        train.pop_back();
        return d;
    }

    int detachWagonFromRight()
    {
        int d = train.front();
        train.pop_front();
        return d;
    }
private:
    std::deque<int> train;
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft(); // 13
}
#endif