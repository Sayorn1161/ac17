#include <iostream>
#include <string>

class Pet {
protected:
    std::string name;
    std::string species;
    int age;
    double weight;

public:
    Pet(std::string name, std::string species, int age, double weight)
        : name(name), species(species), age(age), weight(weight) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << "\n"
                  << "Species: " << species << "\n"
                  << "Age: " << age << " years\n"
                  << "Weight: " << weight << " kg\n";
    }
};

class Dog : public Pet {
private:
    std::string breed;

public:
    Dog(std::string name, int age, double weight, std::string breed)
        : Pet(name, "Dog", age, weight), breed(breed) {}

    void displayInfo() const override {
        Pet::displayInfo();
        std::cout << "Breed: " << breed << "\n";
    }
};

class Cat : public Pet {
private:
    std::string color;

public:
    Cat(std::string name, int age, double weight, std::string color)
        : Pet(name, "Cat", age, weight), color(color) {}

    void displayInfo() const override {
        Pet::displayInfo();
        std::cout << "Color: " << color << "\n";
    }
};

class Parrot : public Pet {
private:
    std::string vocabularySize;

public:
    Parrot(std::string name, int age, double weight, std::string vocabularySize)
        : Pet(name, "Parrot", age, weight), vocabularySize(vocabularySize) {}

    void displayInfo() const override {
        Pet::displayInfo();
        std::cout << "Vocabulary Size: " << vocabularySize << "\n";
    }
};

int main() {
    Dog myDog("Rex", 5, 25.4, "German Shepherd");
    Cat myCat("Whiskers", 3, 4.2, "Black");
    Parrot myParrot("Polly", 2, 0.5, "100 words");

    std::cout << "Dog Information:\n";
    myDog.displayInfo();
    std::cout << "\n";

    std::cout << "Cat Information:\n";
    myCat.displayInfo();
    std::cout << "\n";

    std::cout << "Parrot Information:\n";
    myParrot.displayInfo();
    std::cout << "\n";

    return 0;
}
