#include "test.h"
void final_clear() {
  ModelInfo_t *actual_info = get_info();
  run_terminate_actions(actual_info);
}
int main() {
  int failed = 0;
  int success = 0;

  SRunner *sr = srunner_create(tetris());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  failed += srunner_ntests_failed(sr);
  success += srunner_ntests_run(sr);
  final_clear();

  srunner_free(sr);
  printf("FAILED : %d \n", failed);
  printf("SUCCESS : %d\n", success);

  return (failed == 0) ? FAILURE : SUCCESS;
}