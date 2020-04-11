#pragma once

#include "FindOffsetFunction.h"

// #TODO: (Squaresome) Refactor the s_data_reference_legacy API because it is crazy!

#pragma optimize("", off) // MSVC optimization absolutely destroys function hooking

#include "FunctionHookBase.h"
#include "FunctionHook.h"
#include "FunctionHookEx.h"
#include "FunctionHookVarArgs.h"
#include "FunctionHookVarArgsEx.h"

#pragma optimize("", on)

/* LEGACY */ #include "opus_legacy/detour_helpers.h"
#include "SystemPatch.h"
#include "DataPatch.h"
