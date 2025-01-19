#include <cstdlib>
#include <iostream>

struct Empty          { };
struct Base           { int a; };
struct Derived : Base { int b; };
struct Bit            { unsigned bit: 1; };
struct CharChar       { char c; char c2; };
struct CharCharInt    { char c; char c2; int i; };
struct IntCharChar    { int i;  char c;  char c2; };
struct CharIntChar    { char c; int i;   char c2; };
struct CharShortChar  { char c; short s; char c2; };

int main()
{
    Empty e;
    Derived d;
    Base& b = d;
    [[maybe_unused]] Bit bit;
    int a[10];

    auto f = [&]() { return sizeof(int[10]) == sizeof a ? throw 1 : e; };
//  f(); // the return type is Empty, but always throws 1

    auto println = [](auto rem, std::size_t size) { std::cout << rem << size << '\n'; };

    println( "1) sizeof empty class:              ", sizeof e                     );
    println( "2) sizeof pointer:                  ", sizeof &e                    );
    println( "3) sizeof(Bit) class:               ", sizeof(Bit)                  );
    println( "4) sizeof(int[10]) array of 10 int: ", sizeof(int[10])              );
    println( "5) sizeof a        array of 10 int: ", sizeof a                     );
    println( "6) length of array of 10 int:       ", ((sizeof a) / (sizeof *a))   );
    println( "7) length of array of 10 int (2):   ", ((sizeof a) / (sizeof a[0])) );
    println( "8) sizeof the Derived class:        ", sizeof d                     );
    println( "9) sizeof the Derived through Base: ", sizeof b                     );
    println( "A) sizeof(unsigned):                ", sizeof(unsigned)             );
    println( "B) sizeof(int):                     ", sizeof(int)                  );
    println( "C) sizeof(short):                   ", sizeof(short)                );
    println( "D) sizeof(char):                    ", sizeof(char)                 );
    println( "E) sizeof(CharChar):                ", sizeof(CharChar)             );
    println( "F) sizeof(CharCharInt):             ", sizeof(CharCharInt)          );
    println( "G) sizeof(IntCharChar):             ", sizeof(IntCharChar)          );
    println( "H) sizeof(CharIntChar):             ", sizeof(CharIntChar)          );
    println( "I) sizeof(CharShortChar):           ", sizeof(CharShortChar)        );
    println( "J) sizeof f():                      ", sizeof f()                   );
    println( "K) sizeof Base::a:                  ", sizeof Base::a               );

//  println( "sizeof function:        ", sizeof(void()) ); // error
//  println( "sizeof incomplete type: ", sizeof(int[])  ); // error
//  println( "sizeof bit-field:       ", sizeof bit.bit ); // error
}
