#pragma once

class h_prototype_resource :
	public h_resource
{
public:
	h_prototype* prototype;

	h_prototype_resource(h_prototype* _prototype);

	virtual ~h_prototype_resource();
	virtual BCS_RESULT add_reference(s_resource_details& resource_details, bool create_prototype) override;
	virtual BCS_RESULT remove_reference() override;
	virtual const char* get_debug_type_string() override;
};
