import ctypes

# Load the shared library
lib = ctypes.cdll.LoadLibrary('bcs_python.dll')

# Define the argument and return types for python_test
lib.python_test.argtypes = [ctypes.c_int, ctypes.c_int]
lib.python_test.restype = ctypes.c_int

# Call python_test from Python
result = lib.python_test(1, 2)
print(result)
