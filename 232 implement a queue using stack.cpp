232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
1.void push(int x) Pushes element x to the back of the queue.
2.int pop() Removes the element from the front of the queue and returns it.
3.int peek() Returns the element at the front of the queue.
4.boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

class MyQueue {
public:
        stack <int> input;
        stack <int> output;
        int element;

    MyQueue() {

    }
    
    void push(int x) {
        if(input.empty()){
            element = x;
        }
        input.push(x);
    }
    
    int pop() {
        //amortized 0(1),we have to surf through the whole input stack once and then retrieve from the output stack
        //then only O(n), otherwise O(1).
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }

        int ans = output.top();
        output.pop();
        return ans;        
    }
    
    int peek() {
        if(output.empty()){
            return element;
        }
        return output.top();        
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;

        return false;
        
    }
};