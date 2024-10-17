# Waveform Generator

This C++ program generates various signal waveforms, including sine, square, and triangle waves. It allows for user-defined frequency, amplitude, phase shift, duration, and sampling rate.

## Features
- **Waveform Generation**: Generates sine, square, and triangle waveforms.
- **User Input**: Allows users to specify waveform parameters.
- **Data Output**: Saves waveform data to a CSV file (`output.csv`).

## Requirements
- **C++ Compiler**: (e.g., GCC, Clang)

## Usage

### 1. **Compile the Program:**
To compile the program, use the following command:

```bash
g++ main.cpp -o waveform_generator
```

### 2. Run the Program:
After compiling, run the executable:

```bash
./waveform_generator
```

### 3. Follow the Prompts:
Select the desired waveform type (1-Sine, 2-Square, 3-Triangle).
Enter the required waveform parameters (frequency, amplitude, phase shift, duration, and sampling rate).
Choose whether to save the waveform to a CSV file.
Example:

```bash
Select waveform type (1 - Sine, 2 - Square, 3 - Triangle): 1
Enter frequency (Hz): 50
Enter amplitude: 1.0
Enter phase shift (optional): 0.0
Enter duration (seconds): 1.0
Enter sampling rate (samples/second): 1000
Save waveform to CSV file? (y/n): y
Waveform saved to output.csv
```

## Customization

- **Waveforms**: You can easily add more waveform types by creating new derived classes from the base `Waveform` class.
- **DSP Functions**: Implement additional signal processing operations, such as filtering, noise addition, or combining multiple waveforms.

## Notes

- **CSV Output**: The generated CSV file (`output.csv`) will contain the sampled waveform data.

## Troubleshooting

- If you encounter issues during compilation, ensure you have a C++ compiler installed and correctly configured.
