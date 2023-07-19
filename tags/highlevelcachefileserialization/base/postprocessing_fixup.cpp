#include "highlevelcachefileserialization-private-pch.h"

c_postprocessing_fixup::c_postprocessing_fixup(bool _multi_thread, t_postprocessing_fixup_function _function) :
	multi_thread(_multi_thread),
	function(_function)
{

}