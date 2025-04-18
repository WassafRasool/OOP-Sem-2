#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() const = 0;
    virtual void displayResult() const = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double distance; 
    double time;    

public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() const override {
        return distance * 60.0;
    }

    void displayResult() const override {
        cout << "Running: Distance = " << distance << " km, Time = " << time << " min\n";
        cout << "Calories Burned: " << calculateCaloriesBurned() << " kcal\n";
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;  

public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() const override {
        return speed * time * 30.0;
    }

    void displayResult() const override {
        cout << "Cycling: Speed = " << speed << " km/h, Time = " << time << " hours\n";
        cout << "Calories Burned: " << calculateCaloriesBurned() << " kcal\n";
    }
};

int main() {
    Running run(5.0, 30.0);       
    Cycling cycle(20.0, 1.5);     

    Activity* activities[2];
    activities[0] = &run;
    activities[1] = &cycle;

    cout << "Calories Tracker:\n\n";
    for (int i = 0; i < 2; ++i) {
        activities[i]->displayResult();
        cout << "--------------------------\n";
    }

    return 0;
}
