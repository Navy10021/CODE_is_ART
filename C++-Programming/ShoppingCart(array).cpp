#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_PRODUCT = 5;

// Product class
class Product{
    private:
        string name;
        int productID;
    public:
        Product(const string& name, int ID)
            : productID(ID) {this->name = name;}

        virtual double CalculateDiscountePrice() const = 0;
        virtual void DisplayInfo() const{
            cout << "Product ID : " << productID << " || Product Name : " << name;
        }
        virtual ~Product() {}
};

class ElectronicProduct : public Product{
    private:
        double originalPrice;
        double discountRate;
    public:
        ElectronicProduct(const string& name, int ID, double price, double discount)
            : Product(name, ID), originalPrice(price), discountRate(discount) {}
        
        double CalculateDiscountePrice() const override{
            return originalPrice * (1 - discountRate);
        }
        void DisplayInfo() const override{
            Product::DisplayInfo();
            cout << " || Type : Electronic || Base price : " << originalPrice << " || Discount price : " << CalculateDiscountePrice() << endl;
        } 
};

class ClothingProduct : public Product{
    private:
        string size;
        double basePrice;
    public:
        ClothingProduct(const string& name, int ID, const string& productSize, double price)
            : Product(name, ID), size(productSize), basePrice(price) {}

        double CalculateDiscountePrice() const override {
            return basePrice * 0.9;
        }
        void DisplayInfo() const override{
            Product::DisplayInfo();
            cout << " || Type : Clothing || Size : " << size << " || Base price : " << basePrice << " || Discount price" << CalculateDiscountePrice() << endl;
        }
};

class ShoppingCart {
    private:
        Product* productArr[MAX_PRODUCT];
        int numProducts;
    public:
        ShoppingCart() : numProducts(0) {}

        ~ ShoppingCart(){
            for (int i = 0; i<numProducts; i++){
                delete productArr[i];
            }
        }
        void AddProduct(Product* product){
            if (numProducts < MAX_PRODUCT){
                productArr[numProducts++] = product;
            }
            else{
                cout << "Shopping cart is full.\n" << endl;
                delete product;
            }
        }
        double TotalPrice() const{
            double total = 0.0;
            for (int i = 0; i < numProducts; i++){
                total += productArr[i]->CalculateDiscountePrice();
            }
            return total;
        }

        void sortByPrice(){
            sort(productArr, productArr + numProducts, [](const Product* a, const Product* b){
                return a->CalculateDiscountePrice() > b->CalculateDiscountePrice();
            });
        }

        void DisplayProducts() const{
            for (int i = 0; i < numProducts; i++){
                productArr[i]->DisplayInfo();
            }
        }
};

int main(void){
    ShoppingCart MyCart;
    MyCart.AddProduct(new ElectronicProduct("GALAXY", 301, 200.0, 0.15));
    MyCart.AddProduct(new ElectronicProduct("iPhone", 302, 250.0, 0.0));
    MyCart.AddProduct(new ElectronicProduct("iPad", 305, 600.0, 0.1));
    MyCart.AddProduct(new ClothingProduct("Jeans", 401, "XL", 49.99));
    MyCart.AddProduct(new ClothingProduct("T-shirt", 402, "M", 1299.99));

    cout << "Total Price in Shopping Cart : $" << MyCart.TotalPrice() << endl;
    MyCart.sortByPrice();
    MyCart.DisplayProducts();
    MyCart.AddProduct(new ClothingProduct("GUGI", 501, "XXL", 3900.0));
    
    return 0;
}
