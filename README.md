
# x86 to C Interface Programming Project

This is the reporsitory for our x86 to C Interface Programming Project


## Authors

- [Christian Dela Peña](https://github.com/Cdp11703)
- [Miguel Francis M. Estañol](https://github.com/SStealth12)


## Run Locally

Clone the project

```bash
  git clone https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project
```

Go to the project directory

```bash
  cd LBYARCH_MCO2
```

Open Project Solution in Visual Studio

## Project Specifications

Write the kernel in (1) C program and (2) an x86-64 assembly language.  
The kernel is to perform a dot product between vector A and vector B and place the result in sdot.  

- Required to use functional scalar SIMD registers
- Required to use functional scalar SIMD floating-point instructions

Input: Scalar variable n (integer) contains the length of the vector; Vectors A and B are both double-precision float. Scalar sdot is a doubleprecision float.
  
Output: store the result in memory location sdot. Display the result for all versions of the kernel (i.e., C and x86-64)

## Execution Time and Analysis

### Machine/ Software Specifications

The programs created for this x86-to-C interface programming project were executed on a computer with the following specifications

- Hardware specifications
  - CPU: AMD Ryzen 7 4800H, 2.9GHz
  - RAM: 8GB DDR4
- Software Specification
  - Visual Studio Community 2022 version 17.9.5
- Program Language
  - C (for main.c)
  - Assembly (for asmfunc.asm)

### Chronometry

To measure the execution time of the C and Assembly code, `QueryPerformanceFrequency, QueryPerformanceCounter` from the windows.h header was utilized. QueryPerformanceCounter is a Windows API function that retrieves the current value of the performance counter, which is a high-resolution (<1us) time stamp

For this implementation, `QueryPerformanceFrequency, QueryPerformanceCounter` was used through the following steps

1. **Initialize the Performance Counter**: The QueryPerformanceFrequency function is called to get the frequency of the performance counter, which is the number of ticks per second. This value is stored in the frequency variable.
2. **Start the Timer**: Before the dot product function is called, QueryPerformanceCounter is invoked with the t1 parameter to get the initial count of ticks.
3. **Execute the Function**: The dot product function is then executed.
4. **Stop the Timer**: After the function execution, QueryPerformanceCounter is invoked again with the t2 parameter to get the final count of ticks.
5. **Calculate Elapsed Time**: The elapsed time in milliseconds is calculated using the formula `(t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart`. This gives the time taken for the function to execute.

### Sanity Checking

For this implementation, the C kernel serves as the "Sanity Check Answer Key". This means that the Assembly output is to be compared with the C output to show the correctness of the program run

### Vector Size

Vector size for this implementation are the following: n= 2⁵, 2⁹, 2¹⁵. This is to accomodate for the limitations of the implementation, while following the intervals provided within the specifications

### Execution Time and Analysis for Vector Size n= 2⁵, Debug Mode

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Debug/2%5E5/2%5E5%20Chart.png?raw=true)
![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Debug/2%5E5/2%5E5%20Average%20Execution%20Time.png?raw=true)

- The running time for the C program ranges from 0.0002 ms to 0.0004 ms.
- The running time for the ASM program is consistently lower, with many iterations completing in 0.0001 ms or even 0 ms.
- Outliers have been observed, such as the 10th iteration where the ASM program took 0.0009 ms, which is significantly higher than its usual running time.
- Overall, the ASM program seems to be more efficient in terms of running time for this specific task.

### Execution Time and Analysis for Vector Size n= 2⁹, Debug Mode

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Debug/2%5E9/2%5E9%20Chart.png?raw=true)
![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Debug/2%5E9/2%5E9%20Average%20Execution%20Time.png?raw=true)

- The running time for the C program ranges from 0.0016 ms to 0.0027 ms, with a noticeable spike to 0.0184 ms at the 23rd iteration.
- The running time for the ASM program is consistently lower, with many iterations completing in 0.0007 ms to 0.0011 ms.
- Overall, the ASM program seems to be more efficient in terms of running time for this specific task.

### Execution Time and Analysis for Vector Size n= 2¹⁵, Debug Mode

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Debug/2%5E15/2%5E15%20Chart.png?raw=true)
![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Debug/2%5E15/2%5E15%20Average%20Execution%20Time.png?raw=true)

- The running time for the C program ranges from 0.0871 ms to 0.2196 ms, with noticeable spikes at the 21st and 30th iterations.
- The running time for the ASM program is consistently lower, with many iterations completing in around 0.0405 ms to 0.0664 ms.
- There were a significant number of spikes in execution time for both ASM and C given the maximum vector size for this implementation, compared to other, smaller vector sizes.

### Execution Time and Analysis for Vector Size n= 2⁵, Release Mode

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Release/2%5E5/2%5E5%20Chart.png?raw=true)
![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Release/2%5E5/2%5E5%20Average%20Execution%20Time.png?raw=true)

- The running time for the C program is mostly 0 ms, with a few iterations taking 0.0001 ms and a noticeable spike to 0.0054 ms at the 14th iteration.
- The running time for the ASM program is consistently lower, with many iterations completing in 0 ms or 0.0001 ms.
- Overall, the ASM program seems to be more efficient in terms of running time for this specific task.

### Execution Time and Analysis for Vector Size n= 2⁹, Release Mode

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Release/2%5E9/2%5E9%20Chart.png?raw=true)
![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Release/2%5E9/2%5E9%20Average%20Execution%20Time.png?raw=true)

- The running time for the C program is mostly 0.0006 ms to 0.0008 ms, with a few iterations taking 0.001 ms and a noticeable spike to 0.0016 ms at the 7th iteration.
- The running time for the ASM program is consistently lower, with many iterations completing in 0.0007 ms to 0.0009 ms.
- In the 6th, 15th, and 18th iterations, the ASM program took relatively longer than its usual running time.

### Execution Time and Analysis for Vector Size n= 2¹⁵, Release Mode

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Release/2%5E15/2%5E15%20Chart.png?raw=true)
![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Release/2%5E15/2%5E15%20Average%20Execution%20Time.png?raw=true)

- The running time for the C program varies, with a few iterations taking 0.039 ms and a noticeable spike to 0.2749 ms at the 23rd iteration.
- The running time for the ASM program is also variable, with many iterations completing in around 0.0416 ms to 0.2228 ms.
- Similar to the debug mode, the running time for both the ASM and the C program have a significant number of spikes/outliers than its counterparts

### General Observation and Analysis

- Vector Sizes
  - As the vector size increases (from 2^5 to 2^15), the running time for both C and ASM programs also increases. This is expected as larger vectors require more computations to calculate the dot product.
  - However, the increase in running time is not linear with the increase in vector size.
- Compiler Modes
  - Debug mode, produced a higher execution time for both C and ASM programs when compared to release mode.
- C vs ASM:
  - In general, the ASM program tends to have lower running times compared to the C program. This suggests that the ASM implementation is more efficient for this specific task of calculating the dot product of two 1D arrays of double.
  - However, there are exceptions where the ASM program has higher running times. These outliers could be due to various factors such as other processes interfering with the program’s execution, cache misses, or the specific implementation of the ASM code.

## Appendix

### Program Output with Correctness Checking (Debug Mode)

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Program%20Output%20(With%20Correctness%20Checking)/Debug.png?raw=true)

### Program Output with Correctness Checking (Release Mode)

![alt text](https://github.com/SStealth12/LBYARCH-x86-to-C-Interface-Programming-Project/blob/master/Images/Program%20Output%20(With%20Correctness%20Checking)/Release.png?raw=true)
