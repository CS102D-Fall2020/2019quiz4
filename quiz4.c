#include <stdio.h>

struct Fruit {
    char name[100];
    double price;
    int quantityPurchased;
};

struct Basket {
    char cname[100];
    int numUnique;
    struct Fruit farr[10];
};

void addFruit(struct Basket *b, struct Fruit f);
struct Basket addFruitWithoutPointers(struct Basket b, 
                                      struct Fruit f);
double totalPrice(struct Basket b);

int main() {
    struct Fruit a = {"Apple", 1.50, 2};
    struct Fruit b = {"Banana", 0.50, 5};
    //struct Basket myb = {"Prof. Hong", 2, a, b};
    struct Basket myb = {"Prof. Hong", 0};
    //addFruit(&myb, a);
    //addFruit(&myb, b);

    myb = addFruitWithoutPointers(myb, a);
    myb = addFruitWithoutPointers(myb, b);

    printf("Total: %f", totalPrice(myb));

    return 0; 
}

void addFruit(struct Basket *b, struct Fruit f) {
    b->farr[b->numUnique] = f;
    b->numUnique++; //(*b).numUnique++;
}

struct Basket addFruitWithoutPointers(struct Basket b, 
                                      struct Fruit f) {
    b.farr[b.numUnique] = f;
    b.numUnique++;
    return b;
}

double totalPrice(struct Basket b) {
    double total = 0;
    for (int i=0; i<b.numUnique; i++) {
        //printf("b.farr %s", b.farr[i].name);
        total += b.farr[i].price * b.farr[i].quantityPurchased;
    }
    return total;
}
