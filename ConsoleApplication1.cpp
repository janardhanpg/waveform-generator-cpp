#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string> // For string manipulation
#define M_PI 3.1425
using namespace std;

// Base Waveform Class
class Waveform {
public:
    virtual float generate(float time) = 0; // Pure virtual function to generate waveform value
    void setFrequency(float freq) { frequency = freq; }
    void setAmplitude(float amp) { amplitude = amp; }
    void setPhase(float ph) { phase = ph; }

protected:
    float frequency;
    float amplitude;
    float phase;
};

// Derived Sine Wave Class
class SineWave : public Waveform {
public:
    float generate(float time) override {
        return amplitude * sin(2 * M_PI * frequency * time + phase);
    }
};

// Derived Square Wave Class
class SquareWave : public Waveform {
public:
    float generate(float time) override {
        return amplitude * (sin(2 * M_PI * frequency * time + phase) >= 0 ? 1 : -1);
    }
};

// Derived Triangle Wave Class
class TriangleWave : public Waveform {
public:
    float generate(float time) override {
        float normalizedTime = fmod(frequency * time + phase, 1.0f);
        if (normalizedTime < 0.5f) {
            return 4.0f * amplitude * normalizedTime;
        }
        else {
            return 4.0f * amplitude * (1.0f - normalizedTime);
        }
    }
};

// Function to generate waveform data
vector<float> generateWaveform(Waveform* waveform, float duration, float sampleRate) {
    vector<float> data;
    float timeStep = 1.0f / sampleRate;
    for (float time = 0; time < duration; time += timeStep) {
        data.push_back(waveform->generate(time));
    }
    return data;
}

// Function to save waveform to CSV
void saveToCSV(const vector<float>& data, const string& filename) {
    ofstream outfile(filename, ios::app); // Open file in append mode
    if (!outfile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    for (float value : data) {
        outfile << value << endl;
    }
    outfile.close();
}



int main() {
    int waveformType;
    float freq, amp, ph = 0;
    float duration = 1.0f, sampleRate = 1000.0f;

    cout << "Select waveform type (1 - Sine, 2 - Square, 3 - Triangle): ";
    cin >> waveformType;

    cout << "Enter frequency (Hz): ";
    cin >> freq;
    cout << "Enter amplitude: ";
    cin >> amp;

    cout << "Enter phase shift (optional): ";
    cin >> ph;

    cout << "Enter duration (seconds): ";
    cin >> duration;

    cout << "Enter sampling rate (samples/second): ";
    cin >> sampleRate;

    Waveform* wave;
    if (waveformType == 1) {
        wave = new SineWave();
    }
    else if (waveformType == 2) {
        wave = new SquareWave();
    }
    else if (waveformType == 3) {
        wave = new TriangleWave();
    }
    else {
        cout << "Invalid waveform type." << endl;
        return 1;
    }

    wave->setFrequency(freq);
    wave->setAmplitude(amp);
    wave->setPhase(ph);

    vector<float> data = generateWaveform(wave, duration, sampleRate);

    cout << "Save waveform to CSV file? (y/n): ";
    char saveChoice;
    cin >> saveChoice;
    if (saveChoice == 'y' || saveChoice == 'Y') {
        saveToCSV(data, "output.csv");
        cout << "Waveform saved to output.csv" << endl;
    }

   

    delete wave; // Deallocate memory for the waveform object

    return 0;
}