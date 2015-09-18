"""
Collection of first-order ODE steppers.

First-order differential equations can be solved numerically by
stepping through the solution in discrete increments of the
independent variable (here referred to as time 't'). Several methods
with varying convergence behaviours are implemented.

The function argument 'd_dt' is assumed to be a function which 
takes a state vector (np.array) s and returns ds/dt.
"""

def euler(state, d_dt, dt):
    """
    Euler stepper.

    Evolve the system 'state' by the time derivative function 'd_dt'
    over the timestep dt, using the Euler method.
    """
    f = d_dt(state)
    state += f * dt
    

def rk4(state, d_dt, dt):
    """
    4th-order Runge-Kutta stepper.

    Evolve the system 'state' by the time derivative function 'd_dt'
    over the timestep dt, using Runge-Kutta 4th-order.
    """
    x0 = state
    f1 = d_dt(x0)
    x1 = x0 + f1 * dt/2.
    f2 = d_dt(x1)
    x2 = x0 + f2 * dt/2.
    f3 = d_dt(x2)
    x3 = x0 + f3 * dt
    f4 = d_dt(x3)
    f = ( f1 + 2*f2 + 2*f3 + f4 )/6.
    state += f * dt

