#include <iostream>
#include <math.h>
#include "ODEs/explicit_euler.hpp"
#include "ODEs/modified_midpoint.hpp"
#include "ODEs/modified_euler.hpp"
#include "ODEs/runge_kutta.hpp"
#include "ODEs/extrapolated_midpoint.hpp"

static constexpr double alpha = 4.0*10.0e-13;
static constexpr double T_a4 = pow(250.0, 4);

template <class E>
class ExplicitRadiation : public ODEs::ExplicitEuler<E> {
public:
  ExplicitRadiation(E initial_condition, E step_size, int steps) :
    ODEs::ExplicitEuler<E>(initial_condition, -1*alpha*(pow(initial_condition, 4) - T_a4),
                     step_size, steps) {};

  E derivative(E t_n, E T_n) {
    return -alpha*(pow(T_n, 4) - T_a4);
  };
};

template <class E>
class ModifiedMidpointRadiation : public ODEs::ModifiedMidpoint<E> {
public:
  ModifiedMidpointRadiation(E initial_condition, E step_size, int steps) :
    ODEs::ModifiedMidpoint<E>(initial_condition, -1*alpha*(pow(initial_condition, 4) - T_a4),
                        step_size, steps) {};

  E derivative(E t_n, E T_n) {
    return -alpha*(pow(T_n, 4) - T_a4);
  };
};

template <class E>
class ModifiedEulerRadiation : public ODEs::ModifiedEuler<E> {
public:
  ModifiedEulerRadiation(E initial_condition, E step_size, int steps) :
    ODEs::ModifiedEuler<E>(initial_condition, -1*alpha*(pow(initial_condition, 4) - T_a4),
                     step_size, steps) {};

  E derivative(E t_n, E T_n) {
    return -alpha*(pow(T_n, 4) - T_a4);
  };
};

template <class E>
class RungeKuttaRadiation : public ODEs::RungeKutta<E> {
public:
  RungeKuttaRadiation(E initial_condition, E step_size, int steps) :
    ODEs::RungeKutta<E>(initial_condition, -1*alpha*(pow(initial_condition, 4) - T_a4),
                     step_size, steps) {};

  E derivative(E t_n, E T_n) {
    return -alpha*(pow(T_n, 4) - T_a4);
  };
};

template <class E>
class ExtrapolatedMidpointRadiation : public ODEs::ExtrapolatedMidpoint<E> {
public:
  ExtrapolatedMidpointRadiation(E initial_condition, E step_size, int steps, int M) :
    ODEs::ExtrapolatedMidpoint<E>(initial_condition, -1*alpha*(pow(initial_condition, 4) - T_a4),
                            step_size, steps, M) {};

  E derivative(E t_n, E T_n) {
    return -alpha*(pow(T_n, 4) - T_a4);
  };
};

int main() {
  double initial_condition = 2500.0;
  double del_t = 2.0;
  int steps = 5;

  cout << "Explicit Euler: \n";
  ExplicitRadiation<double> explicit_r(initial_condition, del_t, steps);
  explicit_r.iterate();
  cout << explicit_r << endl;

  cout << "Modified Midpoint: \n";
  ModifiedMidpointRadiation<double> midpoint_r(initial_condition, del_t, steps);
  midpoint_r.iterate();
  cout << midpoint_r << endl;

  cout << "Modified Euler: \n";
  ModifiedEulerRadiation<double> euler_r(initial_condition, del_t, steps);
  euler_r.iterate();
  cout << euler_r << endl;

  cout << "Runge Kutta: \n";
  RungeKuttaRadiation<double> rk_r(initial_condition, del_t, steps);
  rk_r.iterate();
  cout << rk_r << endl;

  cout << "Extrapolated Modified Midpoint: \n";
  ExtrapolatedMidpointRadiation<double> exmidpoint_r(initial_condition, del_t, steps, 16);
  exmidpoint_r.iterate();
  cout << exmidpoint_r;

  return 0;
}
