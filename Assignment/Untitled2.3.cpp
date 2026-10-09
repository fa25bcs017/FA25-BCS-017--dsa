#include <iostream>
#include <string>
using namespace std;

// Item Node
struct ItemNode {
    string itemName;
    ItemNode* next;
};

// Section Node
struct SectionNode {
    string sectionName;
    ItemNode* items;
    SectionNode* next;
};

// Store Node
struct StoreNode {
    string storeName;
    SectionNode* sections;
    StoreNode* next;
};

// Head of stores
StoreNode* storeHead = NULL;


// Add a new store
void addStore(string storeName) {
    StoreNode* newStore = new StoreNode;

    newStore->storeName = storeName;
    newStore->sections = NULL;
    newStore->next = NULL;

    if (storeHead == NULL) {
        storeHead = newStore;
        return;
    }

    StoreNode* temp = storeHead;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newStore;
}


// Find a store
StoreNode* findStore(string storeName) {
    StoreNode* temp = storeHead;

    while (temp != NULL) {
        if (temp->storeName == storeName)
            return temp;

        temp = temp->next;
    }

    return NULL;
}


// Add a section to a store
void addSection(string storeName, string sectionName) {

    StoreNode* store = findStore(storeName);

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    SectionNode* newSection = new SectionNode;

    newSection->sectionName = sectionName;
    newSection->items = NULL;
    newSection->next = NULL;

    if (store->sections == NULL) {
        store->sections = newSection;
        return;
    }

    SectionNode* temp = store->sections;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newSection;
}


// Find a section
SectionNode* findSection(StoreNode* store, string sectionName) {

    SectionNode* temp = store->sections;

    while (temp != NULL) {

        if (temp->sectionName == sectionName)
            return temp;

        temp = temp->next;
    }

    return NULL;
}


// Store an item in a section
void addItem(string storeName, string sectionName, string itemName) {

    StoreNode* store = findStore(storeName);

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    SectionNode* section = findSection(store, sectionName);

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    ItemNode* newItem = new ItemNode;

    newItem->itemName = itemName;
    newItem->next = NULL;

    if (section->items == NULL) {
        section->items = newItem;
        return;
    }

    ItemNode* temp = section->items;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newItem;
}


// Remove an item from a section
void removeItem(string storeName, string sectionName, string itemName) {

    StoreNode* store = findStore(storeName);

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    SectionNode* section = findSection(store, sectionName);

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    ItemNode* temp = section->items;
    ItemNode* previous = NULL;

    while (temp != NULL) {

        if (temp->itemName == itemName) {

            if (previous == NULL) {
                section->items = temp->next;
            }
            else {
                previous->next = temp->next;
            }

            delete temp;

            cout << itemName << " removed successfully." << endl;
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "Item not found!" << endl;
}


// Display items of a section
void displaySectionItems(string storeName, string sectionName) {

    StoreNode* store = findStore(storeName);

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    SectionNode* section = findSection(store, sectionName);

    if (section == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    cout << "\nItems in " << sectionName << " section:" << endl;

    ItemNode* temp = section->items;

    while (temp != NULL) {
        cout << temp->itemName << endl;
        temp = temp->next;
    }
}


// Display all items of a store
void displayStoreItems(string storeName) {

    StoreNode* store = findStore(storeName);

    if (store == NULL) {
        cout << "Store not found!" << endl;
        return;
    }

    cout << "\nStore: " << storeName << endl;

    SectionNode* section = store->sections;

    while (section != NULL) {

        cout << "\nSection: " << section->sectionName << endl;

        ItemNode* item = section->items;

        while (item != NULL) {
            cout << "  - " << item->itemName << endl;
            item = item->next;
        }

        section = section->next;
    }
}


// Main Function
int main() {

    // Add stores
    addStore("Islamabad Store");
    addStore("Lahore Store");

    // Add sections
    addSection("Islamabad Store", "Electronics");
    addSection("Islamabad Store", "Clothing");

    addSection("Lahore Store", "Grocery");
    addSection("Lahore Store", "Electronics");

    // Add items
    addItem("Islamabad Store", "Electronics", "Laptop");
    addItem("Islamabad Store", "Electronics", "Mobile");
    addItem("Islamabad Store", "Electronics", "Headphones");

    addItem("Islamabad Store", "Clothing", "Shirt");
    addItem("Islamabad Store", "Clothing", "Jeans");

    addItem("Lahore Store", "Grocery", "Rice");
    addItem("Lahore Store", "Grocery", "Sugar");

    addItem("Lahore Store", "Electronics", "Tablet");

    // Display section items
    displaySectionItems("Islamabad Store", "Electronics");

    // Display complete store
    displayStoreItems("Islamabad Store");

    // Remove an item
    removeItem("Islamabad Store", "Electronics", "Mobile");

    // Display again
    displayStoreItems("Islamabad Store");

    return 0;
}
