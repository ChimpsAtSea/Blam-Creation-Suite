#include <halo1lib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */


#pragma pack(push, 4)
struct hs_script_op_halo1
{
	short return_type;
	short flags;
	long __unused4;
	const char *name;
	void(__fastcall *print_help_maybe)(short opcode_maybe, unsigned short expression_index);
	void(__fastcall *evaluate)(short opcode, unsigned short expression_index, char execute);
	const char *description;
	const char *parameter_info;
	short parameter_count;
	short parameter_types[2];

	void replace_evaluate(LPVOID new_evaluate)
	{
		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
		memcpy_virtual(&evaluate, &new_evaluate, sizeof(void *));
		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
	}
	void print_parameter_info()
	{
		printf("%s\n", parameter_info);
	}
};
#pragma pack(pop)

// TODO: get the offset for builds 1350, 1367, 1377, 1384, 1387, 1477, 1799, 1520, 1570
uintptr_t hs_function_table_halo1_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180E9C8B0);
	return ~uintptr_t();
}
hs_script_op_halo1 *(&hs_function_table_halo1)[] = reference_symbol<hs_script_op_halo1 *[]>("hs_function_table_halo1", hs_function_table_halo1_offset);

void halo1_halo_script_dump()
{
	if (is_valid(hs_function_table_halo1))
	{
		c_console::write_line_verbose("#include <idc.idc>");
		c_console::write_line_verbose("");

		c_console::write_line_verbose("static main()");
		c_console::write_line_verbose("{");

		c_console::write_line_verbose("    MakeName(0x%08llX, \"_hs_function_table\");", (uintptr_t)&hs_function_table_halo1);
		c_console::write_line_verbose("    SetType(0x%08llX, \"hs_script_op *\");", (uintptr_t)&hs_function_table_halo1);
		c_console::write_line_verbose("");

		for (short i = 0; i < 510; i++)
		{
			uintptr_t hs_function_op = (uintptr_t)hs_function_table_halo1[i];
			uintptr_t hs_function = (uintptr_t)&hs_function_table_halo1[i];
			const char *&hs_function_name = hs_function_table_halo1[i]->name;
			uintptr_t hs_function_evaluate = (uintptr_t)hs_function_table_halo1[i]->evaluate;

			std::string name = hs_function_name;

			std::pair<const char *, const char *> hs_arithmetic_name_map[10] =
			{
				{ "+", "add" }, { "-", "subtract" }, { "*", "multiply" }, {"/", "divide" },
				{ "=", "equal" },  {"!=", "not_equal" }, { ">", "greater_than" }, { "<", "less_than" }, { ">=", "greater_than_or_equal" }, { "<=", "less_than_or_equal" }
			};

			for (decltype(hs_arithmetic_name_map[0]) hs_arithmetic_name_pair : hs_arithmetic_name_map)
			{
				if (strcmp(hs_function_name, hs_arithmetic_name_pair.first) == 0)
				{
					name = hs_arithmetic_name_pair.second;
				}
			}

			c_console::write_line_verbose("    // 0x%03X, %s", i, hs_function_name);

			c_console::write_line_verbose("    MakeName(0x%08llX, \"_hs_%s_op\");", hs_function_op, name.c_str());
			c_console::write_line_verbose("    SetType(0x%08llX, \"hs_script_op\");", hs_function_op);

			c_console::write_line_verbose("    MakeName(0x%08llX, \"_hs_%s_evaluate\");", hs_function_evaluate, name.c_str());
			c_console::write_line_verbose("    MakeCode(0x%08llX);", hs_function_evaluate);


			c_console::write_line_verbose("");
		}


		c_console::write_line_verbose("}");

		return;
	}

	c_console::write_line_verbose("Unable to dump");
}

c_halo1_halo_script_command::c_halo1_halo_script_command()
{
	c_console::register_command(k_halo1_halo_script_command_name, this);
}

c_halo1_halo_script_command::~c_halo1_halo_script_command()
{
	c_console::unregister_command(k_halo1_halo_script_command_name);
}

bool c_halo1_halo_script_command::execute_command(const std::vector<std::string> &arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo1_halo_script_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string &arg1 = arguments[1];

			c_console::set_text_color(_console_color_info);

			if (arguments.size() == 2 && !arg1.compare("dump"))
			{
				halo1_halo_script_dump();
			}
		}
		else return false;
	}
	return true;
}

std::string c_halo1_halo_script_command::get_command_info(const std::string &topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo1_halo_script_command_name))
		{
			return
				"halo_script\n"
				"Usage: halo_script <arg>";
		}
	}
	return "";
}

std::string c_halo1_halo_script_command::get_command_auto_complete(const std::vector<std::string> &Arguments) const
{
	return ""; // todo;
}

/* ---------- private code */

