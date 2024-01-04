#include <iostream>
#include <algorithm> // for std::sort
#include <vector>

using namespace std;

const int MAX_PRINTED_MATERIALS = 10;

class PrintedMaterial {
protected:
    string title;
    double basePrice;

public:
    PrintedMaterial(const string& materialTitle, double price)
        : title(materialTitle), basePrice(price) {}

    virtual double CalculateDiscountedPrice() const = 0; // Pure virtual
    virtual void DisplayInfo() const = 0;

    virtual ~PrintedMaterial() {}
};

class Book : public PrintedMaterial {
private:
    int bookID;

public:
    Book(const string& bookTitle, int ID, double price)
        : PrintedMaterial(bookTitle, price), bookID(ID) {}

    double CalculateDiscountedPrice() const override {
        // Book discount calculation logic
        return basePrice * 0.9; // Example discount for simplicity
    }

    void DisplayInfo() const override {
        cout << "Book ID: " << bookID << " || Title: " << title << " || Discounted Price: $" << CalculateDiscountedPrice() << endl;
    }
};

class Magazine : public PrintedMaterial {
private:
    int issueNumber;

public:
    Magazine(const string& magTitle, int number, double price)
        : PrintedMaterial(magTitle, price), issueNumber(number) {}

    double CalculateDiscountedPrice() const override {
        // Magazine discount calculation logic
        return basePrice * 0.75; // Example discount for simplicity
    }

    void DisplayInfo() const override {
        cout << "Issue Number: " << issueNumber << " || Title: " << title << " || Discounted Price: $" << CalculateDiscountedPrice() << endl;
    }
};

class PrintedMaterialStore {
private:
    vector<PrintedMaterial*> materials;

public:
    ~PrintedMaterialStore() {
        for (PrintedMaterial* material : materials) {
            delete material;
        }
    }

    void AddMaterial(PrintedMaterial* material) {
        materials.push_back(material);
    }

    double TotalDiscountedPrice() const {
        double total = 0.0;
        for (const PrintedMaterial* material : materials) {
            total += material->CalculateDiscountedPrice();
        }
        return total;
    }

    double AvgDiscountedPrice() const{
        return TotalDiscountedPrice() / materials.size();
    }

    void sortByDiscountedPrice() {
        sort(materials.begin(), materials.end(), [](const PrintedMaterial* a, const PrintedMaterial* b) {
            return a->CalculateDiscountedPrice() > b->CalculateDiscountedPrice();
        });
    }

    void DisplayMaterials() const {
        for (const PrintedMaterial* material : materials) {
            material->DisplayInfo();
        }
    }
};

int main() {
    PrintedMaterialStore myMaterialStore;

    PrintedMaterial* ptr;
    ptr = new Book("The Great Gatsby", 1, 19.99);
    myMaterialStore.AddMaterial(ptr);
    ptr = new Magazine("Science Today", 101, 5.99);
    myMaterialStore.AddMaterial(ptr);

    // Add more books and magazines as needed...

    cout << "Total Discounted Price in the material store: $" << myMaterialStore.TotalDiscountedPrice() << endl;
    cout << "Average Price in the material store : $" << myMaterialStore.AvgDiscountedPrice() << endl;
    myMaterialStore.sortByDiscountedPrice();
    myMaterialStore.DisplayMaterials();

    return 0;
}