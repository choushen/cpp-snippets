// import string header
#include <string>
#include <iostream>

class Vehicle {

    private:
        std::string color;
        std::string brand;

    public:
        Vehicle(std::string color, std::string brand) {
            this->color = color;
            this->brand = brand;
            std::cout << "Vehicle object created" << std::endl;
        }
        
        // the virtual keyword is used to allow derived classes to override the method
        virtual ~Vehicle() {
            std::cout << "Vehicle object destroyed" << std::endl;
        }

        std::string getColor() {
            return this->color;
        }

        std::string getBrand() {
            return this->brand;
        }

        void honkHorn() {
            std::cout << "HONKkkkkkkkkkKkkKKk!" << std::endl;
        }

};

class Car : public Vehicle {
    private:
        const int year;
        std::string& model;
        int* mileage;  // Dynamically allocated resource

    public:
        Car(std::string color, std::string brand, int year, std::string& model, int initialMileage)
            : Vehicle(color, brand), year(year), model(model) {
            mileage = new int(initialMileage);  // Dynamically allocate memory
            std::cout << "Car object created" << std::endl;
        }

        /* Overriding the deconstructor is necessary to free the dynamically allocated memory. 
        *  If not done, it will cause a memory leak. if we didn't have extra resources to free, 
        *  we wouldn't need to override the deconstructor.
        */     
        ~Car() override {
            delete mileage;  // Free dynamically allocated memory
            std::cout << "Car object destroyed" << std::endl;
        }

        int getYear() const {
            return year;
        }

        const std::string& getModel() const {
            return model;
        }

        int getMileage() const {
            return *mileage;
        }

        void drive(int distance) {
            *mileage += distance;
        }

};


int main() {

    Vehicle* greenBMW = new Vehicle("Green", "BMW"); // dynamic memory allocation
    Vehicle redToyota = Vehicle("Red", "Toyota"); // stack memory allocation

    std::cout << "[---Green BMW---]" << std::endl;
    std::cout << "Green BMW color: " << greenBMW->getColor() << std::endl;
    std::cout << "Green BMW brand: " << greenBMW->getBrand() << std::endl;
    greenBMW->honkHorn();

    std::cout << "[---Red Toyota---]" << std::endl;
    std::cout << "Red Toyota color: " << redToyota.getColor() << std::endl;
    std::cout << "Red Toyota brand: " << redToyota.getBrand() << std::endl;
    redToyota.honkHorn();

    // add double endl to separate the output
    std:: cout << std::endl << std::endl;
    
    
    std::string model = "A4";
    Car* blueAudi = new Car("Blue", "Audi", 2024, model, 0);
    std::cout << "[---Blue Audi---]" << std::endl;
    std::cout << "Blue Audi color: " << blueAudi->getColor() << std::endl;
    std::cout << "Blue Audi brand: " << blueAudi->getBrand() << std::endl;
    std::cout << "Blue Audi model: " << blueAudi->getModel() << std::endl;
    std::cout << "Blue Audi year: " << blueAudi->getYear() << std::endl;
    std::cout << "Blue Audi mileage: " << blueAudi->getMileage() << std::endl;
    blueAudi->drive(100);
    std::cout << "Blue Audi mileage after driving: " << blueAudi->getMileage() << std::endl;
    blueAudi->honkHorn();

    std::cout << std::endl << std::endl;


    delete greenBMW; // free memory
    delete blueAudi; // free memory
    // redToyota is automatically destroyed when it goes out of scope

    return 0;
}