// Copyright 2020 Nasachenko Maxim <maximka5406@gmail.com>

#ifndef INCLUDE_STACK1_HPP_
#define INCLUDE_STACK1_HPP_
#include <iostream>
#include <memory>
#include <string>
#include <utility>

template <typename T>
class Node {
 public:
  Node(T data_ = T(), Node<T>* pPast_ = nullptr) {
    data = data_;
    pPast = pPast_;
  }

  const T& get_data() { return data; }

  Node<T>*& get_pointer_past() { return pPast; }

 private:
  Node<T>* pPast;
  T data;
};

template <typename T>
class Stack1 {
 public:
  void push(T&& value) {
    if (!pHead) {
      pHead = new Node<T>(std::move(value));
    } else {
      pHead = new Node<T>(std::move(value), std::move(pHead));
    }
  }
  void push(const T& value) {
    if (!pHead) {
      pHead = new Node<T>(value);
    } else {
      pHead = new Node<T>(value, pHead);
    }
  }
  void pop() {
    Node<T>* pTemp = pHead->get_pointer_past();
    delete pHead;
    pHead = pTemp;
  }
  const T& head() const { return pHead->get_data(); }

  Stack1() { pHead = nullptr; }
  Stack1(const Stack1&) = delete;
  Stack1 operator=(const Stack1&) = delete;
  ~Stack1() {
    while (pHead) {
      pop();
    }
  }

 private:
  Node<T>* pHead;
};
#endif  // INCLUDE_STACK1_HPP_
