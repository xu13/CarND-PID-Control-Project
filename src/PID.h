#ifndef PID_H
#define PID_H

class PID {
public:

  /*
   * Errors
   */
  double p_error_;
  double i_error_;
  double d_error_;
  double d_error_prev_;

  /*
   * Coefficients
   */
  double kp_;
  double ki_;
  double kd_;

  /*
   * For twiddle
   */
  int steps_;
  double average_error_;
  double best_error_;

  /*
   * Constructor
   */
  PID();

  /*
   * Destructor.
   */
  virtual ~PID();

  /*
   * Initialize PID.
   */
  void Init(double kp, double ki, double kd);

  /*
   * Update the PID error variables given cross track error.
   */
  void UpdateError(double cte);

  /*
   * Calculate the total PID error.
   */
  double TotalError();

  double getP() { return -kp_ * p_error_; }

  double getI() { return -ki_ * i_error_; }

  double getD() { return -kd_ * d_error_; }
};

#endif /* PID_H */
