#include <iostream>

class Animal{
    public:
        bool isAlive;

        void eat(){
            std::cout << "chomp\n";
        }

        virtual void fazer_som(){ //polimorfismo
            std::cout << "som generico\n";
        }

        Animal(bool isAlive){ //CONSTRUTOR CLASSE PAI
            this->isAlive = isAlive;
        }

};

class Dog : public Animal{
    public:
        std::string name;
        std::string breed;
        std::string gender;
        int age;

        void fazer_som() override { //polimorfismo
            std::cout << "woof\n";
        }

        int months_alive(Dog A){
            int day_age = 12 * A.age;

            return day_age;
        }

        Dog(bool isAlive, std::string name, std::string breed, std::string gender, int age) : Animal(isAlive){ //CHAMA CONSTRUTOR DA CLASSE PAI DENTRO DA CLASSE FILHO
            this->name = name;
            this->breed = breed;
            this->gender = gender;
            this->age = age;
        }
};

int main (){
    std::string nome, raca, genero;
    int idade;

    std::cin >> nome;
    std::cin >> raca;
    std::cin >> genero;
    std::cin >> idade;

    Dog spike(true, nome, raca, genero, idade);

    spike.fazer_som();
    std::cout << spike.months_alive(spike) << "\n";

    spike.eat();
    std::cout << spike.isAlive << "\n";

    return 0;
}