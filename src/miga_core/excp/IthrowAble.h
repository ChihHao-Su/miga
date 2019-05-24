#pragma once
#include "../utils.h"
#include <exception>
#include <string>
using std::exception;
using std::string;

namespace noname{
interface IThrowAble
{
	DCL_INTERFACE_FUNC(
		const string getInfo() const noexcept
	);
	DCL_INTERFACE_FUNC(
		const string getName() const noexcept
	);
};
}
