
# 🎮 Tic-Tac-Toe (C++) – Minimax AI

A simple terminal-based Tic-Tac-Toe game written in modern C++. Play as `X` against a perfect AI opponent powered by the **Minimax algorithm**.

---

## ✨ Features

- ✅ Human vs AI (player = `X`, AI = `O`)
- 🧠 AI uses Minimax – it never loses
- 📊 Console-based user interface
- 🏆 Detects wins, draws, and invalid moves
- 🧹 Clean and modular C++ code

---

## 🖥️ Gameplay Preview

```text
  |   |  
--+---+--
  |   |  
--+---+--
  |   |  

Enter row and column (1-3): 1 1
X |   |  
--+---+--
  |   |  
--+---+--
  |   |  

AI chose position: 2,2
X |   |  
--+---+--
  | O |  
--+---+--
  |   |  
```

---

## 🛠️ Build & Run

### Requirements
- A C++ compiler (e.g. `g++`, `clang++`)

### Compile

```bash
g++ -std=c++11 -o tictactoe main.cpp
```

### Run

```bash
./tictactoe
```

---

## 📚 How the AI Works

The AI uses the **Minimax algorithm** to evaluate all possible moves and chooses the optimal one by simulating the entire game tree.

- AI win → `+10`  
- Player win → `-10`  
- Draw → `0`  

This ensures the AI never loses.

---

## 📁 Project Structure

```
.
├── main.cpp      # Source code
├── README.md     # Project description
```

---

## 🚀 Possible Improvements

- Add difficulty settings (Easy, Medium, Hard)
- GUI version with SFML or SDL
- Multiplayer (Player vs Player)
- Score tracking

---

## 📝 License

MIT License. Feel free to use, modify, and share!

---

Made with ❤️ by [YourNameHere]
