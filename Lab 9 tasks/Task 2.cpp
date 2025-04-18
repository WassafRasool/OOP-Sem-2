#include <iostream>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() const = 0;

    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness; 

public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn() override {
        isOn = true;
        brightness = 75; 
        cout << "LightBulb turned ON with brightness " << brightness << "%.\n";
    }

    void turnOff() override {
        isOn = false;
        brightness = 0;
        cout << "LightBulb turned OFF.\n";
    }

    void getStatus() const override {
        cout << "LightBulb is " << (isOn ? "ON" : "OFF")
             << ", Brightness: " << brightness << "%\n";
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature; s

public:
    Thermostat() : isOn(false), temperature(20.0) {}

    void turnOn() override {
        isOn = true;
        temperature = 22.5; 
        cout << "Thermostat turned ON, temperature set to " << temperature << "°C.\n";
    }

    void turnOff() override {
        isOn = false;
        cout << "Thermostat turned OFF.\n";
    }

    void getStatus() const override {
        cout << "Thermostat is " << (isOn ? "ON" : "OFF");
        if (isOn)
            cout << ", Temperature: " << temperature << "°C";
        cout << endl;
    }
};

int main() {
    LightBulb bulb;
    Thermostat thermo;

    SmartDevice* devices[2];
    devices[0] = &bulb;
    devices[1] = &thermo;

    cout << "Activating Smart Devices...\n\n";

    for (int i = 0; i < 2; ++i) {
        devices[i]->turnOn();
    }

    cout << "\nDevice Status:\n";
    for (int i = 0; i < 2; ++i) {
        devices[i]->getStatus();
        cout << "------------------\n";
    }

    cout << "\nDeactivating Devices...\n";
    for (int i = 0; i < 2; ++i) {
        devices[i]->turnOff();
    }

    cout << "\nFinal Status:\n";
    for (int i = 0; i < 2; ++i) {
        devices[i]->getStatus();
        cout << "------------------\n";
    }

    return 0;
}
