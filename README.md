# prime-factor-calculator
Multi-threaded program that performs prime factorization.
Very inefficient. There are methods like the quadratic sieve algorithm which could do it better. Maybe I'll improve it with another version; this was quickly put together to solve a Project Euler question. The multithreading was a complete afterthought, it was taking ages so I split it into four different threads which sped things up quite a bit.

Compiled with <code> clang++ -std=c++11 factorization.cpp </code>
