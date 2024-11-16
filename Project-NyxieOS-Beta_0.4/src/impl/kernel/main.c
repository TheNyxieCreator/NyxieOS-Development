#include "print.h"

void kernel_main() {
  print_clear();
  print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
  print_str("# Bem-vindo, ao Project NyxieOS com suporte 64bit!");
  
}
