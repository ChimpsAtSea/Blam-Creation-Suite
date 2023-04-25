#include "mopptesting-private-pch.h"

#include <vector>
#include <string>
#include <sstream>

class h_data
{
public:
	std::vector<char> m_data;

	h_data(void*)
	{

	}

	void append_elements(const char* _data, size_t size)
	{
		m_data.insert(m_data.end(), _data, _data + size);
	}

	void* create_elements(unsigned int count)
	{
		size_t index = m_data.size();
		for (unsigned int i = 0; i < count; i++)
		{
			m_data.emplace_back();
		}
		return &m_data[index];
	}

	size_t size()
	{
		return m_data.size();
	}

	char* data()
	{
		return m_data.data();
	}

};

void mopptesting()
{
	constexpr unsigned int k_num_box_requests = 128;

	std::stringstream s;

	//for (int box_request = 1; box_request <= k_num_box_requests; box_request++)
	auto box_request = 5;
	{
		s_mopp_box_request* mopp_box_requests = new s_mopp_box_request[box_request]{};

		for (unsigned int box_request_index = 0; box_request_index < box_request; box_request_index++)
		{
			s_mopp_box_request& mopp_box_request = mopp_box_requests[box_request_index];
			mopp_box_request.half_extents_x = 10000; // #TODO
			mopp_box_request.half_extents_y = 10000; // #TODO
			mopp_box_request.half_extents_z = 10000; // #TODO
		}

		t_mopp_box_result mopp_box_result = box_mopps_request(mopp_box_requests, box_request);
		ASSERT(mopp_box_result);

		delete[] mopp_box_requests;

		h_data mopp_code(nullptr);

		mopp_code.append_elements(reinterpret_cast<char const*>(&mopp_box_result->code_info_x), sizeof(mopp_box_result->code_info_x));
		mopp_code.append_elements(reinterpret_cast<char const*>(&mopp_box_result->code_info_y), sizeof(mopp_box_result->code_info_y));
		mopp_code.append_elements(reinterpret_cast<char const*>(&mopp_box_result->code_info_z), sizeof(mopp_box_result->code_info_z));
		mopp_code.append_elements(reinterpret_cast<char const*>(&mopp_box_result->code_info_w), sizeof(mopp_box_result->code_info_w));
		mopp_code.append_elements(reinterpret_cast<char const*>(&mopp_box_result->build_type), sizeof(mopp_box_result->build_type));
		if (unsigned int alignment_over = mopp_code.size() % 16)
		{
			mopp_code.create_elements(16 - alignment_over);
		}
		mopp_code.append_elements(static_cast<char const*>(mopp_box_result->mopp_codes), mopp_box_result->mopp_codes_bytes);
		if (unsigned int alignment_over = mopp_code.size() % 16)
		{
			mopp_code.create_elements(16 - alignment_over);
		}

		c_fixed_path output;
		output.format("mopps/mopps%i.bin", box_request);
		filesystem_write_file_from_memory(output, mopp_code.data(), mopp_code.size());

		s <<
			box_request << "," <<
			mopp_box_result->mopp_codes_bytes << "," <<
			mopp_box_result->code_info_x << "," <<
			mopp_box_result->code_info_y << "," <<
			mopp_box_result->code_info_z << "," <<
			mopp_box_result->code_info_w << "," <<
			(float)mopp_box_result->build_type;
		for (unsigned int index = 0; index < k_num_box_requests; index++)
		{
			if (index < box_request)
			{
				s << "," << mopp_box_result->hit_index_to_shape_index[index];
			}
			else
			{
				s << "," << "";
			}
		}
		s << std::endl;
	}

	std::string csv = s.str();
	filesystem_write_file_from_memory("mopps/info.csv", csv.data(), csv.size());
}

extern "C" int bcs_main()
{
	BCS_RESULT rs = BCS_S_OK;

	BCS_RESULT console_result = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Eldorado Cache File Test Console") : BCS_S_OK;
	if (BCS_SUCCEEDED(console_result))
	{
		mopptesting();
	}

	bool write_memory_allocations = command_line_has_argument("writememoryallocations");
	if (write_memory_allocations)
	{
		::write_memory_allocations();
	}
	if (console_is_verbose())
	{
		print_memory_allocations();
	}

	BCS_FAIL_RETURN(rs);

	return 0;
}
