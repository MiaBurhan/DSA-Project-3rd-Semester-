#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    double price;
    int qty;
    Node *p, *n;
};


//-----------------------------------Sawaira-----------------------------------------------------

class Menu {
private:
    Node *start, *tem, *curn;
    int undoStack[50];
    string undostackN[50];
    int top;

public:
    Menu() {
        start = NULL;
        top = -1;
    }

    void addItem() {
        tem = new Node;
        cout << "Enter Item ID: "; cin >> tem->id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, tem->name);
        cout << "Enter Price: "; cin >> tem->price;
        cout << "Enter Quantity: "; cin >> tem->qty;
        tem->p = NULL;
        tem->n = NULL;

        if (start == NULL) {
            start = tem;
        } else {
            curn = start;
            while (curn->n != NULL) {
                curn = curn->n;
            }
            curn->n = tem;
            tem->p = curn;
        }
        cout << "Item Added!\n";
    }

    void display() {
        if (start == NULL) {
            cout << "Menu Empty\n";
            return;
        }
        curn = start;
        cout << "\n--- MENU LIST ---\n";
        while (curn != NULL) {
            cout << "ID:" << curn->id << " Name:" << curn->name << " Price:" << curn->price << " Stock:" << curn->qty << endl;
            curn = curn->n;
        }
    }

    Node* search(int id) {
        curn = start;
        while (curn != NULL) {
            if (curn->id == id) return curn;
            curn = curn->n;
        }
        return NULL;
    }

    void deleteItem() {
        int did;
        cout << "Enter ID to delete: "; cin >> did;
        curn = start;
        while (curn != NULL) {
            if (curn->id == did) {
                // Stack for undo
                if (top < 49) {
				undoStack[++top] = curn->id;
				undostackN[++top]=curn->name;}

                if (curn == start) {
                    start = start->n;
                    if (start != NULL) start->p = NULL;
                } else {
                    curn->p->n = curn->n;
                    if (curn->n != NULL) curn->n->p = curn->p;
                }
                delete curn;
                cout << "Deleted successfully\n";
                return;
            }
            curn = curn->n;
        }
        cout << "Not found\n";
    }

    void undo() {
        if (top == -1) {
            cout << "Nothing to undo\n";
        } else {
            cout << "Last deleted ID was: " << undoStack[top--]<<"  "<<undostackN[top--] << ". Please re-add it.\n";
        }
    }
};

//-----------------------------------------BURHAN-------------------------------------------------------------
class OrderSystem {
private:
    int que[50];
    int f, r;
    int cancelStack[50];
    int ctop;

public:
    OrderSystem() {
        f = r = -1;
        ctop = -1;
    }

    void placeOrder(Menu &m) {
        if (r >= 49) {
            cout << "Queue Full\n";
            return;
        }
        int id;
        cout << "Enter Menu ID to order: "; cin >> id;
        Node* res = m.search(id);
        if (res != NULL && res->qty > 0) {
            r++;
            que[r] = id;
            if (f == -1) f = 0;
            res->qty--; // reduce stock
            cout << "Order placed for " << res->name << endl;
        } else {
            cout << "Invalid ID or Out of Stock\n";
        }
    }

    void serveOrder(Menu &m) {
        if (f == -1) {
            cout << "No orders to serve\n";
            return;
        }
        int oid = que[f];
        Node* res = m.search(oid);
        
        double bill = res->price + (res->price * 0.05);
        cout << "\nServing: " << res->name;
        cout << "\nTotal Bill (with 5% tax): " << bill << endl;

        if (f == r) f = r = -1;
        else f++;
    }

    void cancelOrder() {
        if (f == -1) return;
        if (ctop < 49) {
            cancelStack[++ctop] = que[f];
            cout << "Order " << que[f] << " cancelled\n";
            if (f == r) f = r = -1;
            else f++;
        }
    }
};

//------------------------------------ASAD CHEEMA---------------------------------------------------------
class BillingSystem {
private:
    int tables[5]; // 0 free, 1 reserved
    double totalSales;

public:
    BillingSystem() {
        for (int i = 0; i < 5; i++) tables[i] = 0;
        totalSales = 0;
    }

    void reserve() {
        for (int i = 0; i < 5; i++) {
            if (tables[i] == 0) {
                tables[i] = 1;
                cout << "Table " << i + 1 << " Reserved\n";
                return;
            }
        }
        cout << "All tables full\n";
    }

    void showStatus() {
        for (int i = 0; i < 5; i++) {
            cout << "Table " << i + 1 << ": " << (tables[i] == 0 ? "Free" : "Reserved") << endl;
        }
    }
};




int main() {
    Menu m;
    OrderSystem o;
    BillingSystem b;
    int ch, sub;

    do {
        cout << "\n--- RESTAURANT SYSTEM ---\n";
        cout << "1. Menu (Sawaira)\n2. Order (Burhan)\n3. Billing (Asad)\n4. End\n";
        cout << "Choice: "; cin >> ch;

        switch (ch) {
        case 1:
            cout << "1.Add 2.Display 3.Delete 4.Undo\nSub: "; cin >> sub;
            if (sub == 1) m.addItem();
            if (sub == 2) m.display();
            if (sub == 3){m.display();m.deleteItem();}
            if (sub == 4) m.undo();
            break;
        case 2:
            cout << "1.Place 2.Serve 3.Cancel\nSub: "; cin >> sub;
            if (sub == 1){
			m.display(); o.placeOrder(m);}
            if (sub == 2) o.serveOrder(m);
            if (sub == 3) o.cancelOrder();
            break;
        case 3:
            cout << "1.Reserve Table 2.Status\nSub: "; cin >> sub;
            if (sub == 1) b.reserve();
            if (sub == 2) b.showStatus();
            break;
        }
    } while (ch != 4);

    return 0;
}
