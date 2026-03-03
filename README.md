# AI-Powered Python → Optimized C++ Transpiler

This project demonstrates how to use an OpenAI model to automatically convert Python code into highly optimized C++, compile it with aggressive optimization flags, and benchmark the performance difference.

Everything runs inside a Jupyter Notebook.

---

## Overview

The notebook performs the following pipeline:

1. Define a computationally heavy Python function
2. Execute and benchmark the Python implementation
3. Send the Python code to an OpenAI model (`gpt-5-mini`)
4. Receive optimized C++ code
5. Compile the C++ code using `clang++`
6. Execute and benchmark the compiled binary
7. Compare runtime performance

The goal is to demonstrate real-world AI-assisted performance engineering.

---

## How It Works

### Python Benchmark

A CPU-intensive numerical workload (e.g., large-loop approximation with ~200M iterations) is defined in Python and timed using `time`.

This establishes the baseline runtime.

---

### AI Code Generation

The Python code is sent to the OpenAI API with strict instructions:

- Produce valid C++20 code
- Ensure identical output
- Optimize for maximum runtime performance
- Output only raw C++ code (no explanations)

The generated result is saved as:

```cpp
main.cpp
```

---

### High-Performance Compilation

The generated C++ file is compiled using:

```bash
clang++ -std=c++20 -O3 -Ofast -DNDEBUG -flto main.cpp -o main
```

#### Optimization Flags Explained

- `-O3` → Maximum standard optimizations  
- `-Ofast` → Enables aggressive, non-strict optimizations  
- `-DNDEBUG` → Disables debug checks  
- `-flto` → Link Time Optimization  
- `-std=c++20` → Modern C++ standard  

---

### Execution & Benchmark

The compiled binary is executed:

```bash
./main
```

Runtime is measured and compared against the Python execution time.

---

## Example Results

| Language | Runtime |
|----------|---------|
| Python   | ~19s    |
| C++      | ~0.08s  |
| Speedup  | ~230x   |

(Actual numbers depend on hardware.)

---

## Requirements

### Python

- Python 3.9+
- Jupyter Notebook

### Python Packages

```bash
pip install openai python-dotenv
```

### C++ Compiler

You must have `clang++` installed.

Check:

```bash
clang++ --version
```

Install if needed:

**macOS**
```bash
xcode-select --install
```

**Ubuntu / Debian**
```bash
sudo apt install clang
```

---

## Environment Setup

Create a `.env` file:

```
OPENAI_API_KEY=your_api_key_here
```

The notebook loads it automatically using:

```python
from dotenv import load_dotenv
load_dotenv(override=True)
```

---

## Running the Project

1. Open `main.ipynb`
2. Ensure your `.env` file contains your API key
3. Run all notebook cells
4. Observe:
   - Python execution time
   - Generated C++ code
   - Compilation output
   - C++ execution time
   - Final performance comparison

---

## Purpose

This project showcases:

- AI-assisted systems programming
- Automatic Python → C++ transpilation
- Performance optimization using compiler flags
- Practical benchmarking methodology
- LLM-driven code generation workflows

It can be extended into:

- Competitive programming acceleration
- Scientific computing optimization
- Automated performance tooling
- AI-enhanced build pipelines

---

## Important Notes

- Generated C++ code is compiled directly — always review generated code before using in production.
- `-Ofast` may break strict IEEE floating-point guarantees for performance.
- Performance gains depend on workload type and hardware.

---

## License

For experimental and educational use.
