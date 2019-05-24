#pragma once

#define CA App::get_curr_app()
#define CAO App::get_curr_app().MGout()<<'['+rttr::detail::f()+']'
#define interface struct
#define deleted private
#define DCL_INTERFACE_FUNC(id) \
	virtual id = 0;
