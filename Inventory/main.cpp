// 30.10.2015
// The class Inventory uses the struct Product for Inventory control
// It supports the following operations:
//      adding a Product to inventory list,
//      putting two inventory lists together,
//      subtracting a list from another list,
//      comparing the total value of a list and another list.
// There are two sort orders: Alphabetical and by value.

#include <iostream>

using namespace std;

struct Product {
    string name; // name of product
    int amount; // how many ?
    double price; // price of the product
};

class Inventory {
private:
    Product *product; // The Product
    int n; // How many different Products are in the list
    string sortorder; // "Alphabetical" or "Value"

    int itemPos(string p) const;
    void sortList();
    void addSpaceToList(int newsize);
    double totalVal() const;

public:
    Inventory();
    Inventory(const Inventory &copyMe);
    ~Inventory();

    void setsortorder(string order);
    void addProduct(Product i);
    void operator = (const Inventory &same);

    friend istream& operator >> (istream& ins, Inventory& i);
    friend ostream& operator << (ostream& outs, const Inventory& i);
    friend Inventory operator + (const Inventory& a, const Inventory& b);
    friend Inventory operator - (const Inventory& a, const Inventory& b);
    friend bool operator > (const Inventory& a, const Inventory& b);
};

// Default sortorder is Alphabetical
Inventory:: Inventory() {
    n = 0;
    product = NULL;
    sortorder = "Alphabetical";
}

// copy constructor
Inventory::Inventory(const Inventory &copyMe) {
    sortorder = copyMe.sortorder;
    n = copyMe.n;

    if (n == 0)
        product = NULL;

    else {
        product = new Product[n];

        for (int i = 0; i < n; i++)
            product[i] = copyMe.product[i];
    }
}

Inventory::~Inventory() {
    if (product != NULL)
        delete[] product;
}

// Sets the sortorder to order
void Inventory::setsortorder(string order) {
    sortorder = order;
    sortList();
}

// Adds a new Product i to the Inventory list
// If i is already in the Inventory list, the amount of i and the existing i are summed up and the higher priced is used.
void Inventory::addProduct(Product i) {
    int pos = itemPos(i.name);

    if (pos == -1) {
        addSpaceToList(n + 1);
        product[n - 1] = i;
        sortList();
    }

    else {
        product[pos].amount += i.amount;

        if (product[pos].price > i.price)
            product[pos].price = i.price;
    }
}

// Returns the position of a Product with the name p
// If the product doesn't exist return -1
int Inventory::itemPos(string p) const {
    for (int j = 0; j < n; j++) {

        if (product[j].name == p)
            return j;
    }

    return -1;
}

// Returns the total value of the Inventory
double Inventory::totalVal() const {
    double sum = 0.0;

    for (int j = 0; j < n; j++)
        sum += product[j].amount * product[j].price;

    return sum;
}

void Inventory::operator = (const Inventory &same) {
    if (same.n != n) {

        if (n > 0)
            delete[] product;

        n = same.n;

        if (n == 0)
            product = NULL;

        else
            product = new Product[n];
    }

    sortorder = same.sortorder;

    for (int j = 0; j < n; j++)
        product[j] = same.product[j];
}

Inventory operator + (const Inventory& a, const Inventory& b) {
    Inventory newinv(a);

    for (int i = 0; i < b.n; i++)
        newinv.addProduct(b.product[i]);

    newinv.sortList();
    return newinv;
}

Inventory operator - (const Inventory& a, const Inventory& b){
    Inventory inv(a);
    Product tmp;

    for (int j = 0; j < b.n; j++) {
        tmp = b.product[j];
        tmp.amount *= -1;
        inv.addProduct(tmp);
    }

    Inventory newInv;

    for (int j = 0; j < inv.n; j++) {

        if (inv.product[j].amount > 0)
            newInv.addProduct(inv.product[j]);
    }

    newInv.sortList();
    return newInv;
}

bool operator > (const Inventory& a, const Inventory& b) {
    return (a.totalVal() > b.totalVal());
}

istream& operator >> (istream& ins, Inventory& i) {
    int newSize;
    Product tmpProduct;
    ins >> newSize;

    for (int j = 0; j < newSize; j++) {
        ins >> tmpProduct.name >> tmpProduct.amount >> tmpProduct.price;
        i.addProduct(tmpProduct);
    }

    i.sortList();
    return ins;
}

ostream& operator << (ostream& outs, const Inventory& i) {
    for (int j = 0; j < i.n; j++)
        outs << i.product[j].name << " " << i.product[j].amount << " " << i.product[j].price << endl;

    return outs;
}

void Inventory::sortList() {
    int j, k;
    Product tmpProduct;

    for (j = 1; j < n; j++) {
        tmpProduct = product[j];
        k = j;

        if (sortorder == "Alphabetical") {

            while (k > 0 && (product[k - 1].name > tmpProduct.name)) {
                product[k] = product[k - 1];
                k--;
            }
        }

        else {

            while (k > 0 && ((product[k - 1].amount * product[k - 1].price) < (tmpProduct.amount * tmpProduct.price))) {
                product[k] = product[k - 1];
                k--;
            }
        }

        product[k] = tmpProduct;
    }
}

void Inventory:: addSpaceToList(int size) {
    Product* newList = new Product[size];

    for (int j = 0; j < size; j++)
        newList[j] = product[j];

    if (product != NULL)
        delete[] product;

    product = newList;
    n = size;
}

// testing
int main()
{
    Inventory inv1, inv2, inv3;
    cin >> inv1 >> inv2 >> inv3;

    cout << "Testing +:" << endl;
    cout << inv1 + inv2 << endl;
    cout << "Testing -:" << endl;
    cout << inv2 - inv3 << endl;

    cout << "Largest inventory (sorted by value): " << endl;
    if (inv1 > inv2 && inv1 > inv3) {
        inv1.setsortorder("Value");
        cout << inv1;
    }
    else if (inv2 > inv1 && inv2 > inv3) {
        inv2.setsortorder("Value");
        cout << inv2 << endl;
    }
    else {
        inv3.setsortorder("Value");
        cout << inv3 << endl;
    }

    return 0;
}
