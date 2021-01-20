// Copyright 2021 Galex
#include <ctype.h>
#include <string>
#include "../include/MyStack.h"
#include "../include/postfix.h"

std::string infix2postfix(std::string infix) {
  std::string postfix;
  MyStack<char> opStack(200);
  for (int i = 0; i < infix.length(); ++i) {
    if (isdigit(infix[i])) {
      while (isdigit(infix[i]) || infix[i] == '.') {
        postfix += infix[i];
        ++i;
      }
      postfix += ' ';
    }
    if (infix[i] == '*' || infix[i] == '/') {
      if (opStack.isEmpty() || opStack.get() == '+'
          || opStack.get() == '-' || opStack.get() == '(') {
        opStack.push(infix[i]);
      } else {
        while (opStack.get() == '*' || opStack.get() == '/') {
          postfix += opStack.pop();
          postfix += ' ';
        }
        opStack.push(infix[i]);
      }
    }
    if (infix[i] == '+' || infix[i] == '-') {
      if (opStack.isEmpty() || opStack.get() == '(') {
        opStack.push(infix[i]);
      } else {
        while (opStack.get() == '*' || opStack.get() == '/'
            || opStack.get() == '+' || opStack.get() == '-') {
          postfix += opStack.pop();
          postfix += ' ';
        }
        opStack.push(infix[i]);
      }
    }
    if (infix[i] == '(') {
      opStack.push(infix[i]);
    }
    if (infix[i] == ')') {
      while (opStack.get() != '(') {
        postfix += opStack.pop();
        postfix += ' ';
      }
      opStack.pop();
    }
  }
  while (!opStack.isEmpty()) {
    postfix += opStack.pop();
    postfix += ' ';
  }
  if (postfix[postfix.length() - 1] == ' ') {
    postfix.erase(postfix.length() - 1, 1);
  }
  return postfix;
}
