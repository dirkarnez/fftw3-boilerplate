#include <iostream>
#include "fftw3.h"

#define SAMPLE_FREQUENCY (44100)
#define DURATION (0.5)
// #define NUMBER_OF_SAMPLES ((SAMPLE_FREQUENCY) * (DURATION))

#define _USE_MATH_DEFINES
#include <cmath>

int main(void)
{
//   fftw_complex in[NUMBER_OF_SAMPLES];
//   fftw_complex out[NUMBER_OF_SAMPLES]; //, in2[number_of_samples]; /* double [2] */
//   fftw_plan p, q;
//   int i;
  const int NUMBER_OF_SAMPLES = (SAMPLE_FREQUENCY) * (DURATION);

  double *in = (double*) fftw_malloc(sizeof(double) * 2*NUMBER_OF_SAMPLES);
  fftw_complex *fft_result= (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * (NUMBER_OF_SAMPLES + 2));

  double time_intervals[NUMBER_OF_SAMPLES];
  double cos_wave[NUMBER_OF_SAMPLES];
  // fftwf_complex* cos_wave = (fftwf_complex*)fftwf_malloc(sizeof(fftwf_complex) * NUMBER_OF_SAMPLES);

  // Generate cosine wave
  for (int i = 0; i < NUMBER_OF_SAMPLES; i++) {
    time_intervals[i] = (double)i / SAMPLE_FREQUENCY;
    cos_wave[i]= 0.7 * cos(2 * M_PI * 5000 * time_intervals[i]);
  }

  fftw_plan plan = fftw_plan_dft_r2c_1d(2 * NUMBER_OF_SAMPLES, cos_wave, fft_result, FFTW_PATIENT);


  // /* prepare a cosine wave */
  // for (i = 0; i < NUMBER_OF_SAMPLES; i++)
  // {
  //   in[i][0] = 0.7 * cos(2 * M_PI * 5000 * (i / SAMPLE_FREQUENCY));
  //   in[i][1] = 0;
  // }

  /* forward Fourier transform, save the result in 'out' */
  // p = fftw_plan_dft_1d(NUMBER_OF_SAMPLES, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
   fftw_execute(plan);

  int half_samples = NUMBER_OF_SAMPLES / 2;
  double* frequencies = (double*)malloc(half_samples * sizeof(double));
  double* magnitudes = (double*)malloc(half_samples * sizeof(double));

    for (int i = 0; i < half_samples; i++) {
        frequencies[i] = (double)SAMPLE_FREQUENCY * i / NUMBER_OF_SAMPLES;
        magnitudes[i] = sqrt(fft_result[i][0] * fft_result[i][0] + fft_result[i][1] * fft_result[i][1]) / half_samples;
        std::cout << frequencies[i] << ":" << magnitudes[i] << std::endl;
        
    }

  fftw_destroy_plan(plan);

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