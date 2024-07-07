# Observer Pattern

This design pattern is part of the behavioral patterns and is used when there is a one-to-many relationship between objects, such that when one object (the subject or observable) changes its state, all dependent objects (observers) are notified and updated automatically.

## Key Components in the Code

1. **IObserver Interface**:
   - Defines the `update` method which observers must implement.

2. **IObservable Interface**:
   - Defines methods for adding, removing, and notifying observers.

3. **ConcreteObservable Class**:
   - Implements the `IObservable` interface.
   - Manages a list of observers and notifies them when its state changes.

4. **ConcreteObserver Class**:
   - Implements the `IObserver` interface.
   - Updates its state based on the state of the observable and can display the updated state.

5. **Main Function**:
   - Demonstrates creating an observable and multiple observers, adding observers to the observable, updating the state of the observable, and notifying all observers.

## Observer Pattern Characteristics

- **Subject (Observable)**: Maintains a list of its dependents, called observers, and notifies them of any state changes.
- **Observers**: Define an updating interface for objects that should be notified of changes in a subject.
- **Decoupling**: The subject and observers are loosely coupled, meaning the subject does not need to know details about the observers, only that they implement the observer interface.
- **Scalability**: Allows for any number of observers to be attached to a subject and can be added or removed independently.
