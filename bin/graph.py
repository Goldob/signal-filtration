#!/bin/env python

import sys
import matplotlib.pyplot as plt

in_filename = sys.argv[1]
in_file = open(in_filename, 'r')

first_line = in_file.readline().split()
sampling_freq = float(first_line[0])
n_samples = int(first_line[1])
samples = list()

for i in range(n_samples):
    samples.append(float(in_file.readline()))

time = [i / sampling_freq for i in range(n_samples)]
    
plt.plot(time, samples)
plt.xlabel('czas [s]')
plt.ylabel('amplituda')
plt.show()
