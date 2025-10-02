# Chess (C++ OOP Project)

A complete **Chess game** implemented in C++ using Object-Oriented Programming principles.  
Each chess piece is represented as a class, with inheritance and polymorphism used for move validation and interactions.

## 🎮 Features
- **Piece Classes** – Separate classes for King, Queen, Rook, Bishop, Knight, and Pawn, all derived from a common `Piece` class.
- **Polymorphism** – Virtual methods for move validation, allowing piece-specific movement rules.
- **Board Representation** – 2D array / Board class manages game state and rendering.
- **Game Logic**:
  - Legal move checking
  - Turn switching (White vs Black)
  - Check, checkmate, and stalemate detection
  - Pawn promotion
  - undo/redo functionality
- **Console-based UI** – text-based board printing and input handling.

## 🛠️ Tech Stack
- Language: **C++**
- Paradigm: Object-Oriented Programming
- Concepts: Inheritance, Polymorphism, Abstract Classes, Encapsulation
- Data Structures: 2D arrays for board state

## 🚀 How to Compile & Run
1. Clone this repository:
   ```bash
   git clone https://github.com/hamxaShaukat/Chess-oop.git
