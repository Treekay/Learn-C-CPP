const int MAX_LEN = 5;

template<class T>

class Stack{

public:

    explicit Stack(){
      for (int index = 0; index < 0; index++){
        data[index] = 0;
      }
      stack_size = 0;
    }

    bool empty() const{
      return stack_size;
    }

    int size() const{
      return stack_size;
    }

    T& top(){
      if (stack_size == 0) throw 1;
      else return data[stack_size-1];
    }

    const T& top() const{
      if (stack_size == 0) throw 1;
      return data[stack_size-1];
    }

    void push(const T& x){
      if (stack_size < MAX_LEN) data[stack_size++] = x;
      else if (x > data[stack_size-1]) data[stack_size-1] = x;
    }

    void pop(){
      if (stack_size == 0) throw 3.4;
      else {
        data[stack_size-1] = 0;
        stack_size--;
      }
    }

private:

    T data[MAX_LEN];
    int stack_size;

};