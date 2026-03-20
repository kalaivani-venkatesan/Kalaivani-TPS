# Transaction Processing System  
### Mini Project – 24UCS271 Lab

---

## Objective
This mini project focuses on understanding, modifying, and extending a **Transaction Processing System** program. Students are expected to analyze existing code, improve it, and add new functionalities while following good coding practices.

---

## Reference Code
Review the given source code before starting the project:

🔗 https://replit.com/@ashokb/Unit5Programs#trans.c

---

## Tasks to be Performed

1. Compile and run the given executable code.
2. Perform your own testing of the program.
3. Add a new account detail and regenerate the `accounts.txt` file.
   - Inspect the contents of the file.
   - Verify whether the output matches your expectations.
4. Identify and fix any logical errors in the program.
5. Add new functionality  
   - Example: Listing all account information.
6. Optimize the program for better performance and efficiency.

---

## Evaluation Criteria

### 1. General (25 Points)
| Activity | Points | Remarks |
|--------|--------|--------|
| Self-effort | 5 | Student’s own assessment of hours spent (no copying or external references) |
| Turnaround Time | 10 | Provide three time slots; earlier demo gets more points |
| Project Demo | 10 | Demo must be done using repl.it |

---

### 2. Comprehension (15 Points)
| Activity | Points |
|--------|--------|
| Domain Knowledge | 5 |
| Added Functionality (Ideas) | 5 |
| Code Comprehension | 5 |

---

### 3. Modification (35 Points)
| Activity | Points |
|--------|--------|
| Code Improvement | 5 |
| Functional Decomposition | 10 |
| Refactoring for Memory Usage | 10 |
| Refactoring for Speed | 10 |

---

### 4. Innovation (45 Points)
| Activity | Points |
|--------|--------|
| New Features / User Stories (Faculty specified) | 5 |
| Requirement to Code Translation | 10 |
| Added Functionality (Simple – Error Handling) | 10 |
| Added Functionality (Advanced) | 20 |

---

## Total Marks
**120 Marks**  
➡ Reduced to **20 Marks** for final evaluation

---

## Rules for Mini Project Implementation

- Maximum of **2 attempts** will be given for project presentation.
- If dissatisfied with the first score, a second attempt is allowed.
- The **best score** out of the two attempts will be considered final.
- Discussion and clarification among students are allowed.
- **Copying or borrowing code is strictly prohibited.**
- Violation of plagiarism rules will result in a **zero (0 / NULL) score**.

---

## Additional Reference
🔗 http://j.mp/transactionUnit5  
🔗 https://htmlpreview.github.io/?https://github.com/kgisl/makesite/blob/master/content/blog/2021-06-23-unit5-mini-project.md.html
🔗 https://github.com/24UCS271-MiniProject/miniProjectSourceCode/

---

**Date:** 31/01/2026  
**Time:** 06:42
Here’s a **professional, repo-ready README.md** for your project 👇
(just copy & paste into your GitHub)

---

# 📘 Transaction Processing System (C Language)

## 🏦 Project Overview

This project is a **Banking Transaction Processing System** developed using **C language**.
It simulates real-world banking operations such as account creation, secure login, deposits, withdrawals, fund transfers, transaction history, and admin control.

The system uses **file handling** to store and manage persistent data, making it behave like a basic database-driven banking application.

---

## 🎯 Key Features

### 👤 User Features

* Create new bank account
* Secure login with PIN authentication
* Deposit money
* Withdraw money (with daily limit)
* Transfer funds between accounts
* Check account balance
* View transaction history
* Auto-generated transaction receipts

---

### 🔐 Security Features

* PIN encryption (basic hashing)
* Account lock after 3 failed login attempts
* Prevention of invalid transactions
* Input validation for all operations

---

### 🏛️ Admin Features

* Admin login authentication
* View all user accounts
* Monitor balances

---

### 📂 Data Storage

* `accounts.dat` → Stores account details
* `transactions.dat` → Stores transaction logs
* `receipts.txt` → Stores transaction receipts

---

## 🧱 Project Structure

```
📁 Transaction-Processing-System
│
├── main.c
├── account.c
├── transaction.c
├── admin.c
├── utils.c
│
├── account.h
├── transaction.h
├── admin.h
├── utils.h
│
└── data/
    ├── accounts.dat
    ├── transactions.dat
    └── receipts.txt
```

---

## ⚙️ Compilation & Execution

### 🔧 Compile

```bash
gcc main.c account.c transaction.c admin.c utils.c -o bank
```

### ▶️ Run

```bash
./bank
```

---

## 🧪 Sample Flow

```
1. Create Account
2. Login
3. Deposit
4. Withdraw
5. Transfer
6. View Balance
7. Transaction History
8. Logout
```

---

## 🚀 Advanced Functionalities

* Modular code structure (multi-file system)
* File-based persistent storage
* Transaction logging with timestamps
* Daily withdrawal limit control
* Receipt generation system
* Clean and maintainable architecture

---

## ⚠️ Constraints

* Works on **console (CLI only)**
* No GUI interface
* File-based storage (no SQL database)

---

## 💡 Future Enhancements

* GUI using C++ / Java / Web
* Database integration (MySQL)
* OTP-based authentication
* Interest calculation system
* Loan management module

---

## 👨‍💻 Author

**Kalaivani Venkatesan**

---

## 🏁 Conclusion

This project demonstrates:

* Strong understanding of **C programming**
* Use of **file handling as database**
* Implementation of **real-world banking logic**
* Modular and scalable software design

---



---


