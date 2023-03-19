# UBC (Unlimited Base Converter)

Download binary from [releases](https://github.com/mv-kan/unlimited-base-conversion/releases/) (its only for linux) and then 
```
ubc [the number you want to convert] [the number base] [result base]
example1:       ubc 10101 2 10
output1:        21

example2:       ubc AAAABBBBCCCCDDDD 16 36
output2:        2LFLJC63L8XR1

example3:       ubc FFFF 16 10
output3:        65535

example4:       ubc Hello 36 10
output4:        Error (because lowercase letters are not present in 36 base only uppercase)
```
You can convert **any** number of **any** base to **any** base* (to 62 base max, but you can change it in code).

# My specific needs require more than 62 bases!!!

Well in that case you need to:
1. download source code
```
git clone https://github.com/mv-kan/unlimited-base-conversion.git
```
2. change source code in ./src/uuint_t.h
```
// in ./src/uuint_t.h
inline std::string_view NumChar()
{
   // this is max to 62 base number
   // but if you add chars to this, my program would be able to convert to any base you want
   // each index of this string is int value of each char, so if we were to add another char to this string, the last char would convert to 62 in int, and max base would be 63
   return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}
```
3. compile the code (**required** cmake and make to be installed)
```
cd unlimited-base-conversion
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ../src
make
```
4. voala, enjoy more bases with fresh compiled `ubc` bin