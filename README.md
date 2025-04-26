Hospital Patient Record Management System

📌 Overview

This project simulates a basic Hospital Patient Record Management System using core data structures in C++. It uses key data structures like linked lists, queues, and stacks to manage patient records, emergency room queues, and treatment history. It's designed to show how these structures work in a real-world hospital scenario.

⚙️ Date Structures Used

- Linked List (for storing all patients)

- Queue (for emergency patients)

- Stack (for treatment history)

🎯 Features

- Patient Management (Linked List)
    Add new patient records
    
    View all patient records
    
    Search by ID or name
    
    Update patient information
    
    Delete patient records

- Emergency Room Queue (Queue)
    Add patient to emergency queue
    
    Remove (treat) the next patient
    
    Display current queue

- Treatment History (Stack)
    Treat patient (push to treatment stack)
    
    Undo last treatment (pop from stack)
    
    View treatment history

📖 How it Works
- Linked List:
  Stores all patients' records.
  
- Emergency Queue:
  Special queue for patients marked as emergency (added during registration).
  
- Treatment Stack:
  A patient under treatment is pushed onto the stack.
  Undoing treatment pops the latest patient.

▶️ Program Flow
- Displays a Menu on startup.

- Takes user input for different operations.

- Appropriate confirmation or error messages shown after each operation.

- Continues running until the user chooses to Exit.

📝 Dependencies
Uses Standard C++ Libraries
  - iostream
  - string

