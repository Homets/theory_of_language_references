#include "mpc.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

enum { LVAL_NUM, LVAL_ERR, LVAL_SYM, LVAL_SEXPR};
enum  { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM, LERR_MOD_ZERO};

typedef struct {
  int type;
  long num;
  int err;
} lval;

lval eval(mpc_ast_t* t);
lval eval_op(lval x, char* op, lval y);
lval lval_num(long x);
lval lval_err(int x);
void lval_print(lval v);
void lval_println(lval v);
