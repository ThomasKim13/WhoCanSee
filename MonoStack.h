#ifndef PA3_MONOSTACK_H
#define PA3_MONOSTACK_H
template <typename T>
class MonoStack{
public:
    MonoStack(int iSize, char o);
    ~MonoStack();
    void push(T c); //add to the top
    T pop(); //remove from the top
    T peek(); //return the top without removing
    bool isFull();
    bool isEmpty();
    int size();
private:
    T* stackArr;
    char stackType;
    int count; //number of items currently in the stack
    int maxSize; //max number of things in the stack
    int top; //index of the current top of the stack
};
//Default constructor for MonoStack
//Based on the char that is given the stack is either increasing or decreasing
template <typename T>
MonoStack<T>::MonoStack(int iSize, char o){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
    stackType = o;
}
//deconstructor for MonoStack
template <typename T>
MonoStack<T>::~MonoStack(){
    delete[] stackArr;
}
//Checks if the stack is full
//If the stack is full the function returns true else return false
template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}
//Checks if the stack is empty
//If the stack is empty the function returns true else return false
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
}
//Returns the size of the stack
template <typename T>
int MonoStack<T>::size(){
    return count;
}
//This function allows for there to be addition to a stack
template <typename T>
void MonoStack<T>::push(T c){
    //if the stack is full the stack is multiplied by 2 to double its size
    if(isFull()){
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    //Based on the constructor if the char is d then only doubles greater than the top double are added
    //If the double that is being added is less the stack is deleted to add the new double
    if(stackType == 'd'){
        while(!isEmpty() && stackArr[top] < c){
            pop();
        }
        stackArr[++top] = c;
        ++count;
    }
    else if(stackType == 'i'){
        while(!isEmpty() && stackArr[top] > c){
            pop();
        }
        stackArr[++top] = c;
        ++count;
    }
}
//Gets rid of the element that is the top of the stack
template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
}
//Returns the first element of the stack
template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top];
}
#endif