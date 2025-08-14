#include <stdio.h>
#include <math.h>

int main() {
    const float PI = 3.14;

    float samples_per_second = 44100;
    int tone_freq = 440;
    int duration = 2;
    int max_value_encoding = 32767; // highest integer for signed 16-bit

    int i = 0;
    int total_samples = duration * samples_per_second;

    float time = 0;
    float angle;

    short int sample;

    FILE *f;
    f = fopen("sine.raw", "wb");
    if (f == NULL) {
        printf("Could not open file.\n");
        return -1;
    }

    while (i < total_samples) {
        time = i * (1/samples_per_second);
        angle = 2 * PI * tone_freq * time;

        // make the sin output (-1 to 1) map to our signed 16-bit so it can be represented as a Pulse-code modulation (PCM) of 16 bits
        sample = max_value_encoding * sin(angle);

        // each sample is a 16 bits data, so we get the reference to each sample and tell the fwrite to read 2 bytes = 16 bits.
        // the 1 means that we're reading only one chunk of 2 bytes as we only have one sample here. Then we write to the "f" file.
        fwrite(&sample, 2, 1, f);
        
        printf("%d ", sample);

        i = i + 1;
    }

    fclose(f);

    return 0;
}