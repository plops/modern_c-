// https://chriskohlhepp.wordpress.com/advanced-c-lisp/convergence-of-modern-cplusplus-and-lisp/
// g++ --std=gnu++14 -c 1.cpp

#include <iostream>
#include <stdio.h>

struct xplusone {
  template<typename T>
  auto operator() (const T& x) const -> decltype ( x + 1 ){
    return x + 1 ;
  };
} xplusone;

auto terminal = [] (auto term) {
  return [=] (auto func) {
    return func(term);
  };
};
auto fmap = [] (auto f) {
  return [=] (auto t) {
    return terminal(f(t));
  };
};


int main (int argc, char** argv)
{
  auto x = 2.0;
  auto y = xplusone(x);
  auto xplusone2 = [](auto x){
    return x + 1 ;
  };
  auto xplus = [](auto y){
    return [=](auto x) { return x + y; };
  };
  auto z = xplusone2(4);
  std::cout << "= " << xplus(3)(4) << std::endl;

  auto hello = [] (auto s) { fprintf(s,"hefii "); return s; };
  auto world = [] (auto s) { fprintf(s,"wfnti "); return s; };
  auto endl = [] (auto s) { fprintf(s,"\n"); return s; };

  terminal(stdout)(fmap(hello))(fmap(world))(fmap(endl));

  
  return 0;
}

template <typename T> struct is_void { static const bool value = false; };
template <> struct is_void<void> { static const bool value = true; };


// In modern C++, the onus is on the developer to BOTH create type traits AND apply them to attain type safety.


// Concepts are static unit tests embedded inside a template function,
// checks if template argument satisfies the use cases of the template
// function or class.


//////////////////////////////////////////////////////////////
// template <class T> void generic_library_function ( T x ) //
// {							    //
//   BOOST_CONCEPT_ASSERT((EqualityComparable<T>));	    //
// };							    //
//////////////////////////////////////////////////////////////

//  monads are “chainable state containers.”
