#include <iostream>
#include <string>

// Компонент (интерфейс)
class Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Beverage() = default;
};

// Конкретный Компонент
class SimpleCoffee : public Beverage {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }
    double cost() const override {
        return 1.0;
    }
};

// Базовый Декоратор
class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage;
public:
    CondimentDecorator(Beverage* bev) : beverage(bev) {}
    virtual ~CondimentDecorator() { delete beverage; }
};

// Конкретный Декоратор (молоко)
class Milk : public CondimentDecorator {
public:
    Milk(Beverage* bev) : CondimentDecorator(bev) {}
    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }
    double cost() const override {
        return beverage->cost() + 0.5;
    }
};

// Конкретный Декоратор (сахар)
class Sugar : public CondimentDecorator {
public:
    Sugar(Beverage* bev) : CondimentDecorator(bev) {}
    std::string getDescription() const override {
        return beverage->getDescription() + ", Sugar";
    }
    double cost() const override {
        return beverage->cost() + 0.2;
    }
};

int main() {
    // Базовый кофе
    Beverage* coffee = new SimpleCoffee();
    std::cout << coffee->getDescription() << " $" << coffee->cost() << std::endl;

    // Кофе с молоком
    Beverage* coffeeWithMilk = new Milk(coffee);
    std::cout << coffeeWithMilk->getDescription() << " $" << coffeeWithMilk->cost() << std::endl;

    // Кофе с молоком и сахаром
    Beverage* coffeeWithMilkAndSugar = new Sugar(coffeeWithMilk);
    std::cout << coffeeWithMilkAndSugar->getDescription() << " $" << coffeeWithMilkAndSugar->cost() << std::endl;

    delete coffeeWithMilkAndSugar; // Удаление всех объектов
    return 0;
}
