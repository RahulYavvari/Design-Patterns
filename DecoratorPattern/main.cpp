#include <iostream>
#include <string>

class Coffee {
public:
    std::string description;

    Coffee() {
        this->description = "unknown coffee";
    }

    virtual void get_desc() {
        std::cout << description << std::endl;
    }

    virtual double cost() = 0;
};

class Espresso : public Coffee {
public:
    Espresso() {
        this->description = "Espresso";
    }

    double cost() override {
        return 1.99;
    }
};

class CoffeeDecorator : public Coffee {
public:
    Coffee* coffee;

    CoffeeDecorator(Coffee* coffee) {
        this->coffee = coffee;
    }

    virtual void get_desc() override = 0;
    virtual double cost() override = 0;
};

class WithMilk : public CoffeeDecorator {
public:
    WithMilk(Coffee* coffee) : CoffeeDecorator(coffee) {}

    void get_desc() override {
        this->coffee->get_desc();
        std::cout << ", Milk" << std::endl;
    }

    double cost() override {
        return this->coffee->cost() + 0.5;
    }
};

class WithSugar : public CoffeeDecorator {
public:
    WithSugar(Coffee* coffee) : CoffeeDecorator(coffee) {}

    void get_desc() override {
        this->coffee->get_desc();
        std::cout << ", Sugar" << std::endl;
    }

    double cost() override {
        return this->coffee->cost() + 0.25;
    }
};

void coffee_info(Coffee* coffee) {
    coffee->get_desc();
    std::cout << "$ " << coffee->cost() << std::endl;
    std::cout << std::endl;
}

int main() {
    Coffee* order1 = new Espresso();
    coffee_info(order1);

    order1 = new WithSugar(order1);
    coffee_info(order1);

    order1 = new WithMilk(order1);
    coffee_info(order1);

    delete order1;

    return 0;
}
