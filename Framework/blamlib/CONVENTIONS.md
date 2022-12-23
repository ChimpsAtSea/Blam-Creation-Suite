### blam C++ conventions
___
1. safe C practices should generally be preferred over modern C++
___
2. perform static and runtime assertions where possible, i.e: array bounds, pointers, sizes
___
3. everything_is_in_snake_case_and_verbose
```Cpp
int32_t structure_bsp_index;
```
___
4. `typedef` is deprecated, prefer `using` statements with names that have no prefix (try not to use these)
```Cpp
using real = float; // correct

typedef float real; // deprecated
```
___
5. mutable global variable names start with `g_`
```Cpp
extern s_object_type_definition g_object_type_definitions[];
```
___
6. `enum` and `enum class` names start with `e_`
```Cpp
enum e_cache_file_shared_type;
```
___
7. `struct` names start with `s_`
```Cpp
struct s_tag_reference;
```
___
8. class names start with `c_`
```Cpp
class c_cache_file_reader;
```
___
9. `const` global variable names and enum capacity members start with `k_`
```Cpp
enum e_field_type
{
    _field_tag,
    // ...
    _field_terminator,
    k_number_of_field_types
};
```
___
10. `struct` and `class` fields are each declared on their own lines
```Cpp
struct s_real_point3d
{
    real x;
    real y;
    real z;
};
```
___
11. datatype classes should be explicitly declared `final`
```Cpp
class c_datum_handle final
{
private:
    int32_t m_value;

public:
    // ...
};
```
___
12. pure-virtual classes should explicitly declare `novtable`
```Cpp
class __declspec(novtable) c_cache_file_metadata_and_fixup_loader
{
public:
    virtual bool load_metadata_and_fixup(...) = 0;
};
```
___
13. function parameters are each declared on their own line
```Cpp
bool tag_interop_fixup_manual_for_cache(
    s_tag_interop *interop_object,
    int32_t cache_file_type_index,
    c_aligned_allocator *allocator,
    c_cache_file_fixup_verifier *verifier);
```
___
14. curly braces **always** go on their own line
```Cpp
// wrong:
void do_something_wrong() {
    // oh no!
}

// correct:
void do_something_right()
{
    // oh yea!
}
```
___
15. header files (.h) are divided into the following sections:
```Cpp
/* ---------- constants */
/* ---------- macros */
/* ---------- types */
/* ---------- classes */
/* ---------- globals */
/* ---------- prototypes */
```
___
16. source files (.cpp) are divided into the following sections:
```Cpp
/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */
/* ---------- private code */
```
