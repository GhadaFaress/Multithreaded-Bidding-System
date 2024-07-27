# Multithreaded Bidding System

This project implements a simple multithreaded bidding system where multiple bidders place bids on various items concurrently. The highest bid for each item is tracked and displayed at the end of the bidding period.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components](#components)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Example Output](#example-output)

## Introduction

The multithreaded bidding system simulates an auction where multiple bidders place bids on a set of items. The system uses pthreads for concurrent execution and mutexes to ensure thread safety when updating the highest bid for each item.

## Features

- Multiple bidders placing bids concurrently.
- Randomized bidding amounts and item selection.
- Mutex-protected bid updates to prevent race conditions.
- Display of highest bids for each item at the end of the bidding period.

## Components

- `pthread.h`: POSIX threads library for multithreading.
- `unistd.h`: Provides access to the POSIX operating system API.
- `stdio.h`: Standard input/output library.
- `stdlib.h`: Standard library for memory allocation, random number generation, etc.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Linux

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/multithreaded-bidding-system.git
   cd multithreaded-bidding-system
2. Compile the program:
   ```sh
   gcc -pthread -o bidding_system trial.c
   
## Usage
1. Run the compiled program:
   ```sh
   ./bidding_system
2. Enter the names for each item when prompted.
3. The program will simulate the bidding process for a defined period. Each bidder will place bids on random items, and the highest bids will be displayed at the end.

## Example Output
```
Enter name for Item 1:
 Phone
Enter name for Item 2:
 Laptop
Enter name for Item 3:
 Tablet
Bidder 1 placed a bid of 55.00 on item 2 : Laptop
Bidder 2 placed a bid of 80.00 on item 1 : Phone
Bidder 3 placed a bid of 45.00 on item 3 : Tablet
...
Highest bid for Item 1 (Phone): 80.00
Highest bid for Item 2 (Laptop): 55.00
Highest bid for Item 3 (Tablet): 45.00


