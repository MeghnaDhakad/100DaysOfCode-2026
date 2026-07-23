<h2 align="center">Week 6 Day 38 (22/07/2026)</h2>

## 1. Number of Students Unable to Eat Lunch (LeetCode #1700)
A queue and stack simulation problem that requires modeling the interaction between a queue of students and a stack of sandwiches.

The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
- If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
- Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

This problem is commonly asked in interviews and helps build concepts like:
- queue simulation
- stack simulation

which are important for efficient simulation based problems.

**Your task:** Given two integer arrays `students` and `sandwiches`, where `sandwiches[i]` is the type of the ith sandwich in the stack (i = 0 is the top of the stack) and `students[j]` is the preference of the jth student in the initial queue (j = 0 is the front of the queue), return the number of students that are unable to eat.

### Constraints
- 1 <= students.length, sandwiches.length <= 100
- students.length == sandwiches.length
- sandwiches[i] is 0 or 1.
- students[i] is 0 or 1.

### Examples
**Input:**
```
students = [1,1,0,0]
sandwiches = [0,1,0,1]
```
**Output:**
```
0
```
---
**Input:**
```
students = [1,1,1,0,0,1]
sandwiches = [1,0,0,0,1,1]
```
**Output:**
```
3
```
---

## 2. The Card Trick
A deque simulation problem that requires reconstructing the original arrangement of cards from a known reveal sequence.

A magician has a deck of n cards numbered from 1 to n. He repeatedly performs the following steps:
- Reveal the card at the top of the deck and remove it.
- If any cards remain, take the next card from the top and move it to the bottom of the deck.
- Repeat until all cards have been revealed.

After performing this process, the cards are revealed in the exact order [1, 2, 3, ..., n].

This problem is commonly asked in interviews and helps build concepts like:
- deque simulation
- reverse construction

which are important for efficient deque based simulation problems.

**Your task:** Given an integer n representing the number of cards, return the initial arrangement of the deck that produces the reveal order [1, 2, ..., n].

### Constraints
- 1 <= n <= 1000

### Examples
**Input:**
```
n = 4
```
**Output:**
```
[1, 3, 2, 4]
```
---
**Input:**
```
n = 3
```
**Output:**
```
[1, 3, 2]
```
---
**Input:**
```
n = 5
```
**Output:**
```
[1, 5, 2, 4, 3]
```
---
