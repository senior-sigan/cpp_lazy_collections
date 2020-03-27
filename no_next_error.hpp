#pragma once

#include <stdexcept>

struct NoNextError : public std::logic_error {
  NoNextError() : logic_error("End of list") {}
};