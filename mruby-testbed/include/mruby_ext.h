#ifndef MRUBY_EXT_H
#define MRUBY_EXT_H

#include "mruby/common.h"
#include <mruby/value.h>


MRB_API mrb_value* mrb_ext_get_arg(mrb_state *mrb, mrb_int index);


#endif