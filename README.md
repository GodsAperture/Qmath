# Qmath
The qmath library is a math library for C++ (and maybe C in the future if compatibility favors me). This library contains functions that are faster than the standard library (tested on Windows 10 with an Intel i7-7700).

Little testing has been done with this library, I'm not sure which cpus will be able to run it faster and which ones will run slower. It appears though that Ryzen is very slow with this code, and I'm not entirely sure why.

Use this library at your own discretion as there are functions that don't have safety nets whatsoever. Example: qmath::log(n) where n < 0 will still evaluate and return a number.

The library is split into two sections. The default section (qmath) contains double based math functions while the other (qmathf) contains float based version of these same functions.

I'm still working out the header file as I've never done header files before and am trying to get my CS friends to help me better understand header files.
