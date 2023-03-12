import os
import ctypes

# Load the shared library
if os.path.exists('./bcs_python.dll'):
	lib = ctypes.cdll.LoadLibrary('./bcs_python.dll')
else:
	lib = ctypes.cdll.LoadLibrary('bcs_python.dll')


# Define the argument and return types for python_test
lib.python_test.argtypes = [ctypes.c_int, ctypes.c_int]
lib.python_test.restype = ctypes.c_int

# Call python_test from Python
result = lib.python_test(1, 2)
print(result)


# Define the callback function in Python
def my_callback(x):
    print("The value of x is:", x)

# Define the prototype of the C function that will call the callback
callback_type = ctypes.CFUNCTYPE(None, ctypes.c_int)

# Create a function pointer that points to the Python callback function
callback_func = callback_type(my_callback)





# Get a reference to the C function that will call the callback
call_with_callback = lib.call_with_callback

# Set the argument types for the C function
call_with_callback.argtypes = [callback_type]




# Call the C function with the callback
call_with_callback(callback_func)



