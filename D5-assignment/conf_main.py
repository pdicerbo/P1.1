import numpy as np
import matplotlib.pyplot as plt
from steppers import *


# print("\n\tChoose your initial condition.")
# print("\tIf you put a negative value for the central Mass, \n\tthe program will load automatically the values of the sun - earth system.\n\n")

# M_start = float(input("\tCentral Mass value (g): "))

# if M_start >= 0.:
#     M = M_start
#     x_init = float(input("\tx coordinate of the second mass (cm): "))
#     y_init = float(input("\ty coordinate of the second mass (cm): "))
#     vx     = float(input("\tvelocity along x axis of the second mass (cm / s): "))
#     vy     = float(input("\tvelocity along y axis of the second mass (cm / s): "))
#     dt     = float(input("\ttime step (s): "))
#     nstep  = float(input("\tnumber of time steps: "))
# else:
#     print("\n\tChoosing values for the sun - earth - jupiter system")
#     M = 2.*10**33          # M sun in g
#     M_earth = 5.97 * 10.**27
#     M_jup = 1.898 * 10**30
#     Mass = np.array([M_earth, M, M_jup])
#     # Mass = np.array([M_earth, M])
#     x_init = 1.5 * 10**13 # earth - sun distance in cm
#     y_init = 0.    
#     vx = 0.
#     vy = (6.67 * 10**-8 * M / x_init)**.5

#     x_jup_init = 0.
#     y_jup_init = 7.79 * 10.**13
#     vx_jup = (6.67 * 10**-8 * M / y_jup_init)**.5
#     vy_jup = 0.
    
#     dt = 43200        # timestep in seconds (half of day)
#     nstep = 365 * 2 * 10 # one year * 10 (to see also jupiter's orbit)

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
                # lst.append(line)
                # arr = np.append(arr, np.array(line.split(), dtype = float))
                tmp_arr = np.array(line.split(), dtype = float)
                Mass = np.append(Mass, tmp_arr[0])
                state = np.append(state, tmp_arr[1:])
                # print("body ", nbody,": ", line)
                nbody += 1
    nbody -= 1

except IOError:
    raise ValueError("config.dat not exist")
    
# state = np.array([x_init, y_init, vx, vy])
# state = np.array([x_init, y_init, vx, vy, 0., 0., 0., 0.])
# state = np.array([x_init, y_init, vx, vy, 0., 0., 0., 0., x_jup_init, y_jup_init, vx_jup, vy_jup])

x = np.array(state[0])
y = np.array(state[1])
x_jup = np.array(state[8])
y_jup = np.array(state[9])

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

    x = np.append(x, state[0])
    y = np.append(y, state[1])
    x_jup = np.append(x_jup, state[8])
    y_jup = np.append(y_jup, state[9])

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
plt.plot(x, y)
plt.plot(x_jup, y_jup)
plt.show()
