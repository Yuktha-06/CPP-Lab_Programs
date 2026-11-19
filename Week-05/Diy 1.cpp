#include <iostream>

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    
    Counter(const Counter& other) {
        totalCreated++;
        currentlyAlive++;
    }

    
    Counter(Counter&& other) noexcept {
        totalCreated++;
        currentlyAlive++;
    }

    
    ~Counter() {
        currentlyAlive--;
    }

    static int getTotalCreated() {
        return totalCreated;
    }

    static int getCurrentlyAlive() {
        return currentlyAlive;
    }
};


int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    std::cout << "Initial - Created: " << Counter::getTotalCreated() 
              << ", Alive: " << Counter::getCurrentlyAlive() << '\n';

    {
        Counter c1;
        Counter c2;
        std::cout << "Inside block - Created: " << Counter::getTotalCreated() 
                  << ", Alive: " << Counter::getCurrentlyAlive() << '\n';

        Counter c3 = c1; 
        std::cout << "After copy - Created: " << Counter::getTotalCreated() 
                  << ", Alive: " << Counter::getCurrentlyAlive() << '\n';
    } 
  

    std::cout << "After scope - Created: " << Counter::getTotalCreated() 
              << ", Alive: " << Counter::getCurrentlyAlive() << '\n';

    return 0;
}
