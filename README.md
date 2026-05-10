# DSA Project Plan  
## Restaurant Management System

---

## Project Objective

To develop a **Restaurant Management System** using only linear data structures:

- Arrays
- Linked Lists
- Stack
- Queue

> Non-linear data structures such as Trees, Graphs, Maps, etc. will not be used.

---

# Task Division (3 Members)

## Member 1 (Sawaira): Menu & Inventory Management

### Data Structures Used
- Linked List (for storing menu items)
- Stack (for undo delete / recently removed items)

### Responsibilities
- Add food item
- Delete food item
- Update price
- Search item
- Display full menu
- Manage item stock

---

## Member 2 (Burhan): Order Management System

### Data Structures Used
- Queue (for processing customer orders)
- Linked List (for items inside each order)
- Stack (for cancelled order history)

### Responsibilities
- Place new order (enqueue)
- Add multiple items to order
- Cancel order
- Serve order (dequeue)
- View pending orders

---

## Member 3 (Asad): Billing & Table Reservation

### Data Structures Used
- Array (for tables)
- Queue (for waiting customers)
- Stack (for payment history)

### Responsibilities
- Reserve table
- Cancel reservation
- Generate bill
- Apply tax
- Store completed bills
- Show daily sales summary

---

# System Final Result

1. Admin adds menu items
2. Customer places order
3. Order enters queue
4. Order is served
5. Bill is generated
6. Bill stored in history
