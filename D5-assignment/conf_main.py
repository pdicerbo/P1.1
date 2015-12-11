import numpy as np
import matplotlib.pyplot as plt
from steppers import *

try:
    cn = open("config.dat")
    nbody = 0
    # lst = []
    tmp_arr = np.array([])
    Mass = np.array([])
    state = np.array([])
    for line in cn:
        if line[0] != '#':
            if nbody == 0:
                ddt, nstep_f = line.split()
                nstep = int(nstep_f)
                dt = float(ddt)
                nbody = 1
            else:
                tmp_arr = np.array(line.split(), dtype = float)
                Mass = np.append(Mass, tmp_arr[0])
                state = np.append(state, tmp_arr[1:])
                # print("body ", nbody,": ", line)
                nbody += 1
    nbody -= 1

except IOError:
    raise ValueError("config.dat not exist")
    
toplot = np.zeros((1, nbody * 2))
tmp_plot = np.zeros((1, nbody * 2))

# initialize the plot array

for k in range(nbody):
    toplot[0, 2 * k] = state[k*4]
    toplot[0, 2 * k + 1] = state[k * 4 + 1]

i = 0

print("\n\tstarting integration...\n")

while(i < nstep):

    # euler(state, d_dt, dt, M)
    # rk4(state, d_dt, dt, M)
    rk4(state, multiple_d_dt, dt, Mass)
    for k in np.arange(nbody):
        tmp_plot[0, 2 * k] = state[k * 4]
        tmp_plot[0, 2 * k + 1] = state[k * 4 + 1]

    toplot = np.append(toplot, tmp_plot, axis=0)

    i += 1

print("\tintegration done!")

plt.figure()

for k in range(nbody):
    plt.plot(toplot[:, 2 * k], toplot[:, 2 * k + 1])

plt.title("Final Orbit")
plt.xlabel("x (cm)")
plt.ylabel("y (cm)")
plt.show()
plt.close()
plt.figure()
