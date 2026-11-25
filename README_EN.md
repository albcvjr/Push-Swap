*This project was created as part of the 42 curriculum by dbenjume and acuevas.*

[Versión en español](README.md)

# Push_swap

## Description

Push_swap is a C project from the 42 curriculum. Its goal is to sort a sequence of integers in stack `a`, using a second stack `b` and a limited set of operations. The program calculates the initial disorder and can either choose a strategy automatically or receive one through a command-line option.

The project includes swap, push, rotate, and reverse rotate operations, a disorder index calculation, and a benchmark mode that displays the selected strategy and operation counts.

## Instructions

### Requirements

- `cc`
- `make`

### Build

From the repository root, run:

```sh
make
```

This builds the `push_swap` executable and the library included in `libft/`.

### Run

Pass the integers as arguments. The program accepts `--simple`, `--medium`, `--complex`, and `--bench` options:

```sh
./push_swap 4 2 7 1 3
./push_swap --simple 4 2 7 1 3
./push_swap --bench 4 2 7 1 3
./push_swap --complex --bench 4 2 7 1 3
```

If no strategy option is supplied, one is selected automatically based on the disorder index. `--bench` adds benchmark information to the output. Numeric arguments must be valid integers.

### Make targets

```sh
make        # builds push_swap
make clean  # removes libft object files
make fclean # removes push_swap and libft objects/library
make re     # rebuilds from scratch
```

## Available operations

| Operation | Effect |
|---|---|
| `sa`, `sb`, `ss` | Swap the first two elements of `a`, `b`, or both. |
| `pa`, `pb` | Move the first element from one stack to the other. |
| `ra`, `rb`, `rr` | Rotate `a`, `b`, or both upwards. |
| `rra`, `rrb`, `rrr` | Reverse rotate `a`, `b`, or both. |

## Strategies and design choices

The disorder index is calculated by counting out-of-order pairs and dividing by the total number of possible pairs. Internally, the value uses a scale from 0 to 10000. The strategy selector compares it with 20 and 50, corresponding to 0.2 and 0.5 in the subject.

The automatic strategy uses these thresholds:

| Disorder | Selected strategy | Stated complexity |
|---|---|---|
| Below 0.2 | Simple (selection) | O(n²) |
| From 0.2 to below 0.5 | Medium (buckets/chunks) | O(n√n) |
| 0.5 or higher | Complex (radix) | O(n log n) |

### Simple: minimum selection

The implementation finds the smallest node in `a`, rotates `a` until that node is at the top, pushes it to `b`, and repeats. Extracting the minimum values in ascending order leaves them in reverse order in `b`; moving them back to `a` with `pa` produces ascending order. This adapts selection sort to the allowed stack operations. Repeated searches and rotations account for the quadratic operation count.

### Medium: buckets/chunks (pending)

The selector reserves this strategy for medium disorder. The intended approach is to split values into ranges and move each group between the stacks, limiting the shifts needed to insert or retrieve elements. This aims for an intermediate cost, approximately O(n√n) in the subject's operation model.

### Complex: radix (pending)

The selector reserves this strategy for highly disordered inputs. Radix sorts by digits or bits in multiple passes; with normalized indices, the number of passes grows logarithmically, giving an expected O(n log n) operation count.

## Contributions

This project was completed as a pair. The implementation was developed collaboratively, and both contributors should be able to explain the full project.

| Login | Work reflected in the repository |
|---|---|
| `acuevas` | Stack operations and linked-list utilities, disorder calculation, integration updates, and supporting tests. |
| `dbenjume` | Initial structure and headers for several modules; argument parsing and management, benchmark, strategy selection, and sorting functions. |

The history and file headers show contributions from both people across multiple files. This summary describes the main areas and does not imply that each part was developed in isolation.

## Resources

- Push_swap subject from 42: project requirements, available operations, disorder model and required algorithmic complexities.
- Deck of playing cards: used as a practical resource to understand and visualize how the radix sort algorithm works and how its sorting passes are performed.

### Use of artificial intelligence

AI has been used as a supporting tool to write this README. The project description, commands and current state of the strategies have been checked against the repository code and the subject.
