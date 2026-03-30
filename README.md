# 🔐 Cryptography & Network Security Lab
> A comprehensive implementation of symmetric and asymmetric cryptographic algorithms in C++.

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/Status-Lab%20Completed-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

## 📖 Overview
This repository contains a collection of essential cryptographic algorithms implemented as part of the Computer Engineering curriculum. The focus is on understanding the mathematical foundations of security, including modular arithmetic, matrix transformations, and number theory.

---

## 🛠️ Algorithms Implemented

### 1. Classical Substitution Ciphers
* **Multiplicative Cipher**: Uses a key $k$ to encrypt via $C = (P \cdot k) \pmod{26}$. Requires $k$ to be coprime to 26.
* **Affine Cipher**: A combination of multiplicative and shift ciphers using the formula $E(x) = (ax + b) \pmod{26}$.
* **Playfair Cipher**: A digraph-based cipher using a $5 \times 5$ grid of letters.
* **Hill Cipher**: Encrypts blocks of text using matrix multiplication: $C = (P \cdot K) \pmod{26}$.

### 2. Modern Block Ciphers
* **DES Key Generation**: Implementation of the 16-round subkey generation process including PC-1, PC-2, and circular left shifts.

### 3. Asymmetric Cryptography
* **RSA Algorithm**: Implementation of the Rivest-Shamir-Adleman cryptosystem for secure data transmission.
* **Diffie-Hellman**: A protocol for secure key exchange over a public channel.

### 4. Mathematical Foundations
* **Euclidean Algorithm**: Efficiently calculates the Greatest Common Divisor (GCD).
* **Extended Euclidean Algorithm**: Finds the Modular Multiplicative Inverse—essential for RSA and Affine decryption.
* **Euler's Totient Function**: Calculates $\phi(n)$, the number of integers coprime to $n$.

---

## 🚀 Getting Started

### Prerequisites
* A C++ compiler (G++ or Clang)
* Basic understanding of Number Theory

### Compilation & Execution
To run any of the algorithms, navigate to the directory and compile using:
```bash
g++ main.cpp -o output
./output