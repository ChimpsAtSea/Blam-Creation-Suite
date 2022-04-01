#include "devicecommunication-private-pch.h"

BCS_RESULT init_device_communication()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_xbox360_device_manager()))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT deinit_device_communication()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = deinit_xbox360_device_manager()))
	{
		return rs;
	}

	return rs;
}
