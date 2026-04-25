#include <iostream>
#include <string>
#include "memory"

class Plane {
protected:
    std::string name;
private:
    double vehicleContenet;
public:
    Plane(std::string name, double vehicleContenet)
    {
        this->name = name;
        this->vehicleContenet = vehicleContenet;
        std::cout << "Plane " << name << std::endl;
    }

    Plane() {
        name = "Unknown";
        vehicleContenet = 0.0;
        std::cout << "Default Pivo created" << std::endl;
    }

    Plane(const Plane& other) {
        name = other.name;
        vehicleContenet = other.vehicleContenet;
        std::cout << "Plane " << name << " copied" << std::endl;
    }

    // Метод для вывода информации о самолете.
    void print() {
        std::cout << "Plane" << name
            << ", Speed: " << vehicleContenet << "Mach"  << std::endl;
    }

    virtual std::string classname() {
        return "Plane";
    }

    virtual bool isA(std::string className) {
        return className == "Plane";
    }

    std::string getName() {
        return name;
    }
    double getSpeed() {
        return vehicleContenet;
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setSpeed(double newSpeed) {
        vehicleContenet = newSpeed;
    }

    ~Plane() {
        std::cout << "Plane" << name << " destroyed" << std::endl;
    }


};

class Manufacturer : public Plane {
private:
    std::string country;
public:
    // Создан без параметров. 
    Manufacturer() : Plane() {
        country = "Unknown";
        std::cout << "Default Manufacturer created" << std::endl;
    }

    // Создан с параметрами.
    Manufacturer(std::string name, double vehicleContenet, std::string country) : Plane(name, vehicleContenet)
    {
        this->country = country;
        std::cout << "Manufacturer " << name << " from " << country << std::endl;
    }

    // Конструктор копирования.
    Manufacturer(const Manufacturer& other) : Plane(other) {
        country = other.country;
        std::cout << "Manufacturer " << getName() << " copied" << std::endl;
    }

    std::string classname() override {
        return "Manufacturer";
    }

    bool isA(std::string className) override {
        return className == "Manufacturer" || Plane::isA(className);
    }

    // Диструктор.
    ~Manufacturer() {
        std::cout << "Manufacturer " << country << " destroyed" << std::endl;;
    }

    void printManufacturer() {
        std::cout << "Manufacturer: " << getName()
            << ", Speed: " << getSpeed() << "Mach"
            << ", Country: " << country << std::endl;
    }
    void testAccess() {
        std::cout << name << std::endl;
        std::cout << getSpeed() << std::endl;
    }

    // Переопределение метода print() для класса Manufacturer.
    void print() {
        Plane::print();
        std::cout << "Country: " << country << std::endl;
    }
};

int main() {
    std::cout << "---Classname---" << std::endl;
    Plane* p1 = new Plane("Su-25", 2.0);
    Plane* p2 = new Manufacturer("Su-27", 2.5, "Russia");

    std::cout << p1->classname() << std::endl;
    std::cout << p2->classname() << std::endl;
    delete p1;
    delete p2;
    std::cout << " " << std::endl;

    std::cout << "---isA---" << std::endl;
    Plane* p3 = new Manufacturer("F-16", 2.5, "USA");
    std::cout << p3->isA("Plane") << std::endl;
    std::cout << p3->isA("Manufacturer") << std::endl;
    std::cout << p3->isA("Label") << std::endl;
    delete p3;
    std::cout << " " << std::endl;

    std::cout << "---dynamic_cast---" << std::endl;
    Plane* p4 = new Manufacturer("Z-4", 2.8, "Germany");

    Manufacturer* m = dynamic_cast<Manufacturer*>(p4);
    if (m != nullptr) {
        std::cout << "Dynamic cast successful" << std::endl;
        m->printManufacturer();
    }
    else {
        std::cout << "Dynamic cast failed" << std::endl;
    }
    delete p4;
}