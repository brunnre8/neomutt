#define TEST_NO_MAIN
#include "config.h"
#include "acutest.h"
#include <string.h>
#include "mutt/lib.h"
#include "email/lib.h"

void test_email_header_update(void)
{
  // struct ListNode *header_update(sturct ListNode *hdr, const struct Buffer *buf)
  const char *existing_header = "X-Found: foo";
  const char *new_value = "X-Found: 3.14";

  struct ListNode *n = mutt_mem_calloc(1, sizeof(struct ListNode));
  n->data = strdup(existing_header);
  struct Buffer buf = mutt_buffer_make(32);
  mutt_buffer_strcpy(&buf, new_value);

  {
    struct ListNode *got = header_update(n, &buf);
    TEST_CHECK(got == n);                          /* returns updated node */
    TEST_CHECK(strcmp(got->data, new_value) == 0); /* node updated to new value */
  }
}
