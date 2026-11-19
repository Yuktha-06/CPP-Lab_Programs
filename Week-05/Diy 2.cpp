#include <iostream>

class Time {
private:
    int hour;
    int minute;

public:
  
    Time(int h = 0, int m = 0) : hour(h), minute(m) {}

    
    friend Time laterOf(Time t1, Time t2);

    
    void display() const {
        if (hour < 10) std::cout << "0";
        std::cout << hour << ":";
        if (minute < 10) std::cout << "0";
        std::cout << minute << std::endl;
    }
};


Time laterOf(Time t1, Time t2) {

    if (t1.hour > t2.hour) {
        return t1;
    } 
    if (t2.hour > t1.hour) {
        return t2;
    }

    if (t1.minute > t2.minute) {
        return t1;
    }
    return t2;
}

int main() {
    Time breakfast(07, 30);
    Time lunch(13, 15);
    Time eveningSnack(13, 45);

    std::cout << "Comparing 07:30 and 13:15..." << std::endl;
    Time later1 = laterOf(breakfast, lunch);
    std::cout << "The later time is: ";
    later1.display();

    std::cout << "\nComparing 13:15 and 13:45..." << std::endl;
    Time later2 = laterOf(lunch, eveningSnack);
    std::cout << "The later time is: ";
    later2.display();

    return 0;
}
