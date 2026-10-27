# Genome Sequence Alignment Tool

## Overview
The Genome Sequence Alignment Tool is a C++ project that compares two DNA sequences and identifies their Longest Common Subsequence (LCS) using dynamic programming.

This project is related to **Sustainable Development Goal 3 (SDG 3): Good Health and Well-being**, because computational methods for comparing biological sequences can support learning and research in bioinformatics.

## Objectives
- Accept two DNA sequences as input.
- Validate that sequences contain only the DNA bases A, T, G, and C.
- Calculate the Longest Common Subsequence using dynamic programming.
- Reconstruct and display the common subsequence.
- Calculate the LCS-based similarity percentage.

## Technologies Used
- Programming Language: C++
- Standard: C++17
- Algorithm: Longest Common Subsequence (LCS)
- Technique: Dynamic Programming

## How It Works
1. The user enters two DNA sequences.
2. The program validates the input sequences.
3. A dynamic programming table is used to calculate the LCS.
4. Backtracking reconstructs the longest common subsequence.
5. The program displays the sequences, LCS, LCS length, and similarity percentage.

## Sample Input
First DNA sequence:
```text
AGGTAC
```

Second DNA sequence:
```text
GGTACC
```

## Sample Output
```text
=== Genome Sequence Alignment Tool ===
Enter first DNA sequence: AGGTAC
Enter second DNA sequence: GGTACC

--- Alignment Results ---
Sequence 1: AGGTAC
Sequence 2: GGTACC
Longest Common Subsequence: GGTAC
LCS Length: 5
LCS-based similarity: 83.3333%
```

## Similarity Calculation
The program calculates similarity as:

Similarity (%) = (LCS length / length of the longer sequence) × 100

For the sample sequences, both sequences have length 6, and the LCS length is 5. Therefore, the similarity is 83.3333%.

This is an LCS-based similarity measure, not a clinical diagnosis or a complete biological alignment score.

## Requirements
- A C++17-compatible compiler, such as GCC
- Visual Studio Code or another code editor
- A terminal to compile and run the program

## Compile and Run

Compile using GCC:

```bash
g++ -std=c++17 genome_alignment.cpp -o genome_alignment.exe
```

Run in the MSYS2 terminal:

```bash
./genome_alignment.exe
```

## Project Structure

```text
genome-alignment-tool/
├── genome_alignment.cpp
└── README.md
```

## Future Improvements
- Add a graphical user interface.
- Support larger DNA sequences with memory-efficient algorithms.
- Add additional sequence comparison methods.
- Export results to a file.

## Author
team E12

## Disclaimer
This project is for educational purposes. Its similarity percentage should not be used as a medical or diagnostic result.
## Sample Output

![Genome Sequence Alignment Tool Output](Screenshot%202026-10-27%20115357.png)
https://25A31A05HG.github.io/genome-sequence-alignment-tool/
