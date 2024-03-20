#define ENABLE_FILE_OUTPUT
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Абстрактный класс Bird

class Bird {
protected:
    string name;

public:
    Bird(const string& name) : name(name) {
    }
    virtual ~Bird() {
    }

    // Чисто виртуальный метод fly(), который описывает полет птицы
    virtual void fly() const = 0;

    const string& getName() const {
        return name;
    }
};

// Производные классы различных птиц
class Eagle : public Bird {
public:
    Eagle(const string& name) : Bird(name) {
    }

    // Переопределение метода fly() для орла
    void fly() const override {
        cout << "Eagle " << name << " is soaring high in the sky.\n";
    }
};
class Sparrow : public Bird {
public:
    Sparrow(const string& name) : Bird(name) {
    }

    // Переопределение метода fly() для воробья
    void fly() const override {
        cout << "Sparrow " << name << " is flying gracefully.\n";
    }
};

class Parrot : public Bird {
public:
    Parrot(const string& name) : Bird(name) {
    }

    // Переопределение метода fly() для попугая
    void fly() const override {
        cout << "Parrot " << name << " is gliding through the air.\n";
    }
};

class Gull : public Bird {
public:
    Gull(const string& name) : Bird(name) {
    }

    // Переопределение метода fly() для попугая
    void fly() const override {
        cout << "Gull " << name << " is gliding through the air.\n";
    }
};

// Класс Aviary
class Aviary {
private:
    vector<Bird *> birds;

public:
    Aviary() {
    }

    ~Aviary() {
        for (auto b : birds) {
            delete b;
        }
    }

    // Добавление птицы в авиарий
    void addBird(Bird* bird) {
        birds.push_back(bird);
    }

    // Инициация полета для всех птиц в авиарии и запись информации в файл
    void initiateFlight() const {

        ofstream file("flights.txt");
        if (!file.is_open()) {
            cerr << "Unable to open flights.txt\n";
            return;
        }


        for (const auto& bird : birds) {
            bird->fly();

            file << bird->getName() << " is flying.\n";

        }


        file.close();

    }
};

int main() {
    // Создание объектов различных птиц

    int bird;

    Aviary aviary;
    bool flag = true;
    while (flag) {
        std::cout << "Get bird\n";
        std::cin >> bird;
        switch (bird) {
            case 1: {
                aviary.addBird(new Eagle("Dummy Eagle"));
                break;
            }
            case 2: {
                aviary.addBird(new Parrot("King Parrot"));
                break;
            }
            default:
                flag = false;
                break;
        }
    }
    aviary.initiateFlight();

    return 0;
}