# Restaurant Management System (C++ | DSA Project)

A console-based Restaurant Management System built entirely using **linear data structures** — Arrays, Linked Lists, Stacks, and Queues. 
No trees, graphs, or associative maps are used anywhere in the project, as per the project constraints.

## Objective

To design and implement a working restaurant management application that demonstrates practical use of core linear data structures learned in the Data Structures & Algorithms course, split across three modules: menu/inventory, order processing, and billing/table management.

## Team & Module Breakdown

| Member | Module | Data Structures Used |
|---|---|---|
| **Sawaira** | Menu & Inventory Management | Doubly Linked List (menu items), Parallel Arrays (undo stack for deleted items) |
| **Burhan** | Order Management System | Array-based Queue (order processing), Array-based Stack (cancelled orders) |
| **Asad Cheema** | Billing & Table Reservation | Array (table status) |

## Features

### 1. Menu Management (`Menu` class — Sawaira)
- **Add Item** — inserts a new food item (ID, name, price, quantity) at the end of a doubly linked list.
- **Display Menu** — traverses and prints all current menu items with stock levels.
- **Search Item** — looks up a menu item by ID (used internally by the ordering system to check stock).
- **Delete Item** — removes an item from the linked list by ID and pushes its ID/name onto an undo stack.
- **Undo** — pops the most recently deleted item off the stack and prompts the user to re-add it.

### 2. Order Management (`OrderSystem` class — Burhan)
- **Place Order** — looks up the item by ID, checks stock availability, decrements quantity, and enqueues the order.
- **Serve Order** — dequeues the oldest pending order (FIFO) and generates a bill including 5% tax.
- **Cancel Order** — pops the front of the queue onto a separate cancellation-history stack instead of serving it.

### 3. Billing & Table Reservation (`BillingSystem` class — Asad Cheema)
- **Reserve Table** — scans a fixed array of 5 tables and marks the first free one as reserved.
- **Show Status** — displays the current Free/Reserved status of all 5 tables.

## System Flow

1. Admin adds items to the menu (linked list).
2. Customer/staff places an order → item is validated against stock and pushed into the order queue.
3. Orders are served in FIFO order → bill is generated with 5% tax applied.
4. Orders can be cancelled instead of served → moved to a cancellation stack.
5. Tables can be reserved from a fixed pool of 5, with live status tracking.
6. Deleted menu items can be undone via the undo stack.

## File Structure

```
├── Resturent managment system.cpp   # Full source code (all 3 modules + main menu-driven UI)
└── README.md                        # This file
```

## How to Compile & Run

```bash
g++ -o restaurant "Resturent managment system.cpp"
./restaurant
```

On Windows (MinGW):
```bash
g++ -o restaurant.exe "Resturent managment system.cpp"
restaurant.exe
```

## Using the Program

On launch, you'll see the main menu:

```
--- RESTAURANT SYSTEM ---
1. Menu (Sawaira)
2. Order (Burhan)
3. Billing (Asad)
4. End
```

- **Option 1 → Menu**: Add, Display, Delete (with undo), or Undo a deletion.
- **Option 2 → Order**: Place an order (shows current menu first), Serve the next order, or Cancel the pending order.
- **Option 3 → Billing**: Reserve a table or view table status.
- **Option 4**: Exit the program.

## Notes / Known Limitations

- Table status and cancellation history are stored in memory only — no persistence between runs (no file I/O).
- `totalSales` in `BillingSystem` is currently tracked as a variable but not yet wired into a daily sales summary.
- The undo stack currently pairs an ID and name for each delete but does not restore the item's price/quantity automatically — the user must re-enter it.
