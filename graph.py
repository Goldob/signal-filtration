#!/bin/env python

import sys
import matplotlib.pyplot as plt

in_filename = sys.argv[1]
in_file = open(in_filename, 'r')

first_line = in_file.readline().split()
n_samples = int(first_line[1])
samples = list()

for i in range(n_samples):
    samples.append(float(in_file.readline()))

plt.plot(samples)
plt.show()
