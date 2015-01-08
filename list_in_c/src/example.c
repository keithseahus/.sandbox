#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib/list.h"

#define TIMES 1

int test_append() {
	ListHelper *list_helper = newListHelper();
	List *list0 = list_helper->new_list(list_helper);
	List *list1 = list_helper->new_list(list_helper);
	list0->append(list0, list1);

	List *last = list_helper->last(list_helper, list0);

	if (list0 == list1) return 1;
	if (last == list0) return 1;
	if (last == list1) return 0;

	return 1;
}

int test_last() {
	int ret = 0;

	ListHelper *list_helper = newListHelper();
	List *list = list_helper->new_list(list_helper);
	List *last = list_helper->last(list_helper, list);
	if (list != last) {
		printf("list != last\n");
		ret = 1;
	}
	list_helper->destroy_list(list_helper, list);
	(void)list_helper->destroy(list_helper);
	return ret;
}

int test_destroy_list() {
	for (int i=0; i<TIMES; i++) {
		ListHelper *list_helper = newListHelper();
		List *list = list_helper->new_list(list_helper);
		list_helper->destroy_list(list_helper, list);
		// NOTE: 'warning: expression result unused [-Wunused-value]' without cast.
		(void)list_helper->destroy(list_helper);
	}
	return 0;
}

int main(int argc, char *argv[]) {
  int ret = 0;
  printf("---- BEGIN main() ----\n");
  ret = test_destroy_list();
  if (ret != 0) printf("ERROR in test_destroy_list()\n");
  ret = test_last();
  if (ret != 0) printf("ERROR in test_last()\n");
  ret = test_append();
  if (ret != 0) printf("ERROR in test_append()\n");
  printf("---- END main() ----\n");

  /*
  // 1
  List list1 = newList();
  list1.initialize(&list1);
  sprintf(strbuf, "foo");
  memcpy(list1.data, strbuf, sizeof(strbuf));

  // 2
  List list2 = newList();
  list2.initialize(&list2);
  sprintf(strbuf, "bar");
  memcpy(list2.data, strbuf, sizeof(strbuf));

  list1.foreach(&list1, &(list1.dump));

  list1.append(&list1, &list2);
  list1.foreach(&list1, &(list1.dump));

  if(list1.terminate(&list1) != 0) goto err;

  //list1.foreach(&list1, &(list1.dump));
  list1.reverse(&list1, &(list1.dump));
  //List *ptr;
  //list1.last(&list1);
  //memcpy(ptr, list1.last(&list1), sizeof(List*));

  exit_status = EXIT_SUCCESS;
  goto clean_up_and_exit;

err:
  exit_status = EXIT_FAILURE;
  goto clean_up_and_exit;

clean_up_and_exit:
  list1.destroy(&list1);
  list2.destroy(&list2);
  printf("Exit with exit_status(%d)\n", exit_status);
  return exit_status;
  */
}

