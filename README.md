# virtualDestructors
Class Example


This example demonstrates several key points about virtual destructors:

1. **Problem Scenario (Base1/Derived1)**:
   - When deleting a `Derived1` object through a `Base1` pointer, only the base class destructor is called
   - The derived class destructor never runs, causing a memory leak
   - The `data` array in `Derived1` is never deleted

2. **Correct Solution (Base2/Derived2)**:
   - Adding `virtual` to the base class destructor ensures proper cleanup
   - When deleting through a `Base2` pointer, both destructors are called in the correct order
   - No memory leaks occur

3. **Key Observations**:
   - Stack-based objects work fine in both cases because the compiler knows the exact type
   - The problem only occurs with polymorphic deletion through base class pointers
   - This is why it's a best practice to make base class destructors virtual in any class meant to be inherited from

Running this program will show the difference in destruction sequences between the two approaches. In the first case, you'll see that the `Derived1` destructor never runs, while in the second case, both destructors run properly.

