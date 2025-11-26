# Push_swap

## Project Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using only two stacks (stack A and stack B) and a specific set of instructions, with the goal of minimizing the number of operations.

This implementation is inspired by the Turk sort algorithm and includes:
- Norm checks for code quality
- Memory leak checks for robust memory management
- Optimized performance: less than 700 instructions for 100 numbers and 5500 instructions for 500 numbers

## How It Works

You are given two stacks:
- **Stack A**: Contains the initial unsorted list of integers
- **Stack B**: Initially empty, used as auxiliary space

The objective is to sort all integers in Stack A in ascending order using the smallest number of operations.

## Allowed Instructions

### Swap Operations

| Instruction | Description |
|-------------|-------------|
| `sa` | **Swap A** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements. |
| `sb` | **Swap B** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements. |
| `ss` | **Swap Both** - Execute `sa` and `sb` at the same time. |

### Push Operations

| Instruction | Description |
|-------------|-------------|
| `pa` | **Push A** - Take the first element at the top of B and put it at the top of A. Do nothing if B is empty. |
| `pb` | **Push B** - Take the first element at the top of A and put it at the top of B. Do nothing if A is empty. |

### Rotate Operations

| Instruction | Description |
|-------------|-------------|
| `ra` | **Rotate A** - Shift all elements of stack A up by 1. The first element becomes the last one. |
| `rb` | **Rotate B** - Shift all elements of stack B up by 1. The first element becomes the last one. |
| `rr` | **Rotate Both** - Execute `ra` and `rb` at the same time. |

### Reverse Rotate Operations

| Instruction | Description |
|-------------|-------------|
| `rra` | **Reverse Rotate A** - Shift all elements of stack A down by 1. The last element becomes the first one. |
| `rrb` | **Reverse Rotate B** - Shift all elements of stack B down by 1. The last element becomes the first one. |
| `rrr` | **Reverse Rotate Both** - Execute `rra` and `rrb` at the same time. |

## Visual Representation

```
Before ra:          After ra:
┌───┐              ┌───┐
│ 1 │ (top)        │ 2 │ (top)
├───┤              ├───┤
│ 2 │              │ 3 │
├───┤              ├───┤
│ 3 │              │ 1 │
└───┘ (bottom)     └───┘ (bottom)
```

```
Before rra:         After rra:
┌───┐              ┌───┐
│ 1 │ (top)        │ 3 │ (top)
├───┤              ├───┤
│ 2 │              │ 1 │
├───┤              ├───┤
│ 3 │              │ 2 │
└───┘ (bottom)     └───┘ (bottom)
```
