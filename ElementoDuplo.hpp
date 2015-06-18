// Copyright [2015] <Leonardo Vailatti Eichstaedt>

#ifndef ELEMENTODUPLO_HPP
#define  ELEMENTODUPLO_HPP

template<typename T>
class ElementoDuplo{
 private:
  T *info;
  ElementoDuplo<T>* _next;
  ElementoDuplo<T>* _back;

 public:
  ElementoDuplo(const T& info, ElementoDuplo<T>* next, ElementoDuplo<T>* back) :
  info(new T(info)), _next(next), _back(back) {
  }
  ~ElementoDuplo() {
    delete info;
  }
  ElementoDuplo<T>* getProximo() const {
    return _next;
  }
  ElementoDuplo<T>* getAnterior() const {
    return _back;
  }
  T getInfo() const {
    return *info;
  }
  void setProximo(ElementoDuplo<T>* next) {
    _next = next;
  }
  void setAnterior(ElementoDuplo<T>* back) {
    _back = back;
  }
};

#endif
