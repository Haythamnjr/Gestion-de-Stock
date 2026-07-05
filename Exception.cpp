#include "Exception.h"
Exception::Exception(string message) :
	message(message) {
}

const char* Exception::what() const noexcept {
	return message.c_str();
}
