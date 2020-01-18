#include <iostream>
#include <mruby.h>
#include <mruby_ext.h>
#include <mruby/compile.h>
#include <mruby/string.h>
#include "main.h"

using namespace std;


/*
mrb_value DebugLog(mrb_state* mrb, mrb_value self)
{
	const char* str = nullptr;
	mrb_int len = 0;
	auto args = mrb_get_args(mrb, "s", &str, &len);
	puts(str);
	return self;
}
*/


mrb_value DebugLog(mrb_state* mrb, mrb_value self)
{
	auto argc = mrb_get_argc(mrb);
	auto arg0 = mrb_ext_get_arg(mrb, 0);
	
	auto str = mrb_string_value_cstr(mrb, arg0);
	puts(str);
	return self;
}


int main()
{
	auto mrb = mrb_open();
	if (!mrb)
	{
		return 0;
	}

	auto debugClass = mrb_define_class(mrb, "Debug", mrb->object_class);
	mrb_define_method(mrb, debugClass, "log", DebugLog, MRB_ARGS_REQ(1));

	mrb_load_string(mrb, "d = Debug.new; d.log 'hello'");
	mrb_close(mrb);
	return 0;
}
