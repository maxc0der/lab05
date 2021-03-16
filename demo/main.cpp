#include <Stack2.hpp>
int main() {
  class My_class {
   public:
    My_class() {
      value_i = 0;
      value_f = 0.1;
      value_s = "0";
    }
    My_class(int a, double b, std::string c) {
      value_i = a;
      value_f = b;
      value_s = c;
    }
    int value_i;
    double value_f;
    std::string value_s;
  };

  Stack2<int> stack1;
  stack1.push(10);
  int value1 = 15;
  stack1.push_emplace(value1);
  std::cout << stack1.pop() << "\n\n";
  std::cout << stack1.head() << "\n\n";
}
