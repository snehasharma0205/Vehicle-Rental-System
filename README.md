# Vehicle Rental System (C++)

A menu-driven console mini-project demonstrating Object-Oriented Programming in C++.

## Features
- Select Car, Bike, or Exit from a menu.
- Enter a vehicle ID, model, and rental duration.
- Displays a rental receipt with vehicle details and total charges.
- Rejects invalid menu choices and non-positive IDs/durations.
- Uses different rent calculations for cars and bikes.

## Rental rules used
- Car: Rs. 1,500 per day + Rs. 200 fixed insurance charge.
- Bike: Rs. 500 per day.
- Rental duration must be a positive whole number.

These are sample project rates and can be changed in `main.cpp`.

## OOP concepts demonstrated
- **Class and objects:** `Vehicle`, `Car`, and `Bike`.
- **Inheritance:** `Car` and `Bike` publicly inherit from `Vehicle`.
- **Encapsulation:** common vehicle data is stored in the protected section of the base class; class operations expose the required behaviour.
- **Constructors:** initialize vehicle ID, model, and daily rate.
- **Function overriding:** `Car` and `Bike` override `calculateRent()`, `getVehicleType()`, and display behaviour.
- **Runtime polymorphism:** a `Vehicle*` points to either a `Car` or a `Bike`, and virtual functions call the correct derived implementation.
- **Virtual destructor:** allows safe deletion through a base-class pointer.

## Compile and run (macOS)
Open Terminal in this folder and run:

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o rental
./rental
```

You can also compile with `g++` if it is installed.

## Files
- `main.cpp` — complete source code.
- `Project-Report.pdf` — project explanation and OOP concepts.
- `sample-output.txt` — illustrative test runs.

## Before submission
1. Compile and run the program on your computer.
2. Capture your own terminal screenshots of at least one Car and one Bike receipt.
3. Upload `main.cpp`, `README.md`, `Project-Report.pdf`, `sample-output.txt`, and your screenshots folder to a public GitHub repository.
4. Paste the repository's main page URL into the teacher's Google Sheet (not the URL of an individual source file).
