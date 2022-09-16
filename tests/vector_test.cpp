#include "test.hpp"


int vector_test()
{
	v_constructor();

	v_assign_operator();

	v_begin();
	v_end();
	v_rbegin();
	v_rend();

	v_empty();
	v_reserve();
	v_resize();

	v_access_operator();
	v_at();
	v_front();
	v_back();

	v_assign();
	v_push_back();
	v_pop_back();
	v_insert();
	v_erase();
	v_clear();
	v_swap();

	v_operators();
}