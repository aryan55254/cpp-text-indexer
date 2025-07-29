# Text Indexer & Query Tool

A command-line utility built in C++ that creates a searchable index from a collection of text files.

This project reads multiple source files, processes the text to build an in-memory inverse index, and then allows a user to interactively search for words to find a list of all the documents where they appear.

---

## Features

* **Multi-File Indexing:** Processes any number of specified text files.
* **Text Normalization:** Cleans words by converting them to lowercase and removing all punctuation to ensure accurate matching.
* **Efficient Indexing:** Uses `std::map` to build an efficient inverse index, mapping each unique word to a `std::set` of the files it appears in.
* **Interactive Query Mode:** After building the index, the program enters a loop where the user can perform multiple searches.

---

## Core C++ Concepts Practiced

* **STL Containers:** Extensive use of `std::vector`, `std::map`, and `std::set` to manage data.
* **File I/O:** Reading and processing multiple files using `std::ifstream`.
* **String Manipulation:** Parsing text, cleaning words, and using helper functions with `std::string`.
* **Modern C++:** Use of range-based `for` loops, the `auto` keyword, and lambda functions in helper algorithms.

---

## How to Build and Run

### Prerequisites

* A C++ compiler that supports C++11 or newer (e.g., g++, Clang, MSVC).

### Steps

1.  **Create Sample Files:** Before running, create a few text files (e.g., `doc1.txt`, `doc2.txt`) in the same directory and add some text to them. Make sure the filenames match those in the `main.cpp` file.

2.  **Compile the Program:** Open a terminal in the project directory and compile the source code:
    ```bash
    g++ main.cpp -o indexer
    ```

3.  **Run the Program:** Execute the compiled program:
    ```bash
    ./indexer
    ```

4.  **Search:** The program will build its index and then prompt you to enter a word to search for. Follow the on-screen instructions to perform queries.