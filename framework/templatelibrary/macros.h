#pragma once

#define vector_erase_by_value_helper(vector, value) vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
