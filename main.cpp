#include <iostream>
#include <cmath>

class Cylinder {
private:
    double m_radius;
    double m_height;
    double m_volume;
public:
    Cylinder() {
        m_radius = 0;
        m_height = 0;
        m_volume = 0;
    }

    Cylinder(double radius, double height) {
        if (radius > 0){
            m_radius = radius;
        }else {
            m_radius = 1;
        }
        if (height > 0) {
            m_height = height;
        }else {
            m_height = 1;
        }
    }

    void calcVolume() {
        m_volume = M_PI * pow(m_radius,2.0) * m_height;
    }

    [[nodiscard]] double getVolume() const {
        return m_volume;
    }

    Cylinder operator+(Cylinder &rightCylinder) {
        Cylinder temp;
        temp.m_volume = this->m_volume += rightCylinder.m_volume;
        temp.m_height = this->m_height += rightCylinder.m_height;
        temp.m_radius = sqrt(temp.m_volume / temp.m_height / M_PI);

        return temp;
    }

    friend std::ostream operator<<(std::ostream &os, Cylinder &cylinder);

};

std::ostream operator<<(std::ostream &os, Cylinder &cylinder) {
    os << "Radius: " << cylinder.m_radius << std::endl;
    os << "Height: " << cylinder.m_height << std::endl;
    os << "Radius: " << cylinder.m_volume << std::endl;

    return os;
}

int main() {
    Cylinder cylinder0;
    cylinder0.calcVolume();
    std::cout << "The Test Cylinder's volume is: " << cylinder0.getVolume() << std::endl;
    Cylinder cylinder1(2.45,12.5);
    cylinder1.calcVolume();
    std::cout << "Cylinder 1's volume is: " << cylinder1.getVolume() << std::endl;
    Cylinder cylinder2(4.85,9.125);
    cylinder2.calcVolume();
    std::cout << "Cylinder 2's volume is: " << cylinder2.getVolume() << std::endl;

    // cylinder cylinder1.+(cylinder2)
    Cylinder cylinder3 = cylinder1 + cylinder2; // operator  overloading
    cylinder3.calcVolume();
    //std::cout << "Cylinder 3's volume is: " << cylinder3.getVolume() << std::endl;
    std::cout << cylinder3;

    return 0;
}