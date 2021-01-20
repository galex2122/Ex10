// Copyright 2021 Galex

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
template<class T>
class MyStack {
 private:
  int length;
  int maxSize;
  T *array;

 public:
  explicit MyStack(int i) {
    this->maxSize = i;
    this->length = 0;
    this->array = new T[i];
  }
  MyStack(const MyStack &MyStack) {
    this->maxSize = MyStack.maxSize;
    this->length = MyStack.length;
    this->array = MyStack.array;
  }
  ~MyStack() {
    delete[] this->array;
  }
  bool isEmpty() const {
    if (this->length > 0) {
      return false;
    } else {
      return true;
    }
  }
  bool isFull() const {
    if (this->length < this->maxSize) {
      return false;
    } else {
      return true;
    }
  }
  T get() const {
    if (!isEmpty()) {
      return array[this->length - 1];
    } else {
      return -1;
    }
  }
  T pop() {
    if (!isEmpty()) {
      T toReturn = array[this->length - 1];
      this->length--;
      return toReturn;
    } else {
      return -1;
    }
  }
  void push(T toPush) {
    if (!isFull()) {
      this->length++;
      this->array[this->length - 1] = toPush;
    }
  }
};
#endif  // INCLUDE_MYSTACK_H_
