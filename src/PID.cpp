#include "PID.h"
#include <iostream>
#include <cmath>

/*
 * TODO: Complete the PID class.
 */

PID::PID(){ }

PID::~PID(){ }

void PID::Init(double kp, double ki, double kd)
{
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;

  p_error_      = 0;
  i_error_      = 0;
  d_error_      = 0;
  d_error_prev_ = 0;

  steps_         = 0;
  average_error_ = 0;
  best_error_    = std::numeric_limits<double>::max();
}

void PID::UpdateError(double cte)
{
  double alpha = 1.0;
  d_error_      = (1 - alpha) * d_error_prev_ + alpha * (cte - p_error_);
  d_error_prev_ = d_error_;

  p_error_  = cte;
  i_error_ += cte;
  i_error_  = std::min(std::max(i_error_, -100.0), 100.0);

  if (steps_ >= 1000) {
    double n = steps_ - 1000;
    average_error_ = n * average_error_ / (n + 1) + std::abs(cte) / (n + 1);
  }
  steps_++;
} // PID::UpdateError

double PID::TotalError()
{
  return -kp_ * p_error_ - ki_ * i_error_ - kd_ * d_error_;
}
