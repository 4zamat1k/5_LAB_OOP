#include <iostream>
#include <string>

class Plane {
protected:
    std::string name;
private:
    double vehicleContent;
public:
    Plane(std::string name, double vehicleContent)
    {
        this->name = name;
        this->vehicleContent = vehicleContent;
        std::cout << "Plane " << name << std::endl;
    }

    Plane() {
        name = "Unknown";
        vehicleContent = 0.0;
        std::cout << "Default Plane created" << std::endl;
    }

    Plane(const Plane& other) {
        name = other.name;
        vehicleContent = other.vehicleContent;
        std::cout << "Plane " << name << " copied" << std::endl;
    }

    // Метод для вывода информации о самолете.
    void print() {
        std::cout << "Plane" << name
            << ", Speed: " << vehicleContent << "Mach" << std::endl;
    }

    std::string getName() {
        return name;
    }
    double getSpeed() {
        return vehicleContent;
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setSpeed(double newSpeed) {
        vehicleContent = vehicleContent;
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
    Manufacturer(std::string name, double vehicleContent, std::string country) : Plane(name, vehicleContent)
    {
        this->country = country;
        std::cout << "Manufacturer " << name << " from " << country << std::endl;
    }

    // Конструктор копирования.
    Manufacturer(const Manufacturer& other) : Plane(other) {
        country = other.country;
        std::cout << "Manufacturer " << getName() << " copied" << std::endl;
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

void func1(Plane obj) {
    std::cout << "func1 (by value)" << std::endl;
    obj.print();
};

void func2(Plane* obj) {
    std::cout << "func2 (by pointer)" << std::endl;
    obj->print();
}

void func3(Plane& obj) {
    std::cout << "func3 (by reference)" << std::endl;
    obj.print();
}

int main() {
    std::cout << "--------func1 (by value)-------" << std::endl;
    Plane p1("Su-25", 2.0);
    func1(p1);
    std::cout << " " << std::endl;

    std::cout << "--------func2 (by value)-------" << std::endl;
    Plane p2("F-16", 2.5);
    func2(&p2);
    std::cout << " " << std::endl;

    std::cout << "--------func3 (by reference)-------" << std::endl;
    Plane p3("Z-4", 2.8);
    func3(p3);
    std::cout << " " << std::endl;
    return 0;


}