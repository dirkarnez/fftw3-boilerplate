#include <iostream>
#include "fftw3.h"

#define _USE_MATH_DEFINES
#include <cmath>

int main(void)
{
  const int SAMPLE_FREQUENCY = 44100;
  const int DURATION = 0.5;
  const int number_of_samples = SAMPLE_FREQUENCY * DURATION;

  fftw_complex in[number_of_samples], out[number_of_samples]; //, in2[number_of_samples]; /* double [2] */
  fftw_plan p, q;
  int i;

  /* prepare a cosine wave */
  for (i = 0; i < number_of_samples; i++)
  {
    in[i][0] = 0.7 * cos(2 * M_PI * 5000 * (i / SAMPLE_FREQUENCY));
    in[i][1] = 0;
  }

  /* forward Fourier transform, save the result in 'out' */
  p = fftw_plan_dft_1d(number_of_samples, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(p);
  
  for (i = 0; i < number_of_samples; i++)
  {
    printf("freq: %3d %+9.5f %+9.5f I\n", i, out[i][0], out[i][1]);
  }

  fftw_destroy_plan(p);

  // /* backward Fourier transform, save the result in 'in2' */
  // printf("\nInverse transform:\n");
  // q = fftw_plan_dft_1d(N, out, in2, FFTW_BACKWARD, FFTW_ESTIMATE);
  // fftw_execute(q);

  // /* normalize */
  // for (i = 0; i < N; i++)
  // {
  //   in2[i][0] *= 1. / N;
  //   in2[i][1] *= 1. / N;
  // }

  // for (i = 0; i < N; i++)
  // {
  //   printf("recover: %3d %+9.5f %+9.5f I vs. %+9.5f %+9.5f I\n",
  //          i, in[i][0], in[i][1], in2[i][0], in2[i][1]);
  // }
  // fftw_destroy_plan(q);

  fftw_cleanup();

  std::cin.get();
  return 0;
}