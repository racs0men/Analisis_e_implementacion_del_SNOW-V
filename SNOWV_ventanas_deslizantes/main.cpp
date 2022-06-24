#include "SNOWV.h"

using namespace std;
using namespace std::chrono;

double result(double total, double second) {
  double percentage = (100 * second) / total;
  return percentage;
}

int main(void) {
  SnowV32 SNOW_V;

  u8 key[32] = {0x00};
  u8 iv[16] = {0x00};

  int is_aead_mode = 0;

  for (int i = 0; i < 10000; i++) {
    SNOW_V.keyiv_setup(key, iv, is_aead_mode);
    for (int i = 0; i < 8; i++) {
      u8 z[16];
      SNOW_V.keystream(z);
    }
  }

  double acc_total = acc_aes + acc_mul + acc_mul_inv + acc_sigma + acc_fsm + acc_lfsr + acc_key + acc_keyiv;

  cout << "\nTotal execution time:\t " << acc_total << " microseconds.\n" << endl;
  cout << "Function aes_enc_round:\t " << acc_aes << " microseconds." << endl;
  cout << "Function mul_x:\t\t " << acc_mul << " microseconds." << endl;
  cout << "Function mul_x_inv:\t " << acc_mul_inv << " microseconds." << endl;
  cout << "Function permute_sigma:\t " << acc_sigma << " microseconds." << endl;
  cout << "Function fsm_update:\t " << acc_fsm << " microseconds." << endl;
  cout << "Function lfsr_update:\t " << acc_lfsr << " microseconds." << endl;
  cout << "Function keystream:\t " << acc_key << " microseconds." << endl;
  cout << "Function keyiv_setup:\t " << acc_keyiv << " microseconds.\n" << endl;

  cout << "\nPercentages with respect to total:\n" << endl;

  double result_aes = result(acc_total, acc_aes);
  cout << "Function aes_enc_round:\t " << result_aes << " %." << endl;

  double result_mul = result(acc_total, acc_mul);
  cout << "Function mul_x:\t\t " << result_mul << " %." << endl;

  double result_mul_inv = result(acc_total, acc_mul);
  cout << "Function mul_x_inv:\t " << result_mul_inv << " %." << endl;

  double result_sigma = result(acc_total, acc_sigma);
  cout << "Function permute_sigma:\t " << result_sigma << " %." << endl;

  double result_fsm = result(acc_total, acc_fsm);
  cout << "Function fsm_update:\t " << result_fsm << " %." << endl;

  double result_lfsr = result(acc_total, acc_lfsr);
  cout << "Function lfsr_update:\t " << result_lfsr << " %." << endl;

  double result_key = result(acc_total, acc_key);
  cout << "Function keystream:\t " << result_key << " %." << endl;

  double result_keyiv = result(acc_total, acc_keyiv);
  cout << "Function keyiv_setup:\t " << result_keyiv << " %.\n\n" << endl;
}
