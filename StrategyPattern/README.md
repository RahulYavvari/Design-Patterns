# Strategy Pattern

This design pattern is part of the behavioral patterns and is used to define a family of algorithms, encapsulate each one, and make them interchangeable. The strategy pattern lets the algorithm vary independently from the clients that use it.

## Key Components in the Code

1. **SortStrategy Interface**:
   - Defines the `sort` method which concrete sorting strategies must implement.

2. **BubbleSortStrategy Class**:
   - Implements the `SortStrategy` interface.
   - Provides a concrete implementation of the bubble sort algorithm.

3. **SelectionSortStrategy Class**:
   - Implements the `SortStrategy` interface.
   - Provides a concrete implementation of the selection sort algorithm.

4. **InsertionSortStrategy Class**:
   - Implements the `SortStrategy` interface.
   - Provides a concrete implementation of the insertion sort algorithm.

5. **CustomVector Class**:
   - Maintains a vector of integers and a pointer to a `SortStrategy`.
   - Allows setting a different sorting strategy at runtime.
   - Provides methods to sort the vector using the current strategy and print the vector.

6. **Main Function**:
   - Demonstrates creating a `CustomVector` object, setting different sorting strategies, and sorting the vector with those strategies.

## Strategy Pattern Characteristics

- **Encapsulation**: Encapsulates different algorithms (sorting strategies) and makes them interchangeable.
- **Flexibility**: Allows changing the algorithm being used at runtime.
- **Decoupling**: The class using the algorithm (`CustomVector`) is not tightly coupled to any specific algorithm.
- **Scalability**: New strategies can be added without changing the classes that use them.

