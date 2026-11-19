#include <iostream>

class Order {
private:
    static int nextID;

    
    int orderID;
    std::string itemName;

public:
    Order(std::string name) : itemName(name) {
        orderID = nextID++; 
    }

    
    int getOrderID() const { return orderID; }
    std::string getItemName() const { return itemName; }
};


int Order::nextID = 1001;

int main() {

    Order order1("Laptop");
    Order order2("Smartphone");
    Order order3("Wireless Earbuds");

    
    std::cout << "Order 1: ID = " << order1.getOrderID() << ", Item = " << order1.getItemName() << std::endl;
    std::cout << "Order 2: ID = " << order2.getOrderID() << ", Item = " << order2.getItemName() << std::endl;
    std::cout << "Order 3: ID = " << order3.getOrderID() << ", Item = " << order3.getItemName() << std::endl;

    return 0;
}
